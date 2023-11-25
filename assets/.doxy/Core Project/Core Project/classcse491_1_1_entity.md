

# Class cse491::Entity



[**ClassList**](annotated.md) **>** [**cse491**](namespacecse491.md) **>** [**Entity**](classcse491_1_1_entity.md)










Inherited by the following classes: [cse491::AgentBase](classcse491_1_1_agent_base.md)
































## Public Functions

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
|  const size\_t | [**id**](#variable-id)  <br>_Unique ID for this entity._  |
|  std::string | [**name**](#variable-name)  <br>_Name for this entity (E.g., "Player 1" or "+2 Sword")_  |
|  [**GridPosition**](classcse491_1_1_grid_position.md) | [**position**](#variable-position)  <br>_Where on the grid is this entity?_  |
|  std::unordered\_map&lt; std::string, std::unique\_ptr&lt; [**PropertyBase**](structcse491_1_1_entity_1_1_property_base.md) &gt; &gt; | [**property\_map**](#variable-property_map)  <br>_Every entity can have a simple set of properties (with values) associated with it._  |
















## Protected Functions

| Type | Name |
| ---: | :--- |
|  [**Property**](structcse491_1_1_entity_1_1_property.md)&lt; T &gt; & | [**AsProperty**](#function-asproperty) (const std::string & name) const<br> |




## Public Functions Documentation




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






### function GetID 

```C++
inline size_t cse491::Entity::GetID () const
```






### function GetName 

```C++
inline const std::string & cse491::Entity::GetName () const
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






### function HasProperty 

```C++
inline bool cse491::Entity::HasProperty (
    const std::string & name
) const
```






### function IsAgent 

```C++
inline virtual bool cse491::Entity::IsAgent () const
```






### function IsInterface 


```C++
inline virtual bool cse491::Entity::IsInterface () const
```



Is this [**Entity**](classcse491_1_1_entity.md) actually a specialty Agent that's an Interface for a human player? (Overridden in [**InterfaceBase**](classcse491_1_1_interface_base.md) to return true) 


        



### function RemoveProperty 

```C++
inline Entity & cse491::Entity::RemoveProperty (
    const std::string & name
) 
```






### function SetName 

```C++
inline Entity & cse491::Entity::SetName (
    const std::string in_name
) 
```






### function SetPosition [1/2]

```C++
inline Entity & cse491::Entity::SetPosition (
    GridPosition in_pos
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



## Protected Attributes Documentation




### variable id 

```C++
const size_t id;
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
std::unordered_map<std::string, std::unique_ptr<PropertyBase> > property_map;
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

