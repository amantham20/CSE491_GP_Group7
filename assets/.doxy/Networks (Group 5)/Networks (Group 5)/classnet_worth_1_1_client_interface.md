

# Class netWorth::ClientInterface



[**ClassList**](annotated.md) **>** [**netWorth**](namespacenet_worth.md) **>** [**ClientInterface**](classnet_worth_1_1_client_interface.md)








Inherits the following classes: [netWorth::NetworkingInterface](classnet_worth_1_1_networking_interface.md),  MainInterface






















































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**ClientInterface**](#function-clientinterface) (size\_t id, const std::string & name) <br> |
|  bool | [**Initialize**](#function-initialize) () override<br> |
|  size\_t | [**SelectAction**](#function-selectaction) (const cse491::WorldGrid & grid, const cse491::type\_options\_t & typeOptions, const cse491::item\_map\_t & itemMap, const cse491::agent\_map\_t & agentMap) override<br> |


## Public Functions inherited from netWorth::NetworkingInterface

See [netWorth::NetworkingInterface](classnet_worth_1_1_networking_interface.md)

| Type | Name |
| ---: | :--- |
|   | [**NetworkingInterface**](#function-networkinginterface) (size\_t id, const std::string & name) <br>_the destination port of the machine this communicates with_  |
| virtual bool | [**bindSocket**](#function-bindsocket) (UdpSocket & socket, unsigned short port) <br> |
| virtual UdpSocket \* | [**getSocket**](#function-getsocket) () <br> |
| virtual bool | [**receivePacket**](#function-receivepacket) (Packet & pkt, std::optional&lt; IpAddress &gt; & sender, unsigned short & port) <br> |
| virtual bool | [**sendPacket**](#function-sendpacket) (Packet packet, IpAddress destAddr, const unsigned short port) <br> |
















## Protected Attributes inherited from netWorth::NetworkingInterface

See [netWorth::NetworkingInterface](classnet_worth_1_1_networking_interface.md)

| Type | Name |
| ---: | :--- |
|  std::optional&lt; IpAddress &gt; | [**m\_ip**](#variable-m_ip)  <br>_The socket we are going to make our connection._  |
|  unsigned short | [**m\_port**](#variable-m_port)   = = 0<br>_the destination IP of the machine this communicates with_  |
|  UdpSocket | [**m\_socket**](#variable-m_socket)  <br> |






































## Public Functions Documentation




### function ClientInterface 


```C++
inline netWorth::ClientInterface::ClientInterface (
    size_t id,
    const std::string & name
) 
```



Default constructor (AgentBase) 

**Parameters:**


* `id` agent ID 
* `name` agent name 




        



### function Initialize 


```C++
inline bool netWorth::ClientInterface::Initialize () override
```



Establish connection with server, initializing interface 

**Returns:**

True if successful, false if error 





        



### function SelectAction 


```C++
inline size_t netWorth::ClientInterface::SelectAction (
    const cse491::WorldGrid & grid,
    const cse491::type_options_t & typeOptions,
    const cse491::item_map_t & itemMap,
    const cse491::agent_map_t & agentMap
) override
```



Choose action for player agent 

**Parameters:**


* `grid` the client-side grid 
* `typeOptions` different cell types of the world 
* `item_map` the items that may be apart of the grid 
* `agent_map` the agents that may be apart of the grid 



**Returns:**

action ID of the interface 





        

------------------------------
The documentation for this class was generated from the following file `source/Interfaces/NetWorth/client/ClientInterface.hpp`

