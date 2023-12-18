

# Class DataCollection::ItemUseCollector



[**ClassList**](annotated.md) **>** [**DataCollection**](namespace_data_collection.md) **>** [**ItemUseCollector**](class_data_collection_1_1_item_use_collector.md)



_A data collector class for usage amount of game items._ [More...](#detailed-description)

* `#include <ItemUseCollector.hpp>`





































## Public Functions

| Type | Name |
| ---: | :--- |
|  std::string | [**GetLeastFrequent**](#function-getleastfrequent) () <br> |
|  std::string | [**GetMostFrequent**](#function-getmostfrequent) () <br> |
|  int | [**GetNumberOfItems**](#function-getnumberofitems) () <br> |
|  const std::unordered\_map&lt; std::string, int &gt; & | [**GetUsageData**](#function-getusagedata) () <br> |
|  void | [**IncrementItemUsage**](#function-incrementitemusage) (const std::string & itemName) <br> |
|   | [**ItemUseCollector**](#function-itemusecollector) () = default<br>_Damage storage map of item name to amount of uses._  |
|  void | [**WriteToItemUseFile**](#function-writetoitemusefile) (std::string path) <br> |




























# Detailed Description


Useful for setting up graphs for analysis of item balancing. 


    
## Public Functions Documentation




### function GetLeastFrequent 


```C++
inline std::string DataCollection::ItemUseCollector::GetLeastFrequent () 
```



Get the least frequently used item in the game. 

**Returns:**

Name of the least item as a string, empty string if no data 





        



### function GetMostFrequent 


```C++
inline std::string DataCollection::ItemUseCollector::GetMostFrequent () 
```



Get the most frequently used item in the game. 

**Returns:**

Name of the most frequent item as a string, empty string if no data 





        



### function GetNumberOfItems 


```C++
inline int DataCollection::ItemUseCollector::GetNumberOfItems () 
```



Get the amount of unique items that are collected 

**Returns:**

int amount of unique items 





        



### function GetUsageData 


```C++
inline const std::unordered_map< std::string, int > & DataCollection::ItemUseCollector::GetUsageData () 
```



Getter for item usage data 

**Returns:**

Const reference to the usage data storage. 





        



### function IncrementItemUsage 


```C++
inline void DataCollection::ItemUseCollector::IncrementItemUsage (
    const std::string & itemName
) 
```



Increment usage amount for a certain item. 

**Parameters:**


* `itemName` Item name to record new usage of 




        



### function ItemUseCollector 

_Damage storage map of item name to amount of uses._ 
```C++
DataCollection::ItemUseCollector::ItemUseCollector () = default
```



Default constructor for [**ItemUseCollector**](class_data_collection_1_1_item_use_collector.md) 


        



### function WriteToItemUseFile 

```C++
inline void DataCollection::ItemUseCollector::WriteToItemUseFile (
    std::string path
) 
```




------------------------------
The documentation for this class was generated from the following file `source/DataCollection/ItemUseCollector.hpp`

