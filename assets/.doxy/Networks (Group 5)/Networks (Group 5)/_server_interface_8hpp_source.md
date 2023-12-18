

# File ServerInterface.hpp

[**File List**](files.md) **>** [**Interfaces**](dir_e52260c07c5ca641bf485ae92612dd08.md) **>** [**NetWorth**](dir_0121daa1f68cbca759acb74b3e906cff.md) **>** [**server**](dir_1ea711888d2c31b2ee5b33ee0d19cbd8.md) **>** [**ServerInterface.hpp**](_server_interface_8hpp.md)

[Go to the documentation of this file](_server_interface_8hpp.md)

```C++


#pragma once

#include "ServerManager.hpp"
#include <thread>
#include <sstream>
#include "Interfaces/NetWorth/NetworkInterface.hpp"
#include "Worlds/MazeWorld.hpp"

namespace netWorth
{
    using namespace sf;

    class ServerInterface : public NetworkingInterface
    {
    private:
        ServerManager* m_manager = nullptr; 

        unsigned short m_world_update_port = 0;  
    protected:

    public:
        ServerInterface(size_t id, const std::string& name)
            : cse491::InterfaceBase(id, name),
              NetworkingInterface(id, name)
        {

        }

        bool Initialize() override
        {
            // resolve port and IP from entity properties
            m_ip = sf::IpAddress::resolve(NetworkingInterface::GetProperty<std::string>("client_ip"));
            m_world_update_port = NetworkingInterface::GetProperty<unsigned short>("client_port");
            m_manager = GetProperty<netWorth::ServerManager*>("server_manager");

            Packet sendPkt, recvPkt;
            std::string str;

            bindSocket(m_socket, GetProperty<unsigned short>("server_port"));

            // Await client
            if (!receivePacket(recvPkt, m_ip, m_port))
                return false;

            std::cout << m_ip.value() << " has connected successfully." << std::endl;

            // Acknowledge client
            sendPkt << "Connection established.";
            if (!sendPacket(sendPkt, m_ip.value(), m_port))
                return false;

            recvPkt.clear();
            // await request for map
            if (!receivePacket(recvPkt, m_ip, m_port))
                return false;

            GetWorld().SetWorldRunning(true);
            return true;
        }

        static Packet gridToPacket(const cse491::WorldGrid& grid,
            const cse491::type_options_t& typeOptions,
            const cse491::item_map_t& itemMap,
            const cse491::agent_map_t& agentMap)
        {
            std::vector<std::string> packetGrid(grid.GetHeight());

            // Load the world into the symbol_grid;
            for (size_t y = 0; y < grid.GetHeight(); ++y)
            {
                packetGrid[y].resize(grid.GetWidth());
                for (size_t x = 0; x < grid.GetWidth(); ++x)
                {
                    packetGrid[y][x] = typeOptions[grid.At(x, y)].symbol;
                }
            }

            // Add in the agents / entities
            for (const auto& [id, entityPtr] : itemMap)
            {
                cse491::GridPosition pos = entityPtr->GetPosition();
        if(!std::isnan(pos.GetX()) && !std::isnan(pos.GetY())
            && pos.CellX() < grid.GetWidth() && pos.CellY() < grid.GetHeight()){
          packetGrid[pos.CellY()][pos.CellX()] = '+';
        }
            }

            for (const auto& [id, agent_ptr] : agentMap)
            {
                cse491::GridPosition pos = agent_ptr->GetPosition();
                char c = '*';
                if (agent_ptr->HasProperty("symbol"))
                {
                    c = agent_ptr->GetProperty<char>("symbol");
                }
        if(!std::isnan(pos.GetX()) && !std::isnan(pos.GetY())
            && pos.CellX() < grid.GetWidth() && pos.CellY() < grid.GetHeight()){
                  packetGrid[pos.CellY()][pos.CellX()] = c;
        }
            }

            // Print out the symbol_grid with a box around it.
            std::ostringstream oss;
            oss << '+' << std::string(grid.GetWidth(), '-') << "+\n";
            for (const auto& row : packetGrid)
            {
                oss << "|";
                for (char cell : row)
                {
                    oss << cell;
                }
                oss << "|\n";
            }
            oss << '+' << std::string(grid.GetWidth(), '-') << "+\n";
            std::string gridString = oss.str();

            Packet gridPacket;
            gridPacket << gridString;

            return gridPacket;
        }

        size_t SelectAction(const cse491::WorldGrid& grid,
            const cse491::type_options_t& typeOptions,
            const cse491::item_map_t& itemMap,
            const cse491::agent_map_t& agentMap) override
        {
            // send action map to client
            sf::Packet sendPkt = m_manager->actionMapToPacket();
            std::cout << "Sending action map to " << m_ip.value().toString() << " on port " << m_port << std::endl;
            sendPacket(sendPkt, m_ip.value(), m_port);

            // print server-side map (for test purposes)
            sf::Packet mapPkt = gridToPacket(grid, typeOptions, itemMap, agentMap);
            std::string map;
            mapPkt >> map;
            std::cout << map << std::endl;

            // receive player input
            sf::Packet recvPkt;
            uint64_t actionID;
            receivePacket(recvPkt, m_ip, m_port);
            recvPkt >> actionID;

            // handle leaving client
            if (actionID == 9999)
            {
                m_manager->removeInterface(GetID());
                m_manager->removeFromActionMap(GetID());
                m_manager->removeFromUpdatePairs(m_ip.value(), m_world_update_port);
            }

            // return actionId
            return actionID;
        }

    }; // End of class ServerInterface
// End of namespace netWorth
}

```

