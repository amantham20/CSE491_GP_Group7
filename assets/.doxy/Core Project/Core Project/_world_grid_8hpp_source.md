

# File WorldGrid.hpp

[**File List**](files.md) **>** [**core**](dir_0d27ce74e9bd514c31e1d63efab6b388.md) **>** [**WorldGrid.hpp**](_world_grid_8hpp.md)

[Go to the documentation of this file](_world_grid_8hpp.md)

```C++


#pragma once

#include <cassert>
#include <fstream>
#include <iostream>
#include <unordered_map>
#include <vector>

#include "CoreObject.hpp"
#include "GridPosition.hpp"
#include "Data.hpp"

namespace cse491 {

  class WorldGrid : public CoreObject {
  protected:
    size_t width = 0;           
    size_t height = 0;          
    std::vector<size_t> cells;  

    // -- Helper functions --

    [[nodiscard]] inline size_t ToIndex(size_t x, size_t y) const {
      return x + y * width;
    }

    // -- Serialize and Deserialize functions --
    // Mechanisms to efficiently save and load the exact state of the grid.
    // File format is width and height followed by all
    // values in the grid on each line thereafter.

    std::string GetTypeName_impl() const override { return "cse491::WorldGrid"; }

    void Serialize_impl(std::ostream & os) const override {
      os << width << " " << height;
      for (size_t state : cells) os << ' ' << state;
      os << std::endl;
    }

    void Deserialize_impl(std::istream & is) override {
      is >> width >> height;
      cells.resize(width * height);
      for (size_t & state : cells) is >> state;
    }

  public:
    WorldGrid() = default;
    WorldGrid(size_t width, size_t height, size_t default_type=0)
      : width(width), height(height), cells(width*height, default_type) { }
    WorldGrid(const WorldGrid &) = default;
    WorldGrid(WorldGrid &&) = default;
    
    WorldGrid & operator=(const WorldGrid &) = default;
    WorldGrid & operator=(WorldGrid &&) = default;

    // -- Accessors --
    [[nodiscard]] size_t GetWidth() const { return width; }
    [[nodiscard]] size_t GetHeight() const { return height; }
    [[nodiscard]] size_t GetNumCells() const { return cells.size(); }

    [[nodiscard]] bool IsValid(double x, double y) const {
      return x >= 0.0 && x < width && y >= 0.0 && y < height;
    }

    [[nodiscard]] bool IsValid(GridPosition pos) const {
      return IsValid(pos.GetX(), pos.GetY());
    }

    [[nodiscard]] size_t At(size_t x, size_t y) const {
      assert(IsValid(x,y));
      return cells[ToIndex(x,y)];
    }

    [[nodiscard]] size_t & At(size_t x, size_t y) {
      assert(IsValid(x,y));
      return cells[ToIndex(x,y)];
    }

    [[nodiscard]] size_t At(GridPosition p) const { return At(p.CellX(), p.CellY()); }

    [[nodiscard]] size_t & At(GridPosition p) { return At(p.CellX(), p.CellY()); }

    [[nodiscard]] size_t operator[](GridPosition p) const { return At(p); }
    [[nodiscard]] size_t & operator[](GridPosition p) { return At(p); }


    // Size adjustments.
    void Resize(size_t new_width, size_t new_height, size_t default_type=0) {
      // Create a new vector of the correct size.
      std::vector<size_t> new_cells(new_width*new_height, default_type);

      // Copy the overlapping portions of the two grids.
      size_t min_width = std::min(width, new_width);
      size_t min_height = std::min(height, new_height);
      for (size_t x = 0; x < min_width; ++x) {
        for (size_t y = 0; y < min_height; ++y) {
          new_cells[x+y*new_width] = cells[ToIndex(x,y)];
        }
      }

      // Swap the new grid in; let the old grid be deallocated in its place.
      std::swap(cells, new_cells);
      width = new_width;
      height = new_height;
    }


    // -- Read and Write functions --
    // These are the same idea as Save and Load, but they are human readable, but they
    // also require that each state has been assigned a unique character symbol.

    void Write(std::ostream & os, const type_options_t & types) const {
      size_t cell_id = 0;
      for (size_t y=0; y < height; ++y) {
        for (size_t x=0; x < width; ++x) {
          os << types[ cells[cell_id++] ].symbol;
        }
        os << '\n';
      }
      os.flush();
    }

    bool Write(std::string filename, const type_options_t & types) const {
      std::ofstream os(filename);
      if (!os.is_open()) {
        std::cerr << "Could not open file '" << filename << "' to write grid." << std::endl;
        return false;
      }
      Write(os, types);
      return true;
    }

    void Read(std::istream & is, const type_options_t & types) {
      // Build a symbol chart for conversions back.
      std::unordered_map<char, size_t> symbol_map;
      for (size_t i=0; i < types.size(); ++i) {
        symbol_map[types[i].symbol] = i;
      }

      // Load the file into memory.
      std::vector<std::string> char_grid;
      std::string line;
      width = 0;
      while (std::getline(is, line)) {
        char_grid.push_back(line);
        if (line.size() > width) width = line.size();
      }
      height = char_grid.size();

      // Convert each symbol to the appropriate value.
      cells.resize(width * height);
      size_t cell_id = 0;
      for (size_t y = 0; y < height; ++y) {
        for (size_t x = 0; x < width; ++x) {
          // Use the cell values provided, or zero if a cell position is missing.
          cells[cell_id++] =
            (x < char_grid[y].size()) ? symbol_map[char_grid[y][x]] : 0;
        }
      }
    }

    bool Read(std::string filename, const type_options_t & types) {
      std::ifstream is(filename);
      if (!is.is_open()) {
        std::cerr << "Could not open file '" << filename << "' to write grid." << std::endl;
        return false;
      }
      Read(is, types);
      return true;
    }

  };

} // End of namespace cse491

```

