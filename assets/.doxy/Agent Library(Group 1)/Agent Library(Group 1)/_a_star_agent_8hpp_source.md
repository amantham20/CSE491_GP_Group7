

# File AStarAgent.hpp

[**File List**](files.md) **>** [**Agents**](dir_425e53e3c77c59c8573ea1fd0ff9622a.md) **>** [**AStarAgent.hpp**](_a_star_agent_8hpp.md)

[Go to the documentation of this file](_a_star_agent_8hpp.md)

```C++


#pragma once

#include "../core/AgentBase.hpp"
#include "AgentLibary.hpp"
#include <vector>

namespace walle {
  
    class AStarAgent : public cse491::AgentBase {
    private:
        std::vector<cse491::GridPosition> path; 
        cse491::GridPosition goal_position;     
        int recalculate_after_x_turns = 100; 
        int current_move_num = 0;            

    public:
        AStarAgent(size_t id, const std::string &name) : AgentBase(id, name) {}

        ~AStarAgent() = default;

        bool Initialize() override {
            return HasAction("up") && HasAction("down") && HasAction("left") &&
                HasAction("right");
        }

        void SetGoalPosition(const double x, const double y) {
            goal_position = cse491::GridPosition(x, y);
        }

        void SetGoalPosition(const cse491::GridPosition gp) {
            goal_position = gp;
        }

        cse491::GridPosition GetGoalPosition() const {return goal_position; }

        int GetRecalculateValue() const {return recalculate_after_x_turns; }

        int GetPathLength() const {return path.size(); }


        void SetRecalculate(const int recalculate) {
            recalculate_after_x_turns = recalculate;
        }

        void RecalculatePath() {
            path = GetShortestPath(GetPosition(), goal_position, GetWorld(), *this);
            if (!path.empty()){path.pop_back();} // Remove the val that we are currently at
            current_move_num = 0;
        }

        [[nodiscard]] cse491::GridPosition GetNextPosition() override {
            return !path.empty() ? path.back() : GetPosition();
        }

        size_t SelectAction(const cse491::WorldGrid & /*grid*/,
                            const cse491::type_options_t & /* type_options*/,
                            const cse491::item_map_t & /* item_map*/,
                            const cse491::agent_map_t & /* agent_map*/) override {
            // We are taking an action so another turn has passed
            ++current_move_num;
            // If the last step failed, or we need a new path the then regenerate the
            // path
            if (action_result == 0 || path.empty() ||
                current_move_num > recalculate_after_x_turns) {
            RecalculatePath();
            }
            // Return whatever action gets us closer to our goal
            if (!path.empty()) {
            auto pos = path.back();
            path.pop_back();
            if (pos == position.Above())
                return action_map["up"];
            if (pos == position.Below())
                return action_map["down"];
            if (pos == position.ToLeft())
                return action_map["left"];
            if (pos == position.ToRight())
                return action_map["right"];
            }
            return 0; // If no path then do not do anything
        }
    };
}; // namespace walle

```

