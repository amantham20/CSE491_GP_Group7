

# Class netWorth::ControlledAgent



[**ClassList**](annotated.md) **>** [**netWorth**](namespacenet_worth.md) **>** [**ControlledAgent**](classnet_worth_1_1_controlled_agent.md)








Inherits the following classes: AgentBase


































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**ControlledAgent**](#function-controlledagent) (size\_t id, const std::string & name) <br>_Client manager to access agent action map._  |
|  bool | [**Initialize**](#function-initialize) () override<br>_This agent needs a specific set of actions to function._  |
|  size\_t | [**SelectAction**](#function-selectaction) (const cse491::WorldGrid &, const cse491::type\_options\_t &, const cse491::item\_map\_t &, const cse491::agent\_map\_t &) override<br>_Choose the action to take a step in the appropriate direction._  |




























## Public Functions Documentation




### function ControlledAgent 

```C++
inline netWorth::ControlledAgent::ControlledAgent (
    size_t id,
    const std::string & name
) 
```






### function Initialize 

_This agent needs a specific set of actions to function._ 
```C++
inline bool netWorth::ControlledAgent::Initialize () override
```





**Returns:**

Success. 





        



### function SelectAction 

```C++
inline size_t netWorth::ControlledAgent::SelectAction (
    const cse491::WorldGrid &,
    const cse491::type_options_t &,
    const cse491::item_map_t &,
    const cse491::agent_map_t &
) override
```




------------------------------
The documentation for this class was generated from the following file `source/Interfaces/NetWorth/client/ControlledAgent.hpp`

