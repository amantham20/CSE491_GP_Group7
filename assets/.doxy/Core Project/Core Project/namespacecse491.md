

# Namespace cse491



[**Namespace List**](namespaces.md) **>** [**cse491**](namespacecse491.md)



_A base class interface for all agent types._ [More...](#detailed-description)
















## Classes

| Type | Name |
| ---: | :--- |
| class | [**AgentBase**](classcse491_1_1_agent_base.md) <br> |
| struct | [**CellType**](structcse491_1_1_cell_type.md) <br>_Simple data structure to hold info about a TYPE of cell in the world._  |
| class | [**CoreObject**](classcse491_1_1_core_object.md) <br> |
| class | [**Entity**](classcse491_1_1_entity.md) <br> |
| class | [**GridPosition**](classcse491_1_1_grid_position.md) <br>_Represents a position within a 2D grid of cells. This class provides utilities to manage a position in 2D space. The position is stored as floating-point values (to allow for smooth motion through a grid), but is easily converted to size\_t for grid-cell identification._  |
| class | [**InterfaceBase**](classcse491_1_1_interface_base.md) <br> |
| class | [**WorldBase**](classcse491_1_1_world_base.md) <br> |
| class | [**WorldGrid**](classcse491_1_1_world_grid.md) <br>_A common interface class for core objects that sets up required functionality. This class ensures that objects can be serialized (saved), deserialized (restored) and provides helper functions._  |


## Public Types

| Type | Name |
| ---: | :--- |
| typedef std::vector&lt; std::unique\_ptr&lt; [**AgentBase**](classcse491_1_1_agent_base.md) &gt; &gt; | [**agent\_set\_t**](#typedef-agent_set_t)  <br>_Sets of agents will be represented as vectors of pointers to the base class._  |
| typedef std::vector&lt; std::unique\_ptr&lt; [**Entity**](classcse491_1_1_entity.md) &gt; &gt; | [**item\_set\_t**](#typedef-item_set_t)  <br>_Sets of items will be represented as vectors of pointers to the base class._  |
| typedef std::vector&lt; [**CellType**](structcse491_1_1_cell_type.md) &gt; | [**type\_options\_t**](#typedef-type_options_t)  <br>_Available CellTypes will be passed around as a vector of options._  |
















































# Detailed Description


A simple 2D Grid container.


A base class for all World modules.


A base class for all player-interface types.


A mechanism of identifying a grid cell, as well as a position within the cell.


A base class for all items or agents that can exist on the grid.


Set of types used throughout the codebase.


A common interface class for core objects that sets up required functionality.


This file is part of the Fall 2023, CSE 491 course project. 

**Note:**

Status: PROPOSAL


This file is part of the Fall 2023, CSE 491 course project. 

**Note:**

Status: PROPOSAL


This [**CoreObject**](classcse491_1_1_core_object.md) class builds an interface for all of the core object, ensuring that they can be properly serialized.


Derived classes must implement: GetTypeName\_impl() - To return the qualified type name. Serialize\_impl() - To store the object in a stream. Deserialize\_impl() - To restore the object from a stream. 


    
## Public Types Documentation




### typedef agent\_set\_t 

```C++
using agent_set_t =  std::vector<std::unique_ptr<AgentBase> >;
```






### typedef item\_set\_t 

```C++
using item_set_t =  std::vector<std::unique_ptr<Entity> >;
```






### typedef type\_options\_t 

```C++
using type_options_t =  std::vector<CellType>;
```




------------------------------
The documentation for this class was generated from the following file `source/core/AgentBase.hpp`

