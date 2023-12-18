

# Class cowboys::GraphBuilder



[**ClassList**](annotated.md) **>** [**cowboys**](namespacecowboys.md) **>** [**GraphBuilder**](classcowboys_1_1_graph_builder.md)



_A class for building graphs. Graphs are a generic representation, so this class is used to build the specific format of a Cartesian_ [_**Graph**_](classcowboys_1_1_graph.md) _, and also preset graphs._

* `#include <GraphBuilder.hpp>`





































## Public Functions

| Type | Name |
| ---: | :--- |
|  std::unique\_ptr&lt; [**Graph**](classcowboys_1_1_graph.md) &gt; | [**CartesianGraph**](#function-cartesiangraph) (const [**CGPGenotype**](classcowboys_1_1_c_g_p_genotype.md) & genotype, const std::vector&lt; [**InnerFunction**](namespacecowboys.md#typedef-innerfunction) &gt; & function\_set, const cse491::AgentBase \* agent=nullptr) <br>_Creates a decision graph from a CGP genotype._  |
|   | [**GraphBuilder**](#function-graphbuilder) () = default<br> |
|  std::unique\_ptr&lt; [**Graph**](classcowboys_1_1_graph.md) &gt; | [**VerticalPacer**](#function-verticalpacer) () <br>_Creates a decision graph for pacing up and down in a MazeWorld. Assumes that the inputs are in the format: prev\_action, current\_state, above\_state, below\_state, left\_state, right\_state._  |
|   | [**~GraphBuilder**](#function-graphbuilder) () = default<br> |




























## Public Functions Documentation




### function CartesianGraph 

_Creates a decision graph from a CGP genotype._ 
```C++
inline std::unique_ptr< Graph > cowboys::GraphBuilder::CartesianGraph (
    const CGPGenotype & genotype,
    const std::vector< InnerFunction > & function_set,
    const cse491::AgentBase * agent=nullptr
) 
```





**Parameters:**


* `genotype` The genotype to create the decision graph from. 
* `function_set` The set of functions available to the decision graph. 
* `agent` The agent that will be using the decision graph. 



**Returns:**

The decision graph. 





        



### function GraphBuilder 

```C++
cowboys::GraphBuilder::GraphBuilder () = default
```






### function VerticalPacer 

_Creates a decision graph for pacing up and down in a MazeWorld. Assumes that the inputs are in the format: prev\_action, current\_state, above\_state, below\_state, left\_state, right\_state._ 
```C++
inline std::unique_ptr< Graph > cowboys::GraphBuilder::VerticalPacer () 
```





**Parameters:**


* `action_vec` Assumes that the action outputs are in the format: up, down, left, right 



**Returns:**

The decision graph for a vertical pacer. 





        



### function ~GraphBuilder 

```C++
cowboys::GraphBuilder::~GraphBuilder () = default
```




------------------------------
The documentation for this class was generated from the following file `source/Agents/GP/GraphBuilder.hpp`

