

# Struct cowboys::CGPParameters



[**ClassList**](annotated.md) **>** [**cowboys**](namespacecowboys.md) **>** [**CGPParameters**](structcowboys_1_1_c_g_p_parameters.md)



_Holds the parameters that define the structure of a cartesian graph._ 

* `#include <CGPGenotype.hpp>`





















## Public Attributes

| Type | Name |
| ---: | :--- |
|  size\_t | [**layers\_back**](#variable-layers_back)   = {0}<br>_The number of layers backward that a node can connect to._  |
|  size\_t | [**num\_inputs**](#variable-num_inputs)   = {0}<br>_The number of inputs to the graph._  |
|  size\_t | [**num\_layers**](#variable-num_layers)   = {0}<br>_The number of middle layers in the graph._  |
|  size\_t | [**num\_nodes\_per\_layer**](#variable-num_nodes_per_layer)   = {0}<br>_The number of nodes per middle layer._  |
|  size\_t | [**num\_outputs**](#variable-num_outputs)   = {0}<br>_The number of outputs from the graph._  |
















## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**CGPParameters**](#function-cgpparameters-12) () = default<br> |
|   | [**CGPParameters**](#function-cgpparameters-22) (size\_t num\_inputs, size\_t num\_outputs, size\_t num\_layers, size\_t num\_nodes\_per\_layer, size\_t layers\_back) <br>_Constructor for the cartesian graph parameters._  |
|  size\_t | [**GetFunctionalNodeCount**](#function-getfunctionalnodecount) () const<br>_Returns the number of functional nodes in the graph._  |
|  bool | [**operator==**](#function-operator) (const [**CGPParameters**](structcowboys_1_1_c_g_p_parameters.md) & other) const<br>_Check if two_ [_**CGPParameters**_](structcowboys_1_1_c_g_p_parameters.md) _are equal._ |




























## Public Attributes Documentation




### variable layers\_back 

```C++
size_t layers_back;
```






### variable num\_inputs 

```C++
size_t num_inputs;
```






### variable num\_layers 

```C++
size_t num_layers;
```






### variable num\_nodes\_per\_layer 

```C++
size_t num_nodes_per_layer;
```






### variable num\_outputs 

```C++
size_t num_outputs;
```



## Public Functions Documentation




### function CGPParameters [1/2]

```C++
cowboys::CGPParameters::CGPParameters () = default
```






### function CGPParameters [2/2]

```C++
inline cowboys::CGPParameters::CGPParameters (
    size_t num_inputs,
    size_t num_outputs,
    size_t num_layers,
    size_t num_nodes_per_layer,
    size_t layers_back
) 
```






### function GetFunctionalNodeCount 

_Returns the number of functional nodes in the graph._ 
```C++
inline size_t cowboys::CGPParameters::GetFunctionalNodeCount () const
```





**Returns:**

The number of functional nodes in the graph. 





        



### function operator== 

_Check if two_ [_**CGPParameters**_](structcowboys_1_1_c_g_p_parameters.md) _are equal._
```C++
inline bool cowboys::CGPParameters::operator== (
    const CGPParameters & other
) const
```





**Parameters:**


* `other` The other [**CGPParameters**](structcowboys_1_1_c_g_p_parameters.md) to compare to. 



**Returns:**

True if the two [**CGPParameters**](structcowboys_1_1_c_g_p_parameters.md) are equal, false otherwise. 





        

------------------------------
The documentation for this class was generated from the following file `source/Agents/GP/CGPGenotype.hpp`

