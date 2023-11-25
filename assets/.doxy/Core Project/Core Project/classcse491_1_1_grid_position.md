

# Class cse491::GridPosition



[**ClassList**](annotated.md) **>** [**cse491**](namespacecse491.md) **>** [**GridPosition**](classcse491_1_1_grid_position.md)



_Represents a position within a 2D grid of cells. This class provides utilities to manage a position in 2D space. The position is stored as floating-point values (to allow for smooth motion through a grid), but is easily converted to size\_t for grid-cell identification._ 

* `#include <GridPosition.hpp>`





































## Public Functions

| Type | Name |
| ---: | :--- |
|  [**GridPosition**](classcse491_1_1_grid_position.md) | [**Above**](#function-above) (double dist=1.0) const<br>_Return a grid position above this one (by default, directly above)_  |
|  [**GridPosition**](classcse491_1_1_grid_position.md) | [**Below**](#function-below) (double dist=1.0) const<br>_Return a grid position below this one (by default, directly below)_  |
|  size\_t | [**CellX**](#function-cellx) () const<br> |
|  size\_t | [**CellY**](#function-celly) () const<br> |
|  [**GridPosition**](classcse491_1_1_grid_position.md) | [**GetOffset**](#function-getoffset) (double offset\_x, double offset\_y) const<br>_Return a the_ [_**GridPosition**_](classcse491_1_1_grid_position.md) _at the requested offset._ |
|  double | [**GetX**](#function-getx) () const<br> |
|  double | [**GetY**](#function-gety) () const<br> |
|   | [**GridPosition**](#function-gridposition-13) () = default<br> |
|   | [**GridPosition**](#function-gridposition-23) (double x, double y) <br> |
|   | [**GridPosition**](#function-gridposition-33) (const [**GridPosition**](classcse491_1_1_grid_position.md) &) = default<br> |
|  [**GridPosition**](classcse491_1_1_grid_position.md) & | [**Set**](#function-set) (double in\_x, double in\_y) <br> |
|  [**GridPosition**](classcse491_1_1_grid_position.md) & | [**Shift**](#function-shift) (double shift\_x, double shift\_y) <br> |
|  [**GridPosition**](classcse491_1_1_grid_position.md) | [**ToLeft**](#function-toleft) (double dist=1.0) const<br>_Return a grid position to the left of this one (by default, directly left)_  |
|  [**GridPosition**](classcse491_1_1_grid_position.md) | [**ToRight**](#function-toright) (double dist=1.0) const<br>_Return a grid position to the right of this one (by default, directly right)_  |
|  [**GridPosition**](classcse491_1_1_grid_position.md) | [**operator+**](#function-operator) ([**GridPosition**](classcse491_1_1_grid_position.md) in) const<br>_Add together two grid positions and return the result._  |
|  [**GridPosition**](classcse491_1_1_grid_position.md) & | [**operator+=**](#function-operator_1) (const [**GridPosition**](classcse491_1_1_grid_position.md) & in) <br> |
|  [**GridPosition**](classcse491_1_1_grid_position.md) & | [**operator-=**](#function-operator_2) (const [**GridPosition**](classcse491_1_1_grid_position.md) & in) <br> |
|  auto | [**operator&lt;=&gt;**](#function-operator<>) (const [**GridPosition**](classcse491_1_1_grid_position.md) &) const<br>_Enable all comparison operators (==, !=, &lt;, &lt;=, &gt;, &gt;=)_  |
|  [**GridPosition**](classcse491_1_1_grid_position.md) & | [**operator=**](#function-operator_3) (const [**GridPosition**](classcse491_1_1_grid_position.md) &) = default<br> |




























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






### function GetOffset 

```C++
inline GridPosition cse491::GridPosition::GetOffset (
    double offset_x,
    double offset_y
) const
```






### function GetX 

```C++
inline double cse491::GridPosition::GetX () const
```






### function GetY 

```C++
inline double cse491::GridPosition::GetY () const
```






### function GridPosition [1/3]

```C++
cse491::GridPosition::GridPosition () = default
```






### function GridPosition [2/3]

```C++
inline cse491::GridPosition::GridPosition (
    double x,
    double y
) 
```






### function GridPosition [3/3]

```C++
cse491::GridPosition::GridPosition (
    const GridPosition &
) = default
```






### function Set 

```C++
inline GridPosition & cse491::GridPosition::Set (
    double in_x,
    double in_y
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




------------------------------
The documentation for this class was generated from the following file `source/core/GridPosition.hpp`

