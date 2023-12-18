

# Class netWorth::NetworkingInterface



[**ClassList**](annotated.md) **>** [**netWorth**](namespacenet_worth.md) **>** [**NetworkingInterface**](classnet_worth_1_1_networking_interface.md)








Inherits the following classes: InterfaceBase


Inherited by the following classes: [netWorth::ClientInterface](classnet_worth_1_1_client_interface.md),  [netWorth::ServerInterface](classnet_worth_1_1_server_interface.md)
































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**NetworkingInterface**](#function-networkinginterface) (size\_t id, const std::string & name) <br>_the destination port of the machine this communicates with_  |
| virtual bool | [**bindSocket**](#function-bindsocket) (UdpSocket & socket, unsigned short port) <br> |
| virtual UdpSocket \* | [**getSocket**](#function-getsocket) () <br> |
| virtual bool | [**receivePacket**](#function-receivepacket) (Packet & pkt, std::optional&lt; IpAddress &gt; & sender, unsigned short & port) <br> |
| virtual bool | [**sendPacket**](#function-sendpacket) (Packet packet, IpAddress destAddr, const unsigned short port) <br> |








## Protected Attributes

| Type | Name |
| ---: | :--- |
|  std::optional&lt; IpAddress &gt; | [**m\_ip**](#variable-m_ip)  <br>_The socket we are going to make our connection._  |
|  unsigned short | [**m\_port**](#variable-m_port)   = = 0<br>_the destination IP of the machine this communicates with_  |
|  UdpSocket | [**m\_socket**](#variable-m_socket)  <br> |




















## Public Functions Documentation




### function NetworkingInterface 

_the destination port of the machine this communicates with_ 
```C++
inline netWorth::NetworkingInterface::NetworkingInterface (
    size_t id,
    const std::string & name
) 
```



Default constructor (AgentBase) 

**Parameters:**


* `id` agent ID 
* `name` agent name 




        



### function bindSocket 


```C++
inline virtual bool netWorth::NetworkingInterface::bindSocket (
    UdpSocket & socket,
    unsigned short port
) 
```



Bind socket to port number 

**Parameters:**


* `socket` Socket to be bound 
* `port` Port number 



**Returns:**

true if successful 





        



### function getSocket 


```C++
inline virtual UdpSocket * netWorth::NetworkingInterface::getSocket () 
```



Receives a socket that has been connected between client and server 

**Returns:**

the udp socket 





        



### function receivePacket 


```C++
inline virtual bool netWorth::NetworkingInterface::receivePacket (
    Packet & pkt,
    std::optional< IpAddress > & sender,
    unsigned short & port
) 
```



Starts the connection by receiving the first packet 

**Parameters:**


* `sender` IP of sending machine 
* `port` port number of sending machine 



**Returns:**

received packet 





        



### function sendPacket 


```C++
inline virtual bool netWorth::NetworkingInterface::sendPacket (
    Packet packet,
    IpAddress destAddr,
    const unsigned short port
) 
```



Sends a packet across the socket 

**Parameters:**


* `packet` the packet we want to send 
* `destAddr` the destination address we want to send to 
* `port` the port of the connection 



**Returns:**

true if successfully sent 





        
## Protected Attributes Documentation




### variable m\_ip 

```C++
std::optional<IpAddress> m_ip;
```






### variable m\_port 

```C++
unsigned short m_port;
```






### variable m\_socket 

```C++
UdpSocket m_socket;
```




------------------------------
The documentation for this class was generated from the following file `source/Interfaces/NetWorth/NetworkInterface.hpp`

