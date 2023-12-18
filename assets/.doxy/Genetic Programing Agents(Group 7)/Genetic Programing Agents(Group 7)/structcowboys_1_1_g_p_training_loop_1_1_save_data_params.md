

# Struct cowboys::GPTrainingLoop::SaveDataParams



[**ClassList**](annotated.md) **>** [**cowboys**](namespacecowboys.md) **>** [**GPTrainingLoop**](classcowboys_1_1_g_p_training_loop.md) **>** [**SaveDataParams**](structcowboys_1_1_g_p_training_loop_1_1_save_data_params.md)



[More...](#detailed-description)

* `#include <GPTrainingLoop.hpp>`





















## Public Attributes

| Type | Name |
| ---: | :--- |
|  size\_t | [**checkPointEvery**](#variable-checkpointevery)   = = 5<br> |
|  size\_t | [**countMaxAgents**](#variable-countmaxagents)   = = 0<br> |
|  std::string | [**dateTimeStr**](#variable-datetimestr)   = = [**getDateStr**](classcowboys_1_1_g_p_training_loop.md#function-getdatestr)()<br> |
|  size\_t | [**generation**](#variable-generation)  <br> |
|  std::filesystem::path | [**normalizedAbsolutePath**](#variable-normalizedabsolutepath)   = = [**getSystemPath**](classcowboys_1_1_g_p_training_loop.md#function-getsystempath)()<br> |
|  bool | [**save**](#variable-save)   = = false<br> |
|  bool | [**saveAllAgentData**](#variable-saveallagentdata)   = = false<br> |
|  bool | [**saveLastGenerations**](#variable-savelastgenerations)   = = false<br> |
|  bool | [**saveMetaData**](#variable-savemetadata)   = = true<br> |
|  bool | [**saveTopAgents**](#variable-savetopagents)   = = false<br> |
















## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**SaveDataParams**](#function-savedataparams) (size\_t gen) <br> |
|  void | [**updateGeneration**](#function-updategeneration) (size\_t gen) <br> |




























# Detailed Description


[**SaveDataParams**](structcowboys_1_1_g_p_training_loop_1_1_save_data_params.md) for saving data in checkpoints 


    
## Public Attributes Documentation




### variable checkPointEvery 

```C++
size_t checkPointEvery;
```






### variable countMaxAgents 

```C++
size_t countMaxAgents;
```






### variable dateTimeStr 

```C++
std::string dateTimeStr;
```






### variable generation 

```C++
size_t generation;
```






### variable normalizedAbsolutePath 

```C++
std::filesystem::path normalizedAbsolutePath;
```






### variable save 

```C++
bool save;
```






### variable saveAllAgentData 

```C++
bool saveAllAgentData;
```






### variable saveLastGenerations 

```C++
bool saveLastGenerations;
```






### variable saveMetaData 

```C++
bool saveMetaData;
```






### variable saveTopAgents 

```C++
bool saveTopAgents;
```



## Public Functions Documentation




### function SaveDataParams 

```C++
inline cowboys::GPTrainingLoop::SaveDataParams::SaveDataParams (
    size_t gen
) 
```






### function updateGeneration 

```C++
inline void cowboys::GPTrainingLoop::SaveDataParams::updateGeneration (
    size_t gen
) 
```




------------------------------
The documentation for this class was generated from the following file `source/Agents/GP/GPTrainingLoop.hpp`

