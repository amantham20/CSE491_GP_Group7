

# Class cowboys::GPAgentRegisters



[**ClassList**](annotated.md) **>** [**cowboys**](namespacecowboys.md) **>** [**GPAgentRegisters**](classcowboys_1_1_g_p_agent_registers.md)



_Class to hold the registers of the agent._ 

* `#include <GPAgentsRegisters.hpp>`















## Classes

| Type | Name |
| ---: | :--- |
| class | [**iterator**](classcowboys_1_1_g_p_agent_registers_1_1iterator.md) <br>_Iterator class for_ [_**GPAgentRegisters**_](classcowboys_1_1_g_p_agent_registers.md) _._ |






















## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**GPAgentRegisters**](#function-gpagentregisters) (int numRegisters=16) <br> |
|  [**iterator**](classcowboys_1_1_g_p_agent_registers_1_1iterator.md) | [**begin**](#function-begin) () <br> |
|  [**iterator**](classcowboys_1_1_g_p_agent_registers_1_1iterator.md) | [**end**](#function-end) () <br> |
|  int | [**getNumRegisters**](#function-getnumregisters) () <br>_Get the number of registers._  |
|  size\_t | [**getRegister**](#function-getregister) (size\_t index) <br>_Get the Register object._  |
|  bool | [**setRegister**](#function-setregister) (size\_t index, size\_t value) <br>_Set the Register object._  |
|   | [**~GPAgentRegisters**](#function-gpagentregisters) () = default<br> |




























## Public Functions Documentation




### function GPAgentRegisters 


```C++
inline cowboys::GPAgentRegisters::GPAgentRegisters (
    int numRegisters=16
) 
```



Constructor for [**GPAgentRegisters**](classcowboys_1_1_g_p_agent_registers.md) 

**Parameters:**


* `numRegisters` 




        



### function begin 

```C++
inline iterator cowboys::GPAgentRegisters::begin () 
```






### function end 

```C++
inline iterator cowboys::GPAgentRegisters::end () 
```






### function getNumRegisters 

_Get the number of registers._ 
```C++
inline int cowboys::GPAgentRegisters::getNumRegisters () 
```





**Returns:**







        



### function getRegister 

_Get the Register object._ 
```C++
inline size_t cowboys::GPAgentRegisters::getRegister (
    size_t index
) 
```





**Parameters:**


* `index` 



**Returns:**







        



### function setRegister 

_Set the Register object._ 
```C++
inline bool cowboys::GPAgentRegisters::setRegister (
    size_t index,
    size_t value
) 
```





**Parameters:**


* `index` 
* `value` 



**Returns:**







        



### function ~GPAgentRegisters 


```C++
cowboys::GPAgentRegisters::~GPAgentRegisters () = default
```



Destructor for [**GPAgentRegisters**](classcowboys_1_1_g_p_agent_registers.md) 


        

------------------------------
The documentation for this class was generated from the following file `source/Group7_GP_Agent/GPAgentsRegisters.hpp`

