

# Class cowboys::GraphNode



[**ClassList**](annotated.md) **>** [**cowboys**](namespacecowboys.md) **>** [**GraphNode**](classcowboys_1_1_graph_node.md)



_A node in a decision graph._ [More...](#detailed-description)

* `#include <GraphNode.hpp>`



Inherits the following classes: std::enable_shared_from_this< GraphNode >


































## Public Functions

| Type | Name |
| ---: | :--- |
|  void | [**AddInput**](#function-addinput) (std::shared\_ptr&lt; [**GraphNode**](classcowboys_1_1_graph_node.md) &gt; node) <br>_Add an input node to this node._  |
|  void | [**AddInputs**](#function-addinputs) (const std::vector&lt; std::shared\_ptr&lt; [**GraphNode**](classcowboys_1_1_graph_node.md) &gt; &gt; & nodes) <br>_Append nodes in a vector to this node's list of inputs._  |
|  double | [**GetDefaultOutput**](#function-getdefaultoutput) () const<br>_Get the default output of this node._  |
|  std::vector&lt; double &gt; | [**GetInputValues**](#function-getinputvalues-12) () const<br>_Get the output values of the inputs of this node._  |
|  std::optional&lt; std::vector&lt; double &gt; &gt; | [**GetInputValues**](#function-getinputvalues-22) (const std::array&lt; size\_t, N &gt; & indices) const<br>_Get the output values of the inputs of this node given an array of indices._  |
|  double | [**GetOutput**](#function-getoutput) () const<br>_Get the output of this node. Performs caching._  |
|   | [**GraphNode**](#function-graphnode-14) () = default<br> |
|   | [**GraphNode**](#function-graphnode-24) (double default\_value) <br>_TODO: Check guidelines for this._  |
|   | [**GraphNode**](#function-graphnode-34) ([**NodeFunction**](structcowboys_1_1_node_function.md) function) <br> |
|   | [**GraphNode**](#function-graphnode-44) ([**InnerFunction**](namespacecowboys.md#typedef-innerfunction) function) <br> |
|  bool | [**IsCacheValid**](#function-iscachevalid) () const<br>_Check if the cached output is valid._  |
|  void | [**SetDefaultOutput**](#function-setdefaultoutput) (double value) <br>_Set the default output of this node._  |
|  void | [**SetFunctionPointer**](#function-setfunctionpointer-12) ([**NodeFunction**](structcowboys_1_1_node_function.md) function) <br>_Set the function pointer of this node._  |
|  void | [**SetFunctionPointer**](#function-setfunctionpointer-22) ([**InnerFunction**](namespacecowboys.md#typedef-innerfunction) inner\_function) <br>_Set the function pointer of this node._  |
|  void | [**SetInputs**](#function-setinputs) (std::vector&lt; std::shared\_ptr&lt; [**GraphNode**](classcowboys_1_1_graph_node.md) &gt; &gt; nodes) <br>_Set the input nodes of this node._  |
|   | [**~GraphNode**](#function-graphnode) () = default<br> |








## Protected Attributes

| Type | Name |
| ---: | :--- |
|  double | [**cached\_output**](#variable-cached_output)   = {0}<br>_The cached output of this node._  |
|  bool | [**cached\_output\_valid**](#variable-cached_output_valid)   = {false}<br>_Flag indicating whether the cached output is valid._  |
|  double | [**default\_output**](#variable-default_output)   = {0}<br>_The default output of this node._  |
|  [**NodeFunction**](structcowboys_1_1_node_function.md) | [**function\_pointer**](#variable-function_pointer)  <br>_The function that operates on the outputs from a node's input nodes._  |
|  std::vector&lt; std::shared\_ptr&lt; [**GraphNode**](classcowboys_1_1_graph_node.md) &gt; &gt; | [**inputs**](#variable-inputs)  <br>_The input nodes to this node._  |
|  std::vector&lt; [**GraphNode**](classcowboys_1_1_graph_node.md) \* &gt; | [**outputs**](#variable-outputs)  <br>_The nodes connected to this node's output._  |
















## Protected Functions

| Type | Name |
| ---: | :--- |
|  void | [**AddOutput**](#function-addoutput) ([**GraphNode**](classcowboys_1_1_graph_node.md) \* node) <br>_Add an output node to this node. Used for cache invalidation._  |
|  void | [**RecursiveInvalidateCache**](#function-recursiveinvalidatecache) () const<br>_Invalidates this node's cache and the caches of all nodes that depend on this node._  |




# Detailed Description




**Note:**

This should always be a shared pointer. Caching will not work otherwise. 





    
## Public Functions Documentation




### function AddInput 

_Add an input node to this node._ 
```C++
inline void cowboys::GraphNode::AddInput (
    std::shared_ptr< GraphNode > node
) 
```





**Parameters:**


* `node` The node to add as an input. 




        



### function AddInputs 

_Append nodes in a vector to this node's list of inputs._ 
```C++
inline void cowboys::GraphNode::AddInputs (
    const std::vector< std::shared_ptr< GraphNode > > & nodes
) 
```





**Parameters:**


* `nodes` The nodes to add as inputs. 




        



### function GetDefaultOutput 

_Get the default output of this node._ 
```C++
inline double cowboys::GraphNode::GetDefaultOutput () const
```





**Returns:**

The default output. 





        



### function GetInputValues [1/2]

_Get the output values of the inputs of this node._ 
```C++
inline std::vector< double > cowboys::GraphNode::GetInputValues () const
```





**Returns:**

A vector of doubles representing the input values. 





        



### function GetInputValues [2/2]

_Get the output values of the inputs of this node given an array of indices._ 
```C++
template<size_t N>
inline std::optional< std::vector< double > > cowboys::GraphNode::GetInputValues (
    const std::array< size_t, N > & indices
) const
```





**Template parameters:**


* `N` The size of the indices array. 



**Parameters:**


* `indices` The indices of the inputs to get the output values of. 



**Returns:**

A vector of doubles representing the input values in the same order of the indices. 





        



### function GetOutput 

_Get the output of this node. Performs caching._ 
```C++
inline double cowboys::GraphNode::GetOutput () const
```





**Returns:**

The output of this node. 





        



### function GraphNode [1/4]

```C++
cowboys::GraphNode::GraphNode () = default
```






### function GraphNode [2/4]

```C++
inline cowboys::GraphNode::GraphNode (
    double default_value
) 
```






### function GraphNode [3/4]

```C++
inline cowboys::GraphNode::GraphNode (
    NodeFunction function
) 
```






### function GraphNode [4/4]

```C++
inline cowboys::GraphNode::GraphNode (
    InnerFunction function
) 
```






### function IsCacheValid 

_Check if the cached output is valid._ 
```C++
inline bool cowboys::GraphNode::IsCacheValid () const
```





**Returns:**

True if the cached output is valid, false otherwise. 





        



### function SetDefaultOutput 

_Set the default output of this node._ 
```C++
inline void cowboys::GraphNode::SetDefaultOutput (
    double value
) 
```





**Parameters:**


* `value` The new default output. 




        



### function SetFunctionPointer [1/2]

_Set the function pointer of this node._ 
```C++
inline void cowboys::GraphNode::SetFunctionPointer (
    NodeFunction function
) 
```





**Parameters:**


* `function` The function for this node to use. 




        



### function SetFunctionPointer [2/2]

_Set the function pointer of this node._ 
```C++
inline void cowboys::GraphNode::SetFunctionPointer (
    InnerFunction inner_function
) 
```





**Parameters:**


* `inner_function` The inner function for this node to use. Will be wrapped in a [**NodeFunction**](structcowboys_1_1_node_function.md). 




        



### function SetInputs 

_Set the input nodes of this node._ 
```C++
inline void cowboys::GraphNode::SetInputs (
    std::vector< std::shared_ptr< GraphNode > > nodes
) 
```





**Parameters:**


* `nodes` 




        



### function ~GraphNode 

```C++
cowboys::GraphNode::~GraphNode () = default
```



## Protected Attributes Documentation




### variable cached\_output 

```C++
double cached_output;
```






### variable cached\_output\_valid 

```C++
bool cached_output_valid;
```






### variable default\_output 

```C++
double default_output;
```






### variable function\_pointer 

```C++
NodeFunction function_pointer;
```






### variable inputs 

```C++
std::vector<std::shared_ptr<GraphNode> > inputs;
```






### variable outputs 

```C++
std::vector<GraphNode *> outputs;
```



## Protected Functions Documentation




### function AddOutput 

_Add an output node to this node. Used for cache invalidation._ 
```C++
inline void cowboys::GraphNode::AddOutput (
    GraphNode * node
) 
```





**Parameters:**


* `node` The node to add as an output. 




        



### function RecursiveInvalidateCache 

```C++
inline void cowboys::GraphNode::RecursiveInvalidateCache () const
```




------------------------------
The documentation for this class was generated from the following file `source/Agents/GP/GraphNode.hpp`

