

# File EasyLogging.hpp



[**FileList**](files.md) **>** [**core**](dir_0d27ce74e9bd514c31e1d63efab6b388.md) **>** [**EasyLogging.hpp**](_easy_logging_8hpp.md)

[Go to the source code of this file](_easy_logging_8hpp_source.md)



* `#include <fstream>`
* `#include <iostream>`
* `#include <map>`
* `#include <sstream>`













## Namespaces

| Type | Name |
| ---: | :--- |
| namespace | [**clogged**](namespaceclogged.md) <br>_Tools for debug-logging that can be easily controlled._  |


## Classes

| Type | Name |
| ---: | :--- |
| class | [**Logger**](classclogged_1_1_logger.md) <br>[_**Logger**_](classclogged_1_1_logger.md) _class with colors and team names._ |

















































## Macros

| Type | Name |
| ---: | :--- |
| define  | [**LOGLINE**](_easy_logging_8hpp.md#define-logline)  "File: " &lt;&lt; \_\_FILE\_\_ &lt;&lt; "::-&gt;::Line(" &lt;&lt; \_\_LINE\_\_ &lt;&lt; ")"<br>_Ensure that we only log when NDEBUG flg is not set._  |
| define  | [**LOG\_FNC**](_easy_logging_8hpp.md#define-log_fnc)  "Function: " &lt;&lt; \_\_func\_\_ &lt;&lt; " "<br> |
| define  | [**LOG\_RELLINE**](_easy_logging_8hpp.md#define-log_relline)  "File: " &lt;&lt; RELATIVE\_PATH(\_\_FILE\_\_) &lt;&lt; "::-&gt;::Line(" &lt;&lt; \_\_LINE\_\_ &lt;&lt; ")"<br> |
| define  | [**RELATIVE\_PATH**](_easy_logging_8hpp.md#define-relative_path) (file) <br> |

## Macro Definition Documentation





### define LOGLINE 

```C++
#define LOGLINE "File: " << __FILE__ << "::->::Line(" << __LINE__ << ")"
```






### define LOG\_FNC 

```C++
#define LOG_FNC "Function: " << __func__ << " "
```






### define LOG\_RELLINE 

```C++
#define LOG_RELLINE "File: " << RELATIVE_PATH(__FILE__) << "::->::Line(" << __LINE__ << ")"
```






### define RELATIVE\_PATH 

```C++
#define RELATIVE_PATH (
    file
) (std::string(file).find_last_of("/\\") != std::string::npos                \
       ? std::string(file).substr(std::string(file).find_last_of("/\\") + 1) \
       : std::string(file))
```




------------------------------
The documentation for this class was generated from the following file `source/core/EasyLogging.hpp`

