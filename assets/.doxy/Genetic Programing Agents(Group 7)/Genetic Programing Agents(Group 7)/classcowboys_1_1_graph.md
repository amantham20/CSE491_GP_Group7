

# Class cowboys::Graph



[**ClassList**](annotated.md) **>** [**cowboys**](namespacecowboys.md) **>** [**Graph**](classcowboys_1_1_graph.md)



_A graph of nodes that can be used to make decisions._ 

* `#include <Graph.hpp>`





































## Public Functions

| Type | Name |
| ---: | :--- |
|  void | [**AddLayer**](#function-addlayer) (const GraphLayer & layer) <br>_Add a layer to the graph. Purely organizational, but important for CGP for determining the "layers back" parameter._  |
|  std::vector&lt; std::shared\_ptr&lt; [**GraphNode**](classcowboys_1_1_graph_node.md) &gt; &gt; | [**GetFunctionalNodes**](#function-getfunctionalnodes) () const<br>_Returns a vector of functional (non-input) nodes in the graph._  |
|  size\_t | [**GetLayerCount**](#function-getlayercount) () const<br>_Get the number of layers in the graph._  |
|  size\_t | [**GetNodeCount**](#function-getnodecount) () const<br>_Get the number of nodes in the graph._  |
|  std::vector&lt; std::shared\_ptr&lt; [**GraphNode**](classcowboys_1_1_graph_node.md) &gt; &gt; | [**GetNodes**](#function-getnodes) () const<br>_Returns a vector of all nodes in the graph._  |
|   | [**Graph**](#function-graph) () = default<br> |
|  size\_t | [**MakeDecision**](#function-makedecision) (const std::vector&lt; double &gt; & inputs, const std::vector&lt; size\_t &gt; & actions) <br>_Makes a decision based on the inputs and the action vector._  |
|   | [**~Graph**](#function-graph) () = default<br> |








## Protected Attributes

| Type | Name |
| ---: | :--- |
|  std::vector&lt; GraphLayer &gt; | [**layers**](#variable-layers)  <br>_Layers of nodes in the graph._  |




















## Public Functions Documentation




### function AddLayer 

_Add a layer to the graph. Purely organizational, but important for CGP for determining the "layers back" parameter._ 
```C++
inline void cowboys::Graph::AddLayer (
    const GraphLayer & layer
) 
```





**Parameters:**


* `layer` The layer of nodes to add. 




        



### function GetFunctionalNodes 

_Returns a vector of functional (non-input) nodes in the graph._ 
```C++
inline std::vector< std::shared_ptr< GraphNode > > cowboys::Graph::GetFunctionalNodes () const
```





**Returns:**

A vector of functional nodes in the graph. 





        



### function GetLayerCount 

_Get the number of layers in the graph._ 
```C++
inline size_t cowboys::Graph::GetLayerCount () const
```





**Returns:**

The number of layers in the graph. 





        



### function GetNodeCount 

_Get the number of nodes in the graph._ 
```C++
inline size_t cowboys::Graph::GetNodeCount () const
```





**Returns:**

The number of nodes in the graph. 





        



### function GetNodes 

_Returns a vector of all nodes in the graph._ 
```C++
inline std::vector< std::shared_ptr< GraphNode > > cowboys::Graph::GetNodes () const
```





**Returns:**

A vector of all nodes in the graph. 





        



### function Graph 

```C++
cowboys::Graph::Graph () = default
```






### function MakeDecision 

_Makes a decision based on the inputs and the action vector._ 
```C++
inline size_t cowboys::Graph::MakeDecision (
    const std::vector< double > & inputs,
    const std::vector< size_t > & actions
) 
```





**Parameters:**


* `inputs` The inputs to the graph. 
* `action_vec` The action vector. 



**Returns:**

The action to take. 





        



### function ~Graph 

```C++
cowboys::Graph::~Graph () = default
```



## Protected Attributes Documentation




### variable layers 

```C++
std::vector<GraphLayer> layers;
```




------------------------------
The documentation for this class was generated from the following file `source/Agents/GP/Graph.hpp`

