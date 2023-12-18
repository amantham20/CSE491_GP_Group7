

# Class walle::AgentFactory



[**ClassList**](annotated.md) **>** [**walle**](namespacewalle.md) **>** [**AgentFactory**](classwalle_1_1_agent_factory.md)










































## Public Functions

| Type | Name |
| ---: | :--- |
|  [**AStarAgent**](classwalle_1_1_a_star_agent.md) & | [**AddAStarAgent**](#function-addastaragent) (const [**AStarAgentData**](structwalle_1_1_a_star_agent_data.md) & agent\_data) <br> |
|  [**cse491::PacingAgent**](classcse491_1_1_pacing_agent.md) & | [**AddPacingAgent**](#function-addpacingagent) (const [**PacingAgentData**](structwalle_1_1_pacing_agent_data.md) & agent\_data) <br> |
|  [**PathAgent**](classwalle_1_1_path_agent.md) & | [**AddPathAgent**](#function-addpathagent) (const [**PathAgentData**](structwalle_1_1_path_agent_data.md) & agent\_data) <br> |
|  [**TrackingAgent**](classwalle_1_1_tracking_agent.md) & | [**AddTrackingAgent**](#function-addtrackingagent) (const [**TrackingAgentData**](structwalle_1_1_tracking_agent_data.md) & agent\_data) <br> |
|   | [**AgentFactory**](#function-agentfactory-12) () = delete<br>_The world to create Agents in._  |
|   | [**AgentFactory**](#function-agentfactory-22) (cse491::WorldBase & world) <br> |




























## Public Functions Documentation




### function AddAStarAgent 


```C++
AStarAgent & walle::AgentFactory::AddAStarAgent (
    const AStarAgentData & agent_data
) 
```



Add an [**AStarAgent**](classwalle_1_1_a_star_agent.md) to the world 

**Parameters:**


* `agent_data` data for agent we want to create 



**Returns:**

self 





        



### function AddPacingAgent 


```C++
cse491::PacingAgent & walle::AgentFactory::AddPacingAgent (
    const PacingAgentData & agent_data
) 
```



Add a PacingAgent to the world 

**Parameters:**


* `agent_data` data for agent we want to create 



**Returns:**

self 





        



### function AddPathAgent 


```C++
PathAgent & walle::AgentFactory::AddPathAgent (
    const PathAgentData & agent_data
) 
```



Add a [**PathAgent**](classwalle_1_1_path_agent.md) to the world 

**Parameters:**


* `agent_data` data for agent we want to create 



**Returns:**

self 





        



### function AddTrackingAgent 


```C++
TrackingAgent & walle::AgentFactory::AddTrackingAgent (
    const TrackingAgentData & agent_data
) 
```



Add a [**TrackingAgent**](classwalle_1_1_tracking_agent.md) to the world 

**Parameters:**


* `agent_data` data for agent we want to create 



**Returns:**

self 





        



### function AgentFactory [1/2]

```C++
walle::AgentFactory::AgentFactory () = delete
```






### function AgentFactory [2/2]


```C++
inline explicit walle::AgentFactory::AgentFactory (
    cse491::WorldBase & world
) 
```



Constructor for [**AgentFactory**](classwalle_1_1_agent_factory.md) 

**Parameters:**


* `world` we are adding agents too 




        

------------------------------
The documentation for this class was generated from the following file `source/Agents/AgentFactory.hpp`

