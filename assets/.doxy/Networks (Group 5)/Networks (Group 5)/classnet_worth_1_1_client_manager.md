

# Class netWorth::ClientManager



[**ClassList**](annotated.md) **>** [**netWorth**](namespacenet_worth.md) **>** [**ClientManager**](classnet_worth_1_1_client_manager.md)



[More...](#detailed-description)

* `#include <ClientManager.hpp>`





































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**ClientManager**](#function-clientmanager) () = default<br>_Id of client._  |
|  void | [**clearActionMap**](#function-clearactionmap) () <br> |
|  size\_t | [**getActionID**](#function-getactionid) (size\_t id) <br> |
|  size\_t | [**getClientID**](#function-getclientid) () const<br> |
|  std::string | [**getSerializedAgents**](#function-getserializedagents) () <br> |
|  bool | [**iDPresent**](#function-idpresent) (size\_t id) <br> |
|  void | [**packetToActionMap**](#function-packettoactionmap) (sf::Packet pkt) <br> |
|  void | [**setClientID**](#function-setclientid) (size\_t id) <br> |
|  void | [**setUpdatePort**](#function-setupdateport) (unsigned short port) <br> |
|  void | [**setupGameUpdateSocket**](#function-setupgameupdatesocket) (sf::UdpSocket \* socket) <br> |
|  void | [**setupSocket**](#function-setupsocket) (sf::UdpSocket \* socket, std::optional&lt; sf::IpAddress &gt; ip) <br> |




























# Detailed Description


The server that will be running and that allows clients to connect to 


    
## Public Functions Documentation




### function ClientManager 

_Id of client._ 
```C++
netWorth::ClientManager::ClientManager () = default
```



Default constructor (AgentBase) 

**Parameters:**


* `id` agent ID 
* `name` agent name 




        



### function clearActionMap 


```C++
inline void netWorth::ClientManager::clearActionMap () 
```



Clear action map after [**ClientInterface**](classnet_worth_1_1_client_interface.md) moves 


        



### function getActionID 


```C++
inline size_t netWorth::ClientManager::getActionID (
    size_t id
) 
```



Return action ID correspoding to agent ID 

**Parameters:**


* `id` Agent ID 



**Returns:**

action ID 





        



### function getClientID 

```C++
inline size_t netWorth::ClientManager::getClientID () const
```






### function getSerializedAgents 


```C++
inline std::string netWorth::ClientManager::getSerializedAgents () 
```



Receive serialized agent data for midgame updates 

**Returns:**

serialized data (or empty if no update) 





        



### function iDPresent 


```C++
inline bool netWorth::ClientManager::iDPresent (
    size_t id
) 
```



Check if Agent ID is present in agent action map 

**Parameters:**


* `id` Agent ID 



**Returns:**

true if ID is present 





        



### function packetToActionMap 


```C++
inline void netWorth::ClientManager::packetToActionMap (
    sf::Packet pkt
) 
```



Turn packet from server into action map for ControlledAgents 

**Parameters:**


* `pkt` received packet 




        



### function setClientID 

```C++
inline void netWorth::ClientManager::setClientID (
    size_t id
) 
```






### function setUpdatePort 

```C++
inline void netWorth::ClientManager::setUpdatePort (
    unsigned short port
) 
```






### function setupGameUpdateSocket 


```C++
inline void netWorth::ClientManager::setupGameUpdateSocket (
    sf::UdpSocket * socket
) 
```



Set socket for game updates 

**Parameters:**


* `socket` pointer to socket 




        



### function setupSocket 


```C++
inline void netWorth::ClientManager::setupSocket (
    sf::UdpSocket * socket,
    std::optional< sf::IpAddress > ip
) 
```



Set receiving socket for action map and IP/port info 

**Parameters:**


* `socket` pointer to [**ClientInterface**](classnet_worth_1_1_client_interface.md)'s socket 
* `ip` server IP 
* `port` server port 




        

------------------------------
The documentation for this class was generated from the following file `source/Interfaces/NetWorth/client/ClientManager.hpp`

