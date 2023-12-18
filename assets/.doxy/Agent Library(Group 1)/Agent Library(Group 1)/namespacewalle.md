

# Namespace walle



[**Namespace List**](namespaces.md) **>** [**walle**](namespacewalle.md)




















## Classes

| Type | Name |
| ---: | :--- |
| class | [**AStarAgent**](classwalle_1_1_a_star_agent.md) <br> |
| struct | [**AStarAgentData**](structwalle_1_1_a_star_agent_data.md) <br> |
| class | [**AgentFactory**](classwalle_1_1_agent_factory.md) <br> |
| class | [**Alerter**](classwalle_1_1_alerter.md) <br> |
| struct | [**BaseAgentData**](structwalle_1_1_base_agent_data.md) <br> |
| struct | [**CompareNodes**](structwalle_1_1_compare_nodes.md) <br>_Custom comparison function for priority queue._  |
| struct | [**Node**](structwalle_1_1_node.md) <br>[_**Node**_](structwalle_1_1_node.md) _class to hold information about positions for A\* search._ |
| struct | [**PacingAgentData**](structwalle_1_1_pacing_agent_data.md) <br> |
| class | [**PathAgent**](classwalle_1_1_path_agent.md) <br> |
| struct | [**PathAgentData**](structwalle_1_1_path_agent_data.md) <br> |
| class | [**RandomAgent**](classwalle_1_1_random_agent.md) <br> |
| class | [**TrackingAgent**](classwalle_1_1_tracking_agent.md) <br> |
| struct | [**TrackingAgentData**](structwalle_1_1_tracking_agent_data.md) <br> |


## Public Types

| Type | Name |
| ---: | :--- |
| enum  | [**TrackingState**](#enum-trackingstate)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  T & | [**DownCastAgent**](#function-downcastagent) (cse491::Entity & entity) <br>_Helper function for simplifying downcasting entities that have been added to the world._  |
|  std::vector&lt; cse491::GridPosition &gt; | [**GetShortestPath**](#function-getshortestpath) (const cse491::GridPosition & start, const cse491::GridPosition & end, const cse491::WorldBase & world, const cse491::AgentBase & agent) <br>_Uses A\* to return a list of grid positions._  |
|  std::vector&lt; cse491::GridPosition &gt; | [**StrToOffsets**](#function-strtooffsets) (std::string\_view commands) <br> |




























## Public Types Documentation




### enum TrackingState 


```C++
enum walle::TrackingState {
    RETURNING_TO_START,
    TRACKING,
    PATROLLING
};
```



Used to keep track of what action we are currently taking 


        
## Public Functions Documentation




### function DownCastAgent 

```C++
template<typename T typename T>
T & walle::DownCastAgent (
    cse491::Entity & entity
) 
```






### function GetShortestPath 

_Uses A\* to return a list of grid positions._ 
```C++
inline std::vector< cse491::GridPosition > walle::GetShortestPath (
    const cse491::GridPosition & start,
    const cse491::GridPosition & end,
    const cse491::WorldBase & world,
    const cse491::AgentBase & agent
) 
```





**Author:**

@mdkdoc15 




**Parameters:**


* `start` Starting position for search 
* `end` Ending position for the search 



**Returns:**

vector of A\* path from start to end, empty vector if no path exists 





        



### function StrToOffsets 


```C++
inline std::vector< cse491::GridPosition > walle::StrToOffsets (
    std::string_view commands
) 
```



Converts a string to a sequence of offsets


This convenience method takes a string with a special formatting that allows one to specify a sequence of whitespace-separated inputs in linear directions. The format is [steps[\*]]&lt;direction&gt; where `steps` is a positive integer and optional (assumed to be 1 by default) star `*` represents scaling the movement by `steps`. Optional, but cannot be used if `steps` is not provided if the star is not present, then `steps` individual offsets are created in the direction `direction` `direction` is a cardinal direction with the following logical mapping: n: north s: south e: east w: west x: stay put Example: "n w 3e 10\*s 5\*w x" should create the sequence of offsets {0, -1}, {-1, 0}, {1, 0}, {1, 0}, {1, 0}, {0, 10}, {-5, 0}, {0, 0} 

**Parameters:**


* `commands` string in a format of sequential directions 



**Note:**

throws an `std::invalid_argument` when input string is poorly formatted 




**Note:**

this includes when a negative integer is passed as `steps`. If a zero is used, treated as the default (one) 





        

------------------------------
The documentation for this class was generated from the following file `source/Agents/AgentFactory.hpp`

