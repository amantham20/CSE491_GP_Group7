

# Class DataCollection::AgentReceiver



[**ClassList**](annotated.md) **>** [**DataCollection**](namespace_data_collection.md) **>** [**AgentReceiver**](class_data_collection_1_1_agent_receiver.md)



_Data receiver class specialized for storing_ [_**AgentData**_](class_data_collection_1_1_agent_data.md) _objects._[More...](#detailed-description)

* `#include <AgentReciever.hpp>`



Inherits the following classes: [DataCollection::DataReceiver](class_data_collection_1_1_data_receiver.md)






















































## Public Functions

| Type | Name |
| ---: | :--- |
|  void | [**AddAgent**](#function-addagent) (const std::string & name) <br>_Stores agent data into the storage and writes to a json file._  |
|  std::shared\_ptr&lt; [**AgentData**](class_data_collection_1_1_agent_data.md) &gt; | [**GetAgent**](#function-getagent) (const std::string & name) <br> |
|  [**AgentData**](class_data_collection_1_1_agent_data.md) | [**GetAgentData**](#function-getagentdata) (const std::string & name) <br> |
|  void | [**StoreData**](#function-storedata) (std::string name, cse491::GridPosition pos, int last\_action) <br>_Stores a grid position and last action ID associated with an agent._  |
|  void | [**WriteToPositionFile**](#function-writetopositionfile) (std::string path) <br>_Writes the stored_ [_**AgentData**_](class_data_collection_1_1_agent_data.md) _Positions to a JSON file._ |


## Public Functions inherited from DataCollection::DataReceiver

See [DataCollection::DataReceiver](class_data_collection_1_1_data_receiver.md)

| Type | Name |
| ---: | :--- |
|   | [**DataReceiver**](#function-datareceiver) () = default<br>_Default constructor for_ [_**DataReceiver**_](class_data_collection_1_1_data_receiver.md) _class._ |
|  bool | [**IsEmpty**](#function-isempty) () <br>_Checks if the storage is empty._  |
|  void | [**StoreIntoStorage**](#function-storeintostorage) (T obj) <br>_Store a data object into the storage._  |
|  std::vector&lt; T &gt; & | [**getStorage**](#function-getstorage) () <br>_Retrieves the stored data objects._  |
| virtual  | [**~DataReceiver**](#function-datareceiver) () = default<br>_Virtual destructor for_ [_**DataReceiver**_](class_data_collection_1_1_data_receiver.md) _class._ |
















## Protected Attributes inherited from DataCollection::DataReceiver

See [DataCollection::DataReceiver](class_data_collection_1_1_data_receiver.md)

| Type | Name |
| ---: | :--- |
|  std::vector&lt; T &gt; | [**storage**](#variable-storage)  <br>_Vector to store shared\_ptr data objects of type T._  |






































# Detailed Description


This class extends [**DataReceiver**](class_data_collection_1_1_data_receiver.md) class and provides specific functionality for storing [**AgentData**](class_data_collection_1_1_agent_data.md) objects along with grid positions and last action IDs. 


    
## Public Functions Documentation




### function AddAgent 

_Stores agent data into the storage and writes to a json file._ 
```C++
inline void DataCollection::AgentReceiver::AddAgent (
    const std::string & name
) 
```





**Parameters:**


* `name` the name of the agent 




        



### function GetAgent 

```C++
inline std::shared_ptr< AgentData > DataCollection::AgentReceiver::GetAgent (
    const std::string & name
) 
```






### function GetAgentData 

```C++
inline AgentData DataCollection::AgentReceiver::GetAgentData (
    const std::string & name
) 
```






### function StoreData 

_Stores a grid position and last action ID associated with an agent._ 
```C++
inline void DataCollection::AgentReceiver::StoreData (
    std::string name,
    cse491::GridPosition pos,
    int last_action
) 
```





**Parameters:**


* `pos` The grid position to be stored. 
* `last_action` The last action ID associated with the agent. 




        



### function WriteToPositionFile 

_Writes the stored_ [_**AgentData**_](class_data_collection_1_1_agent_data.md) _Positions to a JSON file._
```C++
inline void DataCollection::AgentReceiver::WriteToPositionFile (
    std::string path
) 
```





**Parameters:**


* `agent` The [**AgentData**](class_data_collection_1_1_agent_data.md) Position to be stored. 




        

------------------------------
The documentation for this class was generated from the following file `source/DataCollection/AgentReciever.hpp`

