

# Namespace group4



[**Namespace List**](namespaces.md) **>** [**group4**](namespacegroup4.md)




















## Classes

| Type | Name |
| ---: | :--- |
| class | [**SecondWorld**](classgroup4_1_1_second_world.md) <br> |






## Public Attributes

| Type | Name |
| ---: | :--- |
|  const std::string | [**COMBAT\_SCRIPT**](#variable-combat_script)   = = "../assets/scripts/g4\_agent\_attack.ws"<br>_Filename for agent combat script._  |
|  const std::string | [**FINAL\_FLOOR\_FILENAME**](#variable-final_floor_filename)   = = "../assets/grids/third\_floor.grid"<br>_Filename for the last floor grid file._  |
|  const std::string | [**FIRST\_FLOOR\_FILENAME**](#variable-first_floor_filename)   = = "../assets/grids/group4\_maze.grid"<br>_Filename for the first floor grid file._  |
|  const std::string | [**ITEM\_PICKUP\_SCRIPT**](#variable-item_pickup_script)   = = "../assets/scripts/g4\_item\_pickup.ws"<br>_Filename for item pickup script._  |
|  const size\_t | [**MAX\_INVENTORY\_SIZE**](#variable-max_inventory_size)   = = 30<br>_Maximum inventory size for an agent._  |
|  const cse491::GridPosition | [**OffGrid**](#variable-offgrid)   = = {-1, -1}<br>_Off the grid position._  |
|  const std::string | [**SECOND\_FLOOR\_FILENAME**](#variable-second_floor_filename)   = = "../assets/grids/second\_floor.grid"<br>_Filename for the second floor grid file._  |
|  const std::string | [**WORLD\_LOAD\_SCRIPT**](#variable-world_load_script)   = = "../assets/scripts/g4\_world\_load.ws"<br>_Filename for world initialization script._  |
|  const std::string | [**WORLD\_LOAD\_SCRIPT\_2**](#variable-world_load_script_2)   = = "../assets/scripts/g4\_world\_2\_load.ws"<br>_Filename for second floor initialization script._  |
|  const std::string | [**WORLD\_LOAD\_SCRIPT\_3**](#variable-world_load_script_3)   = = "../assets/scripts/g4\_world\_3\_load.ws"<br>_Filename for final floor initialization script._  |












































## Public Attributes Documentation




### variable COMBAT\_SCRIPT 

_Filename for agent combat script._ 
```C++
const std::string COMBAT_SCRIPT;
```



When an agent attempts to move into another agent, this attack script runs. 


        



### variable FINAL\_FLOOR\_FILENAME 

```C++
const std::string FINAL_FLOOR_FILENAME;
```






### variable FIRST\_FLOOR\_FILENAME 

```C++
const std::string FIRST_FLOOR_FILENAME;
```






### variable ITEM\_PICKUP\_SCRIPT 

_Filename for item pickup script._ 
```C++
const std::string ITEM_PICKUP_SCRIPT;
```



This script modifies properties of the agent collecting the item. 


        



### variable MAX\_INVENTORY\_SIZE 

```C++
const size_t MAX_INVENTORY_SIZE;
```






### variable OffGrid 

```C++
const cse491::GridPosition OffGrid;
```






### variable SECOND\_FLOOR\_FILENAME 

```C++
const std::string SECOND_FLOOR_FILENAME;
```






### variable WORLD\_LOAD\_SCRIPT 

```C++
const std::string WORLD_LOAD_SCRIPT;
```






### variable WORLD\_LOAD\_SCRIPT\_2 

```C++
const std::string WORLD_LOAD_SCRIPT_2;
```






### variable WORLD\_LOAD\_SCRIPT\_3 

```C++
const std::string WORLD_LOAD_SCRIPT_3;
```




------------------------------
The documentation for this class was generated from the following file `source/Worlds/SecondWorld.hpp`

