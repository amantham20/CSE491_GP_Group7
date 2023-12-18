

# Class cowboys::LGPAgent



[**ClassList**](annotated.md) **>** [**cowboys**](namespacecowboys.md) **>** [**LGPAgent**](classcowboys_1_1_l_g_p_agent.md)








Inherits the following classes: [cowboys::GPAgentBase](classcowboys_1_1_g_p_agent_base.md)






















































## Public Functions

| Type | Name |
| ---: | :--- |
|  void | [**Configure**](#function-configure) (const [**LGPAgent**](classcowboys_1_1_l_g_p_agent.md) & other) <br>_Copies the behavior of another_ [_**LGPAgent**_](classcowboys_1_1_l_g_p_agent.md) _into this agent._ |
| virtual void | [**Copy**](#function-copy) (const [**GPAgentBase**](classcowboys_1_1_g_p_agent_base.md) & other) override<br>_Copy the behavior of another agent into this agent._  |
| virtual std::string | [**Export**](#function-export) () override<br>_Export the agent to a string._  |
|  void | [**GenerateRandomActionList**](#function-generaterandomactionlist) () <br>_Generate a random list of instructions from a list of possible instructions._  |
| virtual size\_t | [**GetAction**](#function-getaction) (const cse491::WorldGrid & grid, const cse491::type\_options\_t & type\_options, const cse491::item\_map\_t & item\_set, const cse491::agent\_map\_t & agent\_set) override<br>_Get the action to take._  |
|  const std::vector&lt; std::tuple&lt; std::string, int, int &gt; &gt; & | [**GetInstructionsList**](#function-getinstructionslist) () <br>_Get the instruction list for this agent._  |
| virtual void | [**Import**](#function-import) (const std::string & encodedLists) override<br>_Load in the string representation of an LGP agent and configure this agent based on it._  |
|  bool | [**Initialize**](#function-initialize) () override<br>_Initialize the agent after being given an action map._  |
|   | [**LGPAgent**](#function-lgpagent) (size\_t id, const std::string & name) <br> |
| virtual void | [**MutateAgent**](#function-mutateagent) (double mutation\_rate=0.01) override<br>_Mutate this agent._  |
| virtual void | [**PrintAgent**](#function-printagent) () override<br>_Print the agent._  |
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


## Public Static Functions

| Type | Name |
| ---: | :--- |
|  std::vector&lt; std::string &gt; | [**EncodeActions**](#function-encodeactions) (const std::unordered\_map&lt; std::string, size\_t &gt; & action\_map, const std::vector&lt; std::string &gt; & sensorsNamesList, const std::vector&lt; std::string &gt; & operationsList, std::vector&lt; std::string &gt; & actionsList) <br>_Encodes the actions from an agent's action map into a vector of string, representing action names._  |












## Protected Attributes

| Type | Name |
| ---: | :--- |
|  std::vector&lt; std::string &gt; | [**actionsList**](#variable-actionslist)   = = {}<br> |
|  size\_t | [**currentInstructionIndex**](#variable-currentinstructionindex)   = = 0<br> |
|  std::mt19937 | [**gen**](#variable-gen)  <br> |
|  std::vector&lt; std::tuple&lt; std::string, int, int &gt; &gt; | [**instructionsList**](#variable-instructionslist)   = = {}<br> |
|  std::vector&lt; std::string &gt; | [**operationsList**](#variable-operationslist)   = = {"lessthan", "greaterthan", "equals"}<br> |
|  std::vector&lt; std::string &gt; | [**possibleInstructionsList**](#variable-possibleinstructionslist)   = = {}<br> |
|  std::random\_device | [**rd**](#variable-rd)  <br> |
|  std::vector&lt; int &gt; | [**resultsList**](#variable-resultslist)  <br> |
|  std::vector&lt; std::string &gt; | [**sensorsNamesList**](#variable-sensorsnameslist)   = = {"getLeft", "getRight", "getUp", "getDown"}<br> |


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




### function Configure 

_Copies the behavior of another_ [_**LGPAgent**_](classcowboys_1_1_l_g_p_agent.md) _into this agent._
```C++
inline void cowboys::LGPAgent::Configure (
    const LGPAgent & other
) 
```





**Parameters:**


* `other` The [**LGPAgent**](classcowboys_1_1_l_g_p_agent.md) to copy. 




        



### function Copy 

_Copy the behavior of another agent into this agent._ 
```C++
inline virtual void cowboys::LGPAgent::Copy (
    const GPAgentBase & other
) override
```





**Parameters:**


* `other` The agent to copy. 




        
Implements [*cowboys::GPAgentBase::Copy*](classcowboys_1_1_g_p_agent_base.md#function-copy)




### function Export 

_Export the agent to a string._ 
```C++
inline virtual std::string cowboys::LGPAgent::Export () override
```





**Returns:**

The string representation of the agent 





        
Implements [*cowboys::GPAgentBase::Export*](classcowboys_1_1_g_p_agent_base.md#function-export)




### function GenerateRandomActionList 

_Generate a random list of instructions from a list of possible instructions._ 
```C++
inline void cowboys::LGPAgent::GenerateRandomActionList () 
```





**Returns:**

Success. 





        



### function GetAction 

_Get the action to take._ 
```C++
inline virtual size_t cowboys::LGPAgent::GetAction (
    const cse491::WorldGrid & grid,
    const cse491::type_options_t & type_options,
    const cse491::item_map_t & item_set,
    const cse491::agent_map_t & agent_set
) override
```





**Parameters:**


* `grid` The world grid. 
* `type_options` The available types of cells in the grid. 
* `item_set` The set of items in the world. 
* `agent_set` The set of agents in the world. 



**Returns:**

A size\_t corresponding to the action chosen 





        
Implements [*cowboys::GPAgentBase::GetAction*](classcowboys_1_1_g_p_agent_base.md#function-getaction)




### function GetInstructionsList 

_Get the instruction list for this agent._ 
```C++
inline const std::vector< std::tuple< std::string, int, int > > & cowboys::LGPAgent::GetInstructionsList () 
```





**Returns:**

A const reference to the instruction list for this agent. 





        



### function Import 

_Load in the string representation of an LGP agent and configure this agent based on it._ 
```C++
inline virtual void cowboys::LGPAgent::Import (
    const std::string & encodedLists
) override
```





**Parameters:**


* `genotype` The string representation of an LGP agent. 




        
Implements [*cowboys::GPAgentBase::Import*](classcowboys_1_1_g_p_agent_base.md#function-import)




### function Initialize 

_Initialize the agent after being given an action map._ 
```C++
inline bool cowboys::LGPAgent::Initialize () override
```





**Returns:**

Success. 





        



### function LGPAgent 

```C++
inline cowboys::LGPAgent::LGPAgent (
    size_t id,
    const std::string & name
) 
```






### function MutateAgent 

_Mutate this agent._ 
```C++
inline virtual void cowboys::LGPAgent::MutateAgent (
    double mutation_rate=0.01
) override
```





**Parameters:**


* `mutation_rate` The probability of any instruction being changed 




        
Implements [*cowboys::GPAgentBase::MutateAgent*](classcowboys_1_1_g_p_agent_base.md#function-mutateagent)




### function PrintAgent 

```C++
inline virtual void cowboys::LGPAgent::PrintAgent () override
```



Implements [*cowboys::GPAgentBase::PrintAgent*](classcowboys_1_1_g_p_agent_base.md#function-printagent)




### function SerializeGP 

_Serialize this agent to XML._ 
```C++
inline virtual void cowboys::LGPAgent::SerializeGP (
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

## Public Static Functions Documentation




### function EncodeActions 

_Encodes the actions from an agent's action map into a vector of string, representing action names._ 
```C++
static inline std::vector< std::string > cowboys::LGPAgent::EncodeActions (
    const std::unordered_map< std::string, size_t > & action_map,
    const std::vector< std::string > & sensorsNamesList,
    const std::vector< std::string > & operationsList,
    std::vector< std::string > & actionsList
) 
```





**Parameters:**


* `action_map` The action map from the agent. 
* `sensorsNamesList` The list of sensors from the agent. 
* `operationsList` The list of operations from the agent. 
* `actionsList` The list of actions from the agent. 



**Returns:**

A vector of strings, representing action names. 





        
## Protected Attributes Documentation




### variable actionsList 

```C++
std::vector<std::string> actionsList;
```






### variable currentInstructionIndex 

```C++
size_t currentInstructionIndex;
```






### variable gen 

```C++
std::mt19937 gen;
```






### variable instructionsList 

```C++
std::vector<std::tuple<std::string, int, int> > instructionsList;
```






### variable operationsList 

```C++
std::vector<std::string> operationsList;
```






### variable possibleInstructionsList 

```C++
std::vector<std::string> possibleInstructionsList;
```






### variable rd 

```C++
std::random_device rd;
```






### variable resultsList 

```C++
std::vector<int> resultsList;
```






### variable sensorsNamesList 

```C++
std::vector<std::string> sensorsNamesList;
```




------------------------------
The documentation for this class was generated from the following file `source/Agents/GP/LGPAgent.hpp`

