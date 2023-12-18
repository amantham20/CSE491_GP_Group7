

# Class walle::RandomAgent



[**ClassList**](annotated.md) **>** [**walle**](namespacewalle.md) **>** [**RandomAgent**](classwalle_1_1_random_agent.md)



[More...](#detailed-description)

* `#include <RandomAgent.hpp>`



Inherits the following classes: AgentBase


































## Public Functions

| Type | Name |
| ---: | :--- |
|  void | [**CalculateRandom**](#function-calculaterandom) (double multiplier) <br>_Function to calculate the random direction._  |
|  bool | [**GetMoving**](#function-getmoving) () const<br>_Get the Moving object._  |
|  double | [**GetRandom**](#function-getrandom) () const<br>_Get the Random object._  |
|  bool | [**Initialize**](#function-initialize) () override<br>_This agent needs a specific set of actions to function._  |
|   | [**RandomAgent**](#function-randomagent) (size\_t id, const std::string & name) <br>_Is the agent moving?_  |
|  size\_t | [**SelectAction**](#function-selectaction) (const cse491::WorldGrid &, const cse491::type\_options\_t &, const cse491::item\_map\_t &, const cse491::agent\_map\_t &) override<br>_Choose the action to take a step in the random direction._  |
|  void | [**SetDirection**](#function-setdirection) (double direction) <br>_Set the Direction object._  |
|  void | [**SetMoving**](#function-setmoving) (bool move) <br>_Set the Moving object._  |
|   | [**~RandomAgent**](#function-randomagent) () = default<br> |




























# Detailed Description


Class for the Random Agent 


    
## Public Functions Documentation




### function CalculateRandom 

_Function to calculate the random direction._ 
```C++
inline void walle::RandomAgent::CalculateRandom (
    double multiplier
) 
```





**Parameters:**


* `multiplier` double: random multiplier 




        



### function GetMoving 

_Get the Moving object._ 
```C++
inline bool walle::RandomAgent::GetMoving () const
```





**Returns:**

true 




**Returns:**

false 





        



### function GetRandom 

_Get the Random object._ 
```C++
inline double walle::RandomAgent::GetRandom () const
```





**Returns:**

double random member variable 





        



### function Initialize 

_This agent needs a specific set of actions to function._ 
```C++
inline bool walle::RandomAgent::Initialize () override
```





**Returns:**

Success. 





        



### function RandomAgent 

_Is the agent moving?_ 
```C++
inline walle::RandomAgent::RandomAgent (
    size_t id,
    const std::string & name
) 
```



Construct a new Random Agent object 

**Parameters:**


* `id` id of the agent 
* `name` name of the agent 




        



### function SelectAction 

```C++
inline size_t walle::RandomAgent::SelectAction (
    const cse491::WorldGrid &,
    const cse491::type_options_t &,
    const cse491::item_map_t &,
    const cse491::agent_map_t &
) override
```






### function SetDirection 

_Set the Direction object._ 
```C++
inline void walle::RandomAgent::SetDirection (
    double direction
) 
```





**Parameters:**


* `direction` direction to set 




        



### function SetMoving 

_Set the Moving object._ 
```C++
inline void walle::RandomAgent::SetMoving (
    bool move
) 
```





**Parameters:**


* `move` move to set 




        



### function ~RandomAgent 

```C++
walle::RandomAgent::~RandomAgent () = default
```




------------------------------
The documentation for this class was generated from the following file `source/Agents/RandomAgent.hpp`

