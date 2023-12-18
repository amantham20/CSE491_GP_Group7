

# Struct cowboys::NodeFunction



[**ClassList**](annotated.md) **>** [**cowboys**](namespacecowboys.md) **>** [**NodeFunction**](structcowboys_1_1_node_function.md)



_A function pointer wrapper that holds extra arguments for the function pointer._ 

* `#include <GraphNode.hpp>`





















## Public Attributes

| Type | Name |
| ---: | :--- |
|  const cse491::AgentBase \* | [**agent**](#variable-agent)   = {nullptr}<br> |
|  [**InnerFunction**](namespacecowboys.md#typedef-innerfunction) | [**function**](#variable-function)   = {nullptr}<br> |
















## Public Functions

| Type | Name |
| ---: | :--- |
|  bool | [**IsNull**](#function-isnull) () const<br> |
|  double | [**operator()**](#function-operator()) (const [**GraphNode**](classcowboys_1_1_graph_node.md) & node) const<br> |




























## Public Attributes Documentation




### variable agent 

```C++
const cse491::AgentBase* agent;
```






### variable function 

```C++
InnerFunction function;
```



## Public Functions Documentation




### function IsNull 

```C++
inline bool cowboys::NodeFunction::IsNull () const
```






### function operator() 

```C++
inline double cowboys::NodeFunction::operator() (
    const GraphNode & node
) const
```




------------------------------
The documentation for this class was generated from the following file `source/Agents/GP/GraphNode.hpp`

