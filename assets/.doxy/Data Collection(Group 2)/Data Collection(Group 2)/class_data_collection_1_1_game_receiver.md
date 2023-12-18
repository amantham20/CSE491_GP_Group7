

# Class DataCollection::GameReceiver



[**ClassList**](annotated.md) **>** [**DataCollection**](namespace_data_collection.md) **>** [**GameReceiver**](class_data_collection_1_1_game_receiver.md)



_Represents a receiver specifically designed to handle game-related data._ [More...](#detailed-description)

* `#include <GameReceiver.hpp>`



Inherits the following classes: [DataCollection::DataReceiver](class_data_collection_1_1_data_receiver.md)






















































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**GameReceiver**](#function-gamereceiver) () = default<br>_Default constructor for the_ [_**GameReceiver**_](class_data_collection_1_1_game_receiver.md) _class._ |
|  void | [**store\_GameData**](#function-store_gamedata) (const [**GameData**](class_data_collection_1_1_game_data.md) & gameData) <br>_Store a_ [_**GameData**_](class_data_collection_1_1_game_data.md) _object into the receiver's storage._ |
|   | [**~GameReceiver**](#function-gamereceiver) () override<br>_Destructor for the_ [_**GameReceiver**_](class_data_collection_1_1_game_receiver.md) _class._ |


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


[**GameReceiver**](class_data_collection_1_1_game_receiver.md) is an extension of the generic [**DataReceiver**](class_data_collection_1_1_data_receiver.md), specialized to handle data related to games. It provides methods for storing and processing game-specific data types such as [**GameData**](class_data_collection_1_1_game_data.md). 


    
## Public Functions Documentation




### function GameReceiver 

```C++
DataCollection::GameReceiver::GameReceiver () = default
```






### function store\_GameData 

_Store a_ [_**GameData**_](class_data_collection_1_1_game_data.md) _object into the receiver's storage._
```C++
inline void DataCollection::GameReceiver::store_GameData (
    const GameData & gameData
) 
```



This method allows for the addition of game-specific data into the receiver's storage for further processing or analysis.




**Parameters:**


* `gameData` The [**GameData**](class_data_collection_1_1_game_data.md) object to be stored. 




        



### function ~GameReceiver 

```C++
DataCollection::GameReceiver::~GameReceiver () override
```




------------------------------
The documentation for this class was generated from the following file `source/DataCollection/GameReceiver.hpp`

