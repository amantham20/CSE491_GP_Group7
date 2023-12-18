

# Class DataCollection::DamageCollector



[**ClassList**](annotated.md) **>** [**DataCollection**](namespace_data_collection.md) **>** [**DamageCollector**](class_data_collection_1_1_damage_collector.md)



_A data collector class for damage of game items._ [More...](#detailed-description)

* `#include <DamageCollector.hpp>`





































## Public Functions

| Type | Name |
| ---: | :--- |
|  double | [**CalculateAverageDamage**](#function-calculateaveragedamage) (const std::string & itemName) <br> |
|   | [**DamageCollector**](#function-damagecollector) () = default<br>_Default constructor for_ [_**DamageCollector**_](class_data_collection_1_1_damage_collector.md) _._ |
|  std::vector&lt; double &gt; & | [**GetDamageAmounts**](#function-getdamageamounts) (std::string itemName) <br> |
|  void | [**RecordDamageResult**](#function-recorddamageresult) (const std::string & itemName, double damageAmt) <br> |
|  void | [**WriteToDamageFile**](#function-writetodamagefile) (std::string path) <br> |




























# Detailed Description


Useful for setting up graphs for analysis of item balancing. 


    
## Public Functions Documentation




### function CalculateAverageDamage 


```C++
inline double DataCollection::DamageCollector::CalculateAverageDamage (
    const std::string & itemName
) 
```



Calculate average damage for a certain item 

**Parameters:**


* `itemName` Item name to calculate average for 



**Returns:**

The average damage as a double, -1 if the item does not exist 





        



### function DamageCollector 

```C++
DataCollection::DamageCollector::DamageCollector () = default
```






### function GetDamageAmounts 


```C++
inline std::vector< double > & DataCollection::DamageCollector::GetDamageAmounts (
    std::string itemName
) 
```



Get the damage amounts for a certain item. 

**Parameters:**


* `itemName` Name of the item to get damage amounts for 



**Returns:**

Reference to the vector of damage amounts 





        



### function RecordDamageResult 


```C++
inline void DataCollection::DamageCollector::RecordDamageResult (
    const std::string & itemName,
    double damageAmt
) 
```



Store a damage amount for a certain item. 

**Parameters:**


* `itemName` Name of the item to store the damage for 
* `damageAmt` Amount of damage this item did 




        



### function WriteToDamageFile 

```C++
inline void DataCollection::DamageCollector::WriteToDamageFile (
    std::string path
) 
```




------------------------------
The documentation for this class was generated from the following file `source/DataCollection/DamageCollector.hpp`

