

# Class cse491::WorldBase



[**ClassList**](annotated.md) **>** [**cse491**](namespacecse491.md) **>** [**WorldBase**](classcse491_1_1_world_base.md)


























## Public Attributes

| Type | Name |
| ---: | :--- |
|  netWorth::ClientManager \* | [**client\_manager**](#variable-client_manager)   = = nullptr<br>_Server manager for world if used._  |
|  netWorth::ServerManager \* | [**server\_manager**](#variable-server_manager)   = = nullptr<br> |


## Public Static Attributes

| Type | Name |
| ---: | :--- |
|  constexpr size\_t | [**npos**](#variable-npos)   = = static\_cast&lt;size\_t&gt;(-1)<br> |














## Public Functions

| Type | Name |
| ---: | :--- |
|  [**AgentBase**](classcse491_1_1_agent_base.md) & | [**AddAgent**](#function-addagent) (std::string agent\_name="None", PROPERTY\_Ts... properties) <br>_Build a new agent of the specified type._  |
|  [**AgentBase**](classcse491_1_1_agent_base.md) & | [**AddConfiguredAgent**](#function-addconfiguredagent) (std::unique\_ptr&lt; [**AgentBase**](classcse491_1_1_agent_base.md) &gt; agent\_ptr) <br>_Add an already-created agent._  |
|  [**ItemBase**](classcse491_1_1_item_base.md) & | [**AddItem**](#function-additem-12) (std::unique\_ptr&lt; [**ItemBase**](classcse491_1_1_item_base.md) &gt; item\_ptr) <br>_Add a new, already-built item._  |
|  [**ItemBase**](classcse491_1_1_item_base.md) & | [**AddItem**](#function-additem-22) (std::string item\_name="None", PROPERTY\_Ts... properties) <br>_Build a new item and add it._  |
|  [**WorldBase**](classcse491_1_1_world_base.md) & | [**AddItemToGrid**](#function-additemtogrid) (size\_t item\_id, [**GridPosition**](classcse491_1_1_grid_position.md) pos, size\_t grid\_id=0) <br> |
|  void | [**CollectData**](#function-collectdata) () <br> |
| virtual void | [**ConfigAgent**](#function-configagent-12) ([**AgentBase**](classcse491_1_1_agent_base.md) &) const<br>_Client manager for world if used._  |
|  void | [**Deserialize**](#function-deserialize) (std::istream & is, netWorth::ClientManager \* manager) <br>_Deserialize world, agents, and items from istream._  |
|  void | [**DeserializeAgentSet**](#function-deserializeagentset) (std::istream & is, netWorth::ClientManager \* manager) <br>_Add deserialized agents to world with a manager._  |
|  void | [**DeserializeItemSet**](#function-deserializeitemset) (std::istream & is) <br>_Add deserialized items to world._  |
| virtual int | [**DoAction**](#function-doaction) ([**AgentBase**](classcse491_1_1_agent_base.md) & agent, size\_t action\_id) = 0<br>_Central function for an agent to take any action._  |
| virtual std::vector&lt; size\_t &gt; | [**FindAgentsAt**](#function-findagentsat) ([**GridPosition**](classcse491_1_1_grid_position.md) pos, size\_t grid\_id=0) const<br>_Lookup IDs for all agents at a given grid position._  |
| virtual std::vector&lt; size\_t &gt; | [**FindAgentsNear**](#function-findagentsnear) ([**GridPosition**](classcse491_1_1_grid_position.md) pos, double dist=1.0, size\_t grid\_id=0) const<br>_Lookup IDs for all agents near a given grid position._  |
| virtual std::vector&lt; size\_t &gt; | [**FindItemsAt**](#function-finditemsat) ([**GridPosition**](classcse491_1_1_grid_position.md) pos, size\_t grid\_id=0) const<br>_Lookup IDs for all items at a given grid position._  |
| virtual std::vector&lt; size\_t &gt; | [**FindItemsNear**](#function-finditemsnear) ([**GridPosition**](classcse491_1_1_grid_position.md) pos, double dist=1.0, size\_t grid\_id=0) const<br>_Lookup IDs for all items near a given grid position._  |
|  [**AgentBase**](classcse491_1_1_agent_base.md) & | [**GetAgent**](#function-getagent) (size\_t id) <br>_Return a reference to an agent with a given ID._  |
|  size\_t | [**GetAgentID**](#function-getagentid) (const std::string & name) <br>_Return the ID of an agent with a given name._  |
|  size\_t | [**GetCellTypeID**](#function-getcelltypeid) (const std::string & name) const<br>_Return the ID associated with the cell type name._  |
|  const std::string & | [**GetCellTypeName**](#function-getcelltypename) (size\_t id) const<br> |
|  char | [**GetCellTypeSymbol**](#function-getcelltypesymbol) (size\_t id) const<br> |
|  const [**type\_options\_t**](namespacecse491.md#typedef-type_options_t) & | [**GetCellTypes**](#function-getcelltypes) () const<br> |
| virtual [**WorldGrid**](classcse491_1_1_world_grid.md) & | [**GetGrid**](#function-getgrid-14) () <br>_Return an editable version of the current grid for this world (main\_grid by default)_  |
| virtual [**WorldGrid**](classcse491_1_1_world_grid.md) & | [**GetGrid**](#function-getgrid-24) (size\_t grid\_id) <br> |
| virtual const [**WorldGrid**](classcse491_1_1_world_grid.md) & | [**GetGrid**](#function-getgrid-34) () const<br>_Return a const grid for this world (main\_grid by default)_  |
| virtual const [**WorldGrid**](classcse491_1_1_world_grid.md) & | [**GetGrid**](#function-getgrid-44) (size\_t grid\_id) const<br> |
|  [**ItemBase**](classcse491_1_1_item_base.md) & | [**GetItem**](#function-getitem) (size\_t id) <br>_Return a reference to an agent with a given ID._  |
|  size\_t | [**GetItemID**](#function-getitemid) (const std::string & name) <br>_Return the ID of an item with a given name._  |
|  size\_t | [**GetNumAgents**](#function-getnumagents) () const<br>_Get the total number of AGENT entities._  |
|  size\_t | [**GetNumItems**](#function-getnumitems) () const<br>_Get the total number of NON-agent entities._  |
|  double | [**GetRandom**](#function-getrandom-13) () <br>_Return a uniform random value between 0.0 and 1.0._  |
|  double | [**GetRandom**](#function-getrandom-23) (double max) <br>_Return a uniform random value between 0.0 and max._  |
|  double | [**GetRandom**](#function-getrandom-33) (double min, double max) <br>_Return a uniform random value between min and max._  |
|  double | [**GetRandomNormal**](#function-getrandomnormal-12) () <br>_Return a gaussian random value with mean 0.0 and sd 1.0._  |
|  double | [**GetRandomNormal**](#function-getrandomnormal-22) (double mean, double sd=1.0) <br>_Return a gaussian random value with provided mean and sd._  |
| virtual bool | [**GetRunOver**](#function-getrunover) () const<br>_Determine if the run has ended._  |
|  unsigned int | [**GetSeed**](#function-getseed) () const<br>_Get the seed used to initialize this RNG._  |
|  bool | [**HasAgent**](#function-hasagent) (size\_t id) const<br>_Does an agent with the provided ID exist?_  |
|  bool | [**HasItem**](#function-hasitem) (size\_t id) const<br>_Does an item with the provided ID exist?_  |
| virtual bool | [**IsTraversable**](#function-istraversable) (const [**AgentBase**](classcse491_1_1_agent_base.md) &, [**cse491::GridPosition**](classcse491_1_1_grid_position.md)) const<br>_Determine if this tile can be walked on, defaults to every tile is walkable._  |
|  [**WorldBase**](classcse491_1_1_world_base.md) & | [**RemoveAgent**](#function-removeagent-12) (size\_t agent\_id) <br>_Remove an agent from the agent map._  |
|  [**WorldBase**](classcse491_1_1_world_base.md) & | [**RemoveAgent**](#function-removeagent-22) (std::string agent\_name="None") <br>_Remove an agent from the agent map by name._  |
|  [**WorldBase**](classcse491_1_1_world_base.md) & | [**RemoveItem**](#function-removeitem-12) (size\_t item\_id) <br>_Remove an item from the item map._  |
|  [**WorldBase**](classcse491_1_1_world_base.md) & | [**RemoveItem**](#function-removeitem-22) (std::string item\_name) <br>_Remove an item from the item map by name._  |
| virtual void | [**Reset**](#function-reset) () <br> |
| virtual void | [**Run**](#function-run) () <br>_Run all agents repeatedly until an end condition is met._  |
| virtual void | [**RunAgents**](#function-runagents) () <br>_Step through each agent giving them a chance to take an action._  |
| virtual void | [**RunClient**](#function-runclient) (netWorth::ClientManager \* manager) <br>_Run, but for client-side._  |
| virtual void | [**RunClientAgents**](#function-runclientagents) () <br>_RunAgents, but with extra features for client-side._  |
| virtual void | [**RunServer**](#function-runserver) (netWorth::ServerManager \* manager) <br>_Run, but for server-side._  |
| virtual void | [**RunServerAgents**](#function-runserveragents) () <br>_RunAgents, but with extra features for server-side._  |
|  void | [**Serialize**](#function-serialize) (std::ostream & os) <br>_Serialize world, agents, and items into ostream._  |
|  void | [**SerializeAgentSet**](#function-serializeagentset) (std::ostream & os) <br>_Serialize agent data into an ostream._  |
|  void | [**SerializeItemSet**](#function-serializeitemset) (std::ostream & os) <br>_Serialize item data into an ostream._  |
| virtual void | [**SetWorldRunning**](#function-setworldrunning) (bool running) <br>_Set if world is running or not for concurrency purposes._  |
| virtual void | [**UpdateWorld**](#function-updateworld) () <br>[_**UpdateWorld()**_](classcse491_1_1_world_base.md#function-updateworld) _is run after every agent has a turn. Override this function to manage background events for a world._ |
|   | [**WorldBase**](#function-worldbase) (unsigned int seed=0) <br> |
| virtual  | [**~WorldBase**](#function-worldbase) () = default<br> |








## Protected Attributes

| Type | Name |
| ---: | :--- |
|  std::string | [**action**](#variable-action)  <br>_The action that the agent is currently performing._  |
|  [**agent\_map\_t**](namespacecse491.md#typedef-agent_map_t) | [**agent\_map**](#variable-agent_map)  <br>_Map of IDs to pointers to agent entities._  |
|  std::shared\_ptr&lt; DataCollection::AgentReceiver &gt; | [**agent\_receiver**](#variable-agent_receiver)  <br> |
|  std::unordered\_map&lt; size\_t, [**WorldGrid**](classcse491_1_1_world_grid.md) &gt; | [**grids**](#variable-grids)  <br>_Derived worlds may choose to have more than one grid._  |
|  [**item\_map\_t**](namespacecse491.md#typedef-item_map_t) | [**item\_map**](#variable-item_map)  <br>_Map of IDs to pointers to non-agent entities._  |
|  size\_t | [**last\_entity\_id**](#variable-last_entity_id)   = = 0<br>_The last_ [_**Entity**_](classcse491_1_1_entity.md) _ID used; increment at each creation._ |
|  [**WorldGrid**](classcse491_1_1_world_grid.md) & | [**main\_grid**](#variable-main_grid)  <br>_Main grid for this world; shortcut to_ `grids["main"]` __ |
|  std::normal\_distribution | [**norm\_dist**](#variable-norm_dist)  <br>_Normal distribution; mean 0, std 1._  |
|  std::mt19937 | [**random\_gen**](#variable-random_gen)  <br>_Random number generator._  |
|  bool | [**run\_over**](#variable-run_over)   = = false<br>_Should the run end?_  |
|  unsigned int | [**seed**](#variable-seed)  <br>_Seed used for generator._  |
|  [**type\_options\_t**](namespacecse491.md#typedef-type_options_t) | [**type\_options**](#variable-type_options)  <br>_Vector of types of cells in grids for this world._  |
|  std::uniform\_real\_distribution | [**uni\_dist**](#variable-uni_dist)  <br>_Uniform distribution of doubles, 0 to 1._  |
|  bool | [**world\_running**](#variable-world_running)   = = true<br>_Is the world currently running?_  |
















## Protected Functions

| Type | Name |
| ---: | :--- |
|  size\_t | [**AddCellType**](#function-addcelltype) (const std::string & name, const std::string & desc="", char symbol='\0') <br>_Add a new type of cell to this world._  |
| virtual void | [**ConfigAgent**](#function-configagent-22) ([**AgentBase**](classcse491_1_1_agent_base.md) &) <br> |
|  size\_t | [**NextEntityID**](#function-nextentityid) () <br>_Helper function to set the next entity id._  |




## Public Attributes Documentation




### variable client\_manager 

```C++
netWorth::ClientManager* client_manager;
```






### variable server\_manager 

```C++
netWorth::ServerManager* server_manager;
```



## Public Static Attributes Documentation




### variable npos 

```C++
constexpr size_t npos;
```



## Public Functions Documentation




### function AddAgent 

_Build a new agent of the specified type._ 
```C++
template<typename AGENT_T typename AGENT_T, typename... PROPERTY_Ts>
inline AgentBase & cse491::WorldBase::AddAgent (
    std::string agent_name="None",
    PROPERTY_Ts... properties
) 
```





**Template parameters:**


* `AGENT_T` The type of agent to build 
* `PROPERTY_Ts` Types for any properties to set at creation (automatic) 



**Parameters:**


* `agent_name` The name of this agent 
* `properties` Name/value pairs for any properties set at creation 



**Returns:**

A reference to the newly created agent 





        



### function AddConfiguredAgent 

```C++
inline AgentBase & cse491::WorldBase::AddConfiguredAgent (
    std::unique_ptr< AgentBase > agent_ptr
) 
```






### function AddItem [1/2]

_Add a new, already-built item._ 
```C++
inline ItemBase & cse491::WorldBase::AddItem (
    std::unique_ptr< ItemBase > item_ptr
) 
```





**Returns:**

A reference to the newly created item 





        



### function AddItem [2/2]

_Build a new item and add it._ 
```C++
template<typename ITEM_T typename ITEM_T, typename... PROPERTY_Ts>
inline ItemBase & cse491::WorldBase::AddItem (
    std::string item_name="None",
    PROPERTY_Ts... properties
) 
```





**Template parameters:**


* `PROPERTY_Ts` Types for any properties to set at creation (automatic) 



**Parameters:**


* `item_name` The name of this item 
* `properties` Name/value pairs for any properties set at creation 



**Returns:**

A reference to the newly created item 





        



### function AddItemToGrid 

```C++
inline WorldBase & cse491::WorldBase::AddItemToGrid (
    size_t item_id,
    GridPosition pos,
    size_t grid_id=0
) 
```






### function CollectData 

```C++
inline void cse491::WorldBase::CollectData () 
```






### function ConfigAgent [1/2]

_Client manager for world if used._ 
```C++
inline virtual void cse491::WorldBase::ConfigAgent (
    AgentBase &
) const
```



Helper function that is run whenever a new agent is created. 

**Note:**

Override this function to provide agents with actions or other setup. 





        



### function Deserialize 

_Deserialize world, agents, and items from istream._ 
```C++
inline void cse491::WorldBase::Deserialize (
    std::istream & is,
    netWorth::ClientManager * manager
) 
```





**Parameters:**


* `manager` ClientManager for ControlledAgents 




        



### function DeserializeAgentSet 

_Add deserialized agents to world with a manager._ 
```C++
inline void cse491::WorldBase::DeserializeAgentSet (
    std::istream & is,
    netWorth::ClientManager * manager
) 
```





**Parameters:**


* `is` istream 
* `manager` ClientManager which manages ControlledAgents 




        



### function DeserializeItemSet 

_Add deserialized items to world._ 
```C++
inline void cse491::WorldBase::DeserializeItemSet (
    std::istream & is
) 
```





**Parameters:**


* `istream` 




        



### function DoAction 

_Central function for an agent to take any action._ 
```C++
virtual int cse491::WorldBase::DoAction (
    AgentBase & agent,
    size_t action_id
) = 0
```





**Parameters:**


* `agent` The specific agent taking the action 
* `action` The id of the action to take 



**Returns:**

The result of this action (usually 0/1 to indicate success) 




**Note:**

Thus function must be overridden in any derived world. 





        



### function FindAgentsAt 

_Lookup IDs for all agents at a given grid position._ 
```C++
inline virtual std::vector< size_t > cse491::WorldBase::FindAgentsAt (
    GridPosition pos,
    size_t grid_id=0
) const
```





**Parameters:**


* `pos` Grid position to look up. 



**Returns:**

A vector of agent IDs at the target position. 





        



### function FindAgentsNear 

_Lookup IDs for all agents near a given grid position._ 
```C++
inline virtual std::vector< size_t > cse491::WorldBase::FindAgentsNear (
    GridPosition pos,
    double dist=1.0,
    size_t grid_id=0
) const
```





**Parameters:**


* `pos` Grid position to look up. 
* `dist` Maximum distance away from pos for an agent to be included. 



**Returns:**

A vector of agent IDs within dist of the target position. 





        



### function FindItemsAt 

_Lookup IDs for all items at a given grid position._ 
```C++
inline virtual std::vector< size_t > cse491::WorldBase::FindItemsAt (
    GridPosition pos,
    size_t grid_id=0
) const
```





**Parameters:**


* `pos` Grid position to look up. 
* `grid_id` ID of grid we are examining (default: main grid) 



**Returns:**

A vector of item IDs at the target position. 





        



### function FindItemsNear 

_Lookup IDs for all items near a given grid position._ 
```C++
inline virtual std::vector< size_t > cse491::WorldBase::FindItemsNear (
    GridPosition pos,
    double dist=1.0,
    size_t grid_id=0
) const
```





**Parameters:**


* `pos` Grid position to look up. 
* `dist` Maximum distance away from pos for an item to be included. 



**Returns:**

A vector of item IDs within dist of the target position. 





        



### function GetAgent 

```C++
inline AgentBase & cse491::WorldBase::GetAgent (
    size_t id
) 
```






### function GetAgentID 

```C++
inline size_t cse491::WorldBase::GetAgentID (
    const std::string & name
) 
```






### function GetCellTypeID 

_Return the ID associated with the cell type name._ 
```C++
inline size_t cse491::WorldBase::GetCellTypeID (
    const std::string & name
) const
```





**Parameters:**


* `name` The unique name of the cell type 



**Returns:**

The unique ID of the cell type (or 0 if it doesn't exist.) 





        



### function GetCellTypeName 

```C++
inline const std::string & cse491::WorldBase::GetCellTypeName (
    size_t id
) const
```






### function GetCellTypeSymbol 

```C++
inline char cse491::WorldBase::GetCellTypeSymbol (
    size_t id
) const
```






### function GetCellTypes 

```C++
inline const type_options_t & cse491::WorldBase::GetCellTypes () const
```






### function GetGrid [1/4]

```C++
inline virtual WorldGrid & cse491::WorldBase::GetGrid () 
```






### function GetGrid [2/4]

```C++
inline virtual WorldGrid & cse491::WorldBase::GetGrid (
    size_t grid_id
) 
```






### function GetGrid [3/4]

```C++
inline virtual const WorldGrid & cse491::WorldBase::GetGrid () const
```






### function GetGrid [4/4]

```C++
inline virtual const WorldGrid & cse491::WorldBase::GetGrid (
    size_t grid_id
) const
```






### function GetItem 

```C++
inline ItemBase & cse491::WorldBase::GetItem (
    size_t id
) 
```






### function GetItemID 

```C++
inline size_t cse491::WorldBase::GetItemID (
    const std::string & name
) 
```






### function GetNumAgents 

```C++
inline size_t cse491::WorldBase::GetNumAgents () const
```






### function GetNumItems 

```C++
inline size_t cse491::WorldBase::GetNumItems () const
```






### function GetRandom [1/3]

```C++
inline double cse491::WorldBase::GetRandom () 
```






### function GetRandom [2/3]

```C++
inline double cse491::WorldBase::GetRandom (
    double max
) 
```






### function GetRandom [3/3]

```C++
inline double cse491::WorldBase::GetRandom (
    double min,
    double max
) 
```






### function GetRandomNormal [1/2]

```C++
inline double cse491::WorldBase::GetRandomNormal () 
```






### function GetRandomNormal [2/2]

```C++
inline double cse491::WorldBase::GetRandomNormal (
    double mean,
    double sd=1.0
) 
```






### function GetRunOver 

```C++
inline virtual bool cse491::WorldBase::GetRunOver () const
```






### function GetSeed 

```C++
inline unsigned int cse491::WorldBase::GetSeed () const
```






### function HasAgent 

```C++
inline bool cse491::WorldBase::HasAgent (
    size_t id
) const
```






### function HasItem 

```C++
inline bool cse491::WorldBase::HasItem (
    size_t id
) const
```






### function IsTraversable 

_Determine if this tile can be walked on, defaults to every tile is walkable._ 
```C++
inline virtual bool cse491::WorldBase::IsTraversable (
    const AgentBase &,
    cse491::GridPosition
) const
```





**Author:**

@mdkdoc15 




**Parameters:**


* `pos` The grid position we are checking 



**Returns:**

If an agent should be allowed on this square 





        



### function RemoveAgent [1/2]

_Remove an agent from the agent map._ 
```C++
inline WorldBase & cse491::WorldBase::RemoveAgent (
    size_t agent_id
) 
```





**Parameters:**


* `agent_id` The unique ID this agent 



**Returns:**

A reference to this world. 





        



### function RemoveAgent [2/2]

_Remove an agent from the agent map by name._ 
```C++
inline WorldBase & cse491::WorldBase::RemoveAgent (
    std::string agent_name="None"
) 
```





**Parameters:**


* `agent_name` The name of this agent 



**Returns:**

This world 





        



### function RemoveItem [1/2]

_Remove an item from the item map._ 
```C++
inline WorldBase & cse491::WorldBase::RemoveItem (
    size_t item_id
) 
```





**Parameters:**


* `item_id` The unique ID this item 



**Returns:**

A reference to this world. 





        



### function RemoveItem [2/2]

_Remove an item from the item map by name._ 
```C++
inline WorldBase & cse491::WorldBase::RemoveItem (
    std::string item_name
) 
```





**Parameters:**


* `item_id` The ID of this item 



**Returns:**

This world 





        



### function Reset 

```C++
inline virtual void cse491::WorldBase::Reset () 
```






### function Run 

```C++
inline virtual void cse491::WorldBase::Run () 
```






### function RunAgents 

_Step through each agent giving them a chance to take an action._ 
```C++
inline virtual void cse491::WorldBase::RunAgents () 
```





**Note:**

Override this function if you want to control which grid the agents receive. 





        



### function RunClient 

```C++
inline virtual void cse491::WorldBase::RunClient (
    netWorth::ClientManager * manager
) 
```






### function RunClientAgents 

_RunAgents, but with extra features for client-side._ 
```C++
inline virtual void cse491::WorldBase::RunClientAgents () 
```





**Note:**

Override this function if you want to control which grid the agents receive. 





        



### function RunServer 

```C++
inline virtual void cse491::WorldBase::RunServer (
    netWorth::ServerManager * manager
) 
```






### function RunServerAgents 

_RunAgents, but with extra features for server-side._ 
```C++
inline virtual void cse491::WorldBase::RunServerAgents () 
```





**Note:**

Override this function if you want to control which grid the agents receive. 





        



### function Serialize 

_Serialize world, agents, and items into ostream._ 
```C++
inline void cse491::WorldBase::Serialize (
    std::ostream & os
) 
```





**Parameters:**


* `os` ostream 




        



### function SerializeAgentSet 

_Serialize agent data into an ostream._ 
```C++
inline void cse491::WorldBase::SerializeAgentSet (
    std::ostream & os
) 
```





**Parameters:**


* `os` ostream 




        



### function SerializeItemSet 

_Serialize item data into an ostream._ 
```C++
inline void cse491::WorldBase::SerializeItemSet (
    std::ostream & os
) 
```





**Parameters:**


* `os` ostream 




        



### function SetWorldRunning 

```C++
inline virtual void cse491::WorldBase::SetWorldRunning (
    bool running
) 
```






### function UpdateWorld 

```C++
inline virtual void cse491::WorldBase::UpdateWorld () 
```






### function WorldBase 


```C++
inline cse491::WorldBase::WorldBase (
    unsigned int seed=0
) 
```



Initializes world with cell types and random generator 

**Parameters:**


* `seed` Seed used for RNG. Use 0 for a non-deterministic result. 




        



### function ~WorldBase 

```C++
virtual cse491::WorldBase::~WorldBase () = default
```



## Protected Attributes Documentation




### variable action 

```C++
std::string action;
```






### variable agent\_map 

```C++
agent_map_t agent_map;
```






### variable agent\_receiver 

```C++
std::shared_ptr<DataCollection::AgentReceiver> agent_receiver;
```






### variable grids 

```C++
std::unordered_map<size_t, WorldGrid> grids;
```






### variable item\_map 

```C++
item_map_t item_map;
```






### variable last\_entity\_id 

```C++
size_t last_entity_id;
```






### variable main\_grid 

```C++
WorldGrid& main_grid;
```






### variable norm\_dist 

```C++
std::normal_distribution norm_dist;
```






### variable random\_gen 

```C++
std::mt19937 random_gen;
```






### variable run\_over 

```C++
bool run_over;
```






### variable seed 

```C++
unsigned int seed;
```






### variable type\_options 

```C++
type_options_t type_options;
```






### variable uni\_dist 

```C++
std::uniform_real_distribution uni_dist;
```






### variable world\_running 

```C++
bool world_running;
```



## Protected Functions Documentation




### function AddCellType 

_Add a new type of cell to this world._ 
```C++
inline size_t cse491::WorldBase::AddCellType (
    const std::string & name,
    const std::string & desc="",
    char symbol='\0'
) 
```





**Parameters:**


* `name` A unique name for this cell type 
* `desc` A longer description of the cell type 
* `symbol` An (optional) unique symbol for text IO (files, command line) 



**Returns:**

A unique ID associated with this cell type (position in type\_options vector) 





        



### function ConfigAgent [2/2]


```C++
inline virtual void cse491::WorldBase::ConfigAgent (
    AgentBase &
) 
```



Helper function that is run whenever a new agent is created. 

**Note:**

Override this function to provide agents with actions or other setup. 





        



### function NextEntityID 

```C++
inline size_t cse491::WorldBase::NextEntityID () 
```




------------------------------
The documentation for this class was generated from the following file `source/core/WorldBase.hpp`

