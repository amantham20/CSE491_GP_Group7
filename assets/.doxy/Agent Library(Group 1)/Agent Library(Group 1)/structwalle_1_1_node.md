

# Struct walle::Node



[**ClassList**](annotated.md) **>** [**walle**](namespacewalle.md) **>** [**Node**](structwalle_1_1_node.md)



[_**Node**_](structwalle_1_1_node.md) _class to hold information about positions for A\* search._

* `#include <AgentLibary.hpp>`





















## Public Attributes

| Type | Name |
| ---: | :--- |
|  double | [**g**](#variable-g)  <br>_Cost from start to current node._  |
|  double | [**h**](#variable-h)  <br>_Heuristic (estimated cost from current node to goal)_  |
|  std::shared\_ptr&lt; [**Node**](structwalle_1_1_node.md) &gt; | [**parent**](#variable-parent)  <br>_How we got to this node (Used to construct final path)_  |
|  cse491::GridPosition | [**position**](#variable-position)  <br>_Where node is located._  |
















## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**Node**](#function-node) (const cse491::GridPosition & position, double g, double h, std::shared\_ptr&lt; [**Node**](structwalle_1_1_node.md) &gt; parent) <br> |
|  double | [**f**](#function-f) () const<br>_Calculate the total cost (f) of the node._  |




























## Public Attributes Documentation




### variable g 

```C++
double g;
```






### variable h 

```C++
double h;
```






### variable parent 

```C++
std::shared_ptr<Node> parent;
```






### variable position 

```C++
cse491::GridPosition position;
```



## Public Functions Documentation




### function Node 


```C++
inline walle::Node::Node (
    const cse491::GridPosition & position,
    double g,
    double h,
    std::shared_ptr< Node > parent
) 
```



Constructor for a node 

**Parameters:**


* `position` location on grid of this node 
* `g` actual distance to get from start to this node 
* `h` heuristic guess for distance from this node to end location 
* `parent` Used to construct path back at end 




        



### function f 

_Calculate the total cost (f) of the node._ 
```C++
inline double walle::Node::f () const
```





**Returns:**

sum of actual distance and heuristic distance 





        

------------------------------
The documentation for this class was generated from the following file `source/Agents/AgentLibary.hpp`

