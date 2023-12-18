

# Class DataCollection::AgentInteractionCollector



[**ClassList**](annotated.md) **>** [**DataCollection**](namespace_data_collection.md) **>** [**AgentInteractionCollector**](class_data_collection_1_1_agent_interaction_collector.md)



_A data collector class to quantify agent interactions._ [More...](#detailed-description)

* `#include <AgentInteractionCollector.hpp>`





































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**AgentInteractionCollector**](#function-agentinteractioncollector) () = default<br>_Data storage map of agent name to interactions._  |
|  const std::unordered\_map&lt; std::string, int &gt; & | [**GetInteractionData**](#function-getinteractiondata) () <br> |
|  size\_t | [**GetUniqueInteractions**](#function-getuniqueinteractions) () <br> |
|  void | [**RecordInteraction**](#function-recordinteraction) (const std::string & agentName) <br> |
|  void | [**WriteToInteractionFile**](#function-writetointeractionfile) (const std::string filename) <br> |




























# Detailed Description


Useful for setting up graphs for common interactions. 


    
## Public Functions Documentation




### function AgentInteractionCollector 

_Data storage map of agent name to interactions._ 
```C++
DataCollection::AgentInteractionCollector::AgentInteractionCollector () = default
```



Default constructor for [**AgentInteractionCollector**](class_data_collection_1_1_agent_interaction_collector.md) 


        



### function GetInteractionData 


```C++
inline const std::unordered_map< std::string, int > & DataCollection::AgentInteractionCollector::GetInteractionData () 
```



Getter for interaction data 

**Returns:**

Const reference to the interaction data storage. 





        



### function GetUniqueInteractions 


```C++
inline size_t DataCollection::AgentInteractionCollector::GetUniqueInteractions () 
```



Get the amount of unique agents that occured 

**Returns:**

int amount of agent occurances 





        



### function RecordInteraction 


```C++
inline void DataCollection::AgentInteractionCollector::RecordInteraction (
    const std::string & agentName
) 
```



Increment occurance amount for a certain agent. 

**Parameters:**


* `agentName` Agent name to record new interaction with 




        



### function WriteToInteractionFile 

```C++
inline void DataCollection::AgentInteractionCollector::WriteToInteractionFile (
    const std::string filename
) 
```




------------------------------
The documentation for this class was generated from the following file `source/DataCollection/AgentInteractionCollector.hpp`

