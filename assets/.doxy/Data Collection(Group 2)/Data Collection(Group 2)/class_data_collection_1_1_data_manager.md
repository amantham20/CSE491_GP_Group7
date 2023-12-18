

# Class DataCollection::DataManager



[**ClassList**](annotated.md) **>** [**DataCollection**](namespace_data_collection.md) **>** [**DataManager**](class_data_collection_1_1_data_manager.md)



_Represents a data control system to hold all related receivers and collectors._ [More...](#detailed-description)

* `#include <DataManager.hpp>`





































## Public Functions

| Type | Name |
| ---: | :--- |
|  [**AgentInteractionCollector**](class_data_collection_1_1_agent_interaction_collector.md) & | [**GetAgentInteractionCollector**](#function-getagentinteractioncollector) () <br> |
|  [**AgentReceiver**](class_data_collection_1_1_agent_receiver.md) & | [**GetAgentReceiver**](#function-getagentreceiver) () <br> |
|  const [**DamageCollector**](class_data_collection_1_1_damage_collector.md) & | [**GetDamageCollector**](#function-getdamagecollector) () <br> |
|  const [**GameReceiver**](class_data_collection_1_1_game_receiver.md) & | [**GetGameReceiver**](#function-getgamereceiver) () <br> |
|  [**ItemUseCollector**](class_data_collection_1_1_item_use_collector.md) & | [**GetItemUseCollector**](#function-getitemusecollector) () <br> |
|  void | [**WriteToJson**](#function-writetojson) () <br> |
|   | [**~DataManager**](#function-datamanager) () = default<br> |


## Public Static Functions

| Type | Name |
| ---: | :--- |
|  [**DataManager**](class_data_collection_1_1_data_manager.md) & | [**GetInstance**](#function-getinstance) () <br> |


























# Detailed Description


World should report back relevant data here and it will be stored appropriately. Also manages graphing utilities. 


    
## Public Functions Documentation




### function GetAgentInteractionCollector 


```C++
inline AgentInteractionCollector & DataCollection::DataManager::GetAgentInteractionCollector () 
```



Get a handle to the agent interaction collector 

**Returns:**

Reference to the agent interaction collector 





        



### function GetAgentReceiver 


```C++
inline AgentReceiver & DataCollection::DataManager::GetAgentReceiver () 
```



Get a handle to the agent receiver 

**Returns:**

Reference to the agent receiver 





        



### function GetDamageCollector 


```C++
inline const DamageCollector & DataCollection::DataManager::GetDamageCollector () 
```



Get a handle to the damage collector 

**Returns:**

Const reference to the damage collector 





        



### function GetGameReceiver 


```C++
inline const GameReceiver & DataCollection::DataManager::GetGameReceiver () 
```



Get a handle to the game receiver 

**Returns:**

Const reference to the game receiver 





        



### function GetItemUseCollector 


```C++
inline ItemUseCollector & DataCollection::DataManager::GetItemUseCollector () 
```



Get a handle to the item use collector 

**Returns:**

Reference to the item use collector 





        



### function WriteToJson 

```C++
inline void DataCollection::DataManager::WriteToJson () 
```






### function ~DataManager 


```C++
DataCollection::DataManager::~DataManager () = default
```



Destructor 


        
## Public Static Functions Documentation




### function GetInstance 

```C++
static inline DataManager & DataCollection::DataManager::GetInstance () 
```




------------------------------
The documentation for this class was generated from the following file `source/DataCollection/DataManager.hpp`

