

# Class cowboys::Sensors



[**ClassList**](annotated.md) **>** [**cowboys**](namespacecowboys.md) **>** [**Sensors**](classcowboys_1_1_sensors.md)










































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**Sensors**](#function-sensors) () = default<br>_Constructor._  |
|   | [**~Sensors**](#function-sensors) () = default<br>_Destructor._  |


## Public Static Functions

| Type | Name |
| ---: | :--- |
|  SensorDirection | [**getSensorDirectionEnum**](#function-getsensordirectionenum) (const std::string & direction) <br> |
|  int | [**wallDistance**](#function-walldistance) (const cse491::WorldGrid & grid, const cse491::AgentBase & agent, SensorDirection direction) <br>_returns the distance to the wall in a given direction from the agent_  |


























## Public Functions Documentation




### function Sensors 

```C++
cowboys::Sensors::Sensors () = default
```






### function ~Sensors 

```C++
cowboys::Sensors::~Sensors () = default
```



## Public Static Functions Documentation




### function getSensorDirectionEnum 

```C++
static inline SensorDirection cowboys::Sensors::getSensorDirectionEnum (
    const std::string & direction
) 
```






### function wallDistance 

_returns the distance to the wall in a given direction from the agent_ 
```C++
static inline int cowboys::Sensors::wallDistance (
    const cse491::WorldGrid & grid,
    const cse491::AgentBase & agent,
    SensorDirection direction
) 
```





**Parameters:**


* `grid` grid maze of the world 
* `agent` agent to find the distance from 
* `direction` direction to find the distance (LEFT, RIGHT, ABOVE, BELOW) 



**Returns:**

distance to the wall 





        

------------------------------
The documentation for this class was generated from the following file `source/Agents/GP/GPAgentSensors.hpp`

