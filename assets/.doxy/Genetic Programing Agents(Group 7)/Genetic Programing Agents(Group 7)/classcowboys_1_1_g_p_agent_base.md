

# Class cowboys::GPAgentBase



[**ClassList**](annotated.md) **>** [**cowboys**](namespacecowboys.md) **>** [**GPAgentBase**](classcowboys_1_1_g_p_agent_base.md)








Inherits the following classes: AgentBase


Inherited by the following classes: [cowboys::CGPAgent](classcowboys_1_1_c_g_p_agent.md),  [cowboys::LGPAgent](classcowboys_1_1_l_g_p_agent.md)
































## Public Functions

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
|  std::unordered\_map&lt; std::string, double &gt; | [**extra\_state**](#variable-extra_state)  <br>_A map of extra state information._  |
|  std::normal\_distribution&lt; double &gt; | [**norm\_dist**](#variable-norm_dist)  <br>_Normal distribution._  |
|  std::mt19937 | [**rng**](#variable-rng)   = {[**seed**](classcowboys_1_1_g_p_agent_base.md#variable-seed)}<br>_Random number generator._  |
|  unsigned int | [**seed**](#variable-seed)   = = 0<br>_Seed for the random number generator._  |
|  std::uniform\_real\_distribution&lt; double &gt; | [**uni\_dist**](#variable-uni_dist)  <br>_Uniform distribution._  |




















## Public Functions Documentation




### function Copy 

_Copy the behavior of another agent into this agent._ 
```C++
virtual void cowboys::GPAgentBase::Copy (
    const GPAgentBase & other
) = 0
```





**Parameters:**


* `other` The agent to copy. Should be the same type. 




        



### function Export 

```C++
inline virtual std::string cowboys::GPAgentBase::Export () 
```






### function GPAgentBase 

```C++
inline cowboys::GPAgentBase::GPAgentBase (
    size_t id,
    const std::string & name
) 
```






### function GetAction 

```C++
virtual size_t cowboys::GPAgentBase::GetAction (
    const cse491::WorldGrid & grid,
    const cse491::type_options_t & type_options,
    const cse491::item_map_t & item_set,
    const cse491::agent_map_t & agent_set
) = 0
```






### function GetExtraState 

_Get a map of extra state information._ 
```C++
inline const std::unordered_map< std::string, double > cowboys::GPAgentBase::GetExtraState () const
```





**Returns:**

Map of extra state information 





        



### function GetRandom [1/3]

```C++
inline double cowboys::GPAgentBase::GetRandom () 
```






### function GetRandom [2/3]

```C++
inline double cowboys::GPAgentBase::GetRandom (
    double max
) 
```






### function GetRandom [3/3]

```C++
inline double cowboys::GPAgentBase::GetRandom (
    double min,
    double max
) 
```






### function GetRandomNormal [1/2]

```C++
inline double cowboys::GPAgentBase::GetRandomNormal () 
```






### function GetRandomNormal [2/2]

```C++
inline double cowboys::GPAgentBase::GetRandomNormal (
    double mean,
    double sd=1.0
) 
```






### function GetRandomULL 

```C++
inline size_t cowboys::GPAgentBase::GetRandomULL (
    size_t max
) 
```






### function GetSeed 

```C++
inline unsigned int cowboys::GPAgentBase::GetSeed () const
```






### function Import 

```C++
virtual void cowboys::GPAgentBase::Import (
    const std::string & genotype
) = 0
```






### function Initialize 

_Setup graph._ 
```C++
inline bool cowboys::GPAgentBase::Initialize () override
```





**Returns:**

Success. 





        



### function MutateAgent 

_Mutate this agent._ 
```C++
virtual void cowboys::GPAgentBase::MutateAgent (
    double mutation_rate=0.8
) = 0
```





**Parameters:**


* `mutation_rate` The mutation rate. Between 0 and 1. 




        



### function PrintAgent 

```C++
inline virtual void cowboys::GPAgentBase::PrintAgent () 
```






### function Reset 

```C++
inline virtual void cowboys::GPAgentBase::Reset (
    bool=false
) 
```






### function SelectAction 

```C++
inline size_t cowboys::GPAgentBase::SelectAction (
    const cse491::WorldGrid & grid,
    const cse491::type_options_t & type_options,
    const cse491::item_map_t & item_set,
    const cse491::agent_map_t & agent_set
) override
```






### function SerializeGP 

```C++
virtual void cowboys::GPAgentBase::SerializeGP (
    tinyxml2::XMLDocument & doc,
    tinyxml2::XMLElement * parentElem,
    double fitness=-1
) = 0
```






### function SetSeed 

```C++
inline void cowboys::GPAgentBase::SetSeed (
    unsigned int seed
) 
```






### function ~GPAgentBase 

```C++
cowboys::GPAgentBase::~GPAgentBase () = default
```



## Protected Attributes Documentation




### variable extra\_state 

```C++
std::unordered_map<std::string, double> extra_state;
```






### variable norm\_dist 

```C++
std::normal_distribution<double> norm_dist;
```






### variable rng 

```C++
std::mt19937 rng;
```






### variable seed 

```C++
unsigned int seed;
```






### variable uni\_dist 

```C++
std::uniform_real_distribution<double> uni_dist;
```




------------------------------
The documentation for this class was generated from the following file `source/Agents/GP/GPAgentBase.hpp`

