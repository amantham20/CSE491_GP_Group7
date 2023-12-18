

# Struct cse491::PropertyBase



[**ClassList**](annotated.md) **>** [**cse491**](namespacecse491.md) **>** [**PropertyBase**](structcse491_1_1_property_base.md)








Inherits the following classes: [cse491::CoreObject](classcse491_1_1_core_object.md)


Inherited by the following classes: [cse491::Property](structcse491_1_1_property.md)




















































## Public Functions

| Type | Name |
| ---: | :--- |
| virtual [**PropertyType**](namespacecse491.md#enum-propertytype) | [**GetType**](#function-gettype) () const = 0<br> |
| virtual std::string | [**GetTypeName**](#function-gettypename) () const = 0<br> |
| virtual char | [**ToChar**](#function-tochar) () const = 0<br> |
| virtual double | [**ToDouble**](#function-todouble) () const = 0<br> |
| virtual [**GridPosition**](classcse491_1_1_grid_position.md) | [**ToGridPosition**](#function-togridposition) () const = 0<br> |
| virtual int | [**ToInt**](#function-toint) () const = 0<br> |
| virtual std::string | [**ToString**](#function-tostring) () const = 0<br> |
| virtual  | [**~PropertyBase**](#function-propertybase) () <br> |


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




### function GetType 

```C++
virtual PropertyType cse491::PropertyBase::GetType () const = 0
```






### function GetTypeName 

```C++
virtual std::string cse491::PropertyBase::GetTypeName () const = 0
```






### function ToChar 

```C++
virtual char cse491::PropertyBase::ToChar () const = 0
```






### function ToDouble 

```C++
virtual double cse491::PropertyBase::ToDouble () const = 0
```






### function ToGridPosition 

```C++
virtual GridPosition cse491::PropertyBase::ToGridPosition () const = 0
```






### function ToInt 

```C++
virtual int cse491::PropertyBase::ToInt () const = 0
```






### function ToString 

```C++
virtual std::string cse491::PropertyBase::ToString () const = 0
```






### function ~PropertyBase 

```C++
inline virtual cse491::PropertyBase::~PropertyBase () 
```




------------------------------
The documentation for this class was generated from the following file `source/core/Property.hpp`

