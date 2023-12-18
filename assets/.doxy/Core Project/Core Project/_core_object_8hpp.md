

# File CoreObject.hpp



[**FileList**](files.md) **>** [**core**](dir_0d27ce74e9bd514c31e1d63efab6b388.md) **>** [**CoreObject.hpp**](_core_object_8hpp.md)

[Go to the source code of this file](_core_object_8hpp_source.md)



* `#include <fstream>`
* `#include <functional>`
* `#include <iostream>`
* `#include <map>`
* `#include <sstream>`
* `#include <string>`
* `#include <unordered_map>`
* `#include "Serialize.hpp"`













## Namespaces

| Type | Name |
| ---: | :--- |
| namespace | [**cse491**](namespacecse491.md) <br>_A base class interface for all agent types._  |


## Classes

| Type | Name |
| ---: | :--- |
| class | [**CoreObject**](classcse491_1_1_core_object.md) <br> |

















































## Macros

| Type | Name |
| ---: | :--- |
| define  | [**EXPERIMENTAL\_CLASS**](_core_object_8hpp.md#define-experimental_class)  \_\_attribute\_\_((annotate("experimental\_class")))<br> |
| define  | [**EXPERIMENTAL\_FUNCTION**](_core_object_8hpp.md#define-experimental_function)  \_\_attribute\_\_((annotate("experimental\_function")))<br>_A common interface class for core objects that sets up required functionality._  |

## Macro Definition Documentation





### define EXPERIMENTAL\_CLASS 

```C++
#define EXPERIMENTAL_CLASS __attribute__((annotate("experimental_class")))
```






### define EXPERIMENTAL\_FUNCTION 

_A common interface class for core objects that sets up required functionality._ 
```C++
#define EXPERIMENTAL_FUNCTION __attribute__((annotate("experimental_function")))
```



This file is part of the Fall 2023, CSE 491 course project. 

**Note:**

Status: ALPHA


This CoreObject class builds an interface for all of the core object, ensuring that they can be properly serialized.


Derived classes must implement: GetTypeName\_impl() - Return the qualified type name. Serialize\_impl(std::ostream &) - Store the object in a stream. Deserialize\_impl(std::istream &) - Restore the object from a stream. 

**Author:**

@amantham20 uses as attribute to mark experimental classes and functions 





        

------------------------------
The documentation for this class was generated from the following file `source/core/CoreObject.hpp`

