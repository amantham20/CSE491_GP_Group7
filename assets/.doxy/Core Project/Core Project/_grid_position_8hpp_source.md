

# File GridPosition.hpp

[**File List**](files.md) **>** [**core**](dir_0d27ce74e9bd514c31e1d63efab6b388.md) **>** [**GridPosition.hpp**](_grid_position_8hpp.md)

[Go to the documentation of this file](_grid_position_8hpp.md)

```C++


#pragma once

#include <cassert>
#include <cmath>    // For sqrt and std::nan()
#include <compare>  // For operator<=>
#include <cstddef>  // For size_t
#include <sstream>  // For std::stringstream
#include <string>

#include "CoreObject.hpp"

namespace cse491 {

class GridPosition : public CoreObject {
private:
  double x = 0.0;
  double y = 0.0;

public:
  GridPosition() = default;
  GridPosition(double x, double y) : x(x), y(y) {}
  GridPosition(const std::string & str) { FromString(str); }
  GridPosition(const GridPosition &) = default;

  ~GridPosition() = default;

  GridPosition &operator=(const GridPosition &) = default;

  // -- Accessors --

  [[nodiscard]] double GetX() const { return x; }
  [[nodiscard]] double GetY() const { return y; }
  [[nodiscard]] size_t CellX() const { return static_cast<size_t>(x); }
  [[nodiscard]] size_t CellY() const { return static_cast<size_t>(y); }

  auto operator<=>(const GridPosition &) const = default;

  [[nodiscard]] bool IsInvalid() const { return std::isnan(x) || std::isnan(y); }
  [[nodiscard]] bool IsValid() const { return !IsInvalid(); }

  // -- Modifiers --

  GridPosition &Set(double in_x, double in_y) {
    x = in_x;
    y = in_y;
    return *this;
  }
  GridPosition &SetX(double in) { x = in; return *this; }
  GridPosition &SetY(double in) { y = in; return *this; }
  
  GridPosition &Shift(double shift_x, double shift_y) {
    x += shift_x;
    y += shift_y;
    return *this;
  }

  GridPosition &operator+=(const GridPosition &in) { return Shift(in.x, in.y); }
  GridPosition &operator-=(const GridPosition &in) { return Shift(-in.x, -in.y); }

  GridPosition &MakeInvalid() {
    x = y = std::nan("NAN(0)");
    return *this;
  }

  // A static function to request an invalid grid position.
  static const GridPosition & Invalid() {
    static GridPosition invalid_pos(std::nan("NAN(0)"), std::nan("NAN(0)"));
    return invalid_pos;
  }

  // -- Const Operations --

  [[nodiscard]] GridPosition GetOffset(double offset_x, double offset_y) const {
    return GridPosition{x + offset_x, y + offset_y};
  }

  [[nodiscard]] GridPosition Above(double dist = 1.0) const { return GetOffset(0.0, -dist); }

  [[nodiscard]] GridPosition Below(double dist = 1.0) const { return GetOffset(0.0, dist); }

  [[nodiscard]] GridPosition ToLeft(double dist = 1.0) const { return GetOffset(-dist, 0.0); }

  [[nodiscard]] GridPosition ToRight(double dist = 1.0) const { return GetOffset(dist, 0.0); }

  [[nodiscard]] GridPosition operator+(GridPosition in) const { return GetOffset(in.x, in.y); }

  [[nodiscard]] double Distance(GridPosition pos2) const {
    const double dist1 = x - pos2.x;
    const double dist2 = y - pos2.y;
    return sqrt(dist1 * dist1 + dist2 * dist2);
  }

  [[nodiscard]] double MDistance(GridPosition pos2) const {
    const double dist1 = x - pos2.x;
    const double dist2 = y - pos2.y;
    return abs(dist1) + abs(dist2);
  }

  [[nodiscard]] bool IsNear(GridPosition pos2, double max_dist = 1.0) const {
    const double dist1 = x - pos2.x;
    const double dist2 = y - pos2.y;
    return (dist1 * dist1 + dist2 * dist2) <= (max_dist * max_dist);
  }

  [[nodiscard]] std::string ToString() const {
    std::stringstream ss;
    ss << '(' << x << ',' << y << ')';
    return ss.str();
  }

  GridPosition & FromStream(std::istream & ss) {
    // Format should be "(x,y)" with values filled in.
    // Any deviation from this format produces an undefined position.
    char c = '\0';    
    ss >> c;
    if (c != '(') return MakeInvalid();
    ss >> x;
    ss >> c;
    if (c != ',') return MakeInvalid();
    ss >> y;
    ss >> c;
    if (c != ')') return MakeInvalid();

    return *this;
  }

  GridPosition & FromString(std::string in_str) {
    // Format should be "(x,y)" with values filled in.
    // Any deviation from this format produces an undefined position.
    std::stringstream ss(in_str);
    return FromStream(ss); 
  }


  // --- CoreObject Functionality ---
  std::string GetTypeName_impl() const override { return "cse491::GridPosition"; }

  void Serialize_impl(std::ostream & os) const override {
    SerializeValue(os, x);
    SerializeValue(os, y);
  };

  void Deserialize_impl(std::istream & is) override {
    DeserializeValue(is, x);
    DeserializeValue(is, y);
  };

};

}  // End of namespace cse491

```

