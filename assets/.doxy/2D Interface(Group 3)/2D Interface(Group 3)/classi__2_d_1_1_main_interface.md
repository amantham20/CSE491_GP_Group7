

# Class i\_2D::MainInterface



[**ClassList**](annotated.md) **>** [**i\_2D**](namespacei__2_d.md) **>** [**MainInterface**](classi__2_d_1_1_main_interface.md)



_Represents the main interface for a 2D maze game._ [More...](#detailed-description)

* `#include <MainInterface.hpp>`



Inherits the following classes: InterfaceBase


































## Public Functions

| Type | Name |
| ---: | :--- |
|  void | [**CheckLargerGrid**](#function-checklargergrid) () <br> |
|  std::vector&lt; std::string &gt; | [**CreateVectorMaze**](#function-createvectormaze) (const WorldGrid & grid, const type\_options\_t & type\_options, const item\_map\_t & item\_map, const agent\_map\_t & agent\_map) <br>_Creates a vector representation of the maze grid._  |
|  void | [**DrawGrid**](#function-drawgrid) (const WorldGrid & grid, const type\_options\_t & type\_options, const item\_map\_t & item\_map, const agent\_map\_t & agent\_map) <br>_Draws the maze grid and entities on the SFML window._  |
|  bool | [**Initialize**](#function-initialize) () override<br>_Initializes the main interface._  |
|   | [**MainInterface**](#function-maininterface) (size\_t id, const std::string & name) <br>_Constructs a_ `MainInterface` _object._ |
|  void | [**Notify**](#function-notify) (const std::string & message, const std::string &="none") override<br>_notifies the world if the player have any progress message_  |
|  size\_t | [**SelectAction**](#function-selectaction) (const WorldGrid & grid, const type\_options\_t & type\_options, const item\_map\_t & item\_map, const agent\_map\_t & agent\_map) override<br>_Handles user input for selecting actions._  |
|  void | [**SetLargeGrid**](#function-setlargegrid) (bool b) <br> |
|  void | [**setMInputWaitTime**](#function-setminputwaittime) (double mInputWaitTime) <br> |
|   | [**~MainInterface**](#function-maininterface) () = default<br>_Destructor for the_ `MainInterface` _class._ |




























# Detailed Description


This class inherits from `InterfaceBase` and provides functionality for creating and displaying a 2D maze game world, handling user input, and updating the graphical representation of the game. 


    
## Public Functions Documentation




### function CheckLargerGrid 

```C++
void i_2D::MainInterface::CheckLargerGrid () 
```






### function CreateVectorMaze 

_Creates a vector representation of the maze grid._ 
```C++
std::vector< std::string > i_2D::MainInterface::CreateVectorMaze (
    const WorldGrid & grid,
    const type_options_t & type_options,
    const item_map_t & item_map,
    const agent_map_t & agent_map
) 
```





**Parameters:**


* `grid` The WorldGrid representing the maze. 
* `type_options` The type options for symbols. 
* `item_map` The map of ids to items in the maze. 
* `agent_map` The map of ids to agents in the maze.



**Returns:**

A vector of strings representing the maze grid. 





        



### function DrawGrid 

_Draws the maze grid and entities on the SFML window._ 
```C++
void i_2D::MainInterface::DrawGrid (
    const WorldGrid & grid,
    const type_options_t & type_options,
    const item_map_t & item_map,
    const agent_map_t & agent_map
) 
```





**Parameters:**


* `grid` The WorldGrid representing the maze. 
* `type_options` The type options for symbols. 
* `item_map` The map of ids to items in the maze. 
* `agent_map` The map of ids to agents in t 




        



### function Initialize 

_Initializes the main interface._ 
```C++
inline bool i_2D::MainInterface::Initialize () override
```





**Returns:**

True if initialization is successful; otherwise, false. 





        



### function MainInterface 

_Constructs a_ `MainInterface` _object._
```C++
i_2D::MainInterface::MainInterface (
    size_t id,
    const std::string & name
) 
```





**Parameters:**


* `id` The identifier for this interface. 
* `name` The name of this interface. 




        



### function Notify 

_notifies the world if the player have any progress message_ 
```C++
inline void i_2D::MainInterface::Notify (
    const std::string & message,
    const std::string &="none"
) override
```





**Parameters:**


* `message` that notifies the world 




        



### function SelectAction 

_Handles user input for selecting actions._ 
```C++
size_t i_2D::MainInterface::SelectAction (
    const WorldGrid & grid,
    const type_options_t & type_options,
    const item_map_t & item_map,
    const agent_map_t & agent_map
) override
```





**Parameters:**


* `grid` The WorldGrid representing the maze. 
* `type_options` The type options for symbols. 
* `item_map` The map of ids to items in the maze. 
* `agent_map` The map of ids to agents in the maze. 




        



### function SetLargeGrid 

```C++
inline void i_2D::MainInterface::SetLargeGrid (
    bool b
) 
```






### function setMInputWaitTime 


```C++
void i_2D::MainInterface::setMInputWaitTime (
    double mInputWaitTime
) 
```



Sets the inputwait time for netwrok interface




**Parameters:**


* `waitTime` 




        



### function ~MainInterface 

```C++
i_2D::MainInterface::~MainInterface () = default
```




------------------------------
The documentation for this class was generated from the following file `source/Interfaces/MainInterface.hpp`

