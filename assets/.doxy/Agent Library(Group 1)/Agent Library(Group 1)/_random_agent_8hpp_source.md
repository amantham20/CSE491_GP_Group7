

# File RandomAgent.hpp

[**File List**](files.md) **>** [**Agents**](dir_425e53e3c77c59c8573ea1fd0ff9622a.md) **>** [**RandomAgent.hpp**](_random_agent_8hpp.md)

[Go to the documentation of this file](_random_agent_8hpp.md)

```C++


#pragma once

#include <cassert>
#include "../core/AgentBase.hpp"
#include "../core/GridPosition.hpp"
#include "../core/WorldBase.hpp"

namespace walle {

    class RandomAgent : public cse491::AgentBase {

        private:

            double random_val = 4.0; 

            bool moving = true; 

        public:
            RandomAgent(size_t id, const std::string &name) : AgentBase(id, name) {
            }

            ~RandomAgent() = default;

            bool Initialize() override {
                return HasAction("up") && HasAction("down") && HasAction("left") && HasAction("right");
            }

            size_t SelectAction(const cse491::WorldGrid & /*grid*/,
                                const cse491::type_options_t & /* type_options*/,
                                const cse491::item_map_t & /* item_map*/,
                                const cse491::agent_map_t & /* agent_map*/) override {
                // We are taking an action so another turn has passed

                CalculateRandom(random_val);

                if(moving){
                    if(random_val < 1.0){
                        return action_map["up"];
                    }
                    else if(random_val < 2.0){
                        return action_map["down"];
                    }
                    else if(random_val < 3.0){
                        return action_map["left"];
                    }
                    else{
                        return action_map["right"];
                    }
                }

                return 0; // should not reach this point
            }

            void CalculateRandom(double multiplier){
                random_val = GetWorld().GetRandom(multiplier);
            }

            void SetDirection(double direction) { random_val = direction; }

            void SetMoving(bool move) { moving = move; }

            double GetRandom() const { return random_val; }

            bool GetMoving() const { return moving; }
    };
}

```

