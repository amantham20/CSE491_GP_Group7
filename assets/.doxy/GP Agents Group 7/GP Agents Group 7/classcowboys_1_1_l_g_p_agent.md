

# Class cowboys::LGPAgent



[**ClassList**](annotated.md) **>** [**cowboys**](namespacecowboys.md) **>** [**LGPAgent**](classcowboys_1_1_l_g_p_agent.md)








Inherits the following classes: AgentBase


































## Public Functions

| Type | Name |
| ---: | :--- |
|  EXPERIMENTAL\_FUNCTION void | [**GenerateRandomActionList**](#function-generaterandomactionlist) () <br> |
|  EXPERIMENTAL\_FUNCTION bool | [**Initialize**](#function-initialize) () override<br>_This agent needs a specific set of actions to function._  |
|  EXPERIMENTAL\_FUNCTION | [**LGPAgent**](#function-lgpagent) (size\_t id, const std::string & name) <br> |
|  EXPERIMENTAL\_FUNCTION size\_t | [**SelectAction**](#function-selectaction) (const cse491::WorldGrid & grid, const cse491::type\_options\_t & type\_options, const cse491::item\_set\_t & item\_set, const cse491::agent\_set\_t & agent\_set) override<br> |
|   | [**~LGPAgent**](#function-lgpagent) () override<br> |


## Public Static Functions

| Type | Name |
| ---: | :--- |
|  EXPERIMENTAL\_FUNCTION std::vector&lt; std::string &gt; | [**EncodeActions**](#function-encodeactions) (const std::unordered\_map&lt; std::string, size\_t &gt; & action\_map, const std::vector&lt; std::string &gt; & sensorsNamesList) <br>_Encodes the actions from an agent's action map into a vector of string, representing action names._  |






## Protected Attributes

| Type | Name |
| ---: | :--- |
|  std::vector&lt; std::string &gt; | [**actionsList**](#variable-actionslist)   = = {"up", "down", "left", "right"}<br> |
|  size\_t | [**currentInstructionIndex**](#variable-currentinstructionindex)   = = 0<br> |
|  std::mt19937 | [**gen**](#variable-gen)  <br> |
|  bool | [**hasActionOccured**](#variable-hasactionoccured)   = = false<br> |
|  std::vector&lt; std::tuple&lt; std::string, int, int &gt; &gt; | [**instructionsList**](#variable-instructionslist)   = = {}<br> |
|  std::vector&lt; std::string &gt; | [**operationsList**](#variable-operationslist)   = = {"lessthan", "greaterthan",
                                             "equals"}<br> |
|  std::vector&lt; std::string &gt; | [**possibleInstructionsList**](#variable-possibleinstructionslist)   = = {}<br> |
|  std::random\_device | [**rd**](#variable-rd)  <br> |
|  std::vector&lt; int &gt; | [**resultsList**](#variable-resultslist)   = = std::vector&lt;int&gt;(LISTSIZE)<br> |
|  std::vector&lt; [**cowboys::Sensors**](classcowboys_1_1_sensors.md) &gt; | [**sensorsList**](#variable-sensorslist)  <br> |
|  std::vector&lt; std::string &gt; | [**sensorsNamesList**](#variable-sensorsnameslist)   = = {"getLeft", "getRight", "getUp",
                                               "getDown"}<br> |




















## Public Functions Documentation




### function GenerateRandomActionList 

```C++
inline EXPERIMENTAL_FUNCTION void cowboys::LGPAgent::GenerateRandomActionList () 
```






### function Initialize 

_This agent needs a specific set of actions to function._ 
```C++
inline EXPERIMENTAL_FUNCTION bool cowboys::LGPAgent::Initialize () override
```





**Returns:**

Success. 





        



### function LGPAgent 

```C++
inline EXPERIMENTAL_FUNCTION cowboys::LGPAgent::LGPAgent (
    size_t id,
    const std::string & name
) 
```






### function SelectAction 

```C++
inline EXPERIMENTAL_FUNCTION size_t cowboys::LGPAgent::SelectAction (
    const cse491::WorldGrid & grid,
    const cse491::type_options_t & type_options,
    const cse491::item_set_t & item_set,
    const cse491::agent_set_t & agent_set
) override
```






### function ~LGPAgent 

```C++
cowboys::LGPAgent::~LGPAgent () override
```



## Public Static Functions Documentation




### function EncodeActions 

_Encodes the actions from an agent's action map into a vector of string, representing action names._ 
```C++
static inline EXPERIMENTAL_FUNCTION std::vector< std::string > cowboys::LGPAgent::EncodeActions (
    const std::unordered_map< std::string, size_t > & action_map,
    const std::vector< std::string > & sensorsNamesList
) 
```





**Parameters:**


* `action_map` The action map from the agent. 



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






### variable hasActionOccured 

```C++
bool hasActionOccured;
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






### variable sensorsList 

```C++
std::vector<cowboys::Sensors> sensorsList;
```






### variable sensorsNamesList 

```C++
std::vector<std::string> sensorsNamesList;
```




------------------------------
The documentation for this class was generated from the following file `source/Group7_GP_Agent/LGPAgent.hpp`

