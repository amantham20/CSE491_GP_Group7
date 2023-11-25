

# File Data.hpp

[**File List**](files.md) **>** [**core**](dir_0d27ce74e9bd514c31e1d63efab6b388.md) **>** [**Data.hpp**](_data_8hpp.md)

[Go to the documentation of this file](_data_8hpp.md)

```C++


#pragma once

#include <memory>
#include <string>
#include <vector>

namespace cse491 {
  
  struct CellType {
    std::string name;  
    std::string desc;  
    char symbol;       
  };

  using type_options_t = std::vector<CellType>;

  class Entity;
  using item_set_t = std::vector<std::unique_ptr<Entity>>;

  class AgentBase;
  using agent_set_t = std::vector<std::unique_ptr<AgentBase>>;

}

```

