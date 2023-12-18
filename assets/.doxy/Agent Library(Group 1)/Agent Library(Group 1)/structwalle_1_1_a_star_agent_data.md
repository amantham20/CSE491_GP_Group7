

# Struct walle::AStarAgentData



[**ClassList**](annotated.md) **>** [**walle**](namespacewalle.md) **>** [**AStarAgentData**](structwalle_1_1_a_star_agent_data.md)



[More...](#detailed-description)

* `#include <AgentFactory.hpp>`



Inherits the following classes: [walle::BaseAgentData](structwalle_1_1_base_agent_data.md)






















## Public Attributes

| Type | Name |
| ---: | :--- |
|  cse491::GridPosition | [**goal\_pos**](#variable-goal_pos)  <br>_The final position in the world that the_ [_**AStarAgent**_](classwalle_1_1_a_star_agent.md) _is travelling to._ |
|  int | [**recalculate\_after\_x\_turns**](#variable-recalculate_after_x_turns)   = = 5<br>_Number of steps after which the shortest path is recalculated._  |


## Public Attributes inherited from walle::BaseAgentData

See [walle::BaseAgentData](structwalle_1_1_base_agent_data.md)

| Type | Name |
| ---: | :--- |
|  std::string | [**name**](#variable-name)  <br>_Name of the agent._  |
|  cse491::GridPosition | [**position**](#variable-position)  <br>_Agent's position._  |
|  char | [**symbol**](#variable-symbol)   = = '\*'<br>_Agent's representation._  |






















































































# Detailed Description


Stores data for an [**AStarAgent**](classwalle_1_1_a_star_agent.md) 


    
## Public Attributes Documentation




### variable goal\_pos 

```C++
cse491::GridPosition goal_pos;
```






### variable recalculate\_after\_x\_turns 

```C++
int recalculate_after_x_turns;
```




------------------------------
The documentation for this class was generated from the following file `source/Agents/AgentFactory.hpp`

