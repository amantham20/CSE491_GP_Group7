

# Class cse491::Entity



[**ClassList**](annotated.md) **>** [**cse491**](namespacecse491.md) **>** [**Entity**](classcse491_1_1_entity.md)








Inherits the following classes: [cse491::CoreObject](classcse491_1_1_core_object.md)


Inherited by the following classes: [cse491::AgentBase](classcse491_1_1_agent_base.md),  [cse491::ItemBase](classcse491_1_1_item_base.md)




















































## Public Functions

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






## Protected Types

| Type | Name |
| ---: | :--- |
| typedef std::unordered\_map&lt; std::string, std::unique\_ptr&lt; [**PropertyBase**](structcse491_1_1_property_base.md) &gt; &gt; | [**property\_map\_t**](#typedef-property_map_t)  <br>_Every entity can have a simple set of properties (with values) associated with it._  |








## Protected Attributes

| Type | Name |
| ---: | :--- |
|  size\_t | [**grid\_id**](#variable-grid_id)   = = 0<br>_Which grid is this entity on?_  |
|  size\_t | [**id**](#variable-id)   = = 0<br>_Unique ID for this entity (0 is used for "no ID")_  |
|  std::vector&lt; size\_t &gt; | [**inventory**](#variable-inventory)  <br>_What entity ids are held by this entity?_  |
|  std::string | [**name**](#variable-name)   = = ""<br>_Name for this entity (E.g., "Player 1" or "+2 Sword")_  |
|  [**GridPosition**](classcse491_1_1_grid_position.md) | [**position**](#variable-position)  <br>_Where on the grid is this entity?_  |
|  [**property\_map\_t**](classcse491_1_1_entity.md#typedef-property_map_t) | [**property\_map**](#variable-property_map)  <br> |
































## Protected Functions

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






## Public Functions Documentation




### function AddItem [1/2]

```C++
Entity & cse491::Entity::AddItem (
    size_t id
) 
```






### function AddItem [2/2]

```C++
inline Entity & cse491::Entity::AddItem (
    Entity & item
) 
```






### function Deserialize\_impl 

_Serialize entity-specific values._ 
```C++
inline virtual void cse491::Entity::Deserialize_impl (
    std::istream & is
) override
```





**Parameters:**


* `os` ostream to write contents to. 




        
Implements [*cse491::CoreObject::Deserialize\_impl*](classcse491_1_1_core_object.md#function-deserialize_impl)




### function Entity [1/3]

```C++
inline cse491::Entity::Entity (
    size_t id,
    const std::string & name
) 
```






### function Entity [2/3]

```C++
cse491::Entity::Entity (
    const Entity &
) = delete
```






### function Entity [3/3]

```C++
cse491::Entity::Entity (
    Entity &&
) = default
```






### function GetGridID 

```C++
inline size_t cse491::Entity::GetGridID () const
```






### function GetID 

```C++
inline size_t cse491::Entity::GetID () const
```






### function GetInventory 

```C++
inline std::vector< size_t > cse491::Entity::GetInventory () const
```






### function GetName 

```C++
inline const std::string & cse491::Entity::GetName () const
```






### function GetNumProperties 

```C++
inline size_t cse491::Entity::GetNumProperties () const
```






### function GetPosition 

```C++
inline GridPosition cse491::Entity::GetPosition () const
```






### function GetProperty 

```C++
template<typename T typename T>
inline const T & cse491::Entity::GetProperty (
    const std::string & name
) const
```






### function GetPropertyMap 

```C++
inline property_map_t & cse491::Entity::GetPropertyMap () 
```






### function GetPropertyType 

```C++
inline PropertyType cse491::Entity::GetPropertyType (
    const std::string & name
) const
```






### function GetWorld 

```C++
inline WorldBase & cse491::Entity::GetWorld () const
```






### function HasItem 

```C++
inline bool cse491::Entity::HasItem (
    size_t id
) const
```






### function HasProperty 

```C++
inline bool cse491::Entity::HasProperty (
    const std::string & name
) const
```






### function HasWorld 

```C++
inline bool cse491::Entity::HasWorld () const
```






### function IsAgent 

```C++
inline virtual bool cse491::Entity::IsAgent () const
```






### function IsInterface 

```C++
inline virtual bool cse491::Entity::IsInterface () const
```






### function IsItem 

```C++
inline virtual bool cse491::Entity::IsItem () const
```






### function IsOnGrid 

```C++
inline bool cse491::Entity::IsOnGrid (
    size_t in_grid_id
) const
```






### function RemoveItem [1/2]

```C++
Entity & cse491::Entity::RemoveItem (
    size_t id
) 
```






### function RemoveItem [2/2]

```C++
inline Entity & cse491::Entity::RemoveItem (
    Entity & item
) 
```






### function RemoveProperty 

```C++
inline Entity & cse491::Entity::RemoveProperty (
    const std::string & name
) 
```






### function Serialize\_impl 

_Serialize entity-specific values._ 
```C++
inline virtual void cse491::Entity::Serialize_impl (
    std::ostream & os
) override const
```





**Parameters:**


* `os` ostream to write contents to. 




        
Implements [*cse491::CoreObject::Serialize\_impl*](classcse491_1_1_core_object.md#function-serialize_impl)




### function SetName 

```C++
inline Entity & cse491::Entity::SetName (
    const std::string in_name
) 
```






### function SetPosition [1/2]

```C++
Entity & cse491::Entity::SetPosition (
    GridPosition in_pos,
    size_t grid_id=0
) 
```






### function SetPosition [2/2]

```C++
inline Entity & cse491::Entity::SetPosition (
    double x,
    double y
) 
```






### function SetProperties [1/2]

```C++
inline Entity & cse491::Entity::SetProperties () 
```






### function SetProperties [2/2]

```C++
template<typename VALUE_T typename VALUE_T, typename... EXTRA_Ts>
inline Entity & cse491::Entity::SetProperties (
    const std::string & name,
    VALUE_T && value,
    EXTRA_Ts &&... extras
) 
```






### function SetProperty 

```C++
template<typename T typename T>
inline Entity & cse491::Entity::SetProperty (
    const std::string & name,
    const T & value
) 
```






### function SetWorld 

```C++
inline virtual Entity & cse491::Entity::SetWorld (
    WorldBase & in_world
) 
```






### function operator= 

```C++
Entity & cse491::Entity::operator= (
    const Entity &
) = delete
```






### function operator= 

```C++
Entity & cse491::Entity::operator= (
    Entity &&
) = delete
```






### function ~Entity 

```C++
virtual cse491::Entity::~Entity () = default
```



## Protected Types Documentation




### typedef property\_map\_t 

```C++
using property_map_t =  std::unordered_map<std::string, std::unique_ptr<PropertyBase> >;
```



## Protected Attributes Documentation




### variable grid\_id 

```C++
size_t grid_id;
```






### variable id 

```C++
size_t id;
```






### variable inventory 

```C++
std::vector<size_t> inventory;
```






### variable name 

```C++
std::string name;
```






### variable position 

```C++
GridPosition position;
```






### variable property\_map 

```C++
property_map_t property_map;
```



## Protected Functions Documentation




### function AsProperty 

```C++
template<typename T typename T>
inline Property < T > & cse491::Entity::AsProperty (
    const std::string & name
) const
```




------------------------------
The documentation for this class was generated from the following file `source/core/Entity.hpp`

