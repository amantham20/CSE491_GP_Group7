

# Class cowboys::GPTrainingLoop

**template &lt;class AgentType class AgentType, class EnvironmentType class EnvironmentType&gt;**



[**ClassList**](annotated.md) **>** [**cowboys**](namespacecowboys.md) **>** [**GPTrainingLoop**](classcowboys_1_1_g_p_training_loop.md)




















## Classes

| Type | Name |
| ---: | :--- |
| struct | [**SaveDataParams**](structcowboys_1_1_g_p_training_loop_1_1_save_data_params.md) <br> |






## Public Attributes

| Type | Name |
| ---: | :--- |
|  bool | [**ScavengerQueuing**](#variable-scavengerqueuing)   = = false<br> |
















## Public Functions

| Type | Name |
| ---: | :--- |
|  double | [**AStarFitnessFunction**](#function-astarfitnessfunction) (const cse491::GridPosition & startpos, const cse491::GridPosition & endpos, int arena, int a) <br> |
|  int | [**AgentsAnalysisComputationsAndPrint**](#function-agentsanalysiscomputationsandprint) (int generation, double deltaForMaxFitness=0.1) <br> |
|  std::string | [**FormatPosition**](#function-formatposition) (const cse491::GridPosition & pos, int precision=0) <br> |
|  std::filesystem::path | [**FullLoadGrabLatestGeneration**](#function-fullloadgrablatestgeneration) () <br> |
|   | [**GPTrainingLoop**](#function-gptrainingloop) (const bool scavengerQueuing=false) <br>_: constructor_  |
|  size\_t | [**Get\_A\_StarDistance**](#function-get_a_stardistance) (const cse491::GridPosition & startpos, const cse491::GridPosition & endpos, int arenaIDX, int agentIDX) <br> |
|  void | [**GpLoopMutateHelper**](#function-gploopmutatehelper) () <br>_Helper function for the GP loop mutate function._  |
|  void | [**InitTEMPAgentFitness**](#function-inittempagentfitness) () <br>_: initialize the TEMP agent fitness vector_  |
|  void | [**Initialize**](#function-initialize) (size\_t numArenas=5, size\_t NumAgentsForArena=100) <br>_Initialize the training loop with a number of environments and agents per environment._  |
|  void | [**MemGOBYE**](#function-memgobye) () <br>_Clears the memory of the training loop._  |
|  void | [**MutateAgents**](#function-mutateagents) (int start, int end, const std::vector&lt; std::pair&lt; int, int &gt; &gt; & sortedAgents, std::vector&lt; std::vector&lt; [**cowboys::GPAgentBase**](classcowboys_1_1_g_p_agent_base.md) \* &gt; &gt; & agents, double mutationRate) <br>_Helper function for the GP loop mutate function. This function mutates the agents. This function is called in a thread._  |
|  void | [**MutateAndCopyAgents**](#function-mutateandcopyagents) (int start, int end, const std::vector&lt; std::pair&lt; int, int &gt; &gt; & sortedAgents, std::vector&lt; std::vector&lt; [**cowboys::GPAgentBase**](classcowboys_1_1_g_p_agent_base.md) \* &gt; &gt; & agents, int elitePopulationSize) <br>_Helper function for the GP loop mutate function. This function copies the elite agents and mutates them. This function is called in a thread. for th._  |
|  void | [**Printgrid**](#function-printgrid) (const std::vector&lt; cse491::GridPosition &gt; & positions, char symbol='S') <br>_Prints the grid for a single arena._  |
|  void | [**ResetMainTagLastGenerations**](#function-resetmaintaglastgenerations) () <br> |
|  void | [**Run**](#function-run) (size\_t numGenerations, size\_t numberOfTurns=100, size\_t maxThreads=0, bool saveData=false) <br>_: runs the Genetic Programming training loop for a number of generations to evolve the agents_  |
|  void | [**RunArena**](#function-runarena) (size\_t arena, size\_t numberOfTurns) <br>_Runs the training loop for a single arena. This function is called in a thread. Each arena is run in a separate thread._  |
|  void | [**SaveDataCheckPoint**](#function-savedatacheckpoint) (const [**SaveDataParams**](structcowboys_1_1_g_p_training_loop_1_1_save_data_params.md) & params) <br> |
|  void | [**SerializeAgents**](#function-serializeagents) (int generation, tinyxml2::XMLElement \* rootElement, tinyxml2::XMLDocument & paramDocument, size\_t topN=5) <br>_: Serializes the agents to an XML file._  |
|  double | [**SimpleFitnessFunction**](#function-simplefitnessfunction) (cse491::AgentBase & agent, cse491::GridPosition startPosition) <br> |
|  void | [**SortThemAgents**](#function-sortthemagents) () <br>_: sort the agents based on their fitness_  |
|  void | [**ThreadTrainLoop**](#function-threadtrainloop) (size\_t maxThreads=1, int numberOfTurns=100) <br> |
|  void | [**loadLastGeneration**](#function-loadlastgeneration) () <br> |
|  void | [**resetEnvironments**](#function-resetenvironments) () <br>_Resets the environments to their initial state. This function is called after each generation. This function currently only soft resets the environments._  |
|  void | [**saveXMLDoc**](#function-savexmldoc) (tinyxml2::XMLDocument & paramdoc, std::string fullPath) <br> |
|   | [**~GPTrainingLoop**](#function-gptrainingloop) () = default<br> |


## Public Static Functions

| Type | Name |
| ---: | :--- |
|  std::string | [**getDateStr**](#function-getdatestr) () <br> |
|  std::filesystem::path | [**getSystemPath**](#function-getsystempath) () <br> |


























## Public Attributes Documentation




### variable ScavengerQueuing 

```C++
bool ScavengerQueuing;
```



## Public Functions Documentation




### function AStarFitnessFunction 

```C++
inline double cowboys::GPTrainingLoop::AStarFitnessFunction (
    const cse491::GridPosition & startpos,
    const cse491::GridPosition & endpos,
    int arena,
    int a
) 
```






### function AgentsAnalysisComputationsAndPrint 


```C++
inline int cowboys::GPTrainingLoop::AgentsAnalysisComputationsAndPrint (
    int generation,
    double deltaForMaxFitness=0.1
) 
```



Computes agents analysis metrics




**Parameters:**


* `generation` 



**Returns:**







        



### function FormatPosition 


```C++
inline std::string cowboys::GPTrainingLoop::FormatPosition (
    const cse491::GridPosition & pos,
    int precision=0
) 
```



Helper function to format the data analysis 

**Parameters:**


* `pos` 
* `precision` 



**Returns:**







        



### function FullLoadGrabLatestGeneration 

```C++
inline std::filesystem::path cowboys::GPTrainingLoop::FullLoadGrabLatestGeneration () 
```






### function GPTrainingLoop 

```C++
inline cowboys::GPTrainingLoop::GPTrainingLoop (
    const bool scavengerQueuing=false
) 
```






### function Get\_A\_StarDistance 

```C++
inline size_t cowboys::GPTrainingLoop::Get_A_StarDistance (
    const cse491::GridPosition & startpos,
    const cse491::GridPosition & endpos,
    int arenaIDX,
    int agentIDX
) 
```






### function GpLoopMutateHelper 

```C++
inline void cowboys::GPTrainingLoop::GpLoopMutateHelper () 
```






### function InitTEMPAgentFitness 

```C++
inline void cowboys::GPTrainingLoop::InitTEMPAgentFitness () 
```






### function Initialize 

_Initialize the training loop with a number of environments and agents per environment._ 
```C++
inline void cowboys::GPTrainingLoop::Initialize (
    size_t numArenas=5,
    size_t NumAgentsForArena=100
) 
```





**Parameters:**


* `numArenas` 
* `NumAgentsForArena` 




        



### function MemGOBYE 

```C++
inline void cowboys::GPTrainingLoop::MemGOBYE () 
```






### function MutateAgents 

_Helper function for the GP loop mutate function. This function mutates the agents. This function is called in a thread._ 
```C++
inline void cowboys::GPTrainingLoop::MutateAgents (
    int start,
    int end,
    const std::vector< std::pair< int, int > > & sortedAgents,
    std::vector< std::vector< cowboys::GPAgentBase * > > & agents,
    double mutationRate
) 
```





**Parameters:**


* `start` : The start index of the agents to mutate. 
* `end` : The end index of the agents to mutate. 
* `sortedAgents` : The sorted agents' index vector. 
* `agents` : The agents vector. 
* `mutationRate` The mutation rate. 




        



### function MutateAndCopyAgents 

_Helper function for the GP loop mutate function. This function copies the elite agents and mutates them. This function is called in a thread. for th._ 
```C++
inline void cowboys::GPTrainingLoop::MutateAndCopyAgents (
    int start,
    int end,
    const std::vector< std::pair< int, int > > & sortedAgents,
    std::vector< std::vector< cowboys::GPAgentBase * > > & agents,
    int elitePopulationSize
) 
```





**Parameters:**


* `start` 
* `end` 
* `sortedAgents` 
* `agents` 
* `elitePopulationSize` 




        



### function Printgrid 

_Prints the grid for a single arena._ 
```C++
inline void cowboys::GPTrainingLoop::Printgrid (
    const std::vector< cse491::GridPosition > & positions,
    char symbol='S'
) 
```





**Parameters:**


* `arenaId` 



**Author:**

: @amantham20 





        



### function ResetMainTagLastGenerations 


```C++
inline void cowboys::GPTrainingLoop::ResetMainTagLastGenerations () 
```



Resets the xml for data that needs to be overwritten 


        



### function Run 

_: runs the Genetic Programming training loop for a number of generations to evolve the agents_ 
```C++
inline void cowboys::GPTrainingLoop::Run (
    size_t numGenerations,
    size_t numberOfTurns=100,
    size_t maxThreads=0,
    bool saveData=false
) 
```





**Parameters:**


* `numGenerations` 
* `numberOfTurns` 
* `maxThreads` 




        



### function RunArena 

_Runs the training loop for a single arena. This function is called in a thread. Each arena is run in a separate thread._ 
```C++
inline void cowboys::GPTrainingLoop::RunArena (
    size_t arena,
    size_t numberOfTurns
) 
```





**Author:**

: @amantham20 




**Parameters:**


* `arena` : The arena to run. 
* `numberOfTurns` : The number of turns to run the arena for. 




        



### function SaveDataCheckPoint 


```C++
inline void cowboys::GPTrainingLoop::SaveDataCheckPoint (
    const SaveDataParams & params
) 
```



Saves checkpoint data to XML files everyso often 

**Parameters:**


* `params` 




        



### function SerializeAgents 

_: Serializes the agents to an XML file._ 
```C++
inline void cowboys::GPTrainingLoop::SerializeAgents (
    int generation,
    tinyxml2::XMLElement * rootElement,
    tinyxml2::XMLDocument & paramDocument,
    size_t topN=5
) 
```





**Parameters:**


* `countMaxAgents` 
* `generation` 
* `topN` 




        



### function SimpleFitnessFunction 


```C++
inline double cowboys::GPTrainingLoop::SimpleFitnessFunction (
    cse491::AgentBase & agent,
    cse491::GridPosition startPosition
) 
```



Simple and temporary fitness function 

**Parameters:**


* `agent` 
* `startPosition` 



**Returns:**







        



### function SortThemAgents 

```C++
inline void cowboys::GPTrainingLoop::SortThemAgents () 
```






### function ThreadTrainLoop 


```C++
inline void cowboys::GPTrainingLoop::ThreadTrainLoop (
    size_t maxThreads=1,
    int numberOfTurns=100
) 
```





**Parameters:**


* `maxThreads` 
* `numberOfTurns` 




        



### function loadLastGeneration 

```C++
inline void cowboys::GPTrainingLoop::loadLastGeneration () 
```






### function resetEnvironments 

```C++
inline void cowboys::GPTrainingLoop::resetEnvironments () 
```






### function saveXMLDoc 

```C++
inline void cowboys::GPTrainingLoop::saveXMLDoc (
    tinyxml2::XMLDocument & paramdoc,
    std::string fullPath
) 
```






### function ~GPTrainingLoop 

```C++
cowboys::GPTrainingLoop::~GPTrainingLoop () = default
```



## Public Static Functions Documentation




### function getDateStr 


```C++
static inline std::string cowboys::GPTrainingLoop::getDateStr () 
```



Gets the date and time as a string 

**Returns:**







        



### function getSystemPath 


```C++
static inline std::filesystem::path cowboys::GPTrainingLoop::getSystemPath () 
```



Gets the path of the save location 

**Returns:**







        

------------------------------
The documentation for this class was generated from the following file `source/Agents/GP/GPTrainingLoop.hpp`

