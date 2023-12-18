

# File NetworkInterface.hpp

[**File List**](files.md) **>** [**Interfaces**](dir_e52260c07c5ca641bf485ae92612dd08.md) **>** [**NetWorth**](dir_0121daa1f68cbca759acb74b3e906cff.md) **>** [**NetworkInterface.hpp**](_network_interface_8hpp.md)

[Go to the documentation of this file](_network_interface_8hpp.md)

```C++


#pragma once

#include <cassert>
#include <string>
#include <thread>
#include <vector>
#include <array>
#include <SFML/Network/UdpSocket.hpp>
#include <SFML/Network/Packet.hpp>
#include "../../core/InterfaceBase.hpp"

namespace netWorth{

    using namespace sf;

    class NetworkingInterface : public virtual cse491::InterfaceBase {
        private:

        protected:
            UdpSocket m_socket;             
            std::optional<IpAddress> m_ip;  
            unsigned short m_port = 0;      

        public:
            NetworkingInterface(size_t id, const std::string & name) : cse491::InterfaceBase(id, name) {

            }

            virtual UdpSocket * getSocket(){
                return &m_socket;
            }

            virtual bool bindSocket(UdpSocket &socket, unsigned short port) {
                std::cout << "Binding socket on port: " << port << std::endl;
                if (socket.bind(port) != Socket::Status::Done) {
                    std::cerr << "Failed to bind socket" << std::endl;
                    return false;
                }
                return true;
            }

            virtual bool sendPacket(Packet packet, IpAddress destAddr, const unsigned short port){
                if (m_socket.send(packet, destAddr, port) != Socket::Status::Done) {
                    std::cerr << "Could not connect to" << destAddr << " at port " << port << std::endl;
                    return false;
                }
                return true;
            }

            virtual bool receivePacket(Packet & pkt, std::optional<IpAddress> &sender, unsigned short &port){
                if (m_socket.receive(pkt, sender,port) != Socket::Status::Done) {
                    std::cerr << "Failed to receive" << std::endl;
                    return false;
                }
                return true;
            }

        }; // End of NetworkingInterface
} // End of namespace netWorth

```

