

# File AgentInteractionCollector.hpp

[**File List**](files.md) **>** [**DataCollection**](dir_8adf75fe53ae17187785c216cf2633db.md) **>** [**AgentInteractionCollector.hpp**](_agent_interaction_collector_8hpp.md)

[Go to the documentation of this file](_agent_interaction_collector_8hpp.md)

```C++

#pragma once

#include <unordered_map>
#include <string>
#include "JsonBuilder.hpp"

namespace DataCollection {

    class AgentInteractionCollector {
    private:
        std::unordered_map<std::string, int> interactionData;  
    public:
        AgentInteractionCollector() = default;

        const std::unordered_map<std::string, int>& GetInteractionData() { return interactionData; }

        size_t GetUniqueInteractions() { return interactionData.size(); }

        void RecordInteraction(const std::string& agentName) { interactionData[agentName]++; }

        void WriteToInteractionFile(const std::string filename){
            JsonBuilder json_builder;
            std::ofstream jsonfilestream(filename);
            json_builder.StartArray("agentInteractions");
            for (auto& [agentName, interactionCount] : interactionData) {
                json_builder.AddName(agentName);
                json_builder.AddInt("interactionCount", interactionCount);
                json_builder.InputToArray("agentInteractions", json_builder.GetJSON());
                json_builder.ClearJSON();
            }
            json_builder.WriteToFile(jsonfilestream, json_builder.GetJSONArray());
            jsonfilestream.close();
        }

    };
}

```

