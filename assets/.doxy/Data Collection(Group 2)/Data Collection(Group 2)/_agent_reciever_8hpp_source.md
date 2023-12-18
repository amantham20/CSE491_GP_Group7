

# File AgentReciever.hpp

[**File List**](files.md) **>** [**DataCollection**](dir_8adf75fe53ae17187785c216cf2633db.md) **>** [**AgentReciever.hpp**](_agent_reciever_8hpp.md)

[Go to the documentation of this file](_agent_reciever_8hpp.md)

```C++

#pragma once

#include <filesystem>
#include "DataReceiver.hpp"
#include "AgentData.hpp"
#include "JsonBuilder.hpp"

namespace DataCollection {

    class AgentReceiver : public DataReceiver<AgentData> {
    private:
        std::unordered_map<std::string, std::shared_ptr<AgentData>> agent_map;

    public:
        void StoreData(std::string name, cse491::GridPosition pos, [[maybe_unused]] int last_action) {
            std::shared_ptr<AgentData> agent = GetAgent(name);
            agent->StorePositions(pos);
//            agent->StoreAction(last_action);
            StoreIntoStorage(*agent);
        }

//        void StoreIntoStorage(AgentData obj) override {
//            storage.push_back(obj);
//        }

        void AddAgent(const std::string& name) {
            AgentData agent(name);
            agent_map[name] = std::make_shared<AgentData>(agent);

        }

        std::shared_ptr<AgentData> GetAgent(const std::string& name)
        {
            if (agent_map.find(name)==agent_map.end()) {
                AddAgent(name);
                return agent_map[name];
            }
            else {
                return agent_map[name];
            }
        }

        AgentData GetAgentData(const std::string& name) {
            return *agent_map[name];
        }

        void WriteToPositionFile(std::string path) {
            std::ofstream jsonfilestream(path);
            JsonBuilder json_builder;
            json_builder.StartArray("AgentPositions");
            for (auto& agent : agent_map) {
                json_builder.Addagentname(agent.first);
                for (auto& pos: agent.second->GetPositions()) {
                    json_builder.AddPosition(pos);
                }
                json_builder.InputToArray("AgentPositions", json_builder.GetJSON());
                json_builder.ClearJSON();
            }
            json_builder.WriteToFile(jsonfilestream, json_builder.GetJSONArray());
            jsonfilestream.close();
        }
    };
} // namespace DataCollection

```

