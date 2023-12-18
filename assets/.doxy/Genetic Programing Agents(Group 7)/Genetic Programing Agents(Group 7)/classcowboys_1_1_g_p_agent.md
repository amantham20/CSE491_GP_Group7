

# Class cowboys::GPAgent



[**ClassList**](annotated.md) **>** [**cowboys**](namespacecowboys.md) **>** [**GPAgent**](classcowboys_1_1_g_p_agent.md)








Inherits the following classes: AgentBase


































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**GPAgent**](#function-gpagent) (size\_t id, const std::string & name) <br> |
|  bool | [**Initialize**](#function-initialize) () override<br>_This agent needs a specific set of actions to function._  |
|  size\_t | [**SelectAction**](#function-selectaction) (const cse491::WorldGrid & grid, const cse491::type\_options\_t & type\_options, const cse491::item\_map\_t & item\_map, const cse491::agent\_map\_t & agent\_map) override<br>_Choose the action to take a step in the appropriate direction._  |
|   | [**~GPAgent**](#function-gpagent) () override<br> |








## Protected Attributes

| Type | Name |
| ---: | :--- |
|  size\_t | [**movementIndex**](#variable-movementindex)   = = 0<br>_current move of the agent_  |
|  const std::vector&lt; std::string &gt; | [**predefinedMovement**](#variable-predefinedmovement)   = = {
      "down",  "down",  "down",  "down",  "right", "right", "up",    "up",
      "up",    "up",    "right", "right", "right", "right", "right", "right",
      "right", "right", "right", "right", "right", "left",  "left",  "left"}<br> |




















## Public Functions Documentation




### function GPAgent 

```C++
inline cowboys::GPAgent::GPAgent (
    size_t id,
    const std::string & name
) 
```






### function Initialize 

_This agent needs a specific set of actions to function._ 
```C++
inline bool cowboys::GPAgent::Initialize () override
```





**Returns:**

Success. 





        



### function SelectAction 

```C++
inline size_t cowboys::GPAgent::SelectAction (
    const cse491::WorldGrid & grid,
    const cse491::type_options_t & type_options,
    const cse491::item_map_t & item_map,
    const cse491::agent_map_t & agent_map
) override
```






### function ~GPAgent 

```C++
cowboys::GPAgent::~GPAgent () override
```



## Protected Attributes Documentation




### variable movementIndex 

```C++
size_t movementIndex;
```






### variable predefinedMovement 

```C++
const std::vector<std::string> predefinedMovement;
```




------------------------------
The documentation for this class was generated from the following file `source/Agents/GP/GPAgent.hpp`

