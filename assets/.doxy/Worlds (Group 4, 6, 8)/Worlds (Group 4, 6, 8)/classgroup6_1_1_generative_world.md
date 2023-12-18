

# Class group6::GenerativeWorld



[**ClassList**](annotated.md) **>** [**group6**](namespacegroup6.md) **>** [**GenerativeWorld**](classgroup6_1_1_generative_world.md)








Inherits the following classes: WorldBase


































## Public Functions

| Type | Name |
| ---: | :--- |
|  void | [**AStarAgentHelper**](#function-astaragenthelper) (AgentBase & agent) <br> |
|  void | [**AddArmory**](#function-addarmory) () <br> |
|  void | [**AddTeleporters**](#function-addteleporters) () <br> |
|  void | [**AgentCollisionHelper**](#function-agentcollisionhelper) (AgentBase & agent) <br> |
|  void | [**ArmoryTileHelper**](#function-armorytilehelper) (AgentBase & agent) <br> |
|  int | [**DoAction**](#function-doaction) (AgentBase & agent, size\_t action\_id) override<br> |
|  void | [**DoorTileHelper**](#function-doortilehelper) (AgentBase & agent) <br> |
|  void | [**EndGame**](#function-endgame) (bool win) <br> |
|   | [**GenerativeWorld**](#function-generativeworld) (BiomeType biome, unsigned int width, unsigned int height, unsigned int seed) <br> |
|  void | [**HoleTileHelper**](#function-holetilehelper) (AgentBase & agent, GridPosition & new\_position) <br> |
|  bool | [**IsTraversable**](#function-istraversable) (const AgentBase &, cse491::GridPosition pos) override const<br> |
|  void | [**ItemHelper**](#function-itemhelper) (AgentBase & agent, GridPosition & new\_position) <br> |
|  void | [**KeyTileHelper**](#function-keytilehelper) (AgentBase & agent, GridPosition & new\_position) <br> |
|  void | [**SpikeTileHelper**](#function-spiketilehelper) (AgentBase & agent) <br> |
|  void | [**TarTileHelper**](#function-tartilehelper) (AgentBase & agent) <br> |
|  void | [**TeleporterHelper**](#function-teleporterhelper) (GridPosition & new\_position) <br> |
|   | [**~GenerativeWorld**](#function-generativeworld) () override<br> |


## Public Static Functions

| Type | Name |
| ---: | :--- |
|  vector&lt; GridPosition &gt; | [**FindTiles**](#function-findtiles) (WorldGrid grid, size\_t tile\_id) <br> |


## Protected Types

| Type | Name |
| ---: | :--- |
| enum  | [**ActionType**](#enum-actiontype)  <br> |




## Protected Attributes

| Type | Name |
| ---: | :--- |
|  size\_t | [**armory\_id**](#variable-armory_id)  <br>_Easy access to armory CellTypeID._  |
|  size\_t | [**dirt\_id**](#variable-dirt_id)  <br>_Easy access to dirt CellTypeID._  |
|  size\_t | [**door\_id**](#variable-door_id)  <br>_Easy access to door CellTypeID._  |
|  size\_t | [**floor\_id**](#variable-floor_id)  <br>_Easy access to floor CellType ID._  |
|  size\_t | [**grass\_id**](#variable-grass_id)  <br>_Easy access to grass CellTypeID._  |
|  size\_t | [**hole\_id**](#variable-hole_id)  <br>_Easy access to hole CellTypeID._  |
|  size\_t | [**key\_id**](#variable-key_id)  <br>_Easy access to key CellTypeID._  |
|  size\_t | [**sand\_id**](#variable-sand_id)  <br>_Easy access to sand CellTypeID._  |
|  size\_t | [**spike\_id**](#variable-spike_id)  <br>_Easy access to spike CellType ID._  |
|  size\_t | [**tar\_id**](#variable-tar_id)  <br>_Easy access to tar CellTypeID._  |
|  size\_t | [**teleporter\_id**](#variable-teleporter_id)  <br>_Easy access to teleporter CellTypeId._  |
|  size\_t | [**tree\_id**](#variable-tree_id)  <br>_Easy access to tree CellTypeID._  |
|  size\_t | [**wall\_id**](#variable-wall_id)  <br>_Easy access to wall CellType ID._  |
|  size\_t | [**water\_id**](#variable-water_id)  <br>_Easy access to water CellTypeID._  |
|  unsigned int | [**world\_height**](#variable-world_height)  <br> |
|  unsigned int | [**world\_width**](#variable-world_width)  <br> |
















## Protected Functions

| Type | Name |
| ---: | :--- |
|  void | [**ConfigAgent**](#function-configagent) (AgentBase & agent) override<br> |
|  void | [**CreateGrid**](#function-creategrid) (BiomeType biome, unsigned int width, unsigned int height, unsigned int seed, const string & file) <br> |
|  void | [**DamageAgent**](#function-damageagent) (AgentBase & agent) <br> |




## Public Functions Documentation




### function AStarAgentHelper 

```C++
inline void group6::GenerativeWorld::AStarAgentHelper (
    AgentBase & agent
) 
```






### function AddArmory 


```C++
inline void group6::GenerativeWorld::AddArmory () 
```



Adds armory tiles to grid 


        



### function AddTeleporters 


```C++
inline void group6::GenerativeWorld::AddTeleporters () 
```



Adds teleporters to map 


        



### function AgentCollisionHelper 


```C++
inline void group6::GenerativeWorld::AgentCollisionHelper (
    AgentBase & agent
) 
```



Collision testing functionality 

**Parameters:**


* `agent` agent performing action 




        



### function ArmoryTileHelper 


```C++
inline void group6::GenerativeWorld::ArmoryTileHelper (
    AgentBase & agent
) 
```



Helper function for armory functionality 

**Parameters:**


* `agent` agent performing action 




        



### function DoAction 


```C++
inline int group6::GenerativeWorld::DoAction (
    AgentBase & agent,
    size_t action_id
) override
```



Handles logic for agent movement 

**Parameters:**


* `agent` The agent attempting to do an action 
* `action_id` The action being performed 



**Returns:**

1 if the action was successful. 0 if it was not 





        



### function DoorTileHelper 


```C++
inline void group6::GenerativeWorld::DoorTileHelper (
    AgentBase & agent
) 
```



Helper function for door tile functionality 

**Parameters:**


* `agent` agent performing action 




        



### function EndGame 


```C++
inline void group6::GenerativeWorld::EndGame (
    bool win
) 
```



Ends the game 

**Parameters:**


* `win` True if the game is ending in a win. False if it is a loss 




        



### function GenerativeWorld 

```C++
inline explicit group6::GenerativeWorld::GenerativeWorld (
    BiomeType biome,
    unsigned int width,
    unsigned int height,
    unsigned int seed
) 
```






### function HoleTileHelper 


```C++
inline void group6::GenerativeWorld::HoleTileHelper (
    AgentBase & agent,
    GridPosition & new_position
) 
```



Helper function for hole tile functionality 

**Parameters:**


* `agent` agent performing action 
* `new_position` new position agent is moving to 




        



### function IsTraversable 


```C++
inline bool group6::GenerativeWorld::IsTraversable (
    const AgentBase &,
    cse491::GridPosition pos
) override const
```



Boolean function for traversable tiles in maze 

**Parameters:**


* `agent` agent performing action 
* `pos` position of tile 




        



### function ItemHelper 


```C++
inline void group6::GenerativeWorld::ItemHelper (
    AgentBase & agent,
    GridPosition & new_position
) 
```



Helper function for item pickup functionality 

**Parameters:**


* `agent` agent performing action 
* `new_position` new position agent is moving to 




        



### function KeyTileHelper 


```C++
inline void group6::GenerativeWorld::KeyTileHelper (
    AgentBase & agent,
    GridPosition & new_position
) 
```



Helper function for key tile functionality 

**Parameters:**


* `agent` agent performing action 
* `new_position` new position agent is moving to 




        



### function SpikeTileHelper 


```C++
inline void group6::GenerativeWorld::SpikeTileHelper (
    AgentBase & agent
) 
```



Helper function for spike tile functionality 

**Parameters:**


* `agent` agent performing action 




        



### function TarTileHelper 


```C++
inline void group6::GenerativeWorld::TarTileHelper (
    AgentBase & agent
) 
```



Helper function for tar tile functionality 

**Parameters:**


* `agent` agent performing action 




        



### function TeleporterHelper 


```C++
inline void group6::GenerativeWorld::TeleporterHelper (
    GridPosition & new_position
) 
```



Helper function for armory functionality 

**Parameters:**


* `agent` agent performing action 
* `new_position` new position agent is moving to 




        



### function ~GenerativeWorld 

```C++
group6::GenerativeWorld::~GenerativeWorld () override
```



## Public Static Functions Documentation




### function FindTiles 

```C++
static inline vector< GridPosition > group6::GenerativeWorld::FindTiles (
    WorldGrid grid,
    size_t tile_id
) 
```



## Protected Types Documentation




### enum ActionType 

```C++
enum group6::GenerativeWorld::ActionType {
    REMAIN_STILL = 0,
    MOVE_UP,
    MOVE_DOWN,
    MOVE_LEFT,
    MOVE_RIGHT
};
```



## Protected Attributes Documentation




### variable armory\_id 

```C++
size_t armory_id;
```






### variable dirt\_id 

```C++
size_t dirt_id;
```






### variable door\_id 

```C++
size_t door_id;
```






### variable floor\_id 

```C++
size_t floor_id;
```






### variable grass\_id 

```C++
size_t grass_id;
```






### variable hole\_id 

```C++
size_t hole_id;
```






### variable key\_id 

```C++
size_t key_id;
```






### variable sand\_id 

```C++
size_t sand_id;
```






### variable spike\_id 

```C++
size_t spike_id;
```






### variable tar\_id 

```C++
size_t tar_id;
```






### variable teleporter\_id 

```C++
size_t teleporter_id;
```






### variable tree\_id 

```C++
size_t tree_id;
```






### variable wall\_id 

```C++
size_t wall_id;
```






### variable water\_id 

```C++
size_t water_id;
```






### variable world\_height 

```C++
unsigned int world_height;
```






### variable world\_width 

```C++
unsigned int world_width;
```



## Protected Functions Documentation




### function ConfigAgent 


```C++
inline void group6::GenerativeWorld::ConfigAgent (
    AgentBase & agent
) override
```



Provide the agent with movement actions. 

**Parameters:**


* `agent` The agent being configured 




        



### function CreateGrid 


```C++
inline void group6::GenerativeWorld::CreateGrid (
    BiomeType biome,
    unsigned int width,
    unsigned int height,
    unsigned int seed,
    const string & file
) 
```



Creates a new grid with the given parameters




**Parameters:**


* `biome` The BiomeType being used 
* `width` The width of the grid 
* `height` The height of the grid 
* `seed` The seed used for random generation 
* `file` The file to save the grid to. Full path is "../assets/grids/generated\_[file].grid" 




        



### function DamageAgent 


```C++
inline void group6::GenerativeWorld::DamageAgent (
    AgentBase & agent
) 
```



Ends game if agent is the player 

**Parameters:**


* `agent` The agent being damaged 




        

------------------------------
The documentation for this class was generated from the following file `source/Worlds/GenerativeWorld.hpp`

