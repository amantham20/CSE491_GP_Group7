

# Struct walle::PathAgentData



[**ClassList**](annotated.md) **>** [**walle**](namespacewalle.md) **>** [**PathAgentData**](structwalle_1_1_path_agent_data.md)



[More...](#detailed-description)

* `#include <AgentFactory.hpp>`



Inherits the following classes: [walle::BaseAgentData](structwalle_1_1_base_agent_data.md)






















## Public Attributes

| Type | Name |
| ---: | :--- |
|  int | [**index**](#variable-index)  <br>_Starting index into the vector of GridPositions._  |
|  std::string | [**string\_path**](#variable-string_path)  <br>_String representation of the path traveled (e.g. "n s e w" for north south east west)_  |
|  std::vector&lt; cse491::GridPosition &gt; | [**vector\_path**](#variable-vector_path)  <br>_Set of grid positions that are applied to the agent's position during one step (constructed from string\_path)_  |


## Public Attributes inherited from walle::BaseAgentData

See [walle::BaseAgentData](structwalle_1_1_base_agent_data.md)

| Type | Name |
| ---: | :--- |
|  std::string | [**name**](#variable-name)  <br>_Name of the agent._  |
|  cse491::GridPosition | [**position**](#variable-position)  <br>_Agent's position._  |
|  char | [**symbol**](#variable-symbol)   = = '\*'<br>_Agent's representation._  |






















































































# Detailed Description


Stores data for a [**PathAgent**](classwalle_1_1_path_agent.md) 


    
## Public Attributes Documentation




### variable index 

```C++
int index;
```






### variable string\_path 

```C++
std::string string_path;
```






### variable vector\_path 

```C++
std::vector<cse491::GridPosition> vector_path;
```




------------------------------
The documentation for this class was generated from the following file `source/Agents/AgentFactory.hpp`

