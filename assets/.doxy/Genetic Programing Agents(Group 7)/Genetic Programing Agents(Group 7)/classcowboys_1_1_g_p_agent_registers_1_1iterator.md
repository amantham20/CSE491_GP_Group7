

# Class cowboys::GPAgentRegisters::iterator



[**ClassList**](annotated.md) **>** [**cowboys**](namespacecowboys.md) **>** [**GPAgentRegisters**](classcowboys_1_1_g_p_agent_registers.md) **>** [**iterator**](classcowboys_1_1_g_p_agent_registers_1_1iterator.md)



_Iterator class for_ [_**GPAgentRegisters**_](classcowboys_1_1_g_p_agent_registers.md) _TODO: Just pass in the vector Iterator._

* `#include <GPAgentsRegisters.hpp>`





































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**iterator**](#function-iterator) (size\_t index, [**GPAgentRegisters**](classcowboys_1_1_g_p_agent_registers.md) & regs) <br> |
|  bool | [**operator!=**](#function-operator) (const [**iterator**](classcowboys_1_1_g_p_agent_registers_1_1iterator.md) & other) const<br>_Overload not equal operator._  |
|  size\_t & | [**operator\***](#function-operator_1) () <br> |
|  [**iterator**](classcowboys_1_1_g_p_agent_registers_1_1iterator.md) & | [**operator++**](#function-operator_2) () <br> |
|  bool | [**operator==**](#function-operator_3) (const [**iterator**](classcowboys_1_1_g_p_agent_registers_1_1iterator.md) & other) const<br>_Overload post-increment operator._  |




























## Public Functions Documentation




### function iterator 


```C++
inline cowboys::GPAgentRegisters::iterator::iterator (
    size_t index,
    GPAgentRegisters & regs
) 
```



Constructor for iterator 

**Parameters:**


* `index` 
* `regs` 




        



### function operator!= 

_Overload not equal operator._ 
```C++
inline bool cowboys::GPAgentRegisters::iterator::operator!= (
    const iterator & other
) const
```





**Parameters:**


* `other` 



**Returns:**







        



### function operator\* 


```C++
inline size_t & cowboys::GPAgentRegisters::iterator::operator* () 
```



Overload dereference operator 

**Returns:**







        



### function operator++ 


```C++
inline iterator & cowboys::GPAgentRegisters::iterator::operator++ () 
```



Overload pre-increment operator 

**Returns:**







        



### function operator== 

_Overload post-increment operator._ 
```C++
inline bool cowboys::GPAgentRegisters::iterator::operator== (
    const iterator & other
) const
```





**Parameters:**


* `other` 



**Returns:**







        

------------------------------
The documentation for this class was generated from the following file `source/Agents/GP/GPAgentsRegisters.hpp`

