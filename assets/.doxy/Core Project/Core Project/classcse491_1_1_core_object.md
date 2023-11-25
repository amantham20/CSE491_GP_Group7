

# Class cse491::CoreObject



[**ClassList**](annotated.md) **>** [**cse491**](namespacecse491.md) **>** [**CoreObject**](classcse491_1_1_core_object.md)










Inherited by the following classes: [cse491::WorldGrid](classcse491_1_1_world_grid.md)
































## Public Functions

| Type | Name |
| ---: | :--- |
|  void | [**Deserialize**](#function-deserialize-12) (std::istream & is) <br>_Restore the state of this object, extracting it from the provided stream._  |
|  bool | [**Deserialize**](#function-deserialize-22) (std::string filename) <br>_A version of Deserialize that accepts a filename to read this object from._  |
|  std::string | [**GetTypeName**](#function-gettypename) () const<br>_Access the derived name for this type._  |
|  void | [**Serialize**](#function-serialize-12) (std::ostream & os) const<br>_Store the current state of this object for later extraction._  |
|  bool | [**Serialize**](#function-serialize-22) (std::string filename) const<br>_A version of Serialize that accepts a filename for saving just this object._  |
| virtual  | [**~CoreObject**](#function-coreobject) () <br> |
























## Protected Functions

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




### function Deserialize [1/2]

_Restore the state of this object, extracting it from the provided stream._ 
```C++
inline void cse491::CoreObject::Deserialize (
    std::istream & is
) 
```





**Parameters:**


* `input_stream` The istream with full details about this object. This function takes in an istream that was previously written using the paired [**Serialize()**](classcse491_1_1_core_object.md#function-serialize-12) function and restores the associated class. It should stop loading when all data is finished; this may be signalled by the ":::END" directive. The stream should end ready for the next extraction. 




        



### function Deserialize [2/2]

_A version of Deserialize that accepts a filename to read this object from._ 
```C++
inline bool cse491::CoreObject::Deserialize (
    std::string filename
) 
```





**Parameters:**


* `filename` The name of the file to open to load this object from. 



**Returns:**

Success (true/false) 





        



### function GetTypeName 

_Access the derived name for this type._ 
```C++
inline std::string cse491::CoreObject::GetTypeName () const
```





**Returns:**

A unique typename, ideally the exact name for this class (with scope) This member function will be helpful for serialization and debugging. It should return a fully scoped typename, such as "cse491::WorldGrid". 





        



### function Serialize [1/2]

_Store the current state of this object for later extraction._ 
```C++
inline void cse491::CoreObject::Serialize (
    std::ostream & os
) const
```





**Parameters:**


* `output_stream` An ostream that the required information should be stored in. A derived class is required to store all information about itself in [**Serialize()**](classcse491_1_1_core_object.md#function-serialize-12) and clearly note the end of storage to simplify de-serializing the data. This function will automatic add a start line that reads ":::START" followed by the typename, and an end line with ":::END" followed by the typename again. 




        



### function Serialize [2/2]

_A version of Serialize that accepts a filename for saving just this object._ 
```C++
inline bool cse491::CoreObject::Serialize (
    std::string filename
) const
```





**Parameters:**


* `filename` The name of the file to create for storing this object. 



**Returns:**

Success (true/false) 





        



### function ~CoreObject 

```C++
inline virtual cse491::CoreObject::~CoreObject () 
```



## Protected Functions Documentation




### function Deserialize\_impl 

_Override to restore the state of this object from the provided stream._ 
```C++
virtual void cse491::CoreObject::Deserialize_impl (
    std::istream &
) = 0
```





**Parameters:**


* `input_stream` The istream with full details about this object. 




        



### function EndDeserialize 

_Set up end of the deserialization for this class (does type checking)_ 
```C++
inline bool cse491::CoreObject::EndDeserialize (
    std::istream & is
) 
```





**Parameters:**


* `is` Input stream to deserialize from. 



**Returns:**

success (true/false) 





        



### function EndSerialize 

_Set up end of the serialization for this class (allows checking later)_ 
```C++
inline void cse491::CoreObject::EndSerialize (
    std::ostream & os
) const
```





**Parameters:**


* `os` Output stream to serialize into. 




        



### function GetTypeName\_impl 

_Override to allow access the derived name for this type._ 
```C++
virtual std::string cse491::CoreObject::GetTypeName_impl () const = 0
```





**Returns:**

A unique typename, ideally the exact name for this class (with scope) This member function will be helpful for serialization and debugging. It should return a fully scoped typename, such as "cse491::WorldGrid". 





        



### function Serialize\_impl 

_Override to store the current state of this object for later extraction._ 
```C++
virtual void cse491::CoreObject::Serialize_impl (
    std::ostream &
) const = 0
```





**Parameters:**


* `output_stream` An ostream that the required information should be stored in. 




        



### function StartDeserialize 

_Set up beginning of the deserialization for this class (does type checking)_ 
```C++
inline bool cse491::CoreObject::StartDeserialize (
    std::istream & is
) 
```





**Parameters:**


* `is` Input stream to deserialize from. 



**Returns:**

success (true/false) 





        



### function StartSerialize 

_Set up beginning of the serialization for this class (allows checking later)_ 
```C++
inline void cse491::CoreObject::StartSerialize (
    std::ostream & os
) const
```





**Parameters:**


* `os` Output stream to serialize into. 




        

------------------------------
The documentation for this class was generated from the following file `source/core/CoreObject.hpp`

