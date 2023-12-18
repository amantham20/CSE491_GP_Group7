

# Class cowboys::CGPGenotype



[**ClassList**](annotated.md) **>** [**cowboys**](namespacecowboys.md) **>** [**CGPGenotype**](classcowboys_1_1_c_g_p_genotype.md)



_Holds all the information that uniquely defines a cartesian graph._ 

* `#include <CGPGenotype.hpp>`





































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**CGPGenotype**](#function-cgpgenotype-14) () = default<br>_Default constructor for the cartesian graph genotype. Will have 0 functional nodes._  |
|   | [**CGPGenotype**](#function-cgpgenotype-24) (const [**CGPParameters**](structcowboys_1_1_c_g_p_parameters.md) & parameters) <br>_Constructor for the cartesian graph genotype. Initializes the genotype with the given parameters and leaves everything default (nodes will be unconnected)._  |
|   | [**CGPGenotype**](#function-cgpgenotype-34) (const [**CGPGenotype**](classcowboys_1_1_c_g_p_genotype.md) & other) <br>_Copy constructor for the cartesian graph genotype._  |
|   | [**CGPGenotype**](#function-cgpgenotype-44) ([**CGPGenotype**](classcowboys_1_1_c_g_p_genotype.md) && other) noexcept<br>_Move constructor for the cartesian graph genotype._  |
|  [**CGPGenotype**](classcowboys_1_1_c_g_p_genotype.md) & | [**Configure**](#function-configure) (const std::string & encoded\_genotype) <br>_Configures this genotype from an encoded string._  |
|  std::string | [**Export**](#function-export) () const<br>_Exports this genotype into a string representation._  |
|  std::string | [**ExportRaw**](#function-exportraw) () const<br>_Exports this genotype into a string representation._  |
|  size\_t | [**GetLayersBack**](#function-getlayersback) () const<br>_Returns the number of layers backward that a node can connect to._  |
|  size\_t | [**GetNumConnections**](#function-getnumconnections) () const<br>_Returns the number of connected connections in the graph._  |
|  size\_t | [**GetNumFunctionalNodes**](#function-getnumfunctionalnodes) () const<br>_Returns the number of functional (non-input) nodes in the graph._  |
|  size\_t | [**GetNumInputs**](#function-getnuminputs) () const<br>_Returns the number of inputs to the graph._  |
|  size\_t | [**GetNumLayers**](#function-getnumlayers) () const<br>_Returns the number of middle layers in the graph._  |
|  size\_t | [**GetNumNodesPerLayer**](#function-getnumnodesperlayer) () const<br>_Returns the number of nodes per middle layer._  |
|  size\_t | [**GetNumOutputs**](#function-getnumoutputs) () const<br>_Returns the number of outputs from the graph._  |
|  size\_t | [**GetNumPossibleConnections**](#function-getnumpossibleconnections) () const<br>_Returns the number of possible connections in the graph._  |
|  bool | [**HasInputConnections**](#function-hasinputconnections) () const<br>_Identify if the genome has any non-zero input connections in it._  |
|  void | [**InitGenotype**](#function-initgenotype) () <br>_Initializes an empty genotype with the cartesian graph parameters._  |
|  [**CGPGenotype**](classcowboys_1_1_c_g_p_genotype.md) & | [**Mutate**](#function-mutate) (double mutation\_rate, [**GPAgentBase**](classcowboys_1_1_g_p_agent_base.md) & agent, std::function&lt; void([**CGPNodeGene**](structcowboys_1_1_c_g_p_node_gene.md) &)&gt; mutation) <br>_Mutates the genotype._  |
|  [**CGPGenotype**](classcowboys_1_1_c_g_p_genotype.md) & | [**MutateConnections**](#function-mutateconnections) (double mutation\_rate, [**GPAgentBase**](classcowboys_1_1_g_p_agent_base.md) & agent) <br>_Mutates the input connections of the genotype._  |
|  [**CGPGenotype**](classcowboys_1_1_c_g_p_genotype.md) & | [**MutateDefault**](#function-mutatedefault) (double mutation\_rate, [**GPAgentBase**](classcowboys_1_1_g_p_agent_base.md) & agent, size\_t num\_functions=FUNCTION\_SET.size()) <br>_Performs a mutation on the genotype with default parameters._  |
|  [**CGPGenotype**](classcowboys_1_1_c_g_p_genotype.md) & | [**MutateFunctions**](#function-mutatefunctions) (double mutation\_rate, size\_t num\_functions, [**GPAgentBase**](classcowboys_1_1_g_p_agent_base.md) & agent) <br>_Mutates the genotype by changing the function of each node with a given probability between 0 and 1._  |
|  [**CGPGenotype**](classcowboys_1_1_c_g_p_genotype.md) & | [**MutateHeader**](#function-mutateheader) (double mutation\_rate, [**GPAgentBase**](classcowboys_1_1_g_p_agent_base.md) & agent) <br>_Mutates the header of the genotype._  |
|  [**CGPGenotype**](classcowboys_1_1_c_g_p_genotype.md) & | [**MutateOutputs**](#function-mutateoutputs) (double mutation\_rate, double mean, double std, [**GPAgentBase**](classcowboys_1_1_g_p_agent_base.md) & agent, bool additive=true) <br>_Mutates the genotype, changing the default output of nodes with probability between 0 and 1._  |
|  void | [**SetParameters**](#function-setparameters) (const [**CGPParameters**](structcowboys_1_1_c_g_p_parameters.md) & params) <br>_Set the parameters of the cartesian graph._  |
|  std::vector&lt; [**CGPNodeGene**](structcowboys_1_1_c_g_p_node_gene.md) &gt;::iterator | [**begin**](#function-begin-12) () <br>_Returns the iterator to the beginning of the node configurations._  |
|  std::vector&lt; [**CGPNodeGene**](structcowboys_1_1_c_g_p_node_gene.md) &gt;::const\_iterator | [**begin**](#function-begin-22) () const<br>_Returns the const iterator to the beginning of the node configurations._  |
|  std::vector&lt; [**CGPNodeGene**](structcowboys_1_1_c_g_p_node_gene.md) &gt;::const\_iterator | [**cbegin**](#function-cbegin) () const<br>_Returns the const iterator to the beginning of the node configurations._  |
|  std::vector&lt; [**CGPNodeGene**](structcowboys_1_1_c_g_p_node_gene.md) &gt;::const\_iterator | [**cend**](#function-cend) () const<br>_Returns the const iterator to the end of the node configurations._  |
|  std::vector&lt; [**CGPNodeGene**](structcowboys_1_1_c_g_p_node_gene.md) &gt;::iterator | [**end**](#function-end-12) () <br>_Returns the iterator to the end of the node configurations._  |
|  std::vector&lt; [**CGPNodeGene**](structcowboys_1_1_c_g_p_node_gene.md) &gt;::const\_iterator | [**end**](#function-end-22) () const<br>_Returns the const iterator to the end of the node configurations._  |
|  [**CGPGenotype**](classcowboys_1_1_c_g_p_genotype.md) & | [**operator=**](#function-operator) (const [**CGPGenotype**](classcowboys_1_1_c_g_p_genotype.md) & other) <br>_Copy assignment operator for the cartesian graph genotype._  |
|  [**CGPGenotype**](classcowboys_1_1_c_g_p_genotype.md) & | [**operator=**](#function-operator_1) ([**CGPGenotype**](classcowboys_1_1_c_g_p_genotype.md) && other) noexcept<br>_Move assignment operator for the cartesian graph genotype._  |
|  bool | [**operator==**](#function-operator_2) (const [**CGPGenotype**](classcowboys_1_1_c_g_p_genotype.md) & other) const<br>_Check if two CGPGenotypes are equal._ [_**CGPParameters**_](structcowboys_1_1_c_g_p_parameters.md) _and CGPNodeGenes should be equal._ |
|   | [**~CGPGenotype**](#function-cgpgenotype) () = default<br> |








## Protected Attributes

| Type | Name |
| ---: | :--- |
|  std::vector&lt; [**CGPNodeGene**](structcowboys_1_1_c_g_p_node_gene.md) &gt; | [**nodes**](#variable-nodes)  <br>_The node configurations._  |
|  [**CGPParameters**](structcowboys_1_1_c_g_p_parameters.md) | [**params**](#variable-params)  <br>_The parameters of the cartesian graph._  |




















## Public Functions Documentation




### function CGPGenotype [1/4]

```C++
cowboys::CGPGenotype::CGPGenotype () = default
```






### function CGPGenotype [2/4]

_Constructor for the cartesian graph genotype. Initializes the genotype with the given parameters and leaves everything default (nodes will be unconnected)._ 
```C++
inline cowboys::CGPGenotype::CGPGenotype (
    const CGPParameters & parameters
) 
```





**Parameters:**


* `parameters` The parameters of the cartesian graph. 




        



### function CGPGenotype [3/4]

_Copy constructor for the cartesian graph genotype._ 
```C++
inline cowboys::CGPGenotype::CGPGenotype (
    const CGPGenotype & other
) 
```





**Parameters:**


* `other` The other cartesian graph genotype to copy from. 




        



### function CGPGenotype [4/4]

_Move constructor for the cartesian graph genotype._ 
```C++
inline cowboys::CGPGenotype::CGPGenotype (
    CGPGenotype && other
) noexcept
```





**Parameters:**


* `other` The other cartesian graph genotype to move from. 




        



### function Configure 

_Configures this genotype from an encoded string._ 
```C++
inline CGPGenotype & cowboys::CGPGenotype::Configure (
    const std::string & encoded_genotype
) 
```





**Parameters:**


* `encoded_genotype` The encoded genotype. 



**Returns:**

This genotype. 





        



### function Export 

_Exports this genotype into a string representation._ 
```C++
inline std::string cowboys::CGPGenotype::Export () const
```





**Returns:**

The string representation of this genotype. 





        



### function ExportRaw 

_Exports this genotype into a string representation._ 
```C++
inline std::string cowboys::CGPGenotype::ExportRaw () const
```





**Returns:**

The string representation of this genotype. 





        



### function GetLayersBack 

_Returns the number of layers backward that a node can connect to._ 
```C++
inline size_t cowboys::CGPGenotype::GetLayersBack () const
```





**Returns:**

The number of layers backward that a node can connect to. 





        



### function GetNumConnections 

_Returns the number of connected connections in the graph._ 
```C++
inline size_t cowboys::CGPGenotype::GetNumConnections () const
```





**Returns:**

The number of connected connections in the graph. 





        



### function GetNumFunctionalNodes 

_Returns the number of functional (non-input) nodes in the graph._ 
```C++
inline size_t cowboys::CGPGenotype::GetNumFunctionalNodes () const
```





**Returns:**

The number of functional (non-input) nodes in the graph. 





        



### function GetNumInputs 

_Returns the number of inputs to the graph._ 
```C++
inline size_t cowboys::CGPGenotype::GetNumInputs () const
```





**Returns:**

The number of inputs to the graph. 





        



### function GetNumLayers 

_Returns the number of middle layers in the graph._ 
```C++
inline size_t cowboys::CGPGenotype::GetNumLayers () const
```





**Returns:**

The number of middle layers in the graph. 





        



### function GetNumNodesPerLayer 

_Returns the number of nodes per middle layer._ 
```C++
inline size_t cowboys::CGPGenotype::GetNumNodesPerLayer () const
```





**Returns:**

The number of nodes per middle layer. 





        



### function GetNumOutputs 

_Returns the number of outputs from the graph._ 
```C++
inline size_t cowboys::CGPGenotype::GetNumOutputs () const
```





**Returns:**

The number of outputs from the graph. 





        



### function GetNumPossibleConnections 

_Returns the number of possible connections in the graph._ 
```C++
inline size_t cowboys::CGPGenotype::GetNumPossibleConnections () const
```





**Returns:**

The number of possible connections in the graph. 





        



### function HasInputConnections 

_Identify if the genome has any non-zero input connections in it._ 
```C++
inline bool cowboys::CGPGenotype::HasInputConnections () const
```





**Returns:**

Bool value to indicate if any input connections non-zero. 





        



### function InitGenotype 

```C++
inline void cowboys::CGPGenotype::InitGenotype () 
```






### function Mutate 

_Mutates the genotype._ 
```C++
inline CGPGenotype & cowboys::CGPGenotype::Mutate (
    double mutation_rate,
    GPAgentBase & agent,
    std::function< void( CGPNodeGene &)> mutation
) 
```





**Parameters:**


* `mutation_rate` Value between 0 and 1 representing the probability of mutating a value. 
* `mutation` The function to use for mutating the output. The function will receive the node gene as a parameter. 



**Returns:**

This genotype. 





        



### function MutateConnections 

_Mutates the input connections of the genotype._ 
```C++
inline CGPGenotype & cowboys::CGPGenotype::MutateConnections (
    double mutation_rate,
    GPAgentBase & agent
) 
```





**Parameters:**


* `mutation_rate` The probability of mutating a connection. For a given connection, if it is chosen to be mutated, there is a 50% chance it will stay the same. 
* `agent` The agent to use for random number generation. 



**Returns:**

This genotype. 





        



### function MutateDefault 

_Performs a mutation on the genotype with default parameters._ 
```C++
inline CGPGenotype & cowboys::CGPGenotype::MutateDefault (
    double mutation_rate,
    GPAgentBase & agent,
    size_t num_functions=FUNCTION_SET.size()
) 
```





**Parameters:**


* `mutation_rate` Value between 0 and 1 representing the probability of mutating each value. 
* `agent` The agent to use for random number generation. 
* `num_functions` The number of functions available to the nodes. 



**Returns:**

This genotype. 





        



### function MutateFunctions 

_Mutates the genotype by changing the function of each node with a given probability between 0 and 1._ 
```C++
inline CGPGenotype & cowboys::CGPGenotype::MutateFunctions (
    double mutation_rate,
    size_t num_functions,
    GPAgentBase & agent
) 
```





**Parameters:**


* `mutation_rate` The probability of changing the function of a node. 
* `num_functions` The number of functions available to the nodes. 



**Returns:**

This genotype. 





        



### function MutateHeader 

_Mutates the header of the genotype._ 
```C++
inline CGPGenotype & cowboys::CGPGenotype::MutateHeader (
    double mutation_rate,
    GPAgentBase & agent
) 
```





**Parameters:**


* `mutation_rate` Value between 0 and 1 representing the probability of mutating each value. 
* `agent` The agent to use for random number generation. 



**Returns:**

This genotype. 





        



### function MutateOutputs 

_Mutates the genotype, changing the default output of nodes with probability between 0 and 1._ 
```C++
inline CGPGenotype & cowboys::CGPGenotype::MutateOutputs (
    double mutation_rate,
    double mean,
    double std,
    GPAgentBase & agent,
    bool additive=true
) 
```





**Parameters:**


* `mutation_rate` Value between 0 and 1 representing the probability of mutating each value. 
* `min` The minimum value to generate for mutation. 
* `max` The maximum value to generate for mutation. 



**Returns:**

This genotype. 





        



### function SetParameters 

_Set the parameters of the cartesian graph._ 
```C++
inline void cowboys::CGPGenotype::SetParameters (
    const CGPParameters & params
) 
```





**Parameters:**


* `params` The parameters of the cartesian graph. Basically a 5-tuple. 




        



### function begin [1/2]

_Returns the iterator to the beginning of the node configurations._ 
```C++
inline std::vector< CGPNodeGene >::iterator cowboys::CGPGenotype::begin () 
```





**Returns:**

The iterator to the beginning of the node configurations. 





        



### function begin [2/2]

_Returns the const iterator to the beginning of the node configurations._ 
```C++
inline std::vector< CGPNodeGene >::const_iterator cowboys::CGPGenotype::begin () const
```





**Returns:**

The const iterator to the beginning of the node configurations. 





        



### function cbegin 

_Returns the const iterator to the beginning of the node configurations._ 
```C++
inline std::vector< CGPNodeGene >::const_iterator cowboys::CGPGenotype::cbegin () const
```





**Returns:**

The const iterator to the beginning of the node configurations. 





        



### function cend 

_Returns the const iterator to the end of the node configurations._ 
```C++
inline std::vector< CGPNodeGene >::const_iterator cowboys::CGPGenotype::cend () const
```





**Returns:**

The const iterator to the end of the node configurations. 





        



### function end [1/2]

_Returns the iterator to the end of the node configurations._ 
```C++
inline std::vector< CGPNodeGene >::iterator cowboys::CGPGenotype::end () 
```





**Returns:**

The iterator to the end of the node configurations. 





        



### function end [2/2]

_Returns the const iterator to the end of the node configurations._ 
```C++
inline std::vector< CGPNodeGene >::const_iterator cowboys::CGPGenotype::end () const
```





**Returns:**

The const iterator to the end of the node configurations. 





        



### function operator= 

_Copy assignment operator for the cartesian graph genotype._ 
```C++
inline CGPGenotype & cowboys::CGPGenotype::operator= (
    const CGPGenotype & other
) 
```





**Parameters:**


* `other` The other cartesian graph genotype to copy from. 



**Returns:**

This cartesian graph genotype. 





        



### function operator= 

_Move assignment operator for the cartesian graph genotype._ 
```C++
inline CGPGenotype & cowboys::CGPGenotype::operator= (
    CGPGenotype && other
) noexcept
```





**Parameters:**


* `other` The other cartesian graph genotype to move from. 



**Returns:**

This cartesian graph genotype. 





        



### function operator== 

_Check if two CGPGenotypes are equal._ [_**CGPParameters**_](structcowboys_1_1_c_g_p_parameters.md) _and CGPNodeGenes should be equal._
```C++
inline bool cowboys::CGPGenotype::operator== (
    const CGPGenotype & other
) const
```





**Parameters:**


* `other` The other [**CGPGenotype**](classcowboys_1_1_c_g_p_genotype.md) to compare to. 



**Returns:**

True if the two CGPGenotypes are equal, false otherwise. 





        



### function ~CGPGenotype 

```C++
cowboys::CGPGenotype::~CGPGenotype () = default
```



## Protected Attributes Documentation




### variable nodes 

```C++
std::vector<CGPNodeGene> nodes;
```






### variable params 

```C++
CGPParameters params;
```


## Friends Documentation





### friend operator&lt;&lt; 

_Write the genotype representation to an output stream._ 
```C++
inline std::ostream & cowboys::CGPGenotype::operator<< (
    std::ostream & os,
    const CGPGenotype & genotype
) 
```





**Parameters:**


* `os` The output stream to write to. 
* `genotype` The genotype to write. 



**Returns:**

The output stream. 





        

------------------------------
The documentation for this class was generated from the following file `source/Agents/GP/CGPGenotype.hpp`

