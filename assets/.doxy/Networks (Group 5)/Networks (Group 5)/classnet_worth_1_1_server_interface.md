

# Class netWorth::ServerInterface



[**ClassList**](annotated.md) **>** [**netWorth**](namespacenet_worth.md) **>** [**ServerInterface**](classnet_worth_1_1_server_interface.md)



[More...](#detailed-description)

* `#include <ServerInterface.hpp>`



Inherits the following classes: [netWorth::NetworkingInterface](classnet_worth_1_1_networking_interface.md)






















































## Public Functions

| Type | Name |
| ---: | :--- |
|  bool | [**Initialize**](#function-initialize) () override<br> |
|  size\_t | [**SelectAction**](#function-selectaction) (const cse491::WorldGrid & grid, const cse491::type\_options\_t & typeOptions, const cse491::item\_map\_t & itemMap, const cse491::agent\_map\_t & agentMap) override<br> |
|   | [**ServerInterface**](#function-serverinterface) (size\_t id, const std::string & name) <br>_Port used by server manager to handle world updates._  |


## Public Functions inherited from netWorth::NetworkingInterface

See [netWorth::NetworkingInterface](classnet_worth_1_1_networking_interface.md)

| Type | Name |
| ---: | :--- |
|   | [**NetworkingInterface**](#function-networkinginterface) (size\_t id, const std::string & name) <br>_the destination port of the machine this communicates with_  |
| virtual bool | [**bindSocket**](#function-bindsocket) (UdpSocket & socket, unsigned short port) <br> |
| virtual UdpSocket \* | [**getSocket**](#function-getsocket) () <br> |
| virtual bool | [**receivePacket**](#function-receivepacket) (Packet & pkt, std::optional&lt; IpAddress &gt; & sender, unsigned short & port) <br> |
| virtual bool | [**sendPacket**](#function-sendpacket) (Packet packet, IpAddress destAddr, const unsigned short port) <br> |


## Public Static Functions

| Type | Name |
| ---: | :--- |
|  Packet | [**gridToPacket**](#function-gridtopacket) (const cse491::WorldGrid & grid, const cse491::type\_options\_t & typeOptions, const cse491::item\_map\_t & itemMap, const cse491::agent\_map\_t & agentMap) <br> |














## Protected Attributes inherited from netWorth::NetworkingInterface

See [netWorth::NetworkingInterface](classnet_worth_1_1_networking_interface.md)

| Type | Name |
| ---: | :--- |
|  std::optional&lt; IpAddress &gt; | [**m\_ip**](#variable-m_ip)  <br>_The socket we are going to make our connection._  |
|  unsigned short | [**m\_port**](#variable-m_port)   = = 0<br>_the destination IP of the machine this communicates with_  |
|  UdpSocket | [**m\_socket**](#variable-m_socket)  <br> |






































# Detailed Description


The server that will be running and that allows clients to connect to, acts as a sort of clone 


    
## Public Functions Documentation




### function Initialize 


```C++
inline bool netWorth::ServerInterface::Initialize () override
```



Function that initializes server interface 

**Returns:**

boolean stating whether initialization was successful or not 





        



### function SelectAction 


```C++
inline size_t netWorth::ServerInterface::SelectAction (
    const cse491::WorldGrid & grid,
    const cse491::type_options_t & typeOptions,
    const cse491::item_map_t & itemMap,
    const cse491::agent_map_t & agentMap
) override
```



Choose action for player agent (mirror client agent) 

**Parameters:**


* `grid` the server-side grid 
* `typeOptions` different cell types of the world 
* `itemMap` the items that may be apart of the grid 
* `agentMap` the agents that may be apart of the grid 



**Returns:**

action ID of the interface 





        



### function ServerInterface 

_Port used by server manager to handle world updates._ 
```C++
inline netWorth::ServerInterface::ServerInterface (
    size_t id,
    const std::string & name
) 
```



Default constructor (AgentBase) 

**Parameters:**


* `id` agent ID 
* `name` agent name 




        
## Public Static Functions Documentation




### function gridToPacket 


```C++
static inline Packet netWorth::ServerInterface::gridToPacket (
    const cse491::WorldGrid & grid,
    const cse491::type_options_t & typeOptions,
    const cse491::item_map_t & itemMap,
    const cse491::agent_map_t & agentMap
) 
```



The grid that will be sent to the client from the server after the connection so the client can start asking to make moves 

**Parameters:**


* `grid` the grid to send to the server 
* `typeOptions` different cell types of the world 
* `itemMap` the items that may be apart of the grid 
* `agentMap` the agents that may be apart of the grid 



**Returns:**

the grid that will be sent to the client 





        

------------------------------
The documentation for this class was generated from the following file `source/Interfaces/NetWorth/server/ServerInterface.hpp`

