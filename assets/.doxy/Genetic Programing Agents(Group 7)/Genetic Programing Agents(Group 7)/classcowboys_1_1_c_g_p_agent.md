

# Class cowboys::CGPAgent



[**ClassList**](annotated.md) **>** [**cowboys**](namespacecowboys.md) **>** [**CGPAgent**](classcowboys_1_1_c_g_p_agent.md)



_An agent based on cartesian genetic programming._ 

* `#include <CGPAgent.hpp>`



Inherits the following classes: [cowboys::GPAgentBase](classcowboys_1_1_g_p_agent_base.md)






















































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**CGPAgent**](#function-cgpagent-12) (size\_t id, const std::string & name) <br> |
|   | [**CGPAgent**](#function-cgpagent-22) (size\_t id, const std::string & name, const [**CGPGenotype**](classcowboys_1_1_c_g_p_genotype.md) & genotype) <br> |
|  void | [**Configure**](#function-configure) (const [**CGPAgent**](classcowboys_1_1_c_g_p_agent.md) & other) <br>_Copies the genotype and behavior of another_ [_**CGPAgent**_](classcowboys_1_1_c_g_p_agent.md) _into this agent._ |
| virtual void | [**Copy**](#function-copy) (const [**GPAgentBase**](classcowboys_1_1_g_p_agent_base.md) & other) override<br>_Copy the behavior of another agent into this agent._  |
| virtual std::string | [**Export**](#function-export) () override<br>_Export the genotype for this agent._  |
| virtual size\_t | [**GetAction**](#function-getaction) (const cse491::WorldGrid & grid, const cse491::type\_options\_t & type\_options, const cse491::item\_map\_t & item\_set, const cse491::agent\_map\_t & agent\_set) override<br> |
|  double | [**GetComplexity**](#function-getcomplexity) () const<br>_The complexity of this agent. Used for fitness._  |
|  const [**CGPGenotype**](classcowboys_1_1_c_g_p_genotype.md) & | [**GetGenotype**](#function-getgenotype) () const<br>_Get the genotype for this agent._  |
| virtual void | [**Import**](#function-import) (const std::string & genotype) override<br>_Load in the string representation of a genotype and configure this agent based on it._  |
|  bool | [**Initialize**](#function-initialize) () override<br>_Setup graph._  |
| virtual void | [**MutateAgent**](#function-mutateagent) (double mutation\_rate=0.8) override<br>_Mutate this agent._  |
| virtual void | [**PrintAgent**](#function-printagent) () override<br> |
| virtual void | [**SerializeGP**](#function-serializegp) (tinyxml2::XMLDocument & doc, tinyxml2::XMLElement \* parentElem, double fitness=-1) override<br>_Serialize this agent to XML._  |


## Public Functions inherited from cowboys::GPAgentBase

See [cowboys::GPAgentBase](classcowboys_1_1_g_p_agent_base.md)

| Type | Name |
| ---: | :--- |
| virtual void | [**Copy**](#function-copy) (const [**GPAgentBase**](classcowboys_1_1_g_p_agent_base.md) & other) = 0<br>_Copy the behavior of another agent into this agent._  |
| virtual std::string | [**Export**](#function-export) () <br> |
|   | [**GPAgentBase**](#function-gpagentbase) (size\_t id, const std::string & name) <br> |
| virtual size\_t | [**GetAction**](#function-getaction) (const cse491::WorldGrid & grid, const cse491::type\_options\_t & type\_options, const cse491::item\_map\_t & item\_set, const cse491::agent\_map\_t & agent\_set) = 0<br> |
|  const std::unordered\_map&lt; std::string, double &gt; | [**GetExtraState**](#function-getextrastate) () const<br>_Get a map of extra state information._  |
|  double | [**GetRandom**](#function-getrandom-13) () <br>_Return a uniform random value between 0.0 and 1.0._  |
|  double | [**GetRandom**](#function-getrandom-23) (double max) <br>_Return a uniform random value between 0.0 and max._  |
|  double | [**GetRandom**](#function-getrandom-33) (double min, double max) <br>_Return a uniform random value between min and max._  |
|  double | [**GetRandomNormal**](#function-getrandomnormal-12) () <br>_Return a gaussian random value with mean 0.0 and sd 1.0._  |
|  double | [**GetRandomNormal**](#function-getrandomnormal-22) (double mean, double sd=1.0) <br>_Return a gaussian random value with provided mean and sd._  |
|  size\_t | [**GetRandomULL**](#function-getrandomull) (size\_t max) <br>_Return a uniform random unsigned long long between 0 (inclusive) and max (exclusive)_  |
|  unsigned int | [**GetSeed**](#function-getseed) () const<br>_Get the seed used to initialize this RNG._  |
| virtual void | [**Import**](#function-import) (const std::string & genotype) = 0<br> |
|  bool | [**Initialize**](#function-initialize) () override<br>_Setup graph._  |
| virtual void | [**MutateAgent**](#function-mutateagent) (double mutation\_rate=0.8) = 0<br>_Mutate this agent._  |
| virtual void | [**PrintAgent**](#function-printagent) () <br> |
| virtual void | [**Reset**](#function-reset) (bool=false) <br> |
|  size\_t | [**SelectAction**](#function-selectaction) (const cse491::WorldGrid & grid, const cse491::type\_options\_t & type\_options, const cse491::item\_map\_t & item\_set, const cse491::agent\_map\_t & agent\_set) override<br>_Choose the action to take a step in the appropriate direction._  |
| virtual void | [**SerializeGP**](#function-serializegp) (tinyxml2::XMLDocument & doc, tinyxml2::XMLElement \* parentElem, double fitness=-1) = 0<br> |
|  void | [**SetSeed**](#function-setseed) (unsigned int seed) <br>_Set the seed used to initialize this RNG._  |
|   | [**~GPAgentBase**](#function-gpagentbase) () = default<br> |














## Protected Attributes

| Type | Name |
| ---: | :--- |
|  std::unique\_ptr&lt; [**Graph**](classcowboys_1_1_graph.md) &gt; | [**decision\_graph**](#variable-decision_graph)  <br>_The decision graph for this agent._  |
|  [**CGPGenotype**](classcowboys_1_1_c_g_p_genotype.md) | [**genotype**](#variable-genotype)  <br>_The genotype for this agent._  |


## Protected Attributes inherited from cowboys::GPAgentBase

See [cowboys::GPAgentBase](classcowboys_1_1_g_p_agent_base.md)

| Type | Name |
| ---: | :--- |
|  std::unordered\_map&lt; std::string, double &gt; | [**extra\_state**](#variable-extra_state)  <br>_A map of extra state information._  |
|  std::normal\_distribution&lt; double &gt; | [**norm\_dist**](#variable-norm_dist)  <br>_Normal distribution._  |
|  std::mt19937 | [**rng**](#variable-rng)   = {[**seed**](classcowboys_1_1_g_p_agent_base.md#variable-seed)}<br>_Random number generator._  |
|  unsigned int | [**seed**](#variable-seed)   = = 0<br>_Seed for the random number generator._  |
|  std::uniform\_real\_distribution&lt; double &gt; | [**uni\_dist**](#variable-uni_dist)  <br>_Uniform distribution._  |






































## Public Functions Documentation




### function CGPAgent [1/2]

```C++
inline cowboys::CGPAgent::CGPAgent (
    size_t id,
    const std::string & name
) 
```






### function CGPAgent [2/2]

```C++
inline cowboys::CGPAgent::CGPAgent (
    size_t id,
    const std::string & name,
    const CGPGenotype & genotype
) 
```






### function Configure 

_Copies the genotype and behavior of another_ [_**CGPAgent**_](classcowboys_1_1_c_g_p_agent.md) _into this agent._
```C++
inline void cowboys::CGPAgent::Configure (
    const CGPAgent & other
) 
```





**Parameters:**


* `other` The [**CGPAgent**](classcowboys_1_1_c_g_p_agent.md) to copy. 




        



### function Copy 

_Copy the behavior of another agent into this agent._ 
```C++
inline virtual void cowboys::CGPAgent::Copy (
    const GPAgentBase & other
) override
```





**Parameters:**


* `other` The agent to copy. 




        
Implements [*cowboys::GPAgentBase::Copy*](classcowboys_1_1_g_p_agent_base.md#function-copy)




### function Export 

_Export the genotype for this agent._ 
```C++
inline virtual std::string cowboys::CGPAgent::Export () override
```





**Returns:**

The string representation of the genotype for this agent. 





        
Implements [*cowboys::GPAgentBase::Export*](classcowboys_1_1_g_p_agent_base.md#function-export)




### function GetAction 

```C++
inline virtual size_t cowboys::CGPAgent::GetAction (
    const cse491::WorldGrid & grid,
    const cse491::type_options_t & type_options,
    const cse491::item_map_t & item_set,
    const cse491::agent_map_t & agent_set
) override
```



Implements [*cowboys::GPAgentBase::GetAction*](classcowboys_1_1_g_p_agent_base.md#function-getaction)




### function GetComplexity 

_The complexity of this agent. Used for fitness._ 
```C++
inline double cowboys::CGPAgent::GetComplexity () const
```





**Returns:**

The complexity of this agent. 





        



### function GetGenotype 

_Get the genotype for this agent._ 
```C++
inline const CGPGenotype & cowboys::CGPAgent::GetGenotype () const
```





**Returns:**

A const reference to the genotype for this agent. 





        



### function Import 

_Load in the string representation of a genotype and configure this agent based on it._ 
```C++
inline virtual void cowboys::CGPAgent::Import (
    const std::string & genotype
) override
```





**Parameters:**


* `genotype` The string representation of a genotype. 




        
Implements [*cowboys::GPAgentBase::Import*](classcowboys_1_1_g_p_agent_base.md#function-import)




### function Initialize 

_Setup graph._ 
```C++
inline bool cowboys::CGPAgent::Initialize () override
```





**Returns:**

Success. 





        



### function MutateAgent 

_Mutate this agent._ 
```C++
inline virtual void cowboys::CGPAgent::MutateAgent (
    double mutation_rate=0.8
) override
```





**Parameters:**


* `mutation_rate` The mutation rate. Between 0 and 1. 




        
Implements [*cowboys::GPAgentBase::MutateAgent*](classcowboys_1_1_g_p_agent_base.md#function-mutateagent)




### function PrintAgent 

```C++
inline virtual void cowboys::CGPAgent::PrintAgent () override
```



Implements [*cowboys::GPAgentBase::PrintAgent*](classcowboys_1_1_g_p_agent_base.md#function-printagent)




### function SerializeGP 

_Serialize this agent to XML._ 
```C++
inline virtual void cowboys::CGPAgent::SerializeGP (
    tinyxml2::XMLDocument & doc,
    tinyxml2::XMLElement * parentElem,
    double fitness=-1
) override
```





**Parameters:**


* `doc` The XML document to serialize to. 
* `parentElem` The parent element to serialize to. 
* `fitness` The fitness of this agent to write to the XML. 




        
Implements [*cowboys::GPAgentBase::SerializeGP*](classcowboys_1_1_g_p_agent_base.md#function-serializegp)

## Protected Attributes Documentation




### variable decision\_graph 

```C++
std::unique_ptr<Graph> decision_graph;
```






### variable genotype 

```C++
CGPGenotype genotype;
```




------------------------------
The documentation for this class was generated from the following file `source/Agents/GP/CGPAgent.hpp`

