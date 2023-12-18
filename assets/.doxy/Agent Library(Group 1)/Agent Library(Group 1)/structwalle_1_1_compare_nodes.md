

# Struct walle::CompareNodes



[**ClassList**](annotated.md) **>** [**walle**](namespacewalle.md) **>** [**CompareNodes**](structwalle_1_1_compare_nodes.md)



_Custom comparison function for priority queue._ [More...](#detailed-description)

* `#include <AgentLibary.hpp>`





































## Public Functions

| Type | Name |
| ---: | :--- |
|  bool | [**operator()**](#function-operator()) (const std::shared\_ptr&lt; [**walle::Node**](structwalle_1_1_node.md) &gt; & a, const std::shared\_ptr&lt; [**walle::Node**](structwalle_1_1_node.md) &gt; & b) const<br> |




























# Detailed Description




**Returns:**

if a has a greater total cost than b 





    
## Public Functions Documentation




### function operator() 

```C++
inline bool walle::CompareNodes::operator() (
    const std::shared_ptr< walle::Node > & a,
    const std::shared_ptr< walle::Node > & b
) const
```




------------------------------
The documentation for this class was generated from the following file `source/Agents/AgentLibary.hpp`

