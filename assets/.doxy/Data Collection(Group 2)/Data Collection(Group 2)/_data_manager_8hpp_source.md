

# File DataManager.hpp

[**File List**](files.md) **>** [**DataCollection**](dir_8adf75fe53ae17187785c216cf2633db.md) **>** [**DataManager.hpp**](_data_manager_8hpp.md)

[Go to the documentation of this file](_data_manager_8hpp.md)

```C++

#pragma once

#include "AgentReciever.hpp"
#include "GameReceiver.hpp"
#include "DamageCollector.hpp"
#include "ItemUseCollector.hpp"
#include "AgentInteractionCollector.hpp"

namespace DataCollection {

    class DataManager {
    private:
        AgentReceiver agentReceiver;                            
        GameReceiver gameReceiver;                              
        DamageCollector damageCollector;                        
        ItemUseCollector itemUseCollector;                      
        AgentInteractionCollector agentInteractionCollector;    
        DataManager() {}

        DataManager(const DataManager&) = delete;
        DataManager& operator=(const DataManager&) = delete;
    public:
         ~DataManager() = default;

         static DataManager& GetInstance() {
             static DataManager instance;
             return instance;
         }

         AgentReceiver& GetAgentReceiver() {
             return agentReceiver;
         }

        AgentInteractionCollector& GetAgentInteractionCollector() {
            return agentInteractionCollector;
        }

         ItemUseCollector& GetItemUseCollector() {
             return itemUseCollector;
         }

        const GameReceiver& GetGameReceiver() {
            return gameReceiver;
        }

        const DamageCollector& GetDamageCollector() {
            return damageCollector;
        }

        void WriteToJson() {
            std::filesystem::path currentPath = std::filesystem::current_path().parent_path().parent_path();
            currentPath = currentPath / "source" / "DataCollection" / "GRAPH";
            // Construct the full path to the data directory and the damage_data.json file
            std::filesystem::path DamagefilePath = currentPath  / "damage_data.json";
            std::filesystem::path ItemUsefilePath = currentPath  / "itemUsage.json";
            std::filesystem::path ItemdamagefilePath = currentPath  / "itemDamage.json";
            std::filesystem::path PositionfilePath = currentPath  / "gridPositions.json";
            std::filesystem::path InteractionfilePath = currentPath  / "agentInteractions.json";
            agentReceiver.WriteToPositionFile(PositionfilePath.string());
            itemUseCollector.WriteToItemUseFile(ItemUsefilePath.string());
            agentInteractionCollector.WriteToInteractionFile(InteractionfilePath.string());
        }
    };
}

```

