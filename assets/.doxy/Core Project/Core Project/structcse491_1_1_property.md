

# Struct cse491::Property

**template &lt;typename T typename T&gt;**



[**ClassList**](annotated.md) **>** [**cse491**](namespacecse491.md) **>** [**Property**](structcse491_1_1_property.md)








Inherits the following classes: [cse491::PropertyBase](structcse491_1_1_property_base.md)


























## Public Attributes

| Type | Name |
| ---: | :--- |
|  T | [**value**](#variable-value)  <br> |
















































## Public Functions

| Type | Name |
| ---: | :--- |
| virtual void | [**Deserialize\_impl**](#function-deserialize_impl) (std::istream &) override<br>_Override to restore the state of this object from the provided stream._  |
| virtual [**PropertyType**](namespacecse491.md#enum-propertytype) | [**GetType**](#function-gettype) () override const<br> |
| virtual std::string | [**GetTypeName**](#function-gettypename) () override const<br> |
| virtual std::string | [**GetTypeName\_impl**](#function-gettypename_impl) () override const<br>_Override to allow access the derived name for this type._  |
|   | [**Property**](#function-property-12) (const T & in) <br> |
|   | [**Property**](#function-property-22) (T && in) <br> |
| virtual void | [**Serialize\_impl**](#function-serialize_impl) (std::ostream &) override const<br>_Override to store the current state of this object for later extraction._  |
| virtual char | [**ToChar**](#function-tochar) () override const<br> |
| virtual double | [**ToDouble**](#function-todouble) () override const<br> |
| virtual [**GridPosition**](classcse491_1_1_grid_position.md) | [**ToGridPosition**](#function-togridposition) () override const<br> |
| virtual int | [**ToInt**](#function-toint) () override const<br> |
| virtual std::string | [**ToString**](#function-tostring) () override const<br> |


## Public Functions inherited from cse491::PropertyBase

See [cse491::PropertyBase](structcse491_1_1_property_base.md)

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








## Public Attributes Documentation




### variable value 

```C++
T value;
```



## Public Functions Documentation




### function Deserialize\_impl 

_Override to restore the state of this object from the provided stream._ 
```C++
inline virtual void cse491::Property::Deserialize_impl (
    std::istream &
) override
```





**Parameters:**


* `input_stream` The istream with full details about this object. 




        
Implements [*cse491::CoreObject::Deserialize\_impl*](classcse491_1_1_core_object.md#function-deserialize_impl)




### function GetType 

```C++
inline virtual PropertyType cse491::Property::GetType () override const
```



Implements [*cse491::PropertyBase::GetType*](structcse491_1_1_property_base.md#function-gettype)




### function GetTypeName 

```C++
inline virtual std::string cse491::Property::GetTypeName () override const
```



Implements [*cse491::PropertyBase::GetTypeName*](structcse491_1_1_property_base.md#function-gettypename)




### function GetTypeName\_impl 

_Override to allow access the derived name for this type._ 
```C++
inline virtual std::string cse491::Property::GetTypeName_impl () override const
```





**Returns:**

A unique typename, ideally the exact name for this class (with scope) This member function will be helpful for serialization and debugging. It should return a fully scoped typename, such as "cse491::WorldGrid". 





        
Implements [*cse491::CoreObject::GetTypeName\_impl*](classcse491_1_1_core_object.md#function-gettypename_impl)




### function Property [1/2]

```C++
inline cse491::Property::Property (
    const T & in
) 
```






### function Property [2/2]

```C++
inline cse491::Property::Property (
    T && in
) 
```






### function Serialize\_impl 

_Override to store the current state of this object for later extraction._ 
```C++
inline virtual void cse491::Property::Serialize_impl (
    std::ostream &
) override const
```





**Parameters:**


* `output_stream` An ostream that the required information should be stored in. 




        
Implements [*cse491::CoreObject::Serialize\_impl*](classcse491_1_1_core_object.md#function-serialize_impl)




### function ToChar 

```C++
inline virtual char cse491::Property::ToChar () override const
```



Implements [*cse491::PropertyBase::ToChar*](structcse491_1_1_property_base.md#function-tochar)




### function ToDouble 

```C++
inline virtual double cse491::Property::ToDouble () override const
```



Implements [*cse491::PropertyBase::ToDouble*](structcse491_1_1_property_base.md#function-todouble)




### function ToGridPosition 

```C++
inline virtual GridPosition cse491::Property::ToGridPosition () override const
```



Implements [*cse491::PropertyBase::ToGridPosition*](structcse491_1_1_property_base.md#function-togridposition)




### function ToInt 

```C++
inline virtual int cse491::Property::ToInt () override const
```



Implements [*cse491::PropertyBase::ToInt*](structcse491_1_1_property_base.md#function-toint)




### function ToString 

```C++
inline virtual std::string cse491::Property::ToString () override const
```



Implements [*cse491::PropertyBase::ToString*](structcse491_1_1_property_base.md#function-tostring)


------------------------------
The documentation for this class was generated from the following file `source/core/Property.hpp`

