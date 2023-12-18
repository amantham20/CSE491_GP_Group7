

# Class netWorth::ServerManager



[**ClassList**](annotated.md) **>** [**netWorth**](namespacenet_worth.md) **>** [**ServerManager**](classnet_worth_1_1_server_manager.md)



[More...](#detailed-description)

* `#include <ServerManager.hpp>`





















## Public Attributes

| Type | Name |
| ---: | :--- |
|  unsigned short | [**m\_max\_client\_port**](#variable-m_max_client_port)   = = 55000<br>_Port for initial client connection._  |


## Public Static Attributes

| Type | Name |
| ---: | :--- |
|  const constexpr unsigned short | [**m\_init\_connection\_port**](#variable-m_init_connection_port)   = = 55000<br>_Boolean that states if there are interfaces present on the server._  |














## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**ServerManager**](#function-servermanager) () = default<br>_Port that is incremented for client thread handoff._  |
|  sf::Packet | [**actionMapToPacket**](#function-actionmaptopacket) () <br> |
|  void | [**addToInterfaceSet**](#function-addtointerfaceset) (size\_t agent\_id) <br> |
|  void | [**addToUpdatePairs**](#function-addtoupdatepairs) (sf::IpAddress ip, unsigned short port) <br> |
|  std::string | [**getSerializedAgents**](#function-getserializedagents) () <br> |
|  bool | [**hasAgentsPresent**](#function-hasagentspresent) () const<br> |
|  void | [**increasePort**](#function-increaseport) () <br> |
|  void | [**removeFromActionMap**](#function-removefromactionmap) (size\_t key) <br> |
|  void | [**removeFromUpdatePairs**](#function-removefromupdatepairs) (sf::IpAddress ip, unsigned short port) <br> |
|  void | [**removeInterface**](#function-removeinterface) (size\_t id) <br> |
|  void | [**sendGameUpdates**](#function-sendgameupdates) () <br> |
|  void | [**setNewAgent**](#function-setnewagent) (bool hasNewAgent) <br> |
|  void | [**setSerializedAgents**](#function-setserializedagents) (std::string & serializedAgents) <br> |
|  void | [**writeToActionMap**](#function-writetoactionmap) (size\_t key, size\_t val) <br> |




























# Detailed Description


The server that will be running and that allows clients to connect to 


    
## Public Attributes Documentation




### variable m\_max\_client\_port 

```C++
unsigned short m_max_client_port;
```



## Public Static Attributes Documentation




### variable m\_init\_connection\_port 

```C++
const constexpr unsigned short m_init_connection_port;
```



## Public Functions Documentation




### function ServerManager 

_Port that is incremented for client thread handoff._ 
```C++
netWorth::ServerManager::ServerManager () = default
```



Default constructor (AgentBase) 

**Parameters:**


* `id` agent ID 
* `name` agent name 




        



### function actionMapToPacket 


```C++
inline sf::Packet netWorth::ServerManager::actionMapToPacket () 
```



Convert action map to packet to send to client 

**Returns:**

packet containing action map as series of integers 





        



### function addToInterfaceSet 


```C++
inline void netWorth::ServerManager::addToInterfaceSet (
    size_t agent_id
) 
```



Adds and interface to the interface set 

**Parameters:**


* `agent_id` 




        



### function addToUpdatePairs 


```C++
inline void netWorth::ServerManager::addToUpdatePairs (
    sf::IpAddress ip,
    unsigned short port
) 
```



Adds an IP and port to a vector for group update 

**Parameters:**


* `ip` IP address of client receiving updates 
* `port` port of client receiving updates 




        



### function getSerializedAgents 


```C++
inline std::string netWorth::ServerManager::getSerializedAgents () 
```



Returns the current serialized agents 

**Returns:**

a string of the current serialized agents 





        



### function hasAgentsPresent 


```C++
inline bool netWorth::ServerManager::hasAgentsPresent () const
```



Returns if there are agents present on the server as a boolean 

**Returns:**

boolean representing if there are agents present on the server 





        



### function increasePort 


```C++
inline void netWorth::ServerManager::increasePort () 
```



Increases the max client port 


        



### function removeFromActionMap 


```C++
inline void netWorth::ServerManager::removeFromActionMap (
    size_t key
) 
```



Removes an interface from action map by key 

**Parameters:**


* `key` 




        



### function removeFromUpdatePairs 


```C++
inline void netWorth::ServerManager::removeFromUpdatePairs (
    sf::IpAddress ip,
    unsigned short port
) 
```



Removes ip and port from the update vector 

**Parameters:**


* `ip` ip to remove 
* `port` port to remove 




        



### function removeInterface 


```C++
inline void netWorth::ServerManager::removeInterface (
    size_t id
) 
```



Removes an interface by ID 

**Parameters:**


* `id` 




        



### function sendGameUpdates 


```C++
inline void netWorth::ServerManager::sendGameUpdates () 
```



Sends game updates to all clients when a new agent joins 


        



### function setNewAgent 


```C++
inline void netWorth::ServerManager::setNewAgent (
    bool hasNewAgent
) 
```



Sets a boolean stating if the server has received a new agent 

**Parameters:**


* `hasNewAgent` boolean stating that a new agent has joined 




        



### function setSerializedAgents 


```C++
inline void netWorth::ServerManager::setSerializedAgents (
    std::string & serializedAgents
) 
```



Sets the current serialized agents of the server 

**Parameters:**


* `serializedAgents` string reference representing the serialized agents 




        



### function writeToActionMap 


```C++
inline void netWorth::ServerManager::writeToActionMap (
    size_t key,
    size_t val
) 
```



Writes to the action map 

**Parameters:**


* `key` to reference 
* `val` to write 




        

------------------------------
The documentation for this class was generated from the following file `source/Interfaces/NetWorth/server/ServerManager.hpp`

