

# Class cse491\_team8::ManualWorld



[**ClassList**](annotated.md) **>** [**cse491\_team8**](namespacecse491__team8.md) **>** [**ManualWorld**](classcse491__team8_1_1_manual_world.md)








Inherits the following classes: WorldBase


































## Public Functions

| Type | Name |
| ---: | :--- |
|  void | [**AddMove**](#function-addmove) (cse491::AgentBase & agent, std::string & move, char stat, double modification) <br>_adds a move to the move set for an agent_  |
|  int | [**DoAction**](#function-doaction) (cse491::AgentBase & agent, size\_t action\_id) override<br>_Central function for an agent to take any action._  |
|  void | [**DoActionAttemptItemPickup**](#function-doactionattemptitempickup) (cse491::AgentBase & agent, const cse491::GridPosition & new\_position) <br>_Attempt to pick up an item for the agent._  |
|  cse491::GridPosition | [**DoActionFindNewPosition**](#function-doactionfindnewposition) (cse491::AgentBase & agent, size\_t action\_id) <br>_Updates agent's position and direction._  |
|  void | [**DoActionTestNewPositionTree**](#function-doactiontestnewpositiontree) (cse491::AgentBase & agent, const cse491::GridPosition & new\_position) <br>_Attempt to interact with a tree If the agent can interact with the tree, prompts the user if they want to use one of their chops._  |
|  bool | [**DoActionTestNewPositionWater**](#function-doactiontestnewpositionwater) (cse491::AgentBase & agent) <br>_Attempt to float on a water tile If the agent has a boat, prompts the user if they want to use the boat once._  |
|  void | [**DoBattle**](#function-dobattle) (cse491::AgentBase & other\_agent, cse491::AgentBase & agent, char attack\_type) <br>_Checks the strength between two agents._  |
|  void | [**DropItems**](#function-dropitems) (cse491::AgentBase & agent, cse491::AgentBase & other\_agent) <br>_Removes all items from other agent._  |
|  size\_t | [**FindItem**](#function-finditem) (cse491::AgentBase & agent, const std::string & item\_name) <br>_Check if an agent owns an item._  |
|  void | [**GenerateMoveSets**](#function-generatemovesets) () <br>_Generates move sets for all the agents Sets the move sets as a property for each agent._  |
|  void | [**HealAction**](#function-healaction) (cse491::AgentBase & agent) <br>_Heals an Agent._  |
|  bool | [**IsTraversable**](#function-istraversable) (const cse491::AgentBase &, cse491::GridPosition pos) override const<br>_Determine if this tile can be walked on, defaults to every tile is walkable._  |
|  cse491::GridPosition | [**LookAhead**](#function-lookahead) (cse491::AgentBase & agent) <br>_looks one tile ahead of the agent based on facing direction_  |
|   | [**ManualWorld**](#function-manualworld) () <br> |
|  void | [**MoveSetAction**](#function-movesetaction) (cse491::AgentBase & agent) <br>_Displays the moveset for the agent._  |
|  int | [**OtherAction**](#function-otheraction) (cse491::AgentBase & other\_agent, cse491::AgentBase & agent) <br>_Determines the damage of the other agent._  |
|  bool | [**RemoveMove**](#function-removemove) (cse491::AgentBase & agent, std::string & move) <br>_removes a move from the move set for an agent_  |
|  void | [**Run**](#function-run) () override<br>_Runs agents, updates the world._  |
|  void | [**RunAgents**](#function-runagents) () override<br>_Step through each agent giving them a chance to take an action._  |
|  void | [**StatsAction**](#function-statsaction) (cse491::AgentBase & agent) <br>_Displays the items and properties that the player has._  |
|  void | [**UpdateWorld**](#function-updateworld) () override<br>_Looks for adjacencies._  |
|   | [**~ManualWorld**](#function-manualworld) () = default<br> |




## Protected Types

| Type | Name |
| ---: | :--- |
| enum  | [**ActionType**](#enum-actiontype)  <br> |
| enum  | [**FacingDirection**](#enum-facingdirection)  <br> |




## Protected Attributes

| Type | Name |
| ---: | :--- |
|  size\_t | [**bridge\_id**](#variable-bridge_id)  <br>_Easy access to bridge CellType ID._  |
|  size\_t | [**grass\_id**](#variable-grass_id)  <br>_Easy access to floor CellType ID._  |
|  size\_t | [**portal\_id\_a**](#variable-portal_id_a)  <br>_Easy access to first portal CellType ID._  |
|  size\_t | [**portal\_id\_b**](#variable-portal_id_b)  <br>_Easy access to second portal CellType ID._  |
|  size\_t | [**portal\_id\_c**](#variable-portal_id_c)  <br>_Easy access to third portal CellType ID._  |
|  size\_t | [**portal\_id\_d**](#variable-portal_id_d)  <br>_Easy access to fourth portal CellType ID._  |
|  size\_t | [**rock\_id**](#variable-rock_id)  <br>_Easy access to rock CellType ID._  |
|  size\_t | [**tree\_id**](#variable-tree_id)  <br>_Easy access to tree CellType ID._  |
|  size\_t | [**water\_id**](#variable-water_id)  <br>_Easy access to water CellType ID._  |
















## Protected Functions

| Type | Name |
| ---: | :--- |
|  void | [**ConfigAgent**](#function-configagent) (cse491::AgentBase & agent) override<br>_Provide the agent with movement actions._  |




## Public Functions Documentation




### function AddMove 

_adds a move to the move set for an agent_ 
```C++
inline void cse491_team8::ManualWorld::AddMove (
    cse491::AgentBase & agent,
    std::string & move,
    char stat,
    double modification
) 
```





**Parameters:**


* `agent` the agent to add the move to 
* `move` the name of the move to add 
* `stat` the stat that the move affects 
* `modification` the modification percent of the move to that stat Adds a move to the move set map 



**Returns:**

None 





        



### function DoAction 

_Central function for an agent to take any action._ 
```C++
inline int cse491_team8::ManualWorld::DoAction (
    cse491::AgentBase & agent,
    size_t action_id
) override
```





**Parameters:**


* `agent` The specific agent taking the action 
* `action` The id of the action to take 



**Returns:**

The result of this action (usually 0/1 to indicate success) 




**Note:**

Thus function must be overridden in any derived world. 





        



### function DoActionAttemptItemPickup 

_Attempt to pick up an item for the agent._ 
```C++
inline void cse491_team8::ManualWorld::DoActionAttemptItemPickup (
    cse491::AgentBase & agent,
    const cse491::GridPosition & new_position
) 
```





**Parameters:**


* `agent` The agent that is picking up the item. 
* `new_position` New position of the agent to check if an item is there. 



**Returns:**

Nothing 





        



### function DoActionFindNewPosition 

_Updates agent's position and direction._ 
```C++
inline cse491::GridPosition cse491_team8::ManualWorld::DoActionFindNewPosition (
    cse491::AgentBase & agent,
    size_t action_id
) 
```





**Parameters:**


* `agent` The agent that is moving its position 
* `action_id` A size\_t representing the direction the agent moved 



**Returns:**

The agent's new position 





        



### function DoActionTestNewPositionTree 

_Attempt to interact with a tree If the agent can interact with the tree, prompts the user if they want to use one of their chops._ 
```C++
inline void cse491_team8::ManualWorld::DoActionTestNewPositionTree (
    cse491::AgentBase & agent,
    const cse491::GridPosition & new_position
) 
```





**Parameters:**


* `agent` The agent trying to interact 
* `new_position` The position being interacted with 



**Returns:**

Nothing, the tree gets chopped if possible but the agent doesn't move 





        



### function DoActionTestNewPositionWater 

_Attempt to float on a water tile If the agent has a boat, prompts the user if they want to use the boat once._ 
```C++
inline bool cse491_team8::ManualWorld::DoActionTestNewPositionWater (
    cse491::AgentBase & agent
) 
```





**Parameters:**


* `agent` The agent trying to interact 



**Returns:**

True if the agent is able to (and chooses) to move to the new spot, else false 





        



### function DoBattle 

_Checks the strength between two agents._ 
```C++
inline void cse491_team8::ManualWorld::DoBattle (
    cse491::AgentBase & other_agent,
    cse491::AgentBase & agent,
    char attack_type
) 
```





**Parameters:**


* `other_agent` The autonomous agent to compare 
* `agent` The interface (player) agent to compare 
* `attack_type` The attack that is being used by the player Prints the stronger agent and removes the weaker 



**See also:** RemoveAgent 


**Returns:**

None 





        



### function DropItems 

_Removes all items from other agent._ 
```C++
inline void cse491_team8::ManualWorld::DropItems (
    cse491::AgentBase & agent,
    cse491::AgentBase & other_agent
) 
```





**Parameters:**


* `agent` Agent that won the battle 
* `other_agent` Agent that is dropping items 




        



### function FindItem 

_Check if an agent owns an item._ 
```C++
inline size_t cse491_team8::ManualWorld::FindItem (
    cse491::AgentBase & agent,
    const std::string & item_name
) 
```





**Parameters:**


* `agent` The agent to see if is an owner 
* `item_name` Name of the item 



**Returns:**

item\_id 





        



### function GenerateMoveSets 

_Generates move sets for all the agents Sets the move sets as a property for each agent._ 
```C++
inline void cse491_team8::ManualWorld::GenerateMoveSets () 
```





**Returns:**

None 





        



### function HealAction 

_Heals an Agent._ 
```C++
inline void cse491_team8::ManualWorld::HealAction (
    cse491::AgentBase & agent
) 
```





**Parameters:**


* `agent` The Agent getting healed Calculates the healing of the agent 



**Returns:**

None 





        



### function IsTraversable 

_Determine if this tile can be walked on, defaults to every tile is walkable._ 
```C++
inline bool cse491_team8::ManualWorld::IsTraversable (
    const cse491::AgentBase &,
    cse491::GridPosition pos
) override const
```





**Parameters:**


* `pos` The grid position we are checking 



**Returns:**

If an agent should be allowed on this square 





        



### function LookAhead 

_looks one tile ahead of the agent based on facing direction_ 
```C++
inline cse491::GridPosition cse491_team8::ManualWorld::LookAhead (
    cse491::AgentBase & agent
) 
```





**Parameters:**


* `agent` Agent that is looking ahead 



**Returns:**

the grid position 





        



### function ManualWorld 

```C++
inline cse491_team8::ManualWorld::ManualWorld () 
```






### function MoveSetAction 

_Displays the moveset for the agent._ 
```C++
inline void cse491_team8::ManualWorld::MoveSetAction (
    cse491::AgentBase & agent
) 
```





**Parameters:**


* `agent` Agent moveset being displayed. 




        



### function OtherAction 

_Determines the damage of the other agent._ 
```C++
inline int cse491_team8::ManualWorld::OtherAction (
    cse491::AgentBase & other_agent,
    cse491::AgentBase & agent
) 
```





**Parameters:**


* `other_agent` The NPC agent 
* `agent` The player agent Gets the damage of the NPC agent 



**Returns:**

The damage of the NPC 





        



### function RemoveMove 

_removes a move from the move set for an agent_ 
```C++
inline bool cse491_team8::ManualWorld::RemoveMove (
    cse491::AgentBase & agent,
    std::string & move
) 
```





**Parameters:**


* `agent` the agent to remove a move from 
* `move` the name of the move to remove Removes a move from the move set map 



**Returns:**

true for success, false for failure 





        



### function Run 

```C++
inline void cse491_team8::ManualWorld::Run () override
```






### function RunAgents 

```C++
inline void cse491_team8::ManualWorld::RunAgents () override
```






### function StatsAction 

_Displays the items and properties that the player has._ 
```C++
inline void cse491_team8::ManualWorld::StatsAction (
    cse491::AgentBase & agent
) 
```





**Parameters:**


* `agent` Agent stats being showed. 




        



### function UpdateWorld 

```C++
inline void cse491_team8::ManualWorld::UpdateWorld () override
```






### function ~ManualWorld 

```C++
cse491_team8::ManualWorld::~ManualWorld () = default
```



## Protected Types Documentation




### enum ActionType 

```C++
enum cse491_team8::ManualWorld::ActionType {
    REMAIN_STILL =0,
    MOVE_UP,
    MOVE_DOWN,
    MOVE_LEFT,
    MOVE_RIGHT,
    USE_AXE,
    USE_BOAT,
    STATS,
    HEAL,
    RUN,
    ATTACK,
    SPECIAL,
    BUFF,
    HELP
};
```






### enum FacingDirection 

```C++
enum cse491_team8::ManualWorld::FacingDirection {
    UP =0,
    RIGHT,
    DOWN,
    LEFT
};
```



## Protected Attributes Documentation




### variable bridge\_id 

```C++
size_t bridge_id;
```






### variable grass\_id 

```C++
size_t grass_id;
```






### variable portal\_id\_a 

```C++
size_t portal_id_a;
```






### variable portal\_id\_b 

```C++
size_t portal_id_b;
```






### variable portal\_id\_c 

```C++
size_t portal_id_c;
```






### variable portal\_id\_d 

```C++
size_t portal_id_d;
```






### variable rock\_id 

```C++
size_t rock_id;
```






### variable tree\_id 

```C++
size_t tree_id;
```






### variable water\_id 

```C++
size_t water_id;
```



## Protected Functions Documentation




### function ConfigAgent 

```C++
inline void cse491_team8::ManualWorld::ConfigAgent (
    cse491::AgentBase & agent
) override
```




------------------------------
The documentation for this class was generated from the following file `source/Worlds/ManualWorld.hpp`

