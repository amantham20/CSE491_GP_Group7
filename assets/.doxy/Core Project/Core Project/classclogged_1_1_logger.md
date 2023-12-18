

# Class clogged::Logger



[**ClassList**](annotated.md) **>** [**clogged**](namespaceclogged.md) **>** [**Logger**](classclogged_1_1_logger.md)



[_**Logger**_](classclogged_1_1_logger.md) _class with colors and team names._[More...](#detailed-description)

* `#include <EasyLogging.hpp>`





































## Public Functions

| Type | Name |
| ---: | :--- |
|  [**Logger**](classclogged_1_1_logger.md) & | [**operator&lt;&lt;**](#function-operator) ([**Team**](namespaceclogged.md#enum-team) team) <br>_Sets the Team name for the current log._  |
|  [**Logger**](classclogged_1_1_logger.md) & | [**operator&lt;&lt;**](#function-operator_1) ([**LogLevel**](namespaceclogged.md#enum-loglevel) logLevel) <br>_sets the log level for the current log_  |
|  [**Logger**](classclogged_1_1_logger.md) & | [**operator&lt;&lt;**](#function-operator_2) ([**Color**](namespaceclogged.md#enum-color) color) <br>_colors of the log_  |
|  [**Logger**](classclogged_1_1_logger.md) & | [**operator&lt;&lt;**](#function-operator_3) (std::ostream &(\*)(std::ostream &) manipulator) <br>_Manipulator for endl so that we can reset the values when a team is done logging._  |
|  [**Logger**](classclogged_1_1_logger.md) & | [**operator&lt;&lt;**](#function-operator_4) (const T & value) <br>_Aye I used a template._  |


## Public Static Functions

| Type | Name |
| ---: | :--- |
|  [**Logger**](classclogged_1_1_logger.md) & | [**Log**](#function-log-12) () <br> |
|  [**Logger**](classclogged_1_1_logger.md) & | [**Log**](#function-log-22) (T && arg1, EXTRA\_Ts &&... extra\_args) <br> |
|  std::ostream & | [**endl**](#function-endl) (std::ostream & os) <br>_Custom endl to reset the values._  |


























# Detailed Description


Not a fan of this practice But would prefer not to use parenthesis 

**Author:**

@amantham20 @chatGPT


I was about to name this clogged.


This is a custom logger class that can be used to log messages to the console. 


    
## Public Functions Documentation




### function operator&lt;&lt; 

_Sets the Team name for the current log._ 
```C++
inline Logger & clogged::Logger::operator<< (
    Team team
) 
```





**Parameters:**


* `team` name of the team 



**Returns:**

[**Logger**](classclogged_1_1_logger.md)& 





        



### function operator&lt;&lt; 

_sets the log level for the current log_ 
```C++
inline Logger & clogged::Logger::operator<< (
    LogLevel logLevel
) 
```





**Parameters:**


* `logLevel` Level/Type of the log 



**Returns:**

[**Logger**](classclogged_1_1_logger.md)& 





        



### function operator&lt;&lt; 

_colors of the log_ 
```C++
inline Logger & clogged::Logger::operator<< (
    Color color
) 
```





**Parameters:**


* `color` 



**Returns:**

[**Logger**](classclogged_1_1_logger.md)& 





        



### function operator&lt;&lt; 

_Manipulator for endl so that we can reset the values when a team is done logging._ 
```C++
inline Logger & clogged::Logger::operator<< (
    std::ostream &(*)(std::ostream &) manipulator
) 
```





**Parameters:**


* `manipulator` 



**Returns:**

[**Logger**](classclogged_1_1_logger.md)& 





        



### function operator&lt;&lt; 

_Aye I used a template._ 
```C++
template<typename T typename T>
inline Logger & clogged::Logger::operator<< (
    const T & value
) 
```



Function to log the value




**Template parameters:**


* `T` 



**Parameters:**


* `value` 



**Returns:**

[**Logger**](classclogged_1_1_logger.md)&


@TODO: Might have to change this so that we only break a team log when a new team is set. aka ensure that logger &lt;&lt; Team::TEAM\_1 &lt;&lt; "Hello" &lt;&lt; "World" &lt;&lt; endl; works in one line with one team print 


        
## Public Static Functions Documentation




### function Log [1/2]


```C++
static inline Logger & clogged::Logger::Log () 
```



Only instance of the logger once Changes requested from Dr.@ofria




**Authors:**

@mercere99 




**Returns:**

a unique [**Logger**](classclogged_1_1_logger.md) instance 





        



### function Log [2/2]


```C++
template<typename T typename T, typename... EXTRA_Ts>
static inline Logger & clogged::Logger::Log (
    T && arg1,
    EXTRA_Ts &&... extra_args
) 
```



Only instance of the logger once Changes requested from Dr.@ofria




**Authors:**

@mercere99 




**Parameters:**


* `arg1` Set of values that you want to have logged. 



**Returns:**

Unique [**Logger**](classclogged_1_1_logger.md) instance 





        



### function endl 

_Custom endl to reset the values._ 
```C++
static inline std::ostream & clogged::Logger::endl (
    std::ostream & os
) 
```





**Parameters:**


* `os` 



**Returns:**

std::ostream& 





        

------------------------------
The documentation for this class was generated from the following file `source/core/EasyLogging.hpp`

