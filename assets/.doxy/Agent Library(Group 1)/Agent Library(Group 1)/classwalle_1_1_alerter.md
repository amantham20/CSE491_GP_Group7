

# Class walle::Alerter



[**ClassList**](annotated.md) **>** [**walle**](namespacewalle.md) **>** [**Alerter**](classwalle_1_1_alerter.md)



[More...](#detailed-description)

* `#include <TrackingAgent.hpp>`





































## Public Functions

| Type | Name |
| ---: | :--- |
|  void | [**AddAgent**](#function-addagent) (size\_t id) <br> |
|  void | [**AlertAllTrackingAgents**](#function-alertalltrackingagents) (size\_t caller\_id) <br> |
|   | [**Alerter**](#function-alerter-13) () = delete<br> |
|   | [**Alerter**](#function-alerter-23) (cse491::WorldBase \* world\_ptr) <br> |
|   | [**Alerter**](#function-alerter-33) (cse491::WorldBase \* world\_ptr, size\_t id) <br> |
|  std::unordered\_set&lt; size\_t &gt; const & | [**GetNetworkSet**](#function-getnetworkset) () const<br>_Returns an immutable reference to the_ [_**Alerter**_](classwalle_1_1_alerter.md) _'s set of agents it knows about._ |
|  void | [**RemoveAgent**](#function-removeagent) (size\_t id) <br> |




























# Detailed Description


A single [**Alerter**](classwalle_1_1_alerter.md) is responsible for forcefully changing the state of all trackers in its network to TrackingState::TRACKING when a single [**TrackingAgent**](classwalle_1_1_tracking_agent.md) in the set of trackers comes into range of its goal\_pos 


    
## Public Functions Documentation




### function AddAgent 


```C++
void walle::Alerter::AddAgent (
    size_t id
) 
```



Adds a [**TrackingAgent**](classwalle_1_1_tracking_agent.md) to the network 

**Parameters:**


* `id` id of agent to be added 




        



### function AlertAllTrackingAgents 


```C++
void walle::Alerter::AlertAllTrackingAgents (
    size_t caller_id
) 
```



Uses UpdateState to focus all trackers onto their goal\_pos regardless of the distance away 

**Parameters:**


* `caller_id` the original id of the agent that came into range of its goal\_pos; does not need to be updated 




        



### function Alerter [1/3]

```C++
walle::Alerter::Alerter () = delete
```






### function Alerter [2/3]


```C++
explicit walle::Alerter::Alerter (
    cse491::WorldBase * world_ptr
) 
```



[**Alerter**](classwalle_1_1_alerter.md) constructor (only knows its world and has no agents in its network) 

**Parameters:**


* `world_ptr` the world this alerter is associated with 




        



### function Alerter [3/3]


```C++
walle::Alerter::Alerter (
    cse491::WorldBase * world_ptr,
    size_t id
) 
```



[**Alerter**](classwalle_1_1_alerter.md) constructor (adds the [**TrackingAgent**](classwalle_1_1_tracking_agent.md) with that id to the alerter network) 

**Parameters:**


* `id` id of agent to be added 
* `world_ptr` the world this alerter is associated with 




        



### function GetNetworkSet 

```C++
inline std::unordered_set< size_t > const & walle::Alerter::GetNetworkSet () const
```






### function RemoveAgent 


```C++
void walle::Alerter::RemoveAgent (
    size_t id
) 
```



Removes a [**TrackingAgent**](classwalle_1_1_tracking_agent.md) to the network 

**Parameters:**


* `id` id of agent to be removed 



**Note:**

no assertions here since we may want to allow the [**TrackingAgent**](classwalle_1_1_tracking_agent.md) to join another network later if it's not being destructed 





        

------------------------------
The documentation for this class was generated from the following file `source/Agents/TrackingAgent.hpp`

