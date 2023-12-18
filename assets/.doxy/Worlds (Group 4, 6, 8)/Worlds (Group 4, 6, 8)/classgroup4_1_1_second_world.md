

# Class group4::SecondWorld



[**ClassList**](annotated.md) **>** [**group4**](namespacegroup4.md) **>** [**SecondWorld**](classgroup4_1_1_second_world.md)



[More...](#detailed-description)

* `#include <SecondWorld.hpp>`



Inherits the following classes: WorldBase


































## Public Functions

| Type | Name |
| ---: | :--- |
|  bool | [**CheckPosition**](#function-checkposition) (cse491::AgentBase & agent, cse491::GridPosition & pos) <br> |
|  int | [**DoAction**](#function-doaction) (cse491::AgentBase & agent, size\_t action\_id) override<br> |
|  void | [**DropItem**](#function-dropitem) (cse491::AgentBase & agent, cse491::GridPosition & pos) <br> |
|  bool | [**IsTraversable**](#function-istraversable) (const AgentBase & agent, cse491::GridPosition pos) override const<br> |
|  void | [**LoadFromFile**](#function-loadfromfile) (const std::string & input\_filename) <br> |
|  void | [**PrintEntities**](#function-printentities) () <br> |
| virtual void | [**Run**](#function-run) () override<br> |
|  void | [**SaveToFile**](#function-savetofile) () <br> |
|   | [**SecondWorld**](#function-secondworld-12) () <br> |
|   | [**SecondWorld**](#function-secondworld-22) (std::string grid\_filename, std::string agent\_filename) <br> |
|   | [**~SecondWorld**](#function-secondworld) () = default<br> |




## Protected Types

| Type | Name |
| ---: | :--- |
| enum  | [**ActionType**](#enum-actiontype)  <br> |




## Protected Attributes

| Type | Name |
| ---: | :--- |
|  std::map&lt; size\_t, std::unique\_ptr&lt; cse491::ItemBase &gt; &gt; | [**inventory**](#variable-inventory)  <br>_Vector of the items in this world._  |
|  [**worldlang::ProgramExecutor**](classworldlang_1_1_program_executor.md) | [**pe**](#variable-pe)  <br>_Script executor object._  |
















## Protected Functions

| Type | Name |
| ---: | :--- |
|  void | [**ConfigAgent**](#function-configagent) (cse491::AgentBase & agent) override<br>_Provide the agent with movement actions._  |




# Detailed Description


Creates a world with agents and a win flag 


    
## Public Functions Documentation




### function CheckPosition 


```C++
inline bool group4::SecondWorld::CheckPosition (
    cse491::AgentBase & agent,
    cse491::GridPosition & pos
) 
```



Checks to see if there is a flag or item at the agent's current position 

**Parameters:**


* `agent` The agent 
* `pos` The position 



**Returns:**

true if agent should update position on return 





        



### function DoAction 


```C++
inline int group4::SecondWorld::DoAction (
    cse491::AgentBase & agent,
    size_t action_id
) override
```



Allows agents to perform an action and sets each agent's new position 

**Parameters:**


* `agent` The agent performing the action 
* `action_id` The id that represents the move 



**Returns:**

An int that declares if the move is legal or illegal (true / false) 





        



### function DropItem 


```C++
inline void group4::SecondWorld::DropItem (
    cse491::AgentBase & agent,
    cse491::GridPosition & pos
) 
```



Drops the item in the agent's inventory 

**Parameters:**


* `agent` This agent's item we're dropping 
* `pos` The position where the item will be dropped 




        



### function IsTraversable 


```C++
inline bool group4::SecondWorld::IsTraversable (
    const AgentBase & agent,
    cse491::GridPosition pos
) override const
```



Can walk on all tiles except for walls and water (unless agent has property set) 


        



### function LoadFromFile 


```C++
inline void group4::SecondWorld::LoadFromFile (
    const std::string & input_filename
) 
```



Loads data from a JSON file and adds agents with specified properties into the world. 

**Parameters:**


* `input_filename` Relative path to input.json file 




        



### function PrintEntities 


```C++
inline void group4::SecondWorld::PrintEntities () 
```



Prints the entities in item\_set (testing) 


        



### function Run 


```C++
inline virtual void group4::SecondWorld::Run () override
```



This function gives us an output.json file 


        



### function SaveToFile 


```C++
inline void group4::SecondWorld::SaveToFile () 
```



This function gives us an output.json file using nlohmann::json library 


        



### function SecondWorld [1/2]


```C++
inline group4::SecondWorld::SecondWorld () 
```



Constructor with no arguments 


        



### function SecondWorld [2/2]


```C++
inline group4::SecondWorld::SecondWorld (
    std::string grid_filename,
    std::string agent_filename
) 
```



Constructor with grid and agent file names 

**Parameters:**


* `grid_filename` Relative path to grid file 
* `agent_filename` Relative path to agent input.json file 




        



### function ~SecondWorld 


```C++
group4::SecondWorld::~SecondWorld () = default
```



Destructor 


        
## Protected Types Documentation




### enum ActionType 

```C++
enum group4::SecondWorld::ActionType {
    REMAIN_STILL = 0,
    MOVE_UP,
    MOVE_DOWN,
    MOVE_LEFT,
    MOVE_RIGHT,
    DROP_ITEM
};
```



## Protected Attributes Documentation




### variable inventory 

```C++
std::map<size_t, std::unique_ptr<cse491::ItemBase> > inventory;
```






### variable pe 

```C++
worldlang::ProgramExecutor pe;
```



## Protected Functions Documentation




### function ConfigAgent 

```C++
inline void group4::SecondWorld::ConfigAgent (
    cse491::AgentBase & agent
) override
```




------------------------------
The documentation for this class was generated from the following file `source/Worlds/SecondWorld.hpp`

