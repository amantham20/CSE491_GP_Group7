

# Class DataCollection::JsonBuilder



[**ClassList**](annotated.md) **>** [**DataCollection**](namespace_data_collection.md) **>** [**JsonBuilder**](class_data_collection_1_1_json_builder.md)



_Builds a JSON object from the data collected for an agent._ 

* `#include <JsonBuilder.hpp>`





































## Public Functions

| Type | Name |
| ---: | :--- |
|  void | [**AddDamage**](#function-adddamage) (double damage) <br> |
|  void | [**AddInt**](#function-addint) (std::string title, int usage) <br> |
|  void | [**AddName**](#function-addname) (std::string name) <br>_Adds the agent's name to the JSON object._  |
|  void | [**AddPosition**](#function-addposition) (cse491::GridPosition pos) <br>_Adds a grid position to the JSON object._  |
|  void | [**Addagentname**](#function-addagentname) (std::string name) <br> |
|  void | [**ClearJSON**](#function-clearjson) () <br> |
|  nlohmann::json | [**GetJSON**](#function-getjson) () <br>_Retrieves the JSON object._  |
|  nlohmann::json | [**GetJSONArray**](#function-getjsonarray) () <br> |
|  void | [**InputToArray**](#function-inputtoarray) (std::string title, nlohmann::json input) <br> |
|   | [**JsonBuilder**](#function-jsonbuilder) () = default<br>_Default constructor for JSONBuilder class._  |
|  void | [**StartArray**](#function-startarray) (std::string title) <br> |
|  void | [**WriteToFile**](#function-writetofile) (std::ofstream & jsonfilestream, nlohmann::json Json) <br>_Writes the JSON object to a file._  |
|   | [**~JsonBuilder**](#function-jsonbuilder) () = default<br>_Destructor for JSONBuilder class._  |




























## Public Functions Documentation




### function AddDamage 

```C++
inline void DataCollection::JsonBuilder::AddDamage (
    double damage
) 
```






### function AddInt 

```C++
inline void DataCollection::JsonBuilder::AddInt (
    std::string title,
    int usage
) 
```






### function AddName 

_Adds the agent's name to the JSON object._ 
```C++
inline void DataCollection::JsonBuilder::AddName (
    std::string name
) 
```





**Parameters:**


* `name` The agent's name. 




        



### function AddPosition 

_Adds a grid position to the JSON object._ 
```C++
inline void DataCollection::JsonBuilder::AddPosition (
    cse491::GridPosition pos
) 
```





**Parameters:**


* `pos` The grid position to be added. 




        



### function Addagentname 

```C++
inline void DataCollection::JsonBuilder::Addagentname (
    std::string name
) 
```






### function ClearJSON 

```C++
inline void DataCollection::JsonBuilder::ClearJSON () 
```






### function GetJSON 

_Retrieves the JSON object._ 
```C++
inline nlohmann::json DataCollection::JsonBuilder::GetJSON () 
```





**Returns:**

The JSON object. 





        



### function GetJSONArray 

```C++
inline nlohmann::json DataCollection::JsonBuilder::GetJSONArray () 
```






### function InputToArray 

```C++
inline void DataCollection::JsonBuilder::InputToArray (
    std::string title,
    nlohmann::json input
) 
```






### function JsonBuilder 

```C++
DataCollection::JsonBuilder::JsonBuilder () = default
```






### function StartArray 

```C++
inline void DataCollection::JsonBuilder::StartArray (
    std::string title
) 
```






### function WriteToFile 

```C++
inline void DataCollection::JsonBuilder::WriteToFile (
    std::ofstream & jsonfilestream,
    nlohmann::json Json
) 
```






### function ~JsonBuilder 

```C++
DataCollection::JsonBuilder::~JsonBuilder () = default
```




------------------------------
The documentation for this class was generated from the following file `source/DataCollection/JsonBuilder.hpp`

