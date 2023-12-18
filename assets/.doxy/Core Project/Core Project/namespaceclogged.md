

# Namespace clogged



[**Namespace List**](namespaces.md) **>** [**clogged**](namespaceclogged.md)



_Tools for debug-logging that can be easily controlled._ [More...](#detailed-description)
















## Classes

| Type | Name |
| ---: | :--- |
| class | [**Logger**](classclogged_1_1_logger.md) <br>[_**Logger**_](classclogged_1_1_logger.md) _class with colors and team names._ |


## Public Types

| Type | Name |
| ---: | :--- |
| enum  | [**Color**](#enum-color)  <br>_Colors for logging._  |
| enum  | [**LogLevel**](#enum-loglevel)  <br>_Log levels for logging._  |
| enum  | [**Team**](#enum-team)  <br>_Teams Names for logging._  |




## Public Attributes

| Type | Name |
| ---: | :--- |
|  const [**LogLevel**](namespaceclogged.md#enum-loglevel) | [**LOGLEVEL**](#variable-loglevel)   = = LogLevel::DEBUG<br>_Level of logging @TODO: Change this to be a flag in the CMakeLists.txt._  |












































# Detailed Description


This file is part of the Fall 2023, CSE 491 course project. 

**Note:**

Status: ALPHA 





    
## Public Types Documentation




### enum Color 

```C++
enum clogged::Color {
    RESET = 0,
    BLUE = 34,
    GREEN = 32,
    RED = 31
};
```






### enum LogLevel 

```C++
enum clogged::LogLevel {
    DEBUG,
    INFO,
    WARNING,
    ERR,
    NA
};
```






### enum Team 

```C++
enum clogged::Team {
    TEAM_1,
    TEAM_2,
    TEAM_3,
    TEAM_4,
    TEAM_5,
    TEAM_6,
    TEAM_7,
    TEAM_8,
    TEAM_9,
    GENERAL,
    NA
};
```



## Public Attributes Documentation




### variable LOGLEVEL 

```C++
const LogLevel LOGLEVEL;
```




------------------------------
The documentation for this class was generated from the following file `source/core/EasyLogging.hpp`

