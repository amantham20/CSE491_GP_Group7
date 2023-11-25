

# File GridPosition.hpp

[**File List**](files.md) **>** [**core**](dir_0d27ce74e9bd514c31e1d63efab6b388.md) **>** [**GridPosition.hpp**](_grid_position_8hpp.md)

[Go to the documentation of this file](_grid_position_8hpp.md)

```C++


#pragma once

#include <cassert>
#include <compare>    // For operator<=>
#include <cstddef>    // For size_t

namespace cse491 {

  class GridPosition {
  private:
    double x = 0.0;
    double y = 0.0;

  public:
    GridPosition() = default;
    GridPosition(double x, double y) : x(x), y(y) { }
    GridPosition(const GridPosition &) = default;

    GridPosition & operator=(const GridPosition &) = default;

    // -- Accessors --

    [[nodiscard]] double GetX() const { return x; }
    [[nodiscard]] double GetY() const { return y; }
    [[nodiscard]] size_t CellX() const { return static_cast<size_t>(x); }
    [[nodiscard]] size_t CellY() const { return static_cast<size_t>(y); }

    auto operator<=>(const GridPosition &) const = default;

    // -- Modifiers --

    GridPosition & Set(double in_x, double in_y) {
      x=in_x; y=in_y;
      return *this;
    }
    GridPosition & Shift(double shift_x, double shift_y) {
      x += shift_x; y += shift_y;
      return *this;
    }

    GridPosition & operator+=(const GridPosition & in) { return Shift(in.x, in.y); }
    GridPosition & operator-=(const GridPosition & in) { return Shift(-in.x, -in.y); }


    // -- Const Operations --

    [[nodiscard]] GridPosition GetOffset(double offset_x, double offset_y) const {
      return GridPosition{x+offset_x,y+offset_y};
    }

    [[nodiscard]] GridPosition Above(double dist=1.0) const { return GetOffset(0.0, -dist); }

    [[nodiscard]] GridPosition Below(double dist=1.0) const { return GetOffset(0.0, dist); }

    [[nodiscard]] GridPosition ToLeft(double dist=1.0) const { return GetOffset(-dist, 0.0); }

    [[nodiscard]] GridPosition ToRight(double dist=1.0) const { return GetOffset(dist, 0.0); }

    [[nodiscard]] GridPosition operator+(GridPosition in) const {
      return GetOffset(in.x, in.y);
    }
  };

} // End of namespace cse491

```

