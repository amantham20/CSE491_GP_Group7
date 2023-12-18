

# Class cse491::PacingAgent



[**ClassList**](annotated.md) **>** [**cse491**](namespacecse491.md) **>** [**PacingAgent**](classcse491_1_1_pacing_agent.md)








Inherits the following classes: AgentBase


































## Public Functions

| Type | Name |
| ---: | :--- |
|  bool | [**GetVertical**](#function-getvertical) () const<br>_Returns the vertical member variable._  |
|  bool | [**Initialize**](#function-initialize) () override<br>_This agent needs a specific set of actions to function._  |
|   | [**PacingAgent**](#function-pacingagent) (size\_t id, const std::string & name) <br> |
|  size\_t | [**SelectAction**](#function-selectaction) (const WorldGrid &, const type\_options\_t &, const item\_map\_t &, const agent\_map\_t &) override<br>_Choose the action to take a step in the appropriate direction._  |
|  [**PacingAgent**](classcse491_1_1_pacing_agent.md) & | [**SetVertical**](#function-setvertical) (bool vert) <br> |
|   | [**~PacingAgent**](#function-pacingagent) () = default<br> |








## Protected Attributes

| Type | Name |
| ---: | :--- |
|  bool | [**reverse**](#variable-reverse)   = = false<br>_Is this agent on their way back? (up/left?)_  |
|  bool | [**vertical**](#variable-vertical)   = = true<br>_Is this agent moving down&up? False = right&left._  |




















## Public Functions Documentation




### function GetVertical 

```C++
inline bool cse491::PacingAgent::GetVertical () const
```






### function Initialize 

_This agent needs a specific set of actions to function._ 
```C++
inline bool cse491::PacingAgent::Initialize () override
```





**Returns:**

Success. 





        



### function PacingAgent 

```C++
inline cse491::PacingAgent::PacingAgent (
    size_t id,
    const std::string & name
) 
```






### function SelectAction 

```C++
inline size_t cse491::PacingAgent::SelectAction (
    const WorldGrid &,
    const type_options_t &,
    const item_map_t &,
    const agent_map_t &
) override
```






### function SetVertical 


```C++
inline PacingAgent & cse491::PacingAgent::SetVertical (
    bool vert
) 
```



Setter for vertical param 

**Parameters:**


* `vert` what vertical should be 



**Returns:**

self 





        



### function ~PacingAgent 

```C++
cse491::PacingAgent::~PacingAgent () = default
```



## Protected Attributes Documentation




### variable reverse 

```C++
bool reverse;
```






### variable vertical 

```C++
bool vertical;
```




------------------------------
The documentation for this class was generated from the following file `source/Agents/PacingAgent.hpp`

