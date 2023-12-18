

# Class DataCollection::DamageData



[**ClassList**](annotated.md) **>** [**DataCollection**](namespace_data_collection.md) **>** [**DamageData**](class_data_collection_1_1_damage_data.md)



_Represents damage related data between an agent and other entities (agents, items, grids, etc)_ 

* `#include <DamageData.hpp>`





































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**DamageData**](#function-damagedata) (std::shared\_ptr&lt; cse491::AgentBase &gt; agnt, std::shared\_ptr&lt; cse491::Entity &gt; src, int amt) <br>_The amount of damage taken from this source._  |
|   | [**~DamageData**](#function-damagedata) () = default<br>_Destructor for_ [_**DamageData**_](class_data_collection_1_1_damage_data.md) _class._ |




























## Public Functions Documentation




### function DamageData 

_The amount of damage taken from this source._ 
```C++
inline DataCollection::DamageData::DamageData (
    std::shared_ptr< cse491::AgentBase > agnt,
    std::shared_ptr< cse491::Entity > src,
    int amt
) 
```



Default constructor for a [**DamageData**](class_data_collection_1_1_damage_data.md) 

**Parameters:**


* `src` Damage source entity 
* `amt` Amount of damage taken 




        



### function ~DamageData 

```C++
DataCollection::DamageData::~DamageData () = default
```




------------------------------
The documentation for this class was generated from the following file `source/DataCollection/DamageData.hpp`

