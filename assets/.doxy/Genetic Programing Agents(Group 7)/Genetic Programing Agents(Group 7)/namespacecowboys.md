

# Namespace cowboys



[**Namespace List**](namespaces.md) **>** [**cowboys**](namespacecowboys.md)



_An Agent based on genetic programming._ [More...](#detailed-description)














## Namespaces

| Type | Name |
| ---: | :--- |
| namespace | [**base64**](namespacecowboys_1_1base64.md) <br>_A namespace for_ [_**base64**_](namespacecowboys_1_1base64.md) _encoding and decoding. Does not convert to and from_[_**base64**_](namespacecowboys_1_1base64.md) _in the typical way. Only guarantees that x == b64\_inv(b64(x)), aside from doubles which have problems with precision, so x ~= b64\_inv(b64(x))._ |


## Classes

| Type | Name |
| ---: | :--- |
| class | [**CGPAgent**](classcowboys_1_1_c_g_p_agent.md) <br>_An agent based on cartesian genetic programming._  |
| class | [**CGPGenotype**](classcowboys_1_1_c_g_p_genotype.md) <br>_Holds all the information that uniquely defines a cartesian graph._  |
| struct | [**CGPNodeGene**](structcowboys_1_1_c_g_p_node_gene.md) <br>_Holds the representation of a cartesian graph node._  |
| struct | [**CGPParameters**](structcowboys_1_1_c_g_p_parameters.md) <br>_Holds the parameters that define the structure of a cartesian graph._  |
| class | [**GPAgent**](classcowboys_1_1_g_p_agent.md) <br> |
| class | [**GPAgentAnalyzer**](classcowboys_1_1_g_p_agent_analyzer.md) <br> |
| class | [**GPAgentBase**](classcowboys_1_1_g_p_agent_base.md) <br> |
| class | [**GPAgentRegisters**](classcowboys_1_1_g_p_agent_registers.md) <br>_Class to hold the registers of the agent._  |
| class | [**GPTrainingLoop**](classcowboys_1_1_g_p_training_loop.md) &lt;class AgentType, class EnvironmentType&gt;<br> |
| class | [**Graph**](classcowboys_1_1_graph.md) <br>_A graph of nodes that can be used to make decisions._  |
| class | [**GraphBuilder**](classcowboys_1_1_graph_builder.md) <br>_A class for building graphs. Graphs are a generic representation, so this class is used to build the specific format of a Cartesian_ [_**Graph**_](classcowboys_1_1_graph.md) _, and also preset graphs._ |
| class | [**GraphNode**](classcowboys_1_1_graph_node.md) <br>_A node in a decision graph._  |
| class | [**LGPAgent**](classcowboys_1_1_l_g_p_agent.md) <br> |
| struct | [**NodeFunction**](structcowboys_1_1_node_function.md) <br>_A function pointer wrapper that holds extra arguments for the function pointer._  |
| class | [**Sensors**](classcowboys_1_1_sensors.md) <br> |


## Public Types

| Type | Name |
| ---: | :--- |
| typedef std::vector&lt; std::shared\_ptr&lt; [**GraphNode**](classcowboys_1_1_graph_node.md) &gt; &gt; | [**GraphLayer**](#typedef-graphlayer)  <br> |
| typedef double(\*)(const [**GraphNode**](classcowboys_1_1_graph_node.md) &, const cse491::AgentBase &) | [**InnerFunction**](#typedef-innerfunction)  <br>_Function pointer for a node function._  |
| enum  | [**SensorDirection**](#enum-sensordirection)  <br> |




## Public Attributes

| Type | Name |
| ---: | :--- |
|  constexpr char | [**HEADER\_END**](#variable-header_end)   = = ';'<br>_The separator between the header and the genotype._  |
|  constexpr char | [**HEADER\_SEP**](#variable-header_sep)   = = ','<br>_The separator between each parameter in the header, defining the cartesian graph._  |
|  constexpr size\_t | [**INPUT\_SIZE**](#variable-input_size)   = = 9<br>_Don't know the maximum size a state can be, arbitrary large number._  |
|  constexpr size\_t | [**LAYERS\_BACK**](#variable-layers_back)   = = 2<br>_The number of layers preceding a node's layer that the node can reference._  |
|  const int | [**LISTSIZE**](#variable-listsize)   = = 100<br> |
|  constexpr char | [**NODE\_GENE\_SEP**](#variable-node_gene_sep)   = = '.'<br>_The separator between each attribute in a node._  |
|  constexpr char | [**NODE\_SEP**](#variable-node_sep)   = = ':'<br>_The separator between each node in the genotype._  |
|  constexpr size\_t | [**NUM\_LAYERS**](#variable-num_layers)   = = 3<br>_Number of computational layers for each agent._  |
|  constexpr size\_t | [**NUM\_NODES\_PER\_LAYER**](#variable-num_nodes_per_layer)   = = 2<br>_The number of nodes in each layer._  |
|  constexpr unsigned int | [**TRAINING\_SEED**](#variable-training_seed)   = = 0<br>_If this is 0, then a random seed will be used._  |


## Public Static Attributes

| Type | Name |
| ---: | :--- |
|  const std::vector&lt; [**InnerFunction**](namespacecowboys.md#typedef-innerfunction) &gt; | [**FUNCTION\_SET**](#variable-function_set)   = = []() {
    std::vector&lt;[**InnerFunction**](namespacecowboys.md#typedef-innerfunction)&gt; functions;
    functions.reserve(NODE\_FUNCTION\_SET.size() + SENSOR\_FUNCTION\_SET.size());
    functions.insert(functions.cend(), NODE\_FUNCTION\_SET.cbegin(), NODE\_FUNCTION\_SET.cend());
    functions.insert(functions.cend(), SENSOR\_FUNCTION\_SET.cbegin(), SENSOR\_FUNCTION\_SET.cend());
    return functions;
  }()<br>_A vector of all the node functions and sensors._  |
|  const std::vector&lt; [**InnerFunction**](namespacecowboys.md#typedef-innerfunction) &gt; | [**NODE\_FUNCTION\_SET**](#variable-node_function_set)   = {
      nullptr,  [**Sum**](namespacecowboys.md#function-sum),         [**And**](namespacecowboys.md#function-and), [**AnyEq**](namespacecowboys.md#function-anyeq), [**Not**](namespacecowboys.md#function-not),    [**Gate**](namespacecowboys.md#function-gate),   [**Sin**](namespacecowboys.md#function-sin),      [**Cos**](namespacecowboys.md#function-cos),      [**Product**](namespacecowboys.md#function-product), [**Exp**](namespacecowboys.md#function-exp),
      [**LessThan**](namespacecowboys.md#function-lessthan), [**GreaterThan**](namespacecowboys.md#function-greaterthan), [**Max**](namespacecowboys.md#function-max), [**Min**](namespacecowboys.md#function-min),   [**NegSum**](namespacecowboys.md#function-negsum), [**Square**](namespacecowboys.md#function-square), [**PosClamp**](namespacecowboys.md#function-posclamp), [**NegClamp**](namespacecowboys.md#function-negclamp), [**Sqrt**](namespacecowboys.md#function-sqrt)}<br>_A vector of all the node functions._  |
|  const std::vector&lt; [**InnerFunction**](namespacecowboys.md#typedef-innerfunction) &gt; | [**SENSOR\_FUNCTION\_SET**](#variable-sensor_function_set)   = {[**WallDistanceUp**](namespacecowboys.md#function-walldistanceup), [**WallDistanceDown**](namespacecowboys.md#function-walldistancedown), [**WallDistanceLeft**](namespacecowboys.md#function-walldistanceleft),
                                                              [**WallDistanceRight**](namespacecowboys.md#function-walldistanceright), [**AStarDistance**](namespacecowboys.md#function-astardistance)}<br>_A vector of all the sensor functions._  |
|  constexpr int | [**WALL**](#variable-wall)   = =
    2<br> |














## Public Functions

| Type | Name |
| ---: | :--- |
|  double | [**AStarDistance**](#function-astardistance) (const [**GraphNode**](classcowboys_1_1_graph_node.md) & node, const cse491::AgentBase & agent) <br>_Returns the distance to the grid position represented by the first two inputs using A\*._  |
|  double | [**And**](#function-and) (const [**GraphNode**](classcowboys_1_1_graph_node.md) & node, const cse491::AgentBase &) <br>_Returns 1 if all inputs are not equal to 0, 0 otherwise._  |
|  double | [**AnyEq**](#function-anyeq) (const [**GraphNode**](classcowboys_1_1_graph_node.md) & node, const cse491::AgentBase &) <br>_Returns 1 if any of the inputs besides the first are equal to the first input, 0 otherwise._  |
|  double | [**Cos**](#function-cos) (const [**GraphNode**](classcowboys_1_1_graph_node.md) & node, const cse491::AgentBase &) <br>_Sums the cos(x) of all inputs._  |
|  std::vector&lt; size\_t &gt; | [**EncodeActions**](#function-encodeactions) (const std::unordered\_map&lt; std::string, size\_t &gt; & action\_map) <br>_Encodes the actions from an agent's action map into a vector of size\_t, representing action IDs._  |
|  std::vector&lt; double &gt; | [**EncodeState**](#function-encodestate) (const cse491::WorldGrid & grid, const cse491::type\_options\_t &, const cse491::item\_map\_t &, const cse491::agent\_map\_t &, const cse491::AgentBase \* agent, const std::unordered\_map&lt; std::string, double &gt; & extra\_agent\_state) <br>_Translates state into nodes for the decision graph._  |
|  double | [**Exp**](#function-exp) (const [**GraphNode**](classcowboys_1_1_graph_node.md) & node, const cse491::AgentBase &) <br>_Returns the sum of the exp(x) of all inputs._  |
|  double | [**Gate**](#function-gate) (const [**GraphNode**](classcowboys_1_1_graph_node.md) & node, const cse491::AgentBase &) <br>_Returns the input with index 0 if the condition (input with index 1) is not 0._  |
|  double | [**GreaterThan**](#function-greaterthan) (const [**GraphNode**](classcowboys_1_1_graph_node.md) & node, const cse491::AgentBase &) <br>_Returns 1 if all inputs are in ascending, 0 otherwise. If only one input, then defaults to 1._  |
|  double | [**LessThan**](#function-lessthan) (const [**GraphNode**](classcowboys_1_1_graph_node.md) & node, const cse491::AgentBase &) <br>_Returns 1 if all inputs are in ascending, 0 otherwise. If only one input, then defaults to 1._  |
|  double | [**Max**](#function-max) (const [**GraphNode**](classcowboys_1_1_graph_node.md) & node, const cse491::AgentBase &) <br>_Returns the maximum value of all inputs._  |
|  double | [**Min**](#function-min) (const [**GraphNode**](classcowboys_1_1_graph_node.md) & node, const cse491::AgentBase &) <br>_Returns the minimum value of all inputs._  |
|  double | [**NegClamp**](#function-negclamp) (const [**GraphNode**](classcowboys_1_1_graph_node.md) & node, const cse491::AgentBase &) <br>_Returns the sum of negatively clamped inputs._  |
|  double | [**NegSum**](#function-negsum) (const [**GraphNode**](classcowboys_1_1_graph_node.md) & node, const cse491::AgentBase & agent) <br>_Returns the sum of negated inputs._  |
|  double | [**Not**](#function-not) (const [**GraphNode**](classcowboys_1_1_graph_node.md) & node, const cse491::AgentBase &) <br>_Returns 1 if the first input is equal to 0 or there are no inputs, 0 otherwise._  |
|  double | [**PosClamp**](#function-posclamp) (const [**GraphNode**](classcowboys_1_1_graph_node.md) & node, const cse491::AgentBase &) <br>_Returns the sum of positively clamped inputs._  |
|  double | [**Product**](#function-product) (const [**GraphNode**](classcowboys_1_1_graph_node.md) & node, const cse491::AgentBase &) <br>_Returns the product of all inputs._  |
|  double | [**Reciprocal**](#function-reciprocal) (const [**GraphNode**](classcowboys_1_1_graph_node.md) & node, const cse491::AgentBase &) <br>_Returns the sum of the reciprocal of all inputs._  |
|  double | [**Sin**](#function-sin) (const [**GraphNode**](classcowboys_1_1_graph_node.md) & node, const cse491::AgentBase &) <br>_Sums the sin(x) of all inputs._  |
|  double | [**Sqrt**](#function-sqrt) (const [**GraphNode**](classcowboys_1_1_graph_node.md) & node, const cse491::AgentBase &) <br>_Returns the sum of square root of positively clamped inputs._  |
|  double | [**Square**](#function-square) (const [**GraphNode**](classcowboys_1_1_graph_node.md) & node, const cse491::AgentBase &) <br>_Returns the sum of squared inputs._  |
|  double | [**Sum**](#function-sum) (const [**GraphNode**](classcowboys_1_1_graph_node.md) & node, const cse491::AgentBase &) <br>_Returns the sum all inputs._  |
|  double | [**WallDistanceDown**](#function-walldistancedown) (const [**GraphNode**](classcowboys_1_1_graph_node.md) &, const cse491::AgentBase & agent) <br>_Returns the distance to the nearest obstruction downwards from the agent._  |
|  double | [**WallDistanceLeft**](#function-walldistanceleft) (const [**GraphNode**](classcowboys_1_1_graph_node.md) &, const cse491::AgentBase & agent) <br>_Returns the distance to the nearest obstruction to the left of the agent._  |
|  double | [**WallDistanceRight**](#function-walldistanceright) (const [**GraphNode**](classcowboys_1_1_graph_node.md) &, const cse491::AgentBase & agent) <br>_Returns the distance to the nearest obstruction to the right of the agent._  |
|  double | [**WallDistanceUp**](#function-walldistanceup) (const [**GraphNode**](classcowboys_1_1_graph_node.md) &, const cse491::AgentBase & agent) <br>_Returns the distance to the nearest obstruction upwards from the agent._  |




























# Detailed Description


An Agent based on linear genetic programming.


yeeeeeeeehaaaaaaaaa


Namespace for [**GPAgent**](classcowboys_1_1_g_p_agent.md) and its related classes.


This file is part of the Fall 2023, CSE 491 course project.




**Note:**

yeeeeeeeehaaaaaaaaa 🤠


This file is part of the Fall 2023, CSE 491 course project. 

**Note:**

Status: PROPOSAL


currently a static class




**Author:**

@amantham20


currenly supports only wall distance sensors for left, right, top and bottom. this is library of sensors for a given agent return 


    
## Public Types Documentation




### typedef GraphLayer 

```C++
using GraphLayer =  std::vector<std::shared_ptr<GraphNode> >;
```






### typedef InnerFunction 

_Function pointer for a node function._ 
```C++
using InnerFunction =  double (*)(const GraphNode &, const cse491::AgentBase &);
```



Forward declaration of [**GraphNode**](classcowboys_1_1_graph_node.md) 


        



### enum SensorDirection 

```C++
enum cowboys::SensorDirection {
    LEFT,
    RIGHT,
    ABOVE,
    BELOW
};
```



## Public Attributes Documentation




### variable HEADER\_END 

```C++
constexpr char HEADER_END;
```






### variable HEADER\_SEP 

```C++
constexpr char HEADER_SEP;
```






### variable INPUT\_SIZE 

```C++
constexpr size_t INPUT_SIZE;
```






### variable LAYERS\_BACK 

```C++
constexpr size_t LAYERS_BACK;
```






### variable LISTSIZE 

```C++
const int LISTSIZE;
```






### variable NODE\_GENE\_SEP 

```C++
constexpr char NODE_GENE_SEP;
```






### variable NODE\_SEP 

```C++
constexpr char NODE_SEP;
```






### variable NUM\_LAYERS 

```C++
constexpr size_t NUM_LAYERS;
```






### variable NUM\_NODES\_PER\_LAYER 

```C++
constexpr size_t NUM_NODES_PER_LAYER;
```






### variable TRAINING\_SEED 

```C++
constexpr unsigned int TRAINING_SEED;
```



## Public Static Attributes Documentation




### variable FUNCTION\_SET 

```C++
const std::vector<InnerFunction> FUNCTION_SET;
```






### variable NODE\_FUNCTION\_SET 

```C++
const std::vector<InnerFunction> NODE_FUNCTION_SET;
```






### variable SENSOR\_FUNCTION\_SET 

```C++
const std::vector<InnerFunction> SENSOR_FUNCTION_SET;
```






### variable WALL 

```C++
constexpr int WALL;
```



## Public Functions Documentation




### function AStarDistance 

_Returns the distance to the grid position represented by the first two inputs using A\*._ 
```C++
double cowboys::AStarDistance (
    const GraphNode & node,
    const cse491::AgentBase & agent
) 
```





**Parameters:**


* `node` The node to get the inputs from. 
* `agent` The agent that the node belongs to. 



**Returns:**

The distance to the grid position using A\* 





        



### function And 

_Returns 1 if all inputs are not equal to 0, 0 otherwise._ 
```C++
double cowboys::And (
    const GraphNode & node,
    const cse491::AgentBase &
) 
```





**Parameters:**


* `node` The node to get the inputs from. 



**Returns:**

The function result as a double. 





        



### function AnyEq 

_Returns 1 if any of the inputs besides the first are equal to the first input, 0 otherwise._ 
```C++
double cowboys::AnyEq (
    const GraphNode & node,
    const cse491::AgentBase &
) 
```





**Parameters:**


* `node` The node to get the inputs from. 



**Returns:**

The function result as a double. 





        



### function Cos 

_Sums the cos(x) of all inputs._ 
```C++
double cowboys::Cos (
    const GraphNode & node,
    const cse491::AgentBase &
) 
```





**Parameters:**


* `node` The node to get the inputs from. 



**Returns:**

The function result as a double. 





        



### function EncodeActions 

_Encodes the actions from an agent's action map into a vector of size\_t, representing action IDs._ 
```C++
std::vector< size_t > cowboys::EncodeActions (
    const std::unordered_map< std::string, size_t > & action_map
) 
```





**Parameters:**


* `action_map` The action map from the agent. 



**Returns:**

A vector of size\_t, representing action IDs. 





        



### function EncodeState 

_Translates state into nodes for the decision graph._ 
```C++
std::vector< double > cowboys::EncodeState (
    const cse491::WorldGrid & grid,
    const cse491::type_options_t &,
    const cse491::item_map_t &,
    const cse491::agent_map_t &,
    const cse491::AgentBase * agent,
    const std::unordered_map< std::string, double > & extra_agent_state
) 
```





**Returns:**

A vector of doubles for the decision graph. 





        



### function Exp 

_Returns the sum of the exp(x) of all inputs._ 
```C++
double cowboys::Exp (
    const GraphNode & node,
    const cse491::AgentBase &
) 
```





**Parameters:**


* `node` The node to get the inputs from. 



**Returns:**

The function result as a double. 





        



### function Gate 

_Returns the input with index 0 if the condition (input with index 1) is not 0._ 
```C++
double cowboys::Gate (
    const GraphNode & node,
    const cse491::AgentBase &
) 
```





**Parameters:**


* `node` The node to get the inputs from. 



**Returns:**

The function result as a double. 





        



### function GreaterThan 

_Returns 1 if all inputs are in ascending, 0 otherwise. If only one input, then defaults to 1._ 
```C++
double cowboys::GreaterThan (
    const GraphNode & node,
    const cse491::AgentBase &
) 
```





**Parameters:**


* `node` The node to get the inputs from. 



**Returns:**

The function result as a double. 





        



### function LessThan 

_Returns 1 if all inputs are in ascending, 0 otherwise. If only one input, then defaults to 1._ 
```C++
double cowboys::LessThan (
    const GraphNode & node,
    const cse491::AgentBase &
) 
```





**Parameters:**


* `node` The node to get the inputs from. 



**Returns:**

The function result as a double. 





        



### function Max 

_Returns the maximum value of all inputs._ 
```C++
double cowboys::Max (
    const GraphNode & node,
    const cse491::AgentBase &
) 
```





**Parameters:**


* `node` The node to get the inputs from. 



**Returns:**

The function result as a double. 





        



### function Min 

_Returns the minimum value of all inputs._ 
```C++
double cowboys::Min (
    const GraphNode & node,
    const cse491::AgentBase &
) 
```





**Parameters:**


* `node` The node to get the inputs from. 



**Returns:**

The function result as a double. 





        



### function NegClamp 

_Returns the sum of negatively clamped inputs._ 
```C++
double cowboys::NegClamp (
    const GraphNode & node,
    const cse491::AgentBase &
) 
```





**Parameters:**


* `node` The node to get the inputs from. 



**Returns:**

The function result as a double. 





        



### function NegSum 

_Returns the sum of negated inputs._ 
```C++
double cowboys::NegSum (
    const GraphNode & node,
    const cse491::AgentBase & agent
) 
```





**Parameters:**


* `node` The node to get the inputs from. 



**Returns:**

The function result as a double. 





        



### function Not 

_Returns 1 if the first input is equal to 0 or there are no inputs, 0 otherwise._ 
```C++
double cowboys::Not (
    const GraphNode & node,
    const cse491::AgentBase &
) 
```





**Parameters:**


* `node` The node to get the inputs from. 



**Returns:**

The function result as a double. 





        



### function PosClamp 

_Returns the sum of positively clamped inputs._ 
```C++
double cowboys::PosClamp (
    const GraphNode & node,
    const cse491::AgentBase &
) 
```





**Parameters:**


* `node` The node to get the inputs from. 



**Returns:**

The function result as a double. 





        



### function Product 

_Returns the product of all inputs._ 
```C++
double cowboys::Product (
    const GraphNode & node,
    const cse491::AgentBase &
) 
```





**Parameters:**


* `node` The node to get the inputs from. 



**Returns:**

The function result as a double. 





        



### function Reciprocal 

_Returns the sum of the reciprocal of all inputs._ 
```C++
double cowboys::Reciprocal (
    const GraphNode & node,
    const cse491::AgentBase &
) 
```





**Parameters:**


* `node` The node to get the inputs from. 



**Returns:**

The function result as a double. 





        



### function Sin 

_Sums the sin(x) of all inputs._ 
```C++
double cowboys::Sin (
    const GraphNode & node,
    const cse491::AgentBase &
) 
```





**Parameters:**


* `node` The node to get the inputs from. 



**Returns:**

The function result as a double. 





        



### function Sqrt 

_Returns the sum of square root of positively clamped inputs._ 
```C++
double cowboys::Sqrt (
    const GraphNode & node,
    const cse491::AgentBase &
) 
```





**Parameters:**


* `node` The node to get the inputs from. 



**Returns:**

The function result as a double. 





        



### function Square 

_Returns the sum of squared inputs._ 
```C++
double cowboys::Square (
    const GraphNode & node,
    const cse491::AgentBase &
) 
```





**Parameters:**


* `node` The node to get the inputs from. 



**Returns:**

The function result as a double. 





        



### function Sum 

_Returns the sum all inputs._ 
```C++
double cowboys::Sum (
    const GraphNode & node,
    const cse491::AgentBase &
) 
```





**Parameters:**


* `node` The node to get the inputs from. 



**Returns:**

The function result as a double. 





        



### function WallDistanceDown 

_Returns the distance to the nearest obstruction downwards from the agent._ 
```C++
double cowboys::WallDistanceDown (
    const GraphNode &,
    const cse491::AgentBase & agent
) 
```





**Parameters:**


* `agent` The agent that the node belongs to. 



**Returns:**

The distance to the nearest obstruction downwards. 





        



### function WallDistanceLeft 

_Returns the distance to the nearest obstruction to the left of the agent._ 
```C++
double cowboys::WallDistanceLeft (
    const GraphNode &,
    const cse491::AgentBase & agent
) 
```





**Parameters:**


* `agent` The agent that the node belongs to. 



**Returns:**

The distance to the nearest obstruction to the left. 





        



### function WallDistanceRight 

_Returns the distance to the nearest obstruction to the right of the agent._ 
```C++
double cowboys::WallDistanceRight (
    const GraphNode &,
    const cse491::AgentBase & agent
) 
```





**Parameters:**


* `agent` The agent that the node belongs to. 



**Returns:**

The distance to the nearest obstruction to the right. 





        



### function WallDistanceUp 

_Returns the distance to the nearest obstruction upwards from the agent._ 
```C++
double cowboys::WallDistanceUp (
    const GraphNode &,
    const cse491::AgentBase & agent
) 
```





**Parameters:**


* `agent` The agent that the node belongs to. 



**Returns:**

The distance to the nearest obstruction upwards. 





        

------------------------------
The documentation for this class was generated from the following file `source/Agents/GP/CGPAgent.hpp`

