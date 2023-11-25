

# Class cse491::WorldBase



[**ClassList**](annotated.md) **>** [**cse491**](namespacecse491.md) **>** [**WorldBase**](classcse491_1_1_world_base.md)










































## Public Functions

| Type | Name |
| ---: | :--- |
|  [**AgentBase**](classcse491_1_1_agent_base.md) & | [**AddAgent**](#function-addagent) (std::string agent\_name="None", PROPERTY\_Ts... properties) <br>_Build a new agent of the specified type._  |
| virtual int | [**DoAction**](#function-doaction) ([**AgentBase**](classcse491_1_1_agent_base.md) & agent, size\_t action\_id) = 0<br>_Central function for an agent to take any action._  |
|  [**AgentBase**](classcse491_1_1_agent_base.md) & | [**GetAgent**](#function-getagent) (size\_t id) <br>_Return a reference to an agent with a given ID._  |
|  size\_t | [**GetCellTypeID**](#function-getcelltypeid) (const std::string & name) const<br>_Return the ID associated with the cell type name._  |
|  const std::string & | [**GetCellTypeName**](#function-getcelltypename) (size\_t id) const<br> |
|  char | [**GetCellTypeSymbol**](#function-getcelltypesymbol) (size\_t id) const<br> |
|  const [**type\_options\_t**](namespacecse491.md#typedef-type_options_t) & | [**GetCellTypes**](#function-getcelltypes) () const<br> |
| virtual [**WorldGrid**](classcse491_1_1_world_grid.md) & | [**GetGrid**](#function-getgrid-12) () <br>_Return an editable version of the current grid for this world (main\_grid by default)_  |
| virtual const [**WorldGrid**](classcse491_1_1_world_grid.md) & | [**GetGrid**](#function-getgrid-22) () const<br>_Return the current grid for this world (main\_grid by default)_  |
|  [**Entity**](classcse491_1_1_entity.md) & | [**GetItem**](#function-getitem) (size\_t id) <br>_Return a reference to an agent with a given ID._  |
|  size\_t | [**GetNumAgents**](#function-getnumagents) () const<br>_Get the total number of AGENT entities._  |
|  size\_t | [**GetNumItems**](#function-getnumitems) () const<br>_Get the total number of NON-agent entities._  |
| virtual bool | [**GetRunOver**](#function-getrunover) () const<br>_Determine if the run has ended._  |
| virtual void | [**Run**](#function-run) () <br>_Run all agents repeatedly until an end condition is met._  |
| virtual void | [**RunAgents**](#function-runagents) () <br>_Step through each agent giving them a chance to take an action._  |
| virtual void | [**UpdateWorld**](#function-updateworld) () <br>[_**UpdateWorld()**_](classcse491_1_1_world_base.md#function-updateworld) _is run after every agent has a turn. Override this function to manage background events for a world._ |
|   | [**WorldBase**](#function-worldbase) () <br> |
| virtual  | [**~WorldBase**](#function-worldbase) () = default<br> |








## Protected Attributes

| Type | Name |
| ---: | :--- |
|  [**agent\_set\_t**](namespacecse491.md#typedef-agent_set_t) | [**agent\_set**](#variable-agent_set)  <br>_Vector of pointers to agent entities._  |
|  [**item\_set\_t**](namespacecse491.md#typedef-item_set_t) | [**item\_set**](#variable-item_set)  <br>_Vector of pointers to non-agent entities._  |
|  [**WorldGrid**](classcse491_1_1_world_grid.md) | [**main\_grid**](#variable-main_grid)  <br> |
|  bool | [**run\_over**](#variable-run_over)   = = false<br>_Should the run end?_  |
|  [**type\_options\_t**](namespacecse491.md#typedef-type_options_t) | [**type\_options**](#variable-type_options)  <br>_Vector of types of cells in grids for this world._  |
















## Protected Functions

| Type | Name |
| ---: | :--- |
|  size\_t | [**AddCellType**](#function-addcelltype) (const std::string & name, const std::string & desc="", char symbol='\0') <br>_Add a new type of cell to this world._  |
| virtual void | [**ConfigAgent**](#function-configagent) ([**AgentBase**](classcse491_1_1_agent_base.md) &) <br> |




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





        



### function GetAgent 

```C++
inline AgentBase & cse491::WorldBase::GetAgent (
    size_t id
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






### function GetGrid [1/2]

```C++
inline virtual WorldGrid & cse491::WorldBase::GetGrid () 
```






### function GetGrid [2/2]

```C++
inline virtual const WorldGrid & cse491::WorldBase::GetGrid () const
```






### function GetItem 

```C++
inline Entity & cse491::WorldBase::GetItem (
    size_t id
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






### function GetRunOver 

```C++
inline virtual bool cse491::WorldBase::GetRunOver () const
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





        



### function UpdateWorld 

```C++
inline virtual void cse491::WorldBase::UpdateWorld () 
```






### function WorldBase 

```C++
inline cse491::WorldBase::WorldBase () 
```






### function ~WorldBase 

```C++
virtual cse491::WorldBase::~WorldBase () = default
```



## Protected Attributes Documentation




### variable agent\_set 

```C++
agent_set_t agent_set;
```






### variable item\_set 

```C++
item_set_t item_set;
```






### variable main\_grid 


```C++
WorldGrid main_grid;
```



This is the main grid for this world; derived worlds may choose to have more than one grid. 


        



### variable run\_over 

```C++
bool run_over;
```






### variable type\_options 

```C++
type_options_t type_options;
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





        



### function ConfigAgent 


```C++
inline virtual void cse491::WorldBase::ConfigAgent (
    AgentBase &
) 
```



Helper function that is run whenever a new agent is created. 

**Note:**

Override this function to provide agents with actions or other setup. 





        

------------------------------
The documentation for this class was generated from the following file `source/core/WorldBase.hpp`

