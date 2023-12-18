

# Class cse491::ItemBase



[**ClassList**](annotated.md) **>** [**cse491**](namespacecse491.md) **>** [**ItemBase**](classcse491_1_1_item_base.md)








Inherits the following classes: [cse491::Entity](classcse491_1_1_entity.md)










































































## Public Functions

| Type | Name |
| ---: | :--- |
| virtual void | [**Deserialize\_impl**](#function-deserialize_impl) (std::istream & is) override<br>_Deserialize item-specific values and call_ [_**Entity**_](classcse491_1_1_entity.md) _'s Deserialize\_impl._ |
|  size\_t | [**GetOwnerID**](#function-getownerid) () const<br> |
| virtual std::string | [**GetTypeName\_impl**](#function-gettypename_impl) () override const<br>_Override to allow access the derived name for this type._  |
| virtual bool | [**IsItem**](#function-isitem) () override const<br>_Is_ [_**Entity**_](classcse491_1_1_entity.md) _an item?_ |
|  bool | [**IsOnGrid**](#function-isongrid-12) () const<br> |
|  bool | [**IsOnGrid**](#function-isongrid-22) (size\_t grid\_id) const<br> |
|  bool | [**IsOwned**](#function-isowned) () const<br> |
|  bool | [**IsOwnedBy**](#function-isownedby) (size\_t entity\_id) const<br> |
|  bool | [**IsOwnedByAgent**](#function-isownedbyagent-12) () const<br> |
|  bool | [**IsOwnedByAgent**](#function-isownedbyagent-22) (size\_t agent\_id) const<br> |
|  bool | [**IsOwnedByItem**](#function-isownedbyitem-12) () const<br> |
|  bool | [**IsOwnedByItem**](#function-isownedbyitem-22) (size\_t item\_id) const<br> |
|   | [**ItemBase**](#function-itembase) (size\_t id, const std::string & name) <br> |
| virtual void | [**Serialize\_impl**](#function-serialize_impl) (std::ostream & os) override const<br>_Serialize item-specific values and call_ [_**Entity**_](classcse491_1_1_entity.md) _'s Serialize\_impl._ |
|  [**ItemBase**](classcse491_1_1_item_base.md) & | [**SetGrid**](#function-setgrid) (size\_t grid\_id=0) <br> |
|  [**ItemBase**](classcse491_1_1_item_base.md) & | [**SetOwner**](#function-setowner) (const [**Entity**](classcse491_1_1_entity.md) & owner) <br>_Identify the entity (item or agent) that now owns this item._  |
|  [**ItemBase**](classcse491_1_1_item_base.md) & | [**SetUnowned**](#function-setunowned) () <br> |
|   | [**~ItemBase**](#function-itembase) () = default<br> |


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








## Protected Types

| Type | Name |
| ---: | :--- |
| enum  | [**OwnerType**](#enum-ownertype)  <br> |


## Protected Types inherited from cse491::Entity

See [cse491::Entity](classcse491_1_1_entity.md)

| Type | Name |
| ---: | :--- |
| typedef std::unordered\_map&lt; std::string, std::unique\_ptr&lt; [**PropertyBase**](structcse491_1_1_property_base.md) &gt; &gt; | [**property\_map\_t**](#typedef-property_map_t)  <br>_Every entity can have a simple set of properties (with values) associated with it._  |










## Protected Attributes

| Type | Name |
| ---: | :--- |
|  size\_t | [**owner\_id**](#variable-owner_id)   = = 0<br> |
|  OwnerType | [**owner\_type**](#variable-owner_type)   = = OwnerType::NONE<br> |


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








## Public Functions Documentation




### function Deserialize\_impl 

_Deserialize item-specific values and call_ [_**Entity**_](classcse491_1_1_entity.md) _'s Deserialize\_impl._
```C++
inline virtual void cse491::ItemBase::Deserialize_impl (
    std::istream & is
) override
```





**Parameters:**


* `is` istream to read contents from. 




        
Implements [*cse491::Entity::Deserialize\_impl*](classcse491_1_1_entity.md#function-deserialize_impl)




### function GetOwnerID 

```C++
inline size_t cse491::ItemBase::GetOwnerID () const
```






### function GetTypeName\_impl 

_Override to allow access the derived name for this type._ 
```C++
inline virtual std::string cse491::ItemBase::GetTypeName_impl () override const
```





**Returns:**

A unique typename, ideally the exact name for this class (with scope) This member function will be helpful for serialization and debugging. It should return a fully scoped typename, such as "cse491::WorldGrid". 





        
Implements [*cse491::CoreObject::GetTypeName\_impl*](classcse491_1_1_core_object.md#function-gettypename_impl)




### function IsItem 

```C++
inline virtual bool cse491::ItemBase::IsItem () override const
```



Implements [*cse491::Entity::IsItem*](classcse491_1_1_entity.md#function-isitem)




### function IsOnGrid [1/2]

```C++
inline bool cse491::ItemBase::IsOnGrid () const
```






### function IsOnGrid [2/2]

```C++
inline bool cse491::ItemBase::IsOnGrid (
    size_t grid_id
) const
```






### function IsOwned 

```C++
inline bool cse491::ItemBase::IsOwned () const
```






### function IsOwnedBy 

```C++
inline bool cse491::ItemBase::IsOwnedBy (
    size_t entity_id
) const
```






### function IsOwnedByAgent [1/2]

```C++
inline bool cse491::ItemBase::IsOwnedByAgent () const
```






### function IsOwnedByAgent [2/2]

```C++
inline bool cse491::ItemBase::IsOwnedByAgent (
    size_t agent_id
) const
```






### function IsOwnedByItem [1/2]

```C++
inline bool cse491::ItemBase::IsOwnedByItem () const
```






### function IsOwnedByItem [2/2]

```C++
inline bool cse491::ItemBase::IsOwnedByItem (
    size_t item_id
) const
```






### function ItemBase 

```C++
inline cse491::ItemBase::ItemBase (
    size_t id,
    const std::string & name
) 
```






### function Serialize\_impl 

_Serialize item-specific values and call_ [_**Entity**_](classcse491_1_1_entity.md) _'s Serialize\_impl._
```C++
inline virtual void cse491::ItemBase::Serialize_impl (
    std::ostream & os
) override const
```





**Parameters:**


* `os` ostream to write contents to. 




        
Implements [*cse491::Entity::Serialize\_impl*](classcse491_1_1_entity.md#function-serialize_impl)




### function SetGrid 

```C++
inline ItemBase & cse491::ItemBase::SetGrid (
    size_t grid_id=0
) 
```






### function SetOwner 

_Identify the entity (item or agent) that now owns this item._ 
```C++
inline ItemBase & cse491::ItemBase::SetOwner (
    const Entity & owner
) 
```





**Parameters:**


* `owner` The new owning entity. 



**Returns:**

A reference to this item. 





        



### function SetUnowned 

```C++
inline ItemBase & cse491::ItemBase::SetUnowned () 
```






### function ~ItemBase 

```C++
cse491::ItemBase::~ItemBase () = default
```



## Protected Types Documentation




### enum OwnerType 

```C++
enum cse491::ItemBase::OwnerType {
    NONE = 0,
    GRID,
    ITEM,
    AGENT
};
```



## Protected Attributes Documentation




### variable owner\_id 

```C++
size_t owner_id;
```






### variable owner\_type 

```C++
OwnerType owner_type;
```




------------------------------
The documentation for this class was generated from the following file `source/core/ItemBase.hpp`

