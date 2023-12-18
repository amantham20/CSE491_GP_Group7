

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
| class | [**ItemBase**](classcse491_1_1_item_base.md) <br> |
| struct | [**Property**](structcse491_1_1_property.md) &lt;typename T&gt;<br> |
| struct | [**PropertyBase**](structcse491_1_1_property_base.md) <br> |
| class | [**WorldBase**](classcse491_1_1_world_base.md) <br> |
| class | [**WorldGrid**](classcse491_1_1_world_grid.md) <br>_A common interface class for core objects that sets up required functionality. This class ensures that objects can be serialized (saved), deserialized (restored) and provides helper functions._  |
| struct | [**is\_any\_map**](structcse491_1_1is__any__map.md) &lt;typename T&gt;<br>_Type trait to determine if we are working with any type of map._  |
| struct | [**is\_any\_map&lt; std::map&lt; KEY\_T, VALUE\_T &gt; &gt;**](structcse491_1_1is__any__map_3_01std_1_1map_3_01_k_e_y___t_00_01_v_a_l_u_e___t_01_4_01_4.md) &lt;typename KEY\_T, typename VALUE\_T&gt;<br> |
| struct | [**is\_any\_map&lt; std::unordered\_map&lt; KEY\_T, VALUE\_T &gt; &gt;**](structcse491_1_1is__any__map_3_01std_1_1unordered__map_3_01_k_e_y___t_00_01_v_a_l_u_e___t_01_4_01_4.md) &lt;typename KEY\_T, typename VALUE\_T&gt;<br> |
| struct | [**is\_vector**](structcse491_1_1is__vector.md) &lt;typename T&gt;<br>_Type trait to determine if we are working with a vector._  |
| struct | [**is\_vector&lt; std::vector&lt; T &gt; &gt;**](structcse491_1_1is__vector_3_01std_1_1vector_3_01_t_01_4_01_4.md) &lt;typename T&gt;<br> |


## Public Types

| Type | Name |
| ---: | :--- |
| enum  | [**PropertyType**](#enum-propertytype)  <br>_Common types of properties in network serialization._  |
| enum  | [**State**](#enum-state)  <br>_States that an agent can be in._  |
| enum  | [**WorldType**](#enum-worldtype)  <br>_Enum for World types in network serialization._  |
| typedef std::map&lt; size\_t, std::unique\_ptr&lt; [**AgentBase**](classcse491_1_1_agent_base.md) &gt; &gt; | [**agent\_map\_t**](#typedef-agent_map_t)  <br>_Maps of agent IDs to agent pointers._  |
| typedef std::map&lt; size\_t, std::unique\_ptr&lt; [**ItemBase**](classcse491_1_1_item_base.md) &gt; &gt; | [**item\_map\_t**](#typedef-item_map_t)  <br>_Maps of item IDs to item pointers._  |
| typedef std::vector&lt; [**CellType**](structcse491_1_1_cell_type.md) &gt; | [**type\_options\_t**](#typedef-type_options_t)  <br>_Available CellTypes will be passed around as a vector of options._  |






















## Public Static Functions

| Type | Name |
| ---: | :--- |
|  T | [**DeserializeAs**](#function-deserializeas) (std::istream & is) <br>_Helper function to deserialize and return a specified type._  |
|  void | [**DeserializeFunction**](#function-deserializefunction) (std::istream & is, std::function&lt; void(T)&gt; set\_fun) <br>_Helper function to deserialize a member variables from a function._  |
|  void | [**DeserializeValue**](#function-deserializevalue) (std::istream & is, T & var) <br>_Helper function to deserialize a single member variable._  |
|  void | [**DeserializeValue\_Map**](#function-deserializevalue_map) (std::istream &, T &) <br> |
|  void | [**DeserializeValue\_Map**](#function-deserializevalue_map) (std::istream & is, MAP\_T & var) <br>_Helper specialty function to deserialize a unordered\_map member variable._  |
|  void | [**DeserializeValue\_Vector**](#function-deserializevalue_vector) (std::istream & is, std::vector&lt; T &gt; & var) <br>_Helper specialty function to deserialize a vector-based member variable._  |
|  void | [**SerializeValue**](#function-serializevalue) (std::ostream & os, const T & var) <br>_Helper function to serialize a single member variable._  |
|  void | [**SerializeValue\_Map**](#function-serializevalue_map) (std::ostream & os, const T & var) <br>_Helper specialty function to serialize a unordered\_map member variable._  |
|  void | [**SerializeValue\_Vector**](#function-serializevalue_vector) (std::ostream & os, const std::vector&lt; T &gt; & var) <br>_Helper specialty function to serialize a vector-based member variable._  |


























# Detailed Description


A simple 2D Grid container.


Tools to simplify serializing classes.


A class to maintain arbitrary data and facilitate its use.


A base class interface for all non-agent item types.


A base class for all player-interface types.


A mechanism of identifying a grid cell, as well as a position within the cell.


A base class for all items or agents that can exist on the grid.


Set of types used throughout the codebase.


This file is part of the Fall 2023, CSE 491 course project. 

**Note:**

Status: ALPHA 





    
## Public Types Documentation




### enum PropertyType 

```C++
enum cse491::PropertyType {
    t_double,
    t_int,
    t_char,
    t_string,
    t_position,
    t_bool,
    t_other
};
```






### enum State 

```C++
enum cse491::State {
    Healthy,
    Taking_Damage,
    Dying,
    Deceased
};
```






### enum WorldType 

```C++
enum cse491::WorldType {
    w_maze,
    w_second,
    w_generative,
    w_manual
};
```






### typedef agent\_map\_t 

```C++
using agent_map_t =  std::map<size_t, std::unique_ptr<AgentBase> >;
```






### typedef item\_map\_t 

```C++
using item_map_t =  std::map<size_t, std::unique_ptr<ItemBase> >;
```






### typedef type\_options\_t 

```C++
using type_options_t =  std::vector<CellType>;
```



## Public Static Functions Documentation




### function DeserializeAs 

_Helper function to deserialize and return a specified type._ 
```C++
template<typename T typename T>
static T cse491::DeserializeAs (
    std::istream & is
) 
```





**Parameters:**


* `os` Input stream to write from. 




        



### function DeserializeFunction 

_Helper function to deserialize a member variables from a function._ 
```C++
template<typename T typename T>
static void cse491::DeserializeFunction (
    std::istream & is,
    std::function< void(T)> set_fun
) 
```





**Parameters:**


* `os` Input stream to write from. 
* `var` Variable to serialize. 




        



### function DeserializeValue 

_Helper function to deserialize a single member variable._ 
```C++
template<typename T typename T>
static void cse491::DeserializeValue (
    std::istream & is,
    T & var
) 
```





**Parameters:**


* `os` Input stream to write from. 
* `var` Variable to deserialize. 




        



### function DeserializeValue\_Map 

```C++
template<typename T typename T>
static void cse491::DeserializeValue_Map (
    std::istream &,
    T &
) 
```






### function DeserializeValue\_Map 

_Helper specialty function to deserialize a unordered\_map member variable._ 
```C++
template<typename MAP_T typename MAP_T>
static void cse491::DeserializeValue_Map (
    std::istream & is,
    MAP_T & var
) 
```





**Parameters:**


* `is` Input stream to read from. 
* `var` Variable to deserialize. 




        



### function DeserializeValue\_Vector 

_Helper specialty function to deserialize a vector-based member variable._ 
```C++
template<typename T typename T>
static void cse491::DeserializeValue_Vector (
    std::istream & is,
    std::vector< T > & var
) 
```





**Parameters:**


* `os` Input stream to read from. 
* `var` Variable to deserialize. 




        



### function SerializeValue 

_Helper function to serialize a single member variable._ 
```C++
template<typename T typename T>
static void cse491::SerializeValue (
    std::ostream & os,
    const T & var
) 
```





**Parameters:**


* `os` Output stream to write to. 
* `var` Variable to serialize. 




        



### function SerializeValue\_Map 

_Helper specialty function to serialize a unordered\_map member variable._ 
```C++
template<typename T typename T>
static void cse491::SerializeValue_Map (
    std::ostream & os,
    const T & var
) 
```





**Parameters:**


* `os` Output stream to write to. 
* `var` Variable to serialize. 




        



### function SerializeValue\_Vector 

_Helper specialty function to serialize a vector-based member variable._ 
```C++
template<typename T typename T>
static void cse491::SerializeValue_Vector (
    std::ostream & os,
    const std::vector< T > & var
) 
```





**Parameters:**


* `os` Output stream to write to. 
* `var` Variable to serialize. 




        

------------------------------
The documentation for this class was generated from the following file `source/core/AgentBase.hpp`

