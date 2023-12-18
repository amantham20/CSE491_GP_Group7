

# Class cowboys::GPAgentAnalyzer



[**ClassList**](annotated.md) **>** [**cowboys**](namespacecowboys.md) **>** [**GPAgentAnalyzer**](classcowboys_1_1_g_p_agent_analyzer.md)










































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**GPAgentAnalyzer**](#function-gpagentanalyzer) () = default<br>_Construct a new GP Agent Analyzer object._  |
|  void | [**addAverageFitness**](#function-addaveragefitness) (double fitness) <br>_Adds the average fitness of the best agent._  |
|  void | [**addAverageScore**](#function-addaveragescore) (double score) <br>_Adds the average score of the best agent._  |
|  void | [**addEliteScore**](#function-addelitescore) (double score) <br>_Adds the weighted score of the best agent._  |
|  void | [**addMaxFitness**](#function-addmaxfitness) (double fitness) <br>_Adds the max fitness of the best agent._  |
|  void | [**addNumAgentsWithMaxFitness**](#function-addnumagentswithmaxfitness) (double num\_agents) <br>_Adds the number of agents with the max fitness._  |
|  void | [**saveToFile**](#function-savetofile) () <br>_Saves the data to a csv file._  |
|   | [**~GPAgentAnalyzer**](#function-gpagentanalyzer) () = default<br>_Destroy the GP Agent Analyzer object._  |




























## Public Functions Documentation




### function GPAgentAnalyzer 

```C++
cowboys::GPAgentAnalyzer::GPAgentAnalyzer () = default
```






### function addAverageFitness 

_Adds the average fitness of the best agent._ 
```C++
inline void cowboys::GPAgentAnalyzer::addAverageFitness (
    double fitness
) 
```





**Parameters:**


* `fitness` 




        



### function addAverageScore 

_Adds the average score of the best agent._ 
```C++
inline void cowboys::GPAgentAnalyzer::addAverageScore (
    double score
) 
```





**Parameters:**


* `score` 




        



### function addEliteScore 

_Adds the weighted score of the best agent._ 
```C++
inline void cowboys::GPAgentAnalyzer::addEliteScore (
    double score
) 
```





**Parameters:**


* `score` 




        



### function addMaxFitness 

_Adds the max fitness of the best agent._ 
```C++
inline void cowboys::GPAgentAnalyzer::addMaxFitness (
    double fitness
) 
```





**Parameters:**


* `fitness` 




        



### function addNumAgentsWithMaxFitness 

_Adds the number of agents with the max fitness._ 
```C++
inline void cowboys::GPAgentAnalyzer::addNumAgentsWithMaxFitness (
    double num_agents
) 
```





**Parameters:**


* `num_agents` 




        



### function saveToFile 

```C++
inline void cowboys::GPAgentAnalyzer::saveToFile () 
```






### function ~GPAgentAnalyzer 

```C++
cowboys::GPAgentAnalyzer::~GPAgentAnalyzer () = default
```




------------------------------
The documentation for this class was generated from the following file `source/Agents/GP/GPAgentAnalyze.h`

