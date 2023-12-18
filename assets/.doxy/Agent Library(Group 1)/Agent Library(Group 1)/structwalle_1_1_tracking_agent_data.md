

# Struct walle::TrackingAgentData



[**ClassList**](annotated.md) **>** [**walle**](namespacewalle.md) **>** [**TrackingAgentData**](structwalle_1_1_tracking_agent_data.md)



[More...](#detailed-description)

* `#include <AgentFactory.hpp>`



Inherits the following classes: [walle::BaseAgentData](structwalle_1_1_base_agent_data.md)






















## Public Attributes

| Type | Name |
| ---: | :--- |
|  std::shared\_ptr&lt; [**Alerter**](classwalle_1_1_alerter.md) &gt; | [**alerter**](#variable-alerter)   = = nullptr<br> |
|  cse491::GridPosition | [**start\_pos**](#variable-start_pos)  <br>_Where the_ [_**TrackingAgent**_](classwalle_1_1_tracking_agent.md) _begins from patrolling from and returns two after the target moves out of range._ |
|  std::string | [**string\_path**](#variable-string_path)  <br>_String representation of the path traveled (e.g. "n s e w" for north south east west) like in_ [_**PathAgent**_](classwalle_1_1_path_agent.md) _._ |
|  cse491::Entity \* | [**target**](#variable-target)  <br>_Goal Entity being tracked (must not be null or else the agent simply behaves like a_ [_**PathAgent**_](classwalle_1_1_path_agent.md) _)_ |
|  int | [**tracking\_distance**](#variable-tracking_distance)   = = 5<br>_Distance that the_ [_**TrackingAgent**_](classwalle_1_1_tracking_agent.md) _can "see" such that when the target enters that range, it begins tracking._ |
|  std::vector&lt; cse491::GridPosition &gt; | [**vector\_path**](#variable-vector_path)  <br>_Set of grid positions that are applied to the agent's position during one step (constructed from string\_path) like in_ [_**PathAgent**_](classwalle_1_1_path_agent.md) _._ |


## Public Attributes inherited from walle::BaseAgentData

See [walle::BaseAgentData](structwalle_1_1_base_agent_data.md)

| Type | Name |
| ---: | :--- |
|  std::string | [**name**](#variable-name)  <br>_Name of the agent._  |
|  cse491::GridPosition | [**position**](#variable-position)  <br>_Agent's position._  |
|  char | [**symbol**](#variable-symbol)   = = '\*'<br>_Agent's representation._  |






























## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**TrackingAgentData**](#function-trackingagentdata-12) () = default<br>_Use initial values._  |
|   | [**TrackingAgentData**](#function-trackingagentdata-22) (std::string name, cse491::GridPosition curr\_pos, char symbol, std::string path, cse491::Entity \* target, int tracking\_dist, cse491::GridPosition start\_pos, std::shared\_ptr&lt; [**Alerter**](classwalle_1_1_alerter.md) &gt; alerter) <br>_Set all values._  |
























































# Detailed Description


Stores data for a [**TrackingAgent**](classwalle_1_1_tracking_agent.md) 


    
## Public Attributes Documentation




### variable alerter 


```C++
std::shared_ptr<Alerter> alerter;
```



Shared reference to an [**Alerter**](classwalle_1_1_alerter.md), which is non-null if the agent should be able to tell other agents to immediately focus on their targets 

**Remark:**

You should be using the **same** shared pointer across multiple instances of [**TrackingAgentData**](structwalle_1_1_tracking_agent_data.md) in order to make the TrackingAgents part of the same network. This means you need to copy around this shared pointer when using the factory 





        



### variable start\_pos 

```C++
cse491::GridPosition start_pos;
```






### variable string\_path 

```C++
std::string string_path;
```






### variable target 

```C++
cse491::Entity* target;
```






### variable tracking\_distance 

```C++
int tracking_distance;
```






### variable vector\_path 

```C++
std::vector<cse491::GridPosition> vector_path;
```



## Public Functions Documentation




### function TrackingAgentData [1/2]

```C++
walle::TrackingAgentData::TrackingAgentData () = default
```






### function TrackingAgentData [2/2]

```C++
inline walle::TrackingAgentData::TrackingAgentData (
    std::string name,
    cse491::GridPosition curr_pos,
    char symbol,
    std::string path,
    cse491::Entity * target,
    int tracking_dist,
    cse491::GridPosition start_pos,
    std::shared_ptr< Alerter > alerter
) 
```




------------------------------
The documentation for this class was generated from the following file `source/Agents/AgentFactory.hpp`

