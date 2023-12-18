

# Class DataCollection::AgentData



[**ClassList**](annotated.md) **>** [**DataCollection**](namespace_data_collection.md) **>** [**AgentData**](class_data_collection_1_1_agent_data.md)



_Represents data collected for an agent, including their name, actions, positions, and associated IDs._ 

* `#include <AgentData.hpp>`





































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**AgentData**](#function-agentdata) (std::string name) <br>_Default constructor for_ [_**AgentData**_](class_data_collection_1_1_agent_data.md) _class._ |
|  int | [**GetActionSize**](#function-getactionsize) () const<br> |
|  auto & | [**GetActions**](#function-getactions) () <br>_Retrieves the stored actions._  |
|  auto | [**GetAgentIds**](#function-getagentids) () const<br>_Gets the agent IDs associated with the stored actions._  |
|  std::string | [**GetName**](#function-getname) () const<br> |
|  int | [**GetPositionSize**](#function-getpositionsize) () const<br>_Gets the size of the stored grid positions._  |
|  std::vector&lt; cse491::GridPosition &gt; | [**GetPositions**](#function-getpositions) () const<br> |
|  void | [**SetActions**](#function-setactions) (const std::vector&lt; std::unordered\_map&lt; std::string, size\_t &gt; &gt; & newActions) <br>_Sets the stored actions to a new set of actions._  |
|  void | [**StoreAction**](#function-storeaction) (std::unordered\_map&lt; std::string, size\_t &gt; action) <br>_Stores an action for the agent._  |
|  void | [**StoreAgentId**](#function-storeagentid) (int id) <br>_Stores an agent ID associated with an action._  |
|  void | [**StorePositions**](#function-storepositions) (cse491::GridPosition pos) <br>_Stores a grid position for the agent._  |
|   | [**~AgentData**](#function-agentdata) () = default<br>_Destructor for_ [_**AgentData**_](class_data_collection_1_1_agent_data.md) _class._ |




























## Public Functions Documentation




### function AgentData 

```C++
inline DataCollection::AgentData::AgentData (
    std::string name
) 
```






### function GetActionSize 

```C++
inline int DataCollection::AgentData::GetActionSize () const
```






### function GetActions 

_Retrieves the stored actions._ 
```C++
inline auto & DataCollection::AgentData::GetActions () 
```





**Returns:**

Reference to the vector of action maps. 





        



### function GetAgentIds 

_Gets the agent IDs associated with the stored actions._ 
```C++
inline auto DataCollection::AgentData::GetAgentIds () const
```





**Returns:**

The vector of agent IDs. 





        



### function GetName 

```C++
inline std::string DataCollection::AgentData::GetName () const
```






### function GetPositionSize 

_Gets the size of the stored grid positions._ 
```C++
inline int DataCollection::AgentData::GetPositionSize () const
```





**Returns:**

The number of stored grid positions. 





        



### function GetPositions 

```C++
inline std::vector< cse491::GridPosition > DataCollection::AgentData::GetPositions () const
```






### function SetActions 

_Sets the stored actions to a new set of actions._ 
```C++
inline void DataCollection::AgentData::SetActions (
    const std::vector< std::unordered_map< std::string, size_t > > & newActions
) 
```





**Parameters:**


* `newActions` The new set of actions to be stored. 




        



### function StoreAction 

_Stores an action for the agent._ 
```C++
inline void DataCollection::AgentData::StoreAction (
    std::unordered_map< std::string, size_t > action
) 
```





**Parameters:**


* `action` The action to be stored. 




        



### function StoreAgentId 

_Stores an agent ID associated with an action._ 
```C++
inline void DataCollection::AgentData::StoreAgentId (
    int id
) 
```





**Parameters:**


* `id` The agent ID to be stored. 




        



### function StorePositions 

_Stores a grid position for the agent._ 
```C++
inline void DataCollection::AgentData::StorePositions (
    cse491::GridPosition pos
) 
```





**Parameters:**


* `pos` The grid position to be stored. 




        



### function ~AgentData 

```C++
DataCollection::AgentData::~AgentData () = default
```




------------------------------
The documentation for this class was generated from the following file `source/DataCollection/AgentData.hpp`

