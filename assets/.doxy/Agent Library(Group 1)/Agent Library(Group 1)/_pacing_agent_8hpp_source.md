

# File PacingAgent.hpp

[**File List**](files.md) **>** [**Agents**](dir_425e53e3c77c59c8573ea1fd0ff9622a.md) **>** [**PacingAgent.hpp**](_pacing_agent_8hpp.md)

[Go to the documentation of this file](_pacing_agent_8hpp.md)

```C++


#pragma once

#include <cassert>

#include "../core/AgentBase.hpp"

namespace cse491 {

class PacingAgent : public AgentBase {
 protected:
    bool vertical = true; 
    bool reverse = false;  

 public:
    PacingAgent(size_t id, const std::string &name) : AgentBase(id, name) {}
    ~PacingAgent() = default;

    bool Initialize() override {
        return HasAction("up") && HasAction("down") && HasAction("left") && HasAction("right");
    }

    size_t SelectAction(const WorldGrid & /* grid*/,
                        const type_options_t & /* type_options*/,
                        const item_map_t & /* item_map*/,
                        const agent_map_t & /* agent_map*/) override {
        // If the last step failed, try going in the other direction.
        if (action_result == 0) {
            reverse = !reverse;
        }
        // Take as tep in the direction we are trying to go in.
        if (vertical) {
            if (reverse) return action_map["up"];
            else return action_map["down"];
        } else {
            if (reverse) return action_map["left"];
            else return action_map["right"];
        }
        return 0;  // Should never actually get here...
    }

    PacingAgent &SetVertical(bool vert) {
        vertical = vert;
        return *this;
    }

    bool GetVertical() const { return vertical; }

};

} // End of namespace cse491

```

