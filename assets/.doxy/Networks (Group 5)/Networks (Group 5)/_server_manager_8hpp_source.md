

# File ServerManager.hpp

[**File List**](files.md) **>** [**Interfaces**](dir_e52260c07c5ca641bf485ae92612dd08.md) **>** [**NetWorth**](dir_0121daa1f68cbca759acb74b3e906cff.md) **>** [**server**](dir_1ea711888d2c31b2ee5b33ee0d19cbd8.md) **>** [**ServerManager.hpp**](_server_manager_8hpp.md)

[Go to the documentation of this file](_server_manager_8hpp.md)

```C++


#pragma once
#include <thread>
#include <map>
#include <sstream>
#include <utility>
#include <vector>
#include "Interfaces/NetWorth/NetworkInterface.hpp"

namespace netWorth{
    using namespace sf;

    class ServerManager {
    private:

        sf::UdpSocket m_manager_socket;

        std::set<size_t> m_interface_set;   

        std::map<size_t, size_t> m_action_map; 

        std::string m_current_serialized_agents; 

        std::vector<std::pair<sf::IpAddress, unsigned short>> m_update_vec; 

        bool m_has_new_agent = false; 

        bool m_interfaces_present = false; 

    protected:

    public:
        const static constexpr unsigned short m_init_connection_port = 55000; 

        unsigned short m_max_client_port = 55000; 

        ServerManager() = default;

        std::string getSerializedAgents(){return m_current_serialized_agents;}

        void setSerializedAgents(std::string & serializedAgents) { m_current_serialized_agents = serializedAgents;}

        [[nodiscard]] bool hasAgentsPresent() const {return m_interfaces_present;}

        void setNewAgent(bool hasNewAgent){ m_has_new_agent = hasNewAgent;}

        sf::Packet actionMapToPacket()
        {
            sf::Packet pkt;

            // serialize action map
            pkt << static_cast<uint64_t>(m_action_map.size());
            for (auto [agent_id, action_id]: m_action_map) {
                pkt << static_cast<uint64_t>(agent_id) << static_cast<uint64_t>(action_id);
            }

            return pkt;
        }

        void increasePort(){++m_max_client_port;}

        void removeInterface(size_t id){
            m_interface_set.erase(id);
            if (m_interface_set.empty()) m_interfaces_present = false;
        }

        void addToUpdatePairs(sf::IpAddress ip, unsigned short port){
            m_update_vec.emplace_back(ip, port);
        }

         void sendGameUpdates(){
            if (m_has_new_agent)
            {
                sf::Packet serializedAgentPkt;
                serializedAgentPkt << getSerializedAgents();
                //Loops through all pairs of IP and port and sends serialized agents
                for (auto client: m_update_vec){
                    std::cout << "sending game updates to IP: " << client.first.toString() << " with port " <<
                    client.second << std::endl;
                    if (m_manager_socket.send(serializedAgentPkt, client.first, client.second) != sf::Socket::Status::Done) {
                        std::cerr << "Error sending updates to client at " << client.first.toString() << " port " << client.second << std::endl;
                    }
                }
                m_has_new_agent = false;
            }
        }

        void removeFromActionMap(size_t key){
            m_action_map.erase(key);
        }

        void removeFromUpdatePairs(sf::IpAddress ip, unsigned short port){
            m_update_vec.erase(std::remove_if(m_update_vec.begin(), m_update_vec.end(),
                [ip, port](std::pair<sf::IpAddress, unsigned short> pair){
                return (pair.first == ip && pair.second == port);
            }), m_update_vec.end());
        }

        void writeToActionMap(size_t key, size_t val){
            m_action_map.insert_or_assign(key, val);
        }

        void addToInterfaceSet(size_t agent_id){
            m_interface_set.insert(agent_id);
            m_interfaces_present = true;
        }

    }; // End of class ServerManager
} // End of namespace netWorth

```

