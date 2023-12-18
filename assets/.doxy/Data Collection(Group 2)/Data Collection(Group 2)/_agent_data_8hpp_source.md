

# File AgentData.hpp

[**File List**](files.md) **>** [**DataCollection**](dir_8adf75fe53ae17187785c216cf2633db.md) **>** [**AgentData.hpp**](_agent_data_8hpp.md)

[Go to the documentation of this file](_agent_data_8hpp.md)

```C++

#pragma once

#include <string>
#include <list>
#include <utility>
#include <vector>
#include <unordered_map>
#include "../core/GridPosition.hpp"

namespace DataCollection
{
    class AgentData {
    private:
        std::string name;  
        std::vector<int> actionIds;  
        std::vector<cse491::GridPosition> position;  
        std::vector<std::unordered_map<std::string,size_t>> actions;  

    public:
//        AgentData() = default;
        AgentData(std::string name) : name(std::move(name)) {}

        ~AgentData() = default;

        void StorePositions(cse491::GridPosition pos) {
            position.push_back(pos);
        }

        void StoreAction(std::unordered_map<std::string, size_t> action) {
            actions.push_back(action);
        }

        void StoreAgentId(int id) {
            actionIds.push_back(id);
        }

        auto& GetActions() {
            return actions;
        }

        int GetActionSize() const {
            return actions.size();
        }

        void SetActions(const std::vector<std::unordered_map<std::string, size_t>>& newActions) {
            actions = newActions;
        }

        int GetPositionSize() const {
            return position.size();
        }

        auto GetAgentIds() const {
            return actionIds;
        }

        std::string GetName() const {
            return name;
        }

        std::vector<cse491::GridPosition> GetPositions() const {
            return position;
        }
    };
} // namespace DataCollection

```

