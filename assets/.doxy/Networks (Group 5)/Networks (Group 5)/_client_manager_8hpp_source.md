

# File ClientManager.hpp

[**File List**](files.md) **>** [**client**](dir_d63376ef77eb621cc9b73f8097e771f8.md) **>** [**ClientManager.hpp**](_client_manager_8hpp.md)

[Go to the documentation of this file](_client_manager_8hpp.md)

```C++


#pragma once
#include <map>
#include <sstream>
#include <vector>

namespace netWorth{
    using namespace sf;

    class ClientManager {
    private:
        sf::UdpSocket *m_socket = nullptr;                
        sf::UdpSocket *m_game_update_socket = nullptr;    
        std::optional<sf::IpAddress> m_ip;      
        unsigned short m_update_port = 0; 
        std::unordered_map<size_t, size_t> m_action_map;     
        size_t m_client_id = 0;     
    protected:

    public:

        ClientManager()= default;

        void setUpdatePort(unsigned short port) {m_update_port = port;}

        void packetToActionMap(sf::Packet pkt) {
            uint64_t dataSize, agentID, actionID;
            pkt >> dataSize;
            for (size_t i = 0; i < dataSize; i++) {
                pkt >> agentID >> actionID;
                m_action_map[agentID] = actionID;
            }
        }

        void setupSocket(sf::UdpSocket *socket, std::optional<sf::IpAddress> ip) {
            m_socket = socket;
            m_ip = ip;
        }

        void setupGameUpdateSocket(sf::UdpSocket *socket) {
            m_game_update_socket = socket;
            m_game_update_socket->setBlocking(false);
            if (m_game_update_socket->bind(m_update_port) != Socket::Status::Done){
                std::cerr << "Failed to setup game update socket" << std::endl;
            }
        }

        bool iDPresent(size_t id) {
            return m_action_map.contains(id);
        }

        size_t getActionID(size_t id) {
            return m_action_map[id];
        }

        void clearActionMap() {
            m_action_map.clear();
        }

        std::string getSerializedAgents() {
            sf::Packet recvPkt;
            std::optional<sf::IpAddress> tempIP;
            unsigned short tempPort;
            if (m_game_update_socket->receive(recvPkt, tempIP, tempPort) == sf::Socket::Status::Done) {
                std::string data;
                recvPkt >> data;
                return data;
            }
            return "";
        }


        void setClientID(size_t id) {
            m_client_id = id;
        }

        size_t getClientID() const{
            return m_client_id;
        }

    }; // End of class ClientManager
} // End of namespace netWorth

```

