

# Class cowboys::GPAgentRegisters



[**ClassList**](annotated.md) **>** [**cowboys**](namespacecowboys.md) **>** [**GPAgentRegisters**](classcowboys_1_1_g_p_agent_registers.md)



_Class to hold the registers of the agent._ 

* `#include <GPAgentsRegisters.hpp>`















## Classes

| Type | Name |
| ---: | :--- |
| class | [**iterator**](classcowboys_1_1_g_p_agent_registers_1_1iterator.md) <br>_Iterator class for_ [_**GPAgentRegisters**_](classcowboys_1_1_g_p_agent_registers.md) _TODO: Just pass in the vector Iterator._ |






















## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**GPAgentRegisters**](#function-gpagentregisters) (int numRegisters=16) <br>_Number of registers Default is 16._  |
|  [**iterator**](classcowboys_1_1_g_p_agent_registers_1_1iterator.md) | [**begin**](#function-begin) () <br> |
|  [**iterator**](classcowboys_1_1_g_p_agent_registers_1_1iterator.md) | [**end**](#function-end) () <br> |
|  size\_t | [**getNumRegisters**](#function-getnumregisters) () <br>_Get the number of registers._  |
|  std::optional&lt; size\_t &gt; | [**getRegister**](#function-getregister) (size\_t index) <br>_Get the Register object._  |
|  bool | [**setRegister**](#function-setregister) (size\_t index, size\_t value) <br>_Set the Register object._  |
|  size\_t | [**size**](#function-size) () <br> |
|   | [**~GPAgentRegisters**](#function-gpagentregisters) () = default<br> |




























## Public Functions Documentation




### function GPAgentRegisters 

_Number of registers Default is 16._ 
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
inline size_t cowboys::GPAgentRegisters::getNumRegisters () 
```





**Returns:**

size of the registers 





        



### function getRegister 

_Get the Register object._ 
```C++
inline std::optional< size_t > cowboys::GPAgentRegisters::getRegister (
    size_t index
) 
```





**Parameters:**


* `index` Index of the register 



**Returns:**

std::optional&lt;size\_t&gt; Returns the value of the register if it exists 





        



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







        



### function size 

```C++
inline size_t cowboys::GPAgentRegisters::size () 
```






### function ~GPAgentRegisters 


```C++
cowboys::GPAgentRegisters::~GPAgentRegisters () = default
```



Destructor for [**GPAgentRegisters**](classcowboys_1_1_g_p_agent_registers.md) 


        

------------------------------
The documentation for this class was generated from the following file `source/Agents/GP/GPAgentsRegisters.hpp`

