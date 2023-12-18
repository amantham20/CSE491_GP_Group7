

# File Data.hpp

[**File List**](files.md) **>** [**core**](dir_0d27ce74e9bd514c31e1d63efab6b388.md) **>** [**Data.hpp**](_data_8hpp.md)

[Go to the documentation of this file](_data_8hpp.md)

```C++


#pragma once

#include <map>
#include <memory>
#include <set>
#include <string>
#include <vector>

namespace cse491 {

struct CellType {
  std::string name;  
  std::string desc;  
  char symbol;       
  std::set<std::string> properties{};  

  CellType& SetProperty(const std::string& property) {
    properties.insert(property);
    return *this;
  }

  CellType& RemoveProperty(const std::string& property) {
    properties.erase(property);
    return *this;
  }

  bool HasProperty(const std::string& property) const { return properties.count(property); }

  constexpr static char CELL_WALL[] = "wall";
  constexpr static char CELL_WATER[] = "water";
};

using type_options_t = std::vector<CellType>;

class ItemBase;
using item_map_t = std::map<size_t, std::unique_ptr<ItemBase>>;

class AgentBase;
using agent_map_t = std::map<size_t, std::unique_ptr<AgentBase>>;

enum class PropertyType { t_double, t_int, t_char, t_string, t_position, t_bool, t_other };

enum class WorldType { w_maze, w_second, w_generative, w_manual };

}  // namespace cse491

```

