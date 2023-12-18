

# Class DataCollection::DamageReceiver



[**ClassList**](annotated.md) **>** [**DataCollection**](namespace_data_collection.md) **>** [**DamageReceiver**](class_data_collection_1_1_damage_receiver.md)



_Data receiver class specialized for storing_ [_**DamageData**_](class_data_collection_1_1_damage_data.md) _objects._[More...](#detailed-description)

* `#include <DamageReceiver.hpp>`



Inherits the following classes: [DataCollection::DataReceiver](class_data_collection_1_1_data_receiver.md)
























































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


This class extends [**DataReceiver**](class_data_collection_1_1_data_receiver.md) class and provides specific functionality for storing [**DamageData**](class_data_collection_1_1_damage_data.md) objects along with damage sources and amounts. 


    

------------------------------
The documentation for this class was generated from the following file `source/DataCollection/DamageReceiver.hpp`

