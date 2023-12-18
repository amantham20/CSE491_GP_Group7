

# Struct cse491::CellType



[**ClassList**](annotated.md) **>** [**cse491**](namespacecse491.md) **>** [**CellType**](structcse491_1_1_cell_type.md)



_Simple data structure to hold info about a TYPE of cell in the world._ 

* `#include <Data.hpp>`





















## Public Attributes

| Type | Name |
| ---: | :--- |
|  std::string | [**desc**](#variable-desc)  <br>_Full description of what this type of cell is._  |
|  std::string | [**name**](#variable-name)  <br>_Unique name for this type of cell (e.g., "wall", "tree", "moon")_  |
|  std::set&lt; std::string &gt; | [**properties**](#variable-properties)   = {}<br>_Set of properties for this cell type._  |
|  char | [**symbol**](#variable-symbol)  <br>_Symbol for text representations (files or interface)_  |


## Public Static Attributes

| Type | Name |
| ---: | :--- |
|  constexpr char | [**CELL\_WALL**](#variable-cell_wall)   = = "wall"<br> |
|  constexpr char | [**CELL\_WATER**](#variable-cell_water)   = = "water"<br> |














## Public Functions

| Type | Name |
| ---: | :--- |
|  bool | [**HasProperty**](#function-hasproperty) (const std::string & property) const<br>_Checks if the given property is set on this_ [_**CellType**_](structcse491_1_1_cell_type.md) _._ |
|  [**CellType**](structcse491_1_1_cell_type.md) & | [**RemoveProperty**](#function-removeproperty) (const std::string & property) <br>_Removes the specifed property from this_ [_**CellType**_](structcse491_1_1_cell_type.md) _._ |
|  [**CellType**](structcse491_1_1_cell_type.md) & | [**SetProperty**](#function-setproperty) (const std::string & property) <br>_Adds the specifed property to this_ [_**CellType**_](structcse491_1_1_cell_type.md) _._ |




























## Public Attributes Documentation




### variable desc 

```C++
std::string desc;
```






### variable name 

```C++
std::string name;
```






### variable properties 

```C++
std::set<std::string> properties;
```






### variable symbol 

```C++
char symbol;
```



## Public Static Attributes Documentation




### variable CELL\_WALL 

```C++
constexpr char CELL_WALL[];
```






### variable CELL\_WATER 

```C++
constexpr char CELL_WATER[];
```



## Public Functions Documentation




### function HasProperty 

```C++
inline bool cse491::CellType::HasProperty (
    const std::string & property
) const
```






### function RemoveProperty 

```C++
inline CellType & cse491::CellType::RemoveProperty (
    const std::string & property
) 
```






### function SetProperty 

```C++
inline CellType & cse491::CellType::SetProperty (
    const std::string & property
) 
```




------------------------------
The documentation for this class was generated from the following file `source/core/Data.hpp`

