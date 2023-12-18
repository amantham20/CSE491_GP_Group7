

# Class cse491::GridPosition



[**ClassList**](annotated.md) **>** [**cse491**](namespacecse491.md) **>** [**GridPosition**](classcse491_1_1_grid_position.md)



_Represents a position within a 2D grid of cells. This class provides utilities to manage a position in 2D space. The position is stored as floating-point values (to allow for smooth motion through a grid), but is easily converted to size\_t for grid-cell identification._ 

* `#include <GridPosition.hpp>`



Inherits the following classes: [cse491::CoreObject](classcse491_1_1_core_object.md)






















































## Public Functions

| Type | Name |
| ---: | :--- |
|  [**GridPosition**](classcse491_1_1_grid_position.md) | [**Above**](#function-above) (double dist=1.0) const<br>_Return a grid position above this one (by default, directly above)_  |
|  [**GridPosition**](classcse491_1_1_grid_position.md) | [**Below**](#function-below) (double dist=1.0) const<br>_Return a grid position below this one (by default, directly below)_  |
|  size\_t | [**CellX**](#function-cellx) () const<br> |
|  size\_t | [**CellY**](#function-celly) () const<br> |
| virtual void | [**Deserialize\_impl**](#function-deserialize_impl) (std::istream &) override<br>_Override to restore the state of this object from the provided stream._  |
|  double | [**Distance**](#function-distance) ([**GridPosition**](classcse491_1_1_grid_position.md) pos2) const<br> |
|  [**GridPosition**](classcse491_1_1_grid_position.md) & | [**FromStream**](#function-fromstream) (std::istream & ss) <br> |
|  [**GridPosition**](classcse491_1_1_grid_position.md) & | [**FromString**](#function-fromstring) (std::string in\_str) <br> |
|  [**GridPosition**](classcse491_1_1_grid_position.md) | [**GetOffset**](#function-getoffset) (double offset\_x, double offset\_y) const<br>_Return a the_ [_**GridPosition**_](classcse491_1_1_grid_position.md) _at the requested offset._ |
| virtual std::string | [**GetTypeName\_impl**](#function-gettypename_impl) () override const<br>_Override to allow access the derived name for this type._  |
|  double | [**GetX**](#function-getx) () const<br> |
|  double | [**GetY**](#function-gety) () const<br> |
|   | [**GridPosition**](#function-gridposition-14) () = default<br> |
|   | [**GridPosition**](#function-gridposition-24) (double x, double y) <br> |
|   | [**GridPosition**](#function-gridposition-34) (const std::string & str) <br> |
|   | [**GridPosition**](#function-gridposition-44) (const [**GridPosition**](classcse491_1_1_grid_position.md) &) = default<br> |
|  bool | [**IsInvalid**](#function-isinvalid) () const<br> |
|  bool | [**IsNear**](#function-isnear) ([**GridPosition**](classcse491_1_1_grid_position.md) pos2, double max\_dist=1.0) const<br> |
|  bool | [**IsValid**](#function-isvalid) () const<br> |
|  double | [**MDistance**](#function-mdistance) ([**GridPosition**](classcse491_1_1_grid_position.md) pos2) const<br>_Manhattan distance between grid positions._  |
|  [**GridPosition**](classcse491_1_1_grid_position.md) & | [**MakeInvalid**](#function-makeinvalid) () <br>_Make this grid position invalid, by setting both coords to "not-a-number"._  |
| virtual void | [**Serialize\_impl**](#function-serialize_impl) (std::ostream &) override const<br>_Override to store the current state of this object for later extraction._  |
|  [**GridPosition**](classcse491_1_1_grid_position.md) & | [**Set**](#function-set) (double in\_x, double in\_y) <br> |
|  [**GridPosition**](classcse491_1_1_grid_position.md) & | [**SetX**](#function-setx) (double in) <br> |
|  [**GridPosition**](classcse491_1_1_grid_position.md) & | [**SetY**](#function-sety) (double in) <br> |
|  [**GridPosition**](classcse491_1_1_grid_position.md) & | [**Shift**](#function-shift) (double shift\_x, double shift\_y) <br> |
|  [**GridPosition**](classcse491_1_1_grid_position.md) | [**ToLeft**](#function-toleft) (double dist=1.0) const<br>_Return a grid position to the left of this one (by default, directly left)_  |
|  [**GridPosition**](classcse491_1_1_grid_position.md) | [**ToRight**](#function-toright) (double dist=1.0) const<br>_Return a grid position to the right of this one (by default, directly right)_  |
|  std::string | [**ToString**](#function-tostring) () const<br> |
|  [**GridPosition**](classcse491_1_1_grid_position.md) | [**operator+**](#function-operator) ([**GridPosition**](classcse491_1_1_grid_position.md) in) const<br>_Add together two grid positions and return the result._  |
|  [**GridPosition**](classcse491_1_1_grid_position.md) & | [**operator+=**](#function-operator_1) (const [**GridPosition**](classcse491_1_1_grid_position.md) & in) <br> |
|  [**GridPosition**](classcse491_1_1_grid_position.md) & | [**operator-=**](#function-operator_2) (const [**GridPosition**](classcse491_1_1_grid_position.md) & in) <br> |
|  auto | [**operator&lt;=&gt;**](#function-operator<>) (const [**GridPosition**](classcse491_1_1_grid_position.md) &) const<br>_Enable all comparison operators (==, !=, &lt;, &lt;=, &gt;, &gt;=)_  |
|  [**GridPosition**](classcse491_1_1_grid_position.md) & | [**operator=**](#function-operator_3) (const [**GridPosition**](classcse491_1_1_grid_position.md) &) = default<br> |
|   | [**~GridPosition**](#function-gridposition) () = default<br> |


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


## Public Static Functions

| Type | Name |
| ---: | :--- |
|  const [**GridPosition**](classcse491_1_1_grid_position.md) & | [**Invalid**](#function-invalid) () <br> |














































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




### function Above 

```C++
inline GridPosition cse491::GridPosition::Above (
    double dist=1.0
) const
```






### function Below 

```C++
inline GridPosition cse491::GridPosition::Below (
    double dist=1.0
) const
```






### function CellX 

```C++
inline size_t cse491::GridPosition::CellX () const
```






### function CellY 

```C++
inline size_t cse491::GridPosition::CellY () const
```






### function Deserialize\_impl 

_Override to restore the state of this object from the provided stream._ 
```C++
inline virtual void cse491::GridPosition::Deserialize_impl (
    std::istream &
) override
```





**Parameters:**


* `input_stream` The istream with full details about this object. 




        
Implements [*cse491::CoreObject::Deserialize\_impl*](classcse491_1_1_core_object.md#function-deserialize_impl)




### function Distance 

```C++
inline double cse491::GridPosition::Distance (
    GridPosition pos2
) const
```






### function FromStream 

```C++
inline GridPosition & cse491::GridPosition::FromStream (
    std::istream & ss
) 
```






### function FromString 

```C++
inline GridPosition & cse491::GridPosition::FromString (
    std::string in_str
) 
```






### function GetOffset 

```C++
inline GridPosition cse491::GridPosition::GetOffset (
    double offset_x,
    double offset_y
) const
```






### function GetTypeName\_impl 

_Override to allow access the derived name for this type._ 
```C++
inline virtual std::string cse491::GridPosition::GetTypeName_impl () override const
```





**Returns:**

A unique typename, ideally the exact name for this class (with scope) This member function will be helpful for serialization and debugging. It should return a fully scoped typename, such as "cse491::WorldGrid". 





        
Implements [*cse491::CoreObject::GetTypeName\_impl*](classcse491_1_1_core_object.md#function-gettypename_impl)




### function GetX 

```C++
inline double cse491::GridPosition::GetX () const
```






### function GetY 

```C++
inline double cse491::GridPosition::GetY () const
```






### function GridPosition [1/4]

```C++
cse491::GridPosition::GridPosition () = default
```






### function GridPosition [2/4]

```C++
inline cse491::GridPosition::GridPosition (
    double x,
    double y
) 
```






### function GridPosition [3/4]

```C++
inline cse491::GridPosition::GridPosition (
    const std::string & str
) 
```






### function GridPosition [4/4]

```C++
cse491::GridPosition::GridPosition (
    const GridPosition &
) = default
```






### function IsInvalid 

```C++
inline bool cse491::GridPosition::IsInvalid () const
```






### function IsNear 

```C++
inline bool cse491::GridPosition::IsNear (
    GridPosition pos2,
    double max_dist=1.0
) const
```






### function IsValid 

```C++
inline bool cse491::GridPosition::IsValid () const
```






### function MDistance 

_Manhattan distance between grid positions._ 
```C++
inline double cse491::GridPosition::MDistance (
    GridPosition pos2
) const
```





**Parameters:**


* `pos2` Position to compare to 



**Returns:**

Manhattan distance 





        



### function MakeInvalid 

_Make this grid position invalid, by setting both coords to "not-a-number"._ 
```C++
inline GridPosition & cse491::GridPosition::MakeInvalid () 
```





**Returns:**

This object. 





        



### function Serialize\_impl 

_Override to store the current state of this object for later extraction._ 
```C++
inline virtual void cse491::GridPosition::Serialize_impl (
    std::ostream &
) override const
```





**Parameters:**


* `output_stream` An ostream that the required information should be stored in. 




        
Implements [*cse491::CoreObject::Serialize\_impl*](classcse491_1_1_core_object.md#function-serialize_impl)




### function Set 

```C++
inline GridPosition & cse491::GridPosition::Set (
    double in_x,
    double in_y
) 
```






### function SetX 

```C++
inline GridPosition & cse491::GridPosition::SetX (
    double in
) 
```






### function SetY 

```C++
inline GridPosition & cse491::GridPosition::SetY (
    double in
) 
```






### function Shift 

```C++
inline GridPosition & cse491::GridPosition::Shift (
    double shift_x,
    double shift_y
) 
```






### function ToLeft 

```C++
inline GridPosition cse491::GridPosition::ToLeft (
    double dist=1.0
) const
```






### function ToRight 

```C++
inline GridPosition cse491::GridPosition::ToRight (
    double dist=1.0
) const
```






### function ToString 

```C++
inline std::string cse491::GridPosition::ToString () const
```






### function operator+ 

```C++
inline GridPosition cse491::GridPosition::operator+ (
    GridPosition in
) const
```






### function operator+= 

```C++
inline GridPosition & cse491::GridPosition::operator+= (
    const GridPosition & in
) 
```






### function operator-= 

```C++
inline GridPosition & cse491::GridPosition::operator-= (
    const GridPosition & in
) 
```






### function operator&lt;=&gt; 

```C++
auto cse491::GridPosition::operator<=> (
    const GridPosition &
) const
```






### function operator= 

```C++
GridPosition & cse491::GridPosition::operator= (
    const GridPosition &
) = default
```






### function ~GridPosition 

```C++
cse491::GridPosition::~GridPosition () = default
```



## Public Static Functions Documentation




### function Invalid 

```C++
static inline const GridPosition & cse491::GridPosition::Invalid () 
```




------------------------------
The documentation for this class was generated from the following file `source/core/GridPosition.hpp`

