

# Class walle::PathAgent



[**ClassList**](annotated.md) **>** [**walle**](namespacewalle.md) **>** [**PathAgent**](classwalle_1_1_path_agent.md)



[More...](#detailed-description)

* `#include <PathAgent.hpp>`



Inherits the following classes: AgentBase


































## Public Functions

| Type | Name |
| ---: | :--- |
|  cse491::GridPosition | [**CalcNextPos**](#function-calcnextpos) () const<br> |
|  void | [**DecrementIndex**](#function-decrementindex) () <br> |
|  int | [**GetIndex**](#function-getindex) () const<br>_Get the index._  |
|  cse491::GridPosition | [**GetNextPosition**](#function-getnextposition) () override<br> |
|  std::vector&lt; cse491::GridPosition &gt; const & | [**GetPath**](#function-getpath) () const<br>_Get the Path._  |
|  void | [**IncrementIndex**](#function-incrementindex) () <br> |
|  bool | [**Initialize**](#function-initialize) () override<br> |
|   | [**PathAgent**](#function-pathagent-14) () = delete<br> |
|   | [**PathAgent**](#function-pathagent-24) (size\_t id, std::string const & name) <br> |
|   | [**PathAgent**](#function-pathagent-34) (size\_t id, std::string const & name, std::vector&lt; cse491::GridPosition &gt; offsets) <br> |
|   | [**PathAgent**](#function-pathagent-44) (size\_t id, std::string const & name, std::string\_view commands) <br> |
|  [**PathAgent**](classwalle_1_1_path_agent.md) & | [**ResetIndex**](#function-resetindex) () <br>_Reset the index to 0._  |
|  size\_t | [**SelectAction**](#function-selectaction) (cse491::WorldGrid const &, cse491::type\_options\_t const &, cse491::item\_map\_t const &, cse491::agent\_map\_t const &) override<br> |
|  [**PathAgent**](classwalle_1_1_path_agent.md) & | [**SetPath**](#function-setpath-12) (std::vector&lt; cse491::GridPosition &gt; offsets, size\_t start\_index=0) <br> |
|  [**PathAgent**](classwalle_1_1_path_agent.md) & | [**SetPath**](#function-setpath-22) (std::string\_view commands, size\_t start\_index=0) <br> |
| virtual cse491::GridPosition | [**UpdateAndGetNextPos**](#function-updateandgetnextpos) (bool increment) <br> |
|   | [**~PathAgent**](#function-pathagent) () override<br> |








## Protected Attributes

| Type | Name |
| ---: | :--- |
|  int | [**index\_**](#variable-index_)   = = 0<br>_Current index into offsets\_._  |
|  std::vector&lt; cse491::GridPosition &gt; | [**offsets\_**](#variable-offsets_)  <br> |




















# Detailed Description


Agent that has a user-defined custom movement pattern Passed a sequence of to be sequentially applied as the agent is updated 


    
## Public Functions Documentation




### function CalcNextPos 


```C++
cse491::GridPosition walle::PathAgent::CalcNextPos () const
```



Retrieves the position of the agent after applying the current offset 

**Returns:**

next position of the agent 





        



### function DecrementIndex 


```C++
void walle::PathAgent::DecrementIndex () 
```



Decrements the index into the offsets sequence 


        



### function GetIndex 

_Get the index._ 
```C++
int walle::PathAgent::GetIndex () const
```





**Returns:**

int index


Retrieves which step the agent is on 

**Returns:**

the current index into the offsets 





        



### function GetNextPosition 


```C++
cse491::GridPosition walle::PathAgent::GetNextPosition () override
```



Overrides AgentBase GetNextPosition to retrieve the calculated next position 

**Returns:**

next position to move the path agent in 





        



### function GetPath 

_Get the Path._ 
```C++
std::vector< cse491::GridPosition > const & walle::PathAgent::GetPath () const
```





**Returns:**

vector of GridPositions


Returns an immutable reference to this agent's current path 

**Returns:**

sequence of offsets 





        



### function IncrementIndex 


```C++
void walle::PathAgent::IncrementIndex () 
```



Increments the index into the offsets sequence 


        



### function Initialize 


```C++
bool walle::PathAgent::Initialize () override
```



Checks that the agent is able to move arbitrarily Verifies that it can currently index into a valid offset 

**Returns:**

true if so; false otherwise 





        



### function PathAgent [1/4]

```C++
walle::PathAgent::PathAgent () = delete
```






### function PathAgent [2/4]


```C++
walle::PathAgent::PathAgent (
    size_t id,
    std::string const & name
) 
```



Constructor (agent default) 

**Parameters:**


* `id` unique agent id 
* `name` name of path agent 



**Note:**

When this constructor is called, the agent must still be assigned a path before a call to Initialize 





        



### function PathAgent [3/4]


```C++
walle::PathAgent::PathAgent (
    size_t id,
    std::string const & name,
    std::vector< cse491::GridPosition > offsets
) 
```



Constructor (vector) 

**Parameters:**


* `id` unique agent id 
* `name` name of path agent 
* `offsets` collection of offsets to move the agent 



**Attention:**

The sequence of offsets must not be empty 





        



### function PathAgent [4/4]


```C++
walle::PathAgent::PathAgent (
    size_t id,
    std::string const & name,
    std::string_view commands
) 
```



Constructor (string) 

**Parameters:**


* `id` unique agent id 
* `name` name of path agent 
* `commands` sequence of commands to be interpreted as offsets 



**Attention:**

The sequence of offsets must not be empty 





        



### function ResetIndex 

_Reset the index to 0._ 
```C++
inline PathAgent & walle::PathAgent::ResetIndex () 
```





**Returns:**

self 





        



### function SelectAction 


```C++
size_t walle::PathAgent::SelectAction (
    cse491::WorldGrid const &,
    cse491::type_options_t const &,
    cse491::item_map_t const &,
    cse491::agent_map_t const &
) override
```



Tells world to 

**Returns:**

whether the update succeeded 





        



### function SetPath [1/2]


```C++
PathAgent & walle::PathAgent::SetPath (
    std::vector< cse491::GridPosition > offsets,
    size_t start_index=0
) 
```



Assigns the offsets\_member to a new series of offsets 

**Parameters:**


* `offsets` collection of grid positions used as the new offsets 
* `start_index` which offset to start indexing into (beginning by default) 



**Returns:**

self 




**Attention:**

throws an `std::invalid_argument` when an invalid start index is provided 





        



### function SetPath [2/2]


```C++
PathAgent & walle::PathAgent::SetPath (
    std::string_view commands,
    size_t start_index=0
) 
```



Assigns the offsets\_ member to a new series of offsets, taking a command string 

**Parameters:**


* `commands` formatted string of commands used as offsets 
* `start_index` which command to begin indexing into (first command by default) 



**Returns:**

self 




**Attention:**

throws an `std::invalid_argument` when mis-formatted commands an invalid index is provided 





        



### function UpdateAndGetNextPos 


```C++
virtual cse491::GridPosition walle::PathAgent::UpdateAndGetNextPos (
    bool increment
) 
```



Convenience method Applies the current offset to calculate the next position and then adjusts the index 

**Parameters:**


* `increment` decides whether to move in the forward or backward direction to allow for complex pathing 



**Returns:**







        



### function ~PathAgent 

```C++
walle::PathAgent::~PathAgent () override
```



## Protected Attributes Documentation




### variable index\_ 

```C++
int index_;
```






### variable offsets\_ 


```C++
std::vector<cse491::GridPosition> offsets_;
```



Collection of ways to offset the Agent's position 

**Attention:**

This is a _not_ a sequence of direct coordinates on the WorldGrid, but a series of offsets 





        

------------------------------
The documentation for this class was generated from the following file `source/Agents/PathAgent.hpp`

