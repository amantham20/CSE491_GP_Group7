

# Class walle::TrackingAgent



[**ClassList**](annotated.md) **>** [**walle**](namespacewalle.md) **>** [**TrackingAgent**](classwalle_1_1_tracking_agent.md)



[More...](#detailed-description)

* `#include <TrackingAgent.hpp>`



Inherits the following classes: AgentBase


































## Public Functions

| Type | Name |
| ---: | :--- |
|  void | [**AddToAlerter**](#function-addtoalerter) (std::shared\_ptr&lt; [**Alerter**](classwalle_1_1_alerter.md) &gt; alerter) <br> |
|  void | [**CallAlerter**](#function-callalerter) (size\_t agent\_id) <br>_Tells the alerter to notify all other tracking agents in network._  |
|  std::shared\_ptr&lt; [**Alerter**](classwalle_1_1_alerter.md) &gt; | [**GetAlerter**](#function-getalerter) () const<br> |
|  cse491::GridPosition | [**GetNextPosition**](#function-getnextposition) () override<br> |
|  std::vector&lt; cse491::GridPosition &gt; const & | [**GetPath**](#function-getpath) () const<br> |
|  [**TrackingState**](namespacewalle.md#enum-trackingstate) | [**GetState**](#function-getstate) () <br> |
|  cse491::Entity const \* | [**GetTarget**](#function-gettarget) () const<br> |
|  double | [**GetTrackingDistance**](#function-gettrackingdistance) () const<br> |
|  bool | [**Initialize**](#function-initialize) () override<br> |
|  void | [**MakeAlerter**](#function-makealerter) () <br>_Creates an alerter network and adds this tracking agent to it._  |
|  void | [**RemoveFromAlerter**](#function-removefromalerter) () <br> |
|  size\_t | [**SelectAction**](#function-selectaction) (cse491::WorldGrid const & grid, cse491::type\_options\_t const & type, cse491::item\_map\_t const & item\_set, cse491::agent\_map\_t const & agent\_set) override<br>_Updates the internal state of the_ [_**TrackingAgent**_](classwalle_1_1_tracking_agent.md) _and calls the internal agent's select action method._ |
|  size\_t | [**SelectInnerAction**](#function-selectinneraction-12) ([**PathAgent**](classwalle_1_1_path_agent.md) & agent, cse491::WorldGrid const & grid, cse491::type\_options\_t const & type, cse491::item\_map\_t const & item\_set, cse491::agent\_map\_t const & agent\_set) <br>_Select action for_ [_**PathAgent**_](classwalle_1_1_path_agent.md) _inner type._ |
|  size\_t | [**SelectInnerAction**](#function-selectinneraction-22) ([**AStarAgent**](classwalle_1_1_a_star_agent.md) & agent, cse491::WorldGrid const & grid, cse491::type\_options\_t const & type, cse491::item\_map\_t const & item\_set, cse491::agent\_map\_t const & agent\_set) <br>_Select action for_ [_**AStarAgent**_](classwalle_1_1_a_star_agent.md) _inner type._ |
|  [**TrackingAgent**](classwalle_1_1_tracking_agent.md) & | [**SetPath**](#function-setpath-12) (std::vector&lt; cse491::GridPosition &gt; offsets) <br> |
|  [**TrackingAgent**](classwalle_1_1_tracking_agent.md) & | [**SetPath**](#function-setpath-22) (std::string\_view offsets) <br> |
|  [**TrackingAgent**](classwalle_1_1_tracking_agent.md) & | [**SetStartPosition**](#function-setstartposition-12) (cse491::GridPosition pos) <br> |
|  [**TrackingAgent**](classwalle_1_1_tracking_agent.md) & | [**SetStartPosition**](#function-setstartposition-22) (double x, double y) <br> |
|  [**TrackingAgent**](classwalle_1_1_tracking_agent.md) & | [**SetTarget**](#function-settarget) (Entity \* agent) <br> |
|  [**TrackingAgent**](classwalle_1_1_tracking_agent.md) & | [**SetTrackingDistance**](#function-settrackingdistance) (double dist) <br> |
|  [**TrackingAgent**](classwalle_1_1_tracking_agent.md) & | [**SetWorld**](#function-setworld) (cse491::WorldBase & in\_world) override<br> |
|   | [**TrackingAgent**](#function-trackingagent-14) () = delete<br> |
|   | [**TrackingAgent**](#function-trackingagent-24) (size\_t id, std::string const & name) <br> |
|   | [**TrackingAgent**](#function-trackingagent-34) (size\_t id, std::string const & name, std::vector&lt; cse491::GridPosition &gt; && offsets, std::shared\_ptr&lt; [**Alerter**](classwalle_1_1_alerter.md) &gt; && alerter=nullptr) <br> |
|   | [**TrackingAgent**](#function-trackingagent-44) (size\_t id, std::string const & name, std::string\_view commands, std::shared\_ptr&lt; [**Alerter**](classwalle_1_1_alerter.md) &gt; && alerter=nullptr) <br> |
|  void | [**UpdateState**](#function-updatestate) (bool alerting=true) <br> |
|   | [**~TrackingAgent**](#function-trackingagent) () override<br> |




























# Detailed Description


Agent that switches between user-defined custom movement pattern and tracking a given agent 


    
## Public Functions Documentation




### function AddToAlerter 


```C++
inline void walle::TrackingAgent::AddToAlerter (
    std::shared_ptr< Alerter > alerter
) 
```



Adds this tracking agent to an already-existing alerter network 

**Parameters:**


* `alerter` alerter that this agent should be associated with 



**Note:**

alerter must not be null 





        



### function CallAlerter 

```C++
inline void walle::TrackingAgent::CallAlerter (
    size_t agent_id
) 
```






### function GetAlerter 


```C++
inline std::shared_ptr< Alerter > walle::TrackingAgent::GetAlerter () const
```



Used to expand the alerter network by adding other tracking agents to it 

**Returns:**

a copy of this tracking agent's alerter 




**Note:**

it's expected that this function is used when calling AddToAlerter on a different tracking agent 




**Note:**

may be null 





        



### function GetNextPosition 


```C++
inline cse491::GridPosition walle::TrackingAgent::GetNextPosition () override
```



Overrides the AgentBase getter to retrieve the next calculated position 

**Returns:**

inner [**PathAgent**](classwalle_1_1_path_agent.md)'s next position 





        



### function GetPath 


```C++
inline std::vector< cse491::GridPosition > const & walle::TrackingAgent::GetPath () const
```



Returns an immutable reference to this agent's current path 

**Returns:**

sequence of offsets 





        



### function GetState 


```C++
inline TrackingState walle::TrackingAgent::GetState () 
```



Retrieves the current internal state of the Tracking Agent 

**Returns:**

current state 





        



### function GetTarget 


```C++
inline cse491::Entity const * walle::TrackingAgent::GetTarget () const
```



Returns an immutable pointer to this agent's target 

**Returns:**

ptr to entity 





        



### function GetTrackingDistance 


```C++
inline double walle::TrackingAgent::GetTrackingDistance () const
```



Get the distance around this tracker that it surveys 

**Returns:**

tracking distance 





        



### function Initialize 


```C++
inline bool walle::TrackingAgent::Initialize () override
```



Ensure that the [**TrackingAgent**](classwalle_1_1_tracking_agent.md)'s internal [**PathAgent**](classwalle_1_1_path_agent.md) is correctly initialized Verifies that it can currently index into a valid offset 

**Returns:**

true if so; false otherwise 





        



### function MakeAlerter 

```C++
inline void walle::TrackingAgent::MakeAlerter () 
```






### function RemoveFromAlerter 


```C++
inline void walle::TrackingAgent::RemoveFromAlerter () 
```



Removes this tracking agent from it's own tracking network 

**Note:**

called from the [**TrackingAgent**](classwalle_1_1_tracking_agent.md) destructor 





        



### function SelectAction 

```C++
inline size_t walle::TrackingAgent::SelectAction (
    cse491::WorldGrid const & grid,
    cse491::type_options_t const & type,
    cse491::item_map_t const & item_set,
    cse491::agent_map_t const & agent_set
) override
```






### function SelectInnerAction [1/2]

```C++
inline size_t walle::TrackingAgent::SelectInnerAction (
    PathAgent & agent,
    cse491::WorldGrid const & grid,
    cse491::type_options_t const & type,
    cse491::item_map_t const & item_set,
    cse491::agent_map_t const & agent_set
) 
```






### function SelectInnerAction [2/2]

```C++
inline size_t walle::TrackingAgent::SelectInnerAction (
    AStarAgent & agent,
    cse491::WorldGrid const & grid,
    cse491::type_options_t const & type,
    cse491::item_map_t const & item_set,
    cse491::agent_map_t const & agent_set
) 
```






### function SetPath [1/2]


```C++
inline TrackingAgent & walle::TrackingAgent::SetPath (
    std::vector< cse491::GridPosition > offsets
) 
```



Sets the patrolling path of the [**TrackingAgent**](classwalle_1_1_tracking_agent.md) 

**Parameters:**


* `offsets` grid position offsets creating the path 



**Returns:**







        



### function SetPath [2/2]


```C++
inline TrackingAgent & walle::TrackingAgent::SetPath (
    std::string_view offsets
) 
```



Sets the patrolling path of the [**TrackingAgent**](classwalle_1_1_tracking_agent.md) 

**Parameters:**


* `offsets` grid position offsets creating the path 



**Returns:**







        



### function SetStartPosition [1/2]


```C++
inline TrackingAgent & walle::TrackingAgent::SetStartPosition (
    cse491::GridPosition pos
) 
```



Set where this agent "patrol area" starts 

**Parameters:**


* `gp` grid position of position 



**Returns:**

self 





        



### function SetStartPosition [2/2]


```C++
inline TrackingAgent & walle::TrackingAgent::SetStartPosition (
    double x,
    double y
) 
```



Set where this agent "patrol area" starts 

**Parameters:**


* `x` x-coordinate of start pos 
* `y` y-coordinate of start pos 



**Returns:**

self 





        



### function SetTarget 


```C++
inline TrackingAgent & walle::TrackingAgent::SetTarget (
    Entity * agent
) 
```



Set which agent we are following 

**Parameters:**


* `agent` we want to track 



**Returns:**

self 





        



### function SetTrackingDistance 


```C++
inline TrackingAgent & walle::TrackingAgent::SetTrackingDistance (
    double dist
) 
```



Set how close goal\_pos has to be to start tracking 

**Parameters:**


* `dist` to start tracking at 



**Returns:**

calling object 





        



### function SetWorld 


```C++
inline TrackingAgent & walle::TrackingAgent::SetWorld (
    cse491::WorldBase & in_world
) override
```



Set both the world for the current agent and the agents it is a part of 

**Parameters:**


* `in_world` new world to associate the agent with 



**Returns:**

calling agent 





        



### function TrackingAgent [1/4]


```C++
walle::TrackingAgent::TrackingAgent () = delete
```



Delete default constructor 


        



### function TrackingAgent [2/4]


```C++
inline walle::TrackingAgent::TrackingAgent (
    size_t id,
    std::string const & name
) 
```



Constructor (default) 

**Parameters:**


* `id` unique agent id 
* `name` name of path agent 




        



### function TrackingAgent [3/4]


```C++
inline walle::TrackingAgent::TrackingAgent (
    size_t id,
    std::string const & name,
    std::vector< cse491::GridPosition > && offsets,
    std::shared_ptr< Alerter > && alerter=nullptr
) 
```



Constructor (vector) 

**Parameters:**


* `id` unique agent id 
* `name` name of path agent 
* `offsets` collection of offsets to move the agent 
* `alerter` alerter network to add agent to 



**Attention:**

The sequence of offsets must not be empty 




**Attention:**

alerter should be a nullptr if this tracker is not part of any group of tracking agents 





        



### function TrackingAgent [4/4]


```C++
inline walle::TrackingAgent::TrackingAgent (
    size_t id,
    std::string const & name,
    std::string_view commands,
    std::shared_ptr< Alerter > && alerter=nullptr
) 
```



Constructor (string view) 

**Parameters:**


* `id` unique agent id 
* `name` name of path agent 
* `commands` sequence of commands to be interpreted as offsets 
* `alerter` alerter network to add agent to 



**Attention:**

The sequence of offsets must not be empty 




**Attention:**

alerter should be a nullptr if this tracker is not part of any group of tracking agents 





        



### function UpdateState 


```C++
inline void walle::TrackingAgent::UpdateState (
    bool alerting=true
) 
```



Handles focusing the agent onto a goal\_pos, returning it to its original location, and patrolling 

**Parameters:**


* `alerting` determines whether this agent should alert all other TrackingAgents in its network when its goal\_pos comes into range 



**Note:**

the inner variant type will be [**AStarAgent**](classwalle_1_1_a_star_agent.md) when tracking OR returning to a location, but [**PathAgent**](classwalle_1_1_path_agent.md) when patrolling 





        



### function ~TrackingAgent 


```C++
inline walle::TrackingAgent::~TrackingAgent () override
```



Destructor 


        

------------------------------
The documentation for this class was generated from the following file `source/Agents/TrackingAgent.hpp`

