

# File AgentBase.hpp

[**File List**](files.md) **>** [**core**](dir_0d27ce74e9bd514c31e1d63efab6b388.md) **>** [**AgentBase.hpp**](_agent_base_8hpp.md)

[Go to the documentation of this file](_agent_base_8hpp.md)

```C++


#pragma once

#include <cassert>
#include <string>
#include <unordered_map>

#include "Data.hpp"
#include "Entity.hpp"
#include "GridPosition.hpp"
#include "WorldGrid.hpp"

namespace cse491 {

  class AgentBase : public Entity {
  protected:
    std::unordered_map<std::string, size_t> action_map;

    int action_result=1;  

  public:
    AgentBase(size_t id, const std::string & name) : Entity(id, name) { }
    ~AgentBase() = default; // Already virtual from Entity

    // -- World Interactions --

    virtual bool Initialize() { return true; }

    // -- Entity Overrides --

    bool IsAgent() const override { return true; }


    // -- Action management --

    [[nodiscard]] bool HasAction(const std::string & action_name) const {
      return action_map.count(action_name);
    }

    [[nodiscard]] size_t GetActionID(const std::string & action_name) const {
      auto it = action_map.find(action_name);
      if (it == action_map.end()) return 0;
      return it->second;
    }

    virtual AgentBase & AddAction(const std::string & action_name, size_t action_id) {
      assert(!HasAction(action_name)); // Cannot add existing action name.
      action_map[action_name] = action_id;
      return *this;
    }

    [[nodiscard]] virtual size_t SelectAction(
        [[maybe_unused]] const WorldGrid & grid,
        [[maybe_unused]] const type_options_t & type_options,
        [[maybe_unused]] const item_set_t & item_set,
        [[maybe_unused]] const agent_set_t & agent_set
      )
    { return 0; }

    [[nodiscard]] int GetActionResult() const { return action_result; }

    void SetActionResult(int result) { action_result = result; }

  };

} // End of namespace cse491

```

