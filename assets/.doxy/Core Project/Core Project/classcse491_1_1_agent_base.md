

# Class cse491::AgentBase



[**ClassList**](annotated.md) **>** [**cse491**](namespacecse491.md) **>** [**AgentBase**](classcse491_1_1_agent_base.md)








Inherits the following classes: [cse491::Entity](classcse491_1_1_entity.md)


Inherited by the following classes: [cse491::InterfaceBase](classcse491_1_1_interface_base.md)




















































## Public Functions

| Type | Name |
| ---: | :--- |
| virtual [**AgentBase**](classcse491_1_1_agent_base.md) & | [**AddAction**](#function-addaction) (const std::string & action\_name, size\_t action\_id) <br>_Provide a new action that this agent can take._  |
|   | [**AgentBase**](#function-agentbase) (size\_t id, const std::string & name) <br> |
|  size\_t | [**GetActionID**](#function-getactionid) (const std::string & action\_name) const<br>_Return an action ID_ _if_ _that action exists, otherwise return zero._ |
|  int | [**GetActionResult**](#function-getactionresult) () const<br>_Retrieve the result of the most recent action._  |
|  bool | [**HasAction**](#function-hasaction) (const std::string & action\_name) const<br>_Test if agent already has a specified action._  |
| virtual bool | [**Initialize**](#function-initialize) () <br>_Run AFTER the world configures the agent, for additional tests or setup._  |
| virtual bool | [**IsAgent**](#function-isagent) () override const<br>_Is this_ [_**Entity**_](classcse491_1_1_entity.md) _actually an autonomous agent? (Overridden in_[_**AgentBase**_](classcse491_1_1_agent_base.md) _to return true)_ |
| virtual size\_t | [**SelectAction**](#function-selectaction) (const [**WorldGrid**](classcse491_1_1_world_grid.md) & grid, const [**type\_options\_t**](namespacecse491.md#typedef-type_options_t) & type\_options, const [**item\_set\_t**](namespacecse491.md#typedef-item_set_t) & item\_set, const [**agent\_set\_t**](namespacecse491.md#typedef-agent_set_t) & agent\_set) <br>_Decide the next action for this agent to perform; should be overridden!_  |
|  void | [**SetActionResult**](#function-setactionresult) (int result) <br>_Update the result from the most recent action._  |
|   | [**~AgentBase**](#function-agentbase) () = default<br> |


## Public Functions inherited from cse491::Entity

See [cse491::Entity](classcse491_1_1_entity.md)

| Type | Name |
| ---: | :--- |
|   | [**Entity**](#function-entity-13) (size\_t id, const std::string & name) <br> |
|   | [**Entity**](#function-entity-23) (const [**Entity**](classcse491_1_1_entity.md) &) = delete<br> |
|   | [**Entity**](#function-entity-33) ([**Entity**](classcse491_1_1_entity.md) &&) = default<br> |
|  size\_t | [**GetID**](#function-getid) () const<br> |
|  const std::string & | [**GetName**](#function-getname) () const<br> |
|  [**GridPosition**](classcse491_1_1_grid_position.md) | [**GetPosition**](#function-getposition) () const<br> |
|  const T & | [**GetProperty**](#function-getproperty) (const std::string & name) const<br>_Return the current value of the specified property._  |
|  bool | [**HasProperty**](#function-hasproperty) (const std::string & name) const<br>_Does this agent have a property with the specified name?_  |
| virtual bool | [**IsAgent**](#function-isagent) () const<br>_Is this_ [_**Entity**_](classcse491_1_1_entity.md) _actually an autonomous agent? (Overridden in_[_**AgentBase**_](classcse491_1_1_agent_base.md) _to return true)_ |
| virtual bool | [**IsInterface**](#function-isinterface) () const<br> |
|  [**Entity**](classcse491_1_1_entity.md) & | [**RemoveProperty**](#function-removeproperty) (const std::string & name) <br>_Completely remove a property from an_ [_**Entity**_](classcse491_1_1_entity.md) _._ |
|  [**Entity**](classcse491_1_1_entity.md) & | [**SetName**](#function-setname) (const std::string in\_name) <br> |
|  [**Entity**](classcse491_1_1_entity.md) & | [**SetPosition**](#function-setposition-12) ([**GridPosition**](classcse491_1_1_grid_position.md) in\_pos) <br> |
|  [**Entity**](classcse491_1_1_entity.md) & | [**SetPosition**](#function-setposition-22) (double x, double y) <br> |
|  [**Entity**](classcse491_1_1_entity.md) & | [**SetProperties**](#function-setproperties-12) () <br>_Allow for setting multiple properties at once._  |
|  [**Entity**](classcse491_1_1_entity.md) & | [**SetProperties**](#function-setproperties-22) (const std::string & name, VALUE\_T && value, EXTRA\_Ts &&... extras) <br> |
|  [**Entity**](classcse491_1_1_entity.md) & | [**SetProperty**](#function-setproperty) (const std::string & name, const T & value) <br>_Change the value of the specified property (will create if needed)_  |
|  [**Entity**](classcse491_1_1_entity.md) & | [**operator=**](#function-operator) (const [**Entity**](classcse491_1_1_entity.md) &) = delete<br> |
|  [**Entity**](classcse491_1_1_entity.md) & | [**operator=**](#function-operator_1) ([**Entity**](classcse491_1_1_entity.md) &&) = delete<br> |
| virtual  | [**~Entity**](#function-entity) () = default<br> |














## Protected Attributes

| Type | Name |
| ---: | :--- |
|  std::unordered\_map&lt; std::string, size\_t &gt; | [**action\_map**](#variable-action_map)  <br>_A map of names to IDs for each available action._  |
|  int | [**action\_result**](#variable-action_result)   = =1<br>_Usually a one (success) or zero (failure)._  |


## Protected Attributes inherited from cse491::Entity

See [cse491::Entity](classcse491_1_1_entity.md)

| Type | Name |
| ---: | :--- |
|  const size\_t | [**id**](#variable-id)  <br>_Unique ID for this entity._  |
|  std::string | [**name**](#variable-name)  <br>_Name for this entity (E.g., "Player 1" or "+2 Sword")_  |
|  [**GridPosition**](classcse491_1_1_grid_position.md) | [**position**](#variable-position)  <br>_Where on the grid is this entity?_  |
|  std::unordered\_map&lt; std::string, std::unique\_ptr&lt; [**PropertyBase**](structcse491_1_1_entity_1_1_property_base.md) &gt; &gt; | [**property\_map**](#variable-property_map)  <br>_Every entity can have a simple set of properties (with values) associated with it._  |
































## Protected Functions inherited from cse491::Entity

See [cse491::Entity](classcse491_1_1_entity.md)

| Type | Name |
| ---: | :--- |
|  [**Property**](structcse491_1_1_entity_1_1_property.md)&lt; T &gt; & | [**AsProperty**](#function-asproperty) (const std::string & name) const<br> |






## Public Functions Documentation




### function AddAction 

```C++
inline virtual AgentBase & cse491::AgentBase::AddAction (
    const std::string & action_name,
    size_t action_id
) 
```






### function AgentBase 

```C++
inline cse491::AgentBase::AgentBase (
    size_t id,
    const std::string & name
) 
```






### function GetActionID 

```C++
inline size_t cse491::AgentBase::GetActionID (
    const std::string & action_name
) const
```






### function GetActionResult 

```C++
inline int cse491::AgentBase::GetActionResult () const
```






### function HasAction 

```C++
inline bool cse491::AgentBase::HasAction (
    const std::string & action_name
) const
```






### function Initialize 

_Run AFTER the world configures the agent, for additional tests or setup._ 
```C++
inline virtual bool cse491::AgentBase::Initialize () 
```





**Returns:**

Was the initialization successful? 





        



### function IsAgent 

```C++
inline virtual bool cse491::AgentBase::IsAgent () override const
```



Implements [*cse491::Entity::IsAgent*](classcse491_1_1_entity.md#function-isagent)




### function SelectAction 

_Decide the next action for this agent to perform; should be overridden!_ 
```C++
inline virtual size_t cse491::AgentBase::SelectAction (
    const WorldGrid & grid,
    const type_options_t & type_options,
    const item_set_t & item_set,
    const agent_set_t & agent_set
) 
```





**Parameters:**


* `grid` The agent is provided with the current [**WorldGrid**](classcse491_1_1_world_grid.md) 



**Returns:**

ID associated with the action to perform; (zero is always "no action") 





        



### function SetActionResult 

```C++
inline void cse491::AgentBase::SetActionResult (
    int result
) 
```






### function ~AgentBase 

```C++
cse491::AgentBase::~AgentBase () = default
```



## Protected Attributes Documentation




### variable action\_map 

```C++
std::unordered_map<std::string, size_t> action_map;
```






### variable action\_result 

```C++
int action_result;
```




------------------------------
The documentation for this class was generated from the following file `source/core/AgentBase.hpp`

