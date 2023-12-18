

# Class DataCollection::DataReceiver

**template &lt;typename T typename T&gt;**



[**ClassList**](annotated.md) **>** [**DataCollection**](namespace_data_collection.md) **>** [**DataReceiver**](class_data_collection_1_1_data_receiver.md)



_Generic data receiver template class._ [More...](#detailed-description)

* `#include <DataReceiver.hpp>`





































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**DataReceiver**](#function-datareceiver) () = default<br>_Default constructor for_ [_**DataReceiver**_](class_data_collection_1_1_data_receiver.md) _class._ |
|  bool | [**IsEmpty**](#function-isempty) () <br>_Checks if the storage is empty._  |
|  void | [**StoreIntoStorage**](#function-storeintostorage) (T obj) <br>_Store a data object into the storage._  |
|  std::vector&lt; T &gt; & | [**getStorage**](#function-getstorage) () <br>_Retrieves the stored data objects._  |
| virtual  | [**~DataReceiver**](#function-datareceiver) () = default<br>_Virtual destructor for_ [_**DataReceiver**_](class_data_collection_1_1_data_receiver.md) _class._ |








## Protected Attributes

| Type | Name |
| ---: | :--- |
|  std::vector&lt; T &gt; | [**storage**](#variable-storage)  <br>_Vector to store shared\_ptr data objects of type T._  |




















# Detailed Description


This class provides a template for storing and retrieving data objects of a specified type. 

**Template parameters:**


* `T` The type of data to be stored. 




    
## Public Functions Documentation




### function DataReceiver 

```C++
DataCollection::DataReceiver::DataReceiver () = default
```






### function IsEmpty 

_Checks if the storage is empty._ 
```C++
inline bool DataCollection::DataReceiver::IsEmpty () 
```





**Returns:**

True if the storage is empty, false otherwise. 





        



### function StoreIntoStorage 

_Store a data object into the storage._ 
```C++
inline void DataCollection::DataReceiver::StoreIntoStorage (
    T obj
) 
```





**Parameters:**


* `obj` The data object to store 




        



### function getStorage 

_Retrieves the stored data objects._ 
```C++
inline std::vector< T > & DataCollection::DataReceiver::getStorage () 
```





**Returns:**

Reference to the vector containing stored data objects. 





        



### function ~DataReceiver 

```C++
virtual DataCollection::DataReceiver::~DataReceiver () = default
```



## Protected Attributes Documentation




### variable storage 

```C++
std::vector<T> storage;
```




------------------------------
The documentation for this class was generated from the following file `source/DataCollection/DataReceiver.hpp`

