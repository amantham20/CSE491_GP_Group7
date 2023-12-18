

# Struct worldlang::Unit



[**ClassList**](annotated.md) **>** [**worldlang**](namespaceworldlang.md) **>** [**Unit**](structworldlang_1_1_unit.md)



[More...](#detailed-description)

* `#include <Language.hpp>`

















## Public Types

| Type | Name |
| ---: | :--- |
| enum  | [**Type**](#enum-type)  <br> |




## Public Attributes

| Type | Name |
| ---: | :--- |
|  [**Type**](structworldlang_1_1_unit.md#enum-type) | [**type**](#variable-type)  <br> |
|  std::string | [**value**](#variable-value)  <br>_The value of this code unit. What it means depends on the type._  |












































# Detailed Description


A singular code unit. Will have some specific meaning within the interpreter itself. 


    
## Public Types Documentation




### enum Type 


```C++
enum worldlang::Unit::Type {
    number,
    string,
    identifier,
    function,
    operation,
    function_decl
};
```



Various types of code Units. 

**Note:**

that most internal interpreter functions all fall under `operation`. 





        
## Public Attributes Documentation




### variable type 


```C++
Type type;
```



This determines how this unit is used within the interpreter. The type of this code unit. 


        



### variable value 

```C++
std::string value;
```




------------------------------
The documentation for this class was generated from the following file `source/Worlds/Language.hpp`

