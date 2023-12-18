

# Class cse491::MazeWorld



[**ClassList**](annotated.md) **>** [**cse491**](namespacecse491.md) **>** [**MazeWorld**](classcse491_1_1_maze_world.md)








Inherits the following classes: WorldBase


































## Public Functions

| Type | Name |
| ---: | :--- |
|  void | [**ConfigAgent**](#function-configagent-12) (AgentBase & agent) override const<br> |
|  void | [**ConfigAgent**](#function-configagent-22) (AgentBase & agent) override<br> |
|  int | [**DoAction**](#function-doaction) (AgentBase & agent, size\_t action\_id) override<br>_Allow the agents to move around the maze._  |
|  bool | [**IsTraversable**](#function-istraversable) (const AgentBase &, cse491::GridPosition pos) override const<br> |
|   | [**MazeWorld**](#function-mazeworld) (unsigned int seed=0) <br> |
|   | [**~MazeWorld**](#function-mazeworld) () = default<br> |




## Protected Types

| Type | Name |
| ---: | :--- |
| enum  | [**ActionType**](#enum-actiontype)  <br> |




## Protected Attributes

| Type | Name |
| ---: | :--- |
|  size\_t | [**floor\_id**](#variable-floor_id)  <br>_Easy access to floor CellType ID._  |
|  size\_t | [**wall\_id**](#variable-wall_id)  <br>_Easy access to wall CellType ID._  |




















## Public Functions Documentation




### function ConfigAgent [1/2]

```C++
inline void cse491::MazeWorld::ConfigAgent (
    AgentBase & agent
) override const
```






### function ConfigAgent [2/2]

```C++
inline void cse491::MazeWorld::ConfigAgent (
    AgentBase & agent
) override
```






### function DoAction 

```C++
inline int cse491::MazeWorld::DoAction (
    AgentBase & agent,
    size_t action_id
) override
```






### function IsTraversable 

```C++
inline bool cse491::MazeWorld::IsTraversable (
    const AgentBase &,
    cse491::GridPosition pos
) override const
```






### function MazeWorld 

```C++
inline cse491::MazeWorld::MazeWorld (
    unsigned int seed=0
) 
```






### function ~MazeWorld 

```C++
cse491::MazeWorld::~MazeWorld () = default
```



## Protected Types Documentation




### enum ActionType 

```C++
enum cse491::MazeWorld::ActionType {
    REMAIN_STILL = 0,
    MOVE_UP,
    MOVE_DOWN,
    MOVE_LEFT,
    MOVE_RIGHT,
    MOVE_ARBITRARY
};
```



## Protected Attributes Documentation




### variable floor\_id 

```C++
size_t floor_id;
```






### variable wall\_id 

```C++
size_t wall_id;
```




------------------------------
The documentation for this class was generated from the following file `source/Worlds/MazeWorld.hpp`

