

# Class cse491::InterfaceBase



[**ClassList**](annotated.md) **>** [**cse491**](namespacecse491.md) **>** [**InterfaceBase**](classcse491_1_1_interface_base.md)








Inherits the following classes: [cse491::AgentBase](classcse491_1_1_agent_base.md)






























































































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**InterfaceBase**](#function-interfacebase) (size\_t id, const std::string & name) <br> |
| virtual bool | [**IsInterface**](#function-isinterface) () override const<br>_Is_ [_**Entity**_](classcse491_1_1_entity.md) _an interface for a human?_ |
|   | [**~InterfaceBase**](#function-interfacebase) () = default<br> |


## Public Functions inherited from cse491::AgentBase

See [cse491::AgentBase](classcse491_1_1_agent_base.md)

| Type | Name |
| ---: | :--- |
| virtual [**AgentBase**](classcse491_1_1_agent_base.md) & | [**AddAction**](#function-addaction) (const std::string & action\_name, size\_t action\_id) <br>_Provide a new action that this agent can take._  |
|   | [**AgentBase**](#function-agentbase) (size\_t id, const std::string & name) <br>_Default value upon initialization._  |
| virtual void | [**Deserialize\_impl**](#function-deserialize_impl) (std::istream & is) override<br>_Deserialize item-specific values and call_ [_**Entity**_](classcse491_1_1_entity.md) _'s Deserialize\_impl._ |
|  size\_t | [**GetActionID**](#function-getactionid) (const std::string & action\_name) const<br>_Return an action ID_ _if_ _that action exists, otherwise return zero._ |
|  int | [**GetActionResult**](#function-getactionresult) () const<br>_Retrieve the result of the most recent action._  |
|  [**State**](namespacecse491.md#enum-state) | [**GetAgentState**](#function-getagentstate) () <br>_Get the current state of the Agent._  |
| virtual [**GridPosition**](classcse491_1_1_grid_position.md) | [**GetNextPosition**](#function-getnextposition) () <br>_Allow derived agents to provide an arbitrary next position for the world to move the agent to._  |
| virtual std::string | [**GetTypeName\_impl**](#function-gettypename_impl) () override const<br>_Override to allow access the derived name for this type._  |
|  bool | [**HasAction**](#function-hasaction) (const std::string & action\_name) const<br>_Test if agent already has a specified action._  |
| virtual bool | [**Initialize**](#function-initialize) () <br>_Run AFTER the world configures the agent, for additional tests or setup._  |
| virtual bool | [**IsAgent**](#function-isagent) () override const<br>_Is_ [_**Entity**_](classcse491_1_1_entity.md) _an autonomous agent?_ |
| virtual void | [**Notify**](#function-notify) (const std::string &, const std::string &="none") <br>_Send a notification to this agent, typically from the world._  |
| virtual size\_t | [**SelectAction**](#function-selectaction) (const [**WorldGrid**](classcse491_1_1_world_grid.md) & grid, const [**type\_options\_t**](namespacecse491.md#typedef-type_options_t) & type\_options, const [**item\_map\_t**](namespacecse491.md#typedef-item_map_t) & item\_map, const [**agent\_map\_t**](namespacecse491.md#typedef-agent_map_t) & agent\_map) <br>_Decide the next action for this agent to perform; should be overridden!_  |
| virtual void | [**Serialize\_impl**](#function-serialize_impl) (std::ostream & os) override const<br>_Serialize item-specific values and call_ [_**Entity**_](classcse491_1_1_entity.md) _'s Serialize\_impl._ |
|  void | [**SetActionResult**](#function-setactionresult) (int result) <br>_Update the result from the most recent action._  |
|  void | [**TakeDamage**](#function-takedamage) ([**cse491::AgentBase**](classcse491_1_1_agent_base.md) & agent) <br>_If the agent is in State::Taking\_Damage, decrease the health by the damage factor once per timestep._  |
|  void | [**UpdateAgentState**](#function-updateagentstate) ([**cse491::AgentBase**](classcse491_1_1_agent_base.md) & agent) <br>_Updates an Agent's state depending on health._  |
|  void | [**storeActionMap**](#function-storeactionmap) (std::string name) <br> |
|   | [**~AgentBase**](#function-agentbase) () = default<br> |


## Public Functions inherited from cse491::Entity

See [cse491::Entity](classcse491_1_1_entity.md)

| Type | Name |
| ---: | :--- |
|  [**Entity**](classcse491_1_1_entity.md) & | [**AddItem**](#function-additem-12) (size\_t id) <br> |
|  [**Entity**](classcse491_1_1_entity.md) & | [**AddItem**](#function-additem-22) ([**Entity**](classcse491_1_1_entity.md) & item) <br> |
| virtual void | [**Deserialize\_impl**](#function-deserialize_impl) (std::istream & is) override<br>_Serialize entity-specific values._  |
|   | [**Entity**](#function-entity-13) (size\_t id, const std::string & name) <br> |
|   | [**Entity**](#function-entity-23) (const [**Entity**](classcse491_1_1_entity.md) &) = delete<br> |
|   | [**Entity**](#function-entity-33) ([**Entity**](classcse491_1_1_entity.md) &&) = default<br> |
|  size\_t | [**GetGridID**](#function-getgridid) () const<br> |
|  size\_t | [**GetID**](#function-getid) () const<br> |
|  std::vector&lt; size\_t &gt; | [**GetInventory**](#function-getinventory) () const<br> |
|  const std::string & | [**GetName**](#function-getname) () const<br> |
|  size\_t | [**GetNumProperties**](#function-getnumproperties) () const<br>_How many properties does this entity have?_  |
|  [**GridPosition**](classcse491_1_1_grid_position.md) | [**GetPosition**](#function-getposition) () const<br> |
|  const T & | [**GetProperty**](#function-getproperty) (const std::string & name) const<br>_Return the current value of the specified property._  |
|  [**property\_map\_t**](classcse491_1_1_entity.md#typedef-property_map_t) & | [**GetPropertyMap**](#function-getpropertymap) () <br>_return the property map for the entity_  |
|  [**PropertyType**](namespacecse491.md#enum-propertytype) | [**GetPropertyType**](#function-getpropertytype) (const std::string & name) const<br> |
|  [**WorldBase**](classcse491_1_1_world_base.md) & | [**GetWorld**](#function-getworld) () const<br> |
|  bool | [**HasItem**](#function-hasitem) (size\_t id) const<br>_Inventory Management._  |
|  bool | [**HasProperty**](#function-hasproperty) (const std::string & name) const<br>_Does this agent have a property with the specified name?_  |
|  bool | [**HasWorld**](#function-hasworld) () const<br> |
| virtual bool | [**IsAgent**](#function-isagent) () const<br>_Is_ [_**Entity**_](classcse491_1_1_entity.md) _an autonomous agent?_ |
| virtual bool | [**IsInterface**](#function-isinterface) () const<br>_Is_ [_**Entity**_](classcse491_1_1_entity.md) _an interface for a human?_ |
| virtual bool | [**IsItem**](#function-isitem) () const<br>_Is_ [_**Entity**_](classcse491_1_1_entity.md) _an item?_ |
|  bool | [**IsOnGrid**](#function-isongrid) (size\_t in\_grid\_id) const<br> |
|  [**Entity**](classcse491_1_1_entity.md) & | [**RemoveItem**](#function-removeitem-12) (size\_t id) <br> |
|  [**Entity**](classcse491_1_1_entity.md) & | [**RemoveItem**](#function-removeitem-22) ([**Entity**](classcse491_1_1_entity.md) & item) <br> |
|  [**Entity**](classcse491_1_1_entity.md) & | [**RemoveProperty**](#function-removeproperty) (const std::string & name) <br>_Completely remove a property from an_ [_**Entity**_](classcse491_1_1_entity.md) _._ |
| virtual void | [**Serialize\_impl**](#function-serialize_impl) (std::ostream & os) override const<br>_Serialize entity-specific values._  |
|  [**Entity**](classcse491_1_1_entity.md) & | [**SetName**](#function-setname) (const std::string in\_name) <br> |
|  [**Entity**](classcse491_1_1_entity.md) & | [**SetPosition**](#function-setposition-12) ([**GridPosition**](classcse491_1_1_grid_position.md) in\_pos, size\_t grid\_id=0) <br> |
|  [**Entity**](classcse491_1_1_entity.md) & | [**SetPosition**](#function-setposition-22) (double x, double y) <br> |
|  [**Entity**](classcse491_1_1_entity.md) & | [**SetProperties**](#function-setproperties-12) () <br>_Allow for setting multiple properties at once._  |
|  [**Entity**](classcse491_1_1_entity.md) & | [**SetProperties**](#function-setproperties-22) (const std::string & name, VALUE\_T && value, EXTRA\_Ts &&... extras) <br> |
|  [**Entity**](classcse491_1_1_entity.md) & | [**SetProperty**](#function-setproperty) (const std::string & name, const T & value) <br>_Change the value of the specified property (will create if needed)_  |
| virtual [**Entity**](classcse491_1_1_entity.md) & | [**SetWorld**](#function-setworld) ([**WorldBase**](classcse491_1_1_world_base.md) & in\_world) <br> |
|  [**Entity**](classcse491_1_1_entity.md) & | [**operator=**](#function-operator) (const [**Entity**](classcse491_1_1_entity.md) &) = delete<br> |
|  [**Entity**](classcse491_1_1_entity.md) & | [**operator=**](#function-operator_1) ([**Entity**](classcse491_1_1_entity.md) &&) = delete<br> |
| virtual  | [**~Entity**](#function-entity) () = default<br> |


## Public Functions inherited from cse491::CoreObject

See [cse491::CoreObject](classcse491_1_1_core_object.md)

| Type | Name |
| ---: | :--- |
|  void | [**Deserialize**](#function-deserialize-12) (std::istream & is) <br>_Restore the state of this object, extracting it from the provided stream._  |
|  bool | [**Deserialize**](#function-deserialize-22) (std::string filename) <br>_A version of Deserialize that accepts a filename to read this object from._  |
|  std::string | [**GetTypeName**](#function-gettypename) () const<br>_Access the derived name for this type._  |
|  void | [**Serialize**](#function-serialize-12) (std::ostream & os) const<br>_Store the current state of this object for later extraction._  |
|  bool | [**Serialize**](#function-serialize-22) (std::string filename) const<br>_A version of Serialize that accepts a filename for saving just this object._  |
|  auto | [**operator&lt;=&gt;**](#function-operator<>) (const [**CoreObject**](classcse491_1_1_core_object.md) &) const<br> |
| virtual  | [**~CoreObject**](#function-coreobject) () <br> |














## Protected Types inherited from cse491::Entity

See [cse491::Entity](classcse491_1_1_entity.md)

| Type | Name |
| ---: | :--- |
| typedef std::unordered\_map&lt; std::string, std::unique\_ptr&lt; [**PropertyBase**](structcse491_1_1_property_base.md) &gt; &gt; | [**property\_map\_t**](#typedef-property_map_t)  <br>_Every entity can have a simple set of properties (with values) associated with it._  |














## Protected Attributes inherited from cse491::AgentBase

See [cse491::AgentBase](classcse491_1_1_agent_base.md)

| Type | Name |
| ---: | :--- |
|  int | [**action**](#variable-action)  <br>_Action that agent is currently performing._  |
|  std::unordered\_map&lt; std::string, size\_t &gt; | [**action\_map**](#variable-action_map)  <br>_Map of names to action ids._  |
|  int | [**action\_result**](#variable-action_result)   = = 0<br>_Usually a one (success) or zero (failure)._  |
|  [**State**](namespacecse491.md#enum-state) | [**agent\_state**](#variable-agent_state)   = = Healthy<br> |


## Protected Attributes inherited from cse491::Entity

See [cse491::Entity](classcse491_1_1_entity.md)

| Type | Name |
| ---: | :--- |
|  size\_t | [**grid\_id**](#variable-grid_id)   = = 0<br>_Which grid is this entity on?_  |
|  size\_t | [**id**](#variable-id)   = = 0<br>_Unique ID for this entity (0 is used for "no ID")_  |
|  std::vector&lt; size\_t &gt; | [**inventory**](#variable-inventory)  <br>_What entity ids are held by this entity?_  |
|  std::string | [**name**](#variable-name)   = = ""<br>_Name for this entity (E.g., "Player 1" or "+2 Sword")_  |
|  [**GridPosition**](classcse491_1_1_grid_position.md) | [**position**](#variable-position)  <br>_Where on the grid is this entity?_  |
|  [**property\_map\_t**](classcse491_1_1_entity.md#typedef-property_map_t) | [**property\_map**](#variable-property_map)  <br> |
































































## Protected Functions inherited from cse491::Entity

See [cse491::Entity](classcse491_1_1_entity.md)

| Type | Name |
| ---: | :--- |
|  [**Property**](structcse491_1_1_property.md)&lt; T &gt; & | [**AsProperty**](#function-asproperty) (const std::string & name) const<br> |


## Protected Functions inherited from cse491::CoreObject

See [cse491::CoreObject](classcse491_1_1_core_object.md)

| Type | Name |
| ---: | :--- |
| virtual void | [**Deserialize\_impl**](#function-deserialize_impl) (std::istream &) = 0<br>_Override to restore the state of this object from the provided stream._  |
|  bool | [**EndDeserialize**](#function-enddeserialize) (std::istream & is) <br>_Set up end of the deserialization for this class (does type checking)_  |
|  void | [**EndSerialize**](#function-endserialize) (std::ostream & os) const<br>_Set up end of the serialization for this class (allows checking later)_  |
| virtual std::string | [**GetTypeName\_impl**](#function-gettypename_impl) () const = 0<br>_Override to allow access the derived name for this type._  |
| virtual void | [**Serialize\_impl**](#function-serialize_impl) (std::ostream &) const = 0<br>_Override to store the current state of this object for later extraction._  |
|  bool | [**StartDeserialize**](#function-startdeserialize) (std::istream & is) <br>_Set up beginning of the deserialization for this class (does type checking)_  |
|  void | [**StartSerialize**](#function-startserialize) (std::ostream & os) const<br>_Set up beginning of the serialization for this class (allows checking later)_  |


## Protected Static Functions

| Type | Name |
| ---: | :--- |
|  void | [**exitCleanup**](#function-exitcleanup) () <br> |








## Public Functions Documentation




### function InterfaceBase 

```C++
inline cse491::InterfaceBase::InterfaceBase (
    size_t id,
    const std::string & name
) 
```






### function IsInterface 

```C++
inline virtual bool cse491::InterfaceBase::IsInterface () override const
```



Implements [*cse491::Entity::IsInterface*](classcse491_1_1_entity.md#function-isinterface)




### function ~InterfaceBase 

```C++
cse491::InterfaceBase::~InterfaceBase () = default
```



## Protected Static Functions Documentation




### function exitCleanup 

```C++
static inline void cse491::InterfaceBase::exitCleanup () 
```




------------------------------
The documentation for this class was generated from the following file `source/core/InterfaceBase.hpp`

