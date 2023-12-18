

# Struct cowboys::CGPNodeGene



[**ClassList**](annotated.md) **>** [**cowboys**](namespacecowboys.md) **>** [**CGPNodeGene**](structcowboys_1_1_c_g_p_node_gene.md)



_Holds the representation of a cartesian graph node._ 

* `#include <CGPGenotype.hpp>`





















## Public Attributes

| Type | Name |
| ---: | :--- |
|  double | [**default\_output**](#variable-default_output)   = {0}<br>_The default output of the node._  |
|  size\_t | [**function\_idx**](#variable-function_idx)   = {0}<br>_The index of the function the node uses._  |
|  std::vector&lt; char &gt; | [**input\_connections**](#variable-input_connections)   = {}<br>_The input connections of this node. '1' means connected, '0' means not connected._  |
















## Public Functions

| Type | Name |
| ---: | :--- |
|  bool | [**operator==**](#function-operator) (const [**CGPNodeGene**](structcowboys_1_1_c_g_p_node_gene.md) & other) const<br>_Compare two CGPNodeGenes for equality._  |




























## Public Attributes Documentation




### variable default\_output 

```C++
double default_output;
```






### variable function\_idx 

```C++
size_t function_idx;
```






### variable input\_connections 

```C++
std::vector<char> input_connections;
```



## Public Functions Documentation




### function operator== 

_Compare two CGPNodeGenes for equality._ 
```C++
inline bool cowboys::CGPNodeGene::operator== (
    const CGPNodeGene & other
) const
```





**Parameters:**


* `other` The other [**CGPNodeGene**](structcowboys_1_1_c_g_p_node_gene.md) to compare to. 



**Returns:**

True if the two CGPNodeGenes are equal, false otherwise. 





        

------------------------------
The documentation for this class was generated from the following file `source/Agents/GP/CGPGenotype.hpp`

