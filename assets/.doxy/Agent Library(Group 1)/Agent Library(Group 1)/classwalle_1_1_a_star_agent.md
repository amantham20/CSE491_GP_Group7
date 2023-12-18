

# Class walle::AStarAgent



[**ClassList**](annotated.md) **>** [**walle**](namespacewalle.md) **>** [**AStarAgent**](classwalle_1_1_a_star_agent.md)



[More...](#detailed-description)

* `#include <AStarAgent.hpp>`



Inherits the following classes: AgentBase


































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**AStarAgent**](#function-astaragent) (size\_t id, const std::string & name) <br>_Constructor for creating a new_ [_**AStarAgent**_](classwalle_1_1_a_star_agent.md) _object._ |
|  cse491::GridPosition | [**GetGoalPosition**](#function-getgoalposition) () const<br>_gets the goal position and returns it_  |
|  cse491::GridPosition | [**GetNextPosition**](#function-getnextposition) () override<br>_Get the next position to move to._  |
|  int | [**GetPathLength**](#function-getpathlength) () const<br> |
|  int | [**GetRecalculateValue**](#function-getrecalculatevalue) () const<br> |
|  bool | [**Initialize**](#function-initialize) () override<br>_This agent needs a specific set of actions to function._  |
|  void | [**RecalculatePath**](#function-recalculatepath) () <br>_Update the path to go to goal position._  |
|  size\_t | [**SelectAction**](#function-selectaction) (const cse491::WorldGrid &, const cse491::type\_options\_t &, const cse491::item\_map\_t &, const cse491::agent\_map\_t &) override<br>_Choose the action to take a step in the appropriate direction._  |
|  void | [**SetGoalPosition**](#function-setgoalposition-12) (const double x, const double y) <br>_Set where the agent should head towards._  |
|  void | [**SetGoalPosition**](#function-setgoalposition-22) (const cse491::GridPosition gp) <br>_Set where the agent should head towards._  |
|  void | [**SetRecalculate**](#function-setrecalculate) (const int recalculate) <br>_Set how many moves should occur before recalculating path A lower number will react faster to updates in the world but will call A\* search more often._  |
|   | [**~AStarAgent**](#function-astaragent) () = default<br> |




























# Detailed Description


Class that describes a [**AStarAgent**](classwalle_1_1_a_star_agent.md) class 


    
## Public Functions Documentation




### function AStarAgent 

_Constructor for creating a new_ [_**AStarAgent**_](classwalle_1_1_a_star_agent.md) _object._
```C++
inline walle::AStarAgent::AStarAgent (
    size_t id,
    const std::string & name
) 
```





**Parameters:**


* `id` id of the agent 
* `name` name of the agent 




        



### function GetGoalPosition 

_gets the goal position and returns it_ 
```C++
inline cse491::GridPosition walle::AStarAgent::GetGoalPosition () const
```





**Returns:**

goal\_position member variable 





        



### function GetNextPosition 

_Get the next position to move to._ 
```C++
inline cse491::GridPosition walle::AStarAgent::GetNextPosition () override
```





**Returns:**

GridPosition to move to 





        



### function GetPathLength 


```C++
inline int walle::AStarAgent::GetPathLength () const
```



Gets the size of the current path 

**Returns:**

length of path 





        



### function GetRecalculateValue 


```C++
inline int walle::AStarAgent::GetRecalculateValue () const
```



Returns the recalculate value 

**Returns:**

recalculated value 





        



### function Initialize 

_This agent needs a specific set of actions to function._ 
```C++
inline bool walle::AStarAgent::Initialize () override
```





**Returns:**

Success. 





        



### function RecalculatePath 

```C++
inline void walle::AStarAgent::RecalculatePath () 
```






### function SelectAction 

```C++
inline size_t walle::AStarAgent::SelectAction (
    const cse491::WorldGrid &,
    const cse491::type_options_t &,
    const cse491::item_map_t &,
    const cse491::agent_map_t &
) override
```






### function SetGoalPosition [1/2]

_Set where the agent should head towards._ 
```C++
inline void walle::AStarAgent::SetGoalPosition (
    const double x,
    const double y
) 
```





**Parameters:**


* `x` x-coordinate of the goal position 
* `y` y-coordinate of the goal position 




        



### function SetGoalPosition [2/2]

_Set where the agent should head towards._ 
```C++
inline void walle::AStarAgent::SetGoalPosition (
    const cse491::GridPosition gp
) 
```





**Parameters:**


* `gp` position agent should go towards 




        



### function SetRecalculate 

_Set how many moves should occur before recalculating path A lower number will react faster to updates in the world but will call A\* search more often._ 
```C++
inline void walle::AStarAgent::SetRecalculate (
    const int recalculate
) 
```





**Parameters:**


* `recalculate` How often path should be recalculated 




        



### function ~AStarAgent 

```C++
walle::AStarAgent::~AStarAgent () = default
```




------------------------------
The documentation for this class was generated from the following file `source/Agents/AStarAgent.hpp`

