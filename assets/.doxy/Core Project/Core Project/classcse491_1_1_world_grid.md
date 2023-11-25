

# Class cse491::WorldGrid



[**ClassList**](annotated.md) **>** [**cse491**](namespacecse491.md) **>** [**WorldGrid**](classcse491_1_1_world_grid.md)



_A common interface class for core objects that sets up required functionality. This class ensures that objects can be serialized (saved), deserialized (restored) and provides helper functions._ [More...](#detailed-description)

* `#include <CoreObject.hpp>`



Inherits the following classes: [cse491::CoreObject](classcse491_1_1_core_object.md)






















































## Public Functions

| Type | Name |
| ---: | :--- |
|  size\_t | [**At**](#function-at-14) (size\_t x, size\_t y) const<br> |
|  size\_t & | [**At**](#function-at-24) (size\_t x, size\_t y) <br> |
|  size\_t | [**At**](#function-at-34) ([**GridPosition**](classcse491_1_1_grid_position.md) p) const<br> |
|  size\_t & | [**At**](#function-at-44) ([**GridPosition**](classcse491_1_1_grid_position.md) p) <br> |
|  size\_t | [**GetHeight**](#function-getheight) () const<br> |
|  size\_t | [**GetNumCells**](#function-getnumcells) () const<br> |
|  size\_t | [**GetWidth**](#function-getwidth) () const<br> |
|  bool | [**IsValid**](#function-isvalid-12) (double x, double y) const<br>_Test if specific coordinates are in range for this GridWorld._  |
|  bool | [**IsValid**](#function-isvalid-22) ([**GridPosition**](classcse491_1_1_grid_position.md) pos) const<br>_Test if a_ [_**GridPosition**_](classcse491_1_1_grid_position.md) _is in range for this GridWorld._ |
|  void | [**Read**](#function-read-12) (std::istream & is, const [**type\_options\_t**](namespacecse491.md#typedef-type_options_t) & types) <br> |
|  bool | [**Read**](#function-read-22) (std::string filename, const [**type\_options\_t**](namespacecse491.md#typedef-type_options_t) & types) <br>_Helper function to specify a file name to read the grid state from._  |
|  void | [**Resize**](#function-resize) (size\_t new\_width, size\_t new\_height, size\_t default\_type=0) <br> |
|   | [**WorldGrid**](#function-worldgrid-14) () = default<br> |
|   | [**WorldGrid**](#function-worldgrid-24) (size\_t width, size\_t height, size\_t default\_type=0) <br> |
|   | [**WorldGrid**](#function-worldgrid-34) (const [**WorldGrid**](classcse491_1_1_world_grid.md) &) = default<br> |
|   | [**WorldGrid**](#function-worldgrid-44) ([**WorldGrid**](classcse491_1_1_world_grid.md) &&) = default<br> |
|  void | [**Write**](#function-write-12) (std::ostream & os, const [**type\_options\_t**](namespacecse491.md#typedef-type_options_t) & types) const<br>_Write out a human-readable version of the current_ [_**WorldGrid**_](classcse491_1_1_world_grid.md) _._ |
|  bool | [**Write**](#function-write-22) (std::string filename, const [**type\_options\_t**](namespacecse491.md#typedef-type_options_t) & types) const<br>_Helper function to specify a file name to write the grid state to._  |
|  [**WorldGrid**](classcse491_1_1_world_grid.md) & | [**operator=**](#function-operator) (const [**WorldGrid**](classcse491_1_1_world_grid.md) &) = default<br> |
|  [**WorldGrid**](classcse491_1_1_world_grid.md) & | [**operator=**](#function-operator_1) ([**WorldGrid**](classcse491_1_1_world_grid.md) &&) = default<br> |
|  size\_t | [**operator[]**](#function-operator_2) ([**GridPosition**](classcse491_1_1_grid_position.md) p) const<br> |
|  size\_t & | [**operator[]**](#function-operator_3) ([**GridPosition**](classcse491_1_1_grid_position.md) p) <br> |


## Public Functions inherited from cse491::CoreObject

See [cse491::CoreObject](classcse491_1_1_core_object.md)

| Type | Name |
| ---: | :--- |
|  void | [**Deserialize**](#function-deserialize-12) (std::istream & is) <br>_Restore the state of this object, extracting it from the provided stream._  |
|  bool | [**Deserialize**](#function-deserialize-22) (std::string filename) <br>_A version of Deserialize that accepts a filename to read this object from._  |
|  std::string | [**GetTypeName**](#function-gettypename) () const<br>_Access the derived name for this type._  |
|  void | [**Serialize**](#function-serialize-12) (std::ostream & os) const<br>_Store the current state of this object for later extraction._  |
|  bool | [**Serialize**](#function-serialize-22) (std::string filename) const<br>_A version of Serialize that accepts a filename for saving just this object._  |
| virtual  | [**~CoreObject**](#function-coreobject) () <br> |














## Protected Attributes

| Type | Name |
| ---: | :--- |
|  std::vector&lt; size\_t &gt; | [**cells**](#variable-cells)  <br>_All cells, grouped by full rows, top to bottom._  |
|  size\_t | [**height**](#variable-height)   = = 0<br>_Number of rows of cells in the grid._  |
|  size\_t | [**width**](#variable-width)   = = 0<br>_Number of cells in each row of the grid._  |
































## Protected Functions

| Type | Name |
| ---: | :--- |
| virtual void | [**Deserialize\_impl**](#function-deserialize_impl) (std::istream & is) override<br>_Read the state of the grid out of the provided stream._  |
| virtual std::string | [**GetTypeName\_impl**](#function-gettypename_impl) () override const<br>_Override to allow access the derived name for this type._  |
| virtual void | [**Serialize\_impl**](#function-serialize_impl) (std::ostream & os) override const<br>_Write the current state of this grid into the provided stream._  |
|  size\_t | [**ToIndex**](#function-toindex) (size\_t x, size\_t y) const<br>_Convert an X and a Y value to the index in the vector._  |


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






# Detailed Description


Represents a 2D grid of cells. This class provides utilities to manage, access, and modify cells within a grid. 


    
## Public Functions Documentation




### function At [1/4]


```C++
inline size_t cse491::WorldGrid::At (
    size_t x,
    size_t y
) const
```





**Returns:**

The grid state at the provided x and y coordinates 





        



### function At [2/4]


```C++
inline size_t & cse491::WorldGrid::At (
    size_t x,
    size_t y
) 
```





**Returns:**

A reference to the grid state at the provided x and y coordinates 





        



### function At [3/4]


```C++
inline size_t cse491::WorldGrid::At (
    GridPosition p
) const
```





**Returns:**

The state at a given [**GridPosition**](classcse491_1_1_grid_position.md). 





        



### function At [4/4]


```C++
inline size_t & cse491::WorldGrid::At (
    GridPosition p
) 
```





**Returns:**

A reference to the state at a given [**GridPosition**](classcse491_1_1_grid_position.md). 





        



### function GetHeight 

```C++
inline size_t cse491::WorldGrid::GetHeight () const
```






### function GetNumCells 

```C++
inline size_t cse491::WorldGrid::GetNumCells () const
```






### function GetWidth 

```C++
inline size_t cse491::WorldGrid::GetWidth () const
```






### function IsValid [1/2]

```C++
inline bool cse491::WorldGrid::IsValid (
    double x,
    double y
) const
```






### function IsValid [2/2]

```C++
inline bool cse491::WorldGrid::IsValid (
    GridPosition pos
) const
```






### function Read [1/2]

```C++
inline void cse491::WorldGrid::Read (
    std::istream & is,
    const type_options_t & types
) 
```






### function Read [2/2]

```C++
inline bool cse491::WorldGrid::Read (
    std::string filename,
    const type_options_t & types
) 
```






### function Resize 

```C++
inline void cse491::WorldGrid::Resize (
    size_t new_width,
    size_t new_height,
    size_t default_type=0
) 
```






### function WorldGrid [1/4]

```C++
cse491::WorldGrid::WorldGrid () = default
```






### function WorldGrid [2/4]

```C++
inline cse491::WorldGrid::WorldGrid (
    size_t width,
    size_t height,
    size_t default_type=0
) 
```






### function WorldGrid [3/4]

```C++
cse491::WorldGrid::WorldGrid (
    const WorldGrid &
) = default
```






### function WorldGrid [4/4]

```C++
cse491::WorldGrid::WorldGrid (
    WorldGrid &&
) = default
```






### function Write [1/2]

_Write out a human-readable version of the current_ [_**WorldGrid**_](classcse491_1_1_world_grid.md) _._
```C++
inline void cse491::WorldGrid::Write (
    std::ostream & os,
    const type_options_t & types
) const
```





**Parameters:**


* `os` Stream to write to 
* `types` A vector of CellTypes for symbol identification 




        



### function Write [2/2]

```C++
inline bool cse491::WorldGrid::Write (
    std::string filename,
    const type_options_t & types
) const
```






### function operator= 

```C++
WorldGrid & cse491::WorldGrid::operator= (
    const WorldGrid &
) = default
```






### function operator= 

```C++
WorldGrid & cse491::WorldGrid::operator= (
    WorldGrid &&
) = default
```






### function operator[] 

```C++
inline size_t cse491::WorldGrid::operator[] (
    GridPosition p
) const
```






### function operator[] 

```C++
inline size_t & cse491::WorldGrid::operator[] (
    GridPosition p
) 
```



## Protected Attributes Documentation




### variable cells 

```C++
std::vector<size_t> cells;
```






### variable height 

```C++
size_t height;
```






### variable width 

```C++
size_t width;
```



## Protected Functions Documentation




### function Deserialize\_impl 

```C++
inline virtual void cse491::WorldGrid::Deserialize_impl (
    std::istream & is
) override
```



Implements [*cse491::CoreObject::Deserialize\_impl*](classcse491_1_1_core_object.md#function-deserialize_impl)




### function GetTypeName\_impl 

_Override to allow access the derived name for this type._ 
```C++
inline virtual std::string cse491::WorldGrid::GetTypeName_impl () override const
```





**Returns:**

A unique typename, ideally the exact name for this class (with scope) This member function will be helpful for serialization and debugging. It should return a fully scoped typename, such as "cse491::WorldGrid". 





        
Implements [*cse491::CoreObject::GetTypeName\_impl*](classcse491_1_1_core_object.md#function-gettypename_impl)




### function Serialize\_impl 

```C++
inline virtual void cse491::WorldGrid::Serialize_impl (
    std::ostream & os
) override const
```



Implements [*cse491::CoreObject::Serialize\_impl*](classcse491_1_1_core_object.md#function-serialize_impl)




### function ToIndex 

```C++
inline size_t cse491::WorldGrid::ToIndex (
    size_t x,
    size_t y
) const
```




------------------------------
The documentation for this class was generated from the following file `source/core/WorldGrid.hpp`

