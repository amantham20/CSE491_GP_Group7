

# Class cse491::TrashInterface



[**ClassList**](annotated.md) **>** [**cse491**](namespacecse491.md) **>** [**TrashInterface**](classcse491_1_1_trash_interface.md)








Inherits the following classes: InterfaceBase


































## Public Functions

| Type | Name |
| ---: | :--- |
|  bool | [**Initialize**](#function-initialize) () override<br> |
|  void | [**Notify**](#function-notify) (const std::string & message, const std::string &="none") override<br> |
|  size\_t | [**SelectAction**](#function-selectaction) (const WorldGrid & grid, const type\_options\_t & type\_options, const item\_map\_t & item\_map, const agent\_map\_t & agent\_map) override<br> |
|   | [**TrashInterface**](#function-trashinterface) (size\_t id, const std::string & name) <br> |
|   | [**~TrashInterface**](#function-trashinterface) () = default<br> |








## Protected Attributes

| Type | Name |
| ---: | :--- |
|  bool | [**wait\_for\_input**](#variable-wait_for_input)   = = true<br>_Should we pause and wait for the user to hit a key?_  |
















## Protected Functions

| Type | Name |
| ---: | :--- |
|  void | [**DrawGrid**](#function-drawgrid) (const WorldGrid & grid, const type\_options\_t & type\_options, const item\_map\_t & item\_map, const agent\_map\_t & agent\_map) <br> |




## Public Functions Documentation




### function Initialize 

```C++
inline bool cse491::TrashInterface::Initialize () override
```






### function Notify 

```C++
inline void cse491::TrashInterface::Notify (
    const std::string & message,
    const std::string &="none"
) override
```






### function SelectAction 

```C++
inline size_t cse491::TrashInterface::SelectAction (
    const WorldGrid & grid,
    const type_options_t & type_options,
    const item_map_t & item_map,
    const agent_map_t & agent_map
) override
```






### function TrashInterface 

```C++
inline cse491::TrashInterface::TrashInterface (
    size_t id,
    const std::string & name
) 
```






### function ~TrashInterface 

```C++
cse491::TrashInterface::~TrashInterface () = default
```



## Protected Attributes Documentation




### variable wait\_for\_input 

```C++
bool wait_for_input;
```



## Protected Functions Documentation




### function DrawGrid 

```C++
inline void cse491::TrashInterface::DrawGrid (
    const WorldGrid & grid,
    const type_options_t & type_options,
    const item_map_t & item_map,
    const agent_map_t & agent_map
) 
```




------------------------------
The documentation for this class was generated from the following file `source/Interfaces/TrashInterface.hpp`

