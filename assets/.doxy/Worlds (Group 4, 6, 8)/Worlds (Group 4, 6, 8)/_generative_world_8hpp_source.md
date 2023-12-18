

# File GenerativeWorld.hpp

[**File List**](files.md) **>** [**source**](dir_b2f33c71d4aa5e7af42a1ca61ff5af1b.md) **>** [**Worlds**](dir_9813a27ecb6dbdc5ed22cda8cf865019.md) **>** [**GenerativeWorld.hpp**](_generative_world_8hpp.md)

[Go to the documentation of this file](_generative_world_8hpp.md)

```C++


#pragma once

#include <cassert>

#include "BiomeGenerator.hpp"
#include "../core/WorldBase.hpp"
#include "../Agents/AStarAgent.hpp"

namespace group6 {
    using namespace cse491;
    using std::vector, std::string;

    class GenerativeWorld : public WorldBase {
    protected:
        enum ActionType {
            REMAIN_STILL = 0, MOVE_UP, MOVE_DOWN, MOVE_LEFT, MOVE_RIGHT
        };

        size_t floor_id; 
        size_t wall_id;  

        size_t spike_id;      
        size_t tar_id;        
        size_t key_id;        
        size_t door_id;       
        size_t teleporter_id; 
        size_t armory_id;     

        size_t tree_id;       
        size_t grass_id;      
        size_t dirt_id;       
        size_t hole_id;       

        size_t water_id;      
        size_t sand_id;       

        unsigned int world_width;
        unsigned int world_height;

        void ConfigAgent(AgentBase &agent) override {
            agent.AddAction("up", MOVE_UP);
            agent.AddAction("down", MOVE_DOWN);
            agent.AddAction("left", MOVE_LEFT);
            agent.AddAction("right", MOVE_RIGHT);
            agent.SetProperty("key_property",0.0); 
            agent.SetProperty("tar_property",5.0); 
        }

        void DamageAgent(AgentBase &agent) {
            if (agent.IsInterface()) {
                EndGame(false);
            }
        }

        void CreateGrid(BiomeType biome, unsigned int width, unsigned int height, unsigned int seed, const string &file) {
            BiomeGenerator biomeGenerator(biome, width, height, seed);
            biomeGenerator.setWorld(this);
            biomeGenerator.generate();

            string filePath = "../assets/grids/generated_" + file + ".grid";

            biomeGenerator.saveToFile(filePath);

            main_grid.Read(filePath, type_options);
        }

    public:
        explicit GenerativeWorld(BiomeType biome, unsigned int width, unsigned int height, unsigned int seed)
                : WorldBase(seed) {
            floor_id = AddCellType("floor", "Floor that you can easily walk over.", ' ');
            wall_id = AddCellType("wall", "Impenetrable wall that you must find a way around.", '#');

            spike_id = AddCellType("spike", "Dangerous spike that resets the game.", 'X');

            tar_id = AddCellType("tar", "Slow tile that makes you take two steps to get through it", 'O');
            key_id = AddCellType("key", "item that can be picked up to unlock door and escape maze", 'K');
            door_id = AddCellType("door", "Door that can be walked through only with possession of key to leave maze",'D');
            teleporter_id = AddCellType("teleporter", "Teleports agent to other teleporter", 'T');

            armory_id = AddCellType("armory", "Armory tile that repairs damaged inventory items", 'A');
            tree_id = AddCellType("tree", "A tree that blocks the way.", 't');
            grass_id = AddCellType("grass", "Grass you can walk on.", 'M');
            dirt_id = AddCellType("dirt", "Dirt you can walk on.", '~');
            hole_id = AddCellType("hole", "A hole that you can fall into the maze from.", '8');

            water_id = AddCellType("water", "Water that you may be able to swim on.", 'W');
            sand_id = AddCellType("sand", "Sand you can walk on.", '-');

            world_width = width;
            world_height = height;

            CreateGrid(biome, width, height, seed, "maze");
        }

        ~GenerativeWorld() override = default;

        void AddTeleporters() {
            main_grid.At(53, 6) = teleporter_id;
            main_grid.At(18, 18) = teleporter_id;
        }

        [[noreturn]] void EndGame(bool win) {
            run_over = true;

            if (win) {
                std::cout << "You successfully exited maze!" << std::endl;
            } else {
                std::cout << "Game over, try again!" << std::endl;
            }
            std::exit(0);
        }

        void AddArmory() {
            bool counter = false;
            while (!counter) {
                //generate random location in bottom left quarter of map
                int random_y = (int)GetRandom((double)main_grid.GetHeight() / 2, (double)main_grid.GetHeight() - 1);
                int random_x = (int)GetRandom(0, (double)main_grid.GetWidth() / 2);

                if (main_grid.At(random_x, random_y) == floor_id) {
                    main_grid.At(random_x, random_y) = armory_id;
                    counter = true;
                }
            }

            counter = false;
            while (!counter) {
                //generate random location in top right quarter of map
                int random_y = (int)GetRandom(0, (double)main_grid.GetHeight() / 2);
                int random_x = (int)GetRandom((double)main_grid.GetWidth() / 2, (double)main_grid.GetWidth() - 1);

                if (main_grid.At(random_x, random_y) == floor_id) {
                    main_grid.At(random_x, random_y) = armory_id;
                    counter = true;
                }
            }
        }

        [[nodiscard]] static vector<GridPosition> FindTiles(WorldGrid grid, size_t tile_id) {
            vector<GridPosition> result;

            for (size_t x = 0; x < grid.GetWidth(); ++x) {
                for (size_t y = 0; y < grid.GetHeight(); ++y) {
                    if (grid.At(x, y) == tile_id) {
                        result.emplace_back(x, y);
                    }
                }
            }

            return result;
        }

        int DoAction(AgentBase &agent, size_t action_id) override {
            AgentCollisionHelper(agent);

            // Skip turn if stuck on tar
            if (agent.GetProperty("tar_property") == 6.0) {
                agent.SetProperty("tar_property", 5.0);
                return true;
            }

            // Determine where the agent is trying to move.
            GridPosition new_position;
            switch (action_id) {
                case REMAIN_STILL:
                    new_position = agent.GetPosition();
                    break;
                case MOVE_UP:
                    new_position = agent.GetPosition().Above();
                    break;
                case MOVE_DOWN:
                    new_position = agent.GetPosition().Below();
                    break;
                case MOVE_LEFT:
                    new_position = agent.GetPosition().ToLeft();
                    break;
                case MOVE_RIGHT:
                    new_position = agent.GetPosition().ToRight();
                    break;
            }

            // Don't let the agent move off the world or into a wall.
            if (!main_grid.IsValid(new_position)) { return false; }
            if (main_grid.At(new_position) == wall_id) { return false; }

            //check to see if player is going onto armory tile
            if (main_grid.At(new_position) == armory_id) {
                ArmoryTileHelper(agent);
            }
            // check to see if player is moving onto spike tile
            if (main_grid.At(new_position) == spike_id) {
                SpikeTileHelper(agent);
            }
            // check to see if player is moving onto a tar tile
            else if (main_grid.At(new_position) == tar_id) {
                TarTileHelper(agent);
            }
            // check to see if player is moving onto teleporter
            else if (main_grid.At(new_position) == teleporter_id) {
                TeleporterHelper(new_position);
            }
            // check to see if player is moving onto key tile
            else if (main_grid.At(new_position) == key_id) {
                KeyTileHelper(agent, new_position);
            }
            // check to see if the player is moving onto door tile
            else if (main_grid.At(new_position) == door_id) {
                DoorTileHelper(agent);
            }
            // check to see if player is moving onto a hole tile
            else if (main_grid.At(new_position) == hole_id) {
                HoleTileHelper(agent, new_position);
            }

            //recalculate AStarAgent's path when player moves
            AStarAgentHelper(agent);

            //check to see if agent is walking on an item
            ItemHelper(agent, new_position);

            // Set the agent to its new position.
            agent.SetPosition(new_position);

            return true;
        }

        void ArmoryTileHelper(AgentBase &agent) {
            for (const auto &pair: item_map) {
                //if agent has the item in its inventory, heal it back to full health
                if (agent.HasItem(pair.first)) {
                    pair.second->SetProperty("Health", 4.0);
                }
            }
        }

        void SpikeTileHelper(AgentBase &agent) {
            bool spike_immune = false;

            //check to see if player has shield on
            for (const auto &pair: item_map) {
                if (agent.HasItem(pair.first) && pair.second->GetName() == "Shield") {
                    //agent's shield has enough health and will protect player from spike tile
                    if (pair.second->GetProperty("Health") > 0) {
                        pair.second->SetProperty("Health", pair.second->GetProperty("Health") - 1);
                        spike_immune = true;

                        break;
                    }
                }
            }

            // Damage agent if not immune to spike
            if (!spike_immune) {
                DamageAgent(agent);
            }
        }

        void TarTileHelper(AgentBase &agent) {
            bool tar_immune = false;

            //check to see if player has boots on
            for (const auto &pair: item_map) {
                if (agent.HasItem(pair.first) && pair.second->GetName() == "Boots") {
                    //agent's boots have enough health and will protect player from tar
                    if (pair.second->GetProperty("Health") > 0) {
                        pair.second->SetProperty("Health", pair.second->GetProperty("Health") - 1);
                        tar_immune = true;

                        break;
                    }
                }
            }

            // Slow agent if not immune to tar
            if (!tar_immune) {
                agent.SetProperty("tar_property", 6.0);
            }
        }

        void TeleporterHelper(GridPosition &new_position) {
            vector<GridPosition> teleporters = FindTiles(main_grid, teleporter_id);

            for (GridPosition teleporter: teleporters) {
                if (new_position != teleporter) {
                    new_position = teleporter;

                    break;
                }
            }
        }

        void KeyTileHelper(AgentBase &agent, GridPosition &new_position) {
            // Only player can pick up keys
            if (agent.IsInterface()) {
                agent.SetProperty("key_property", 1.0);
                main_grid.At(new_position) = floor_id;
            }
        }

        void DoorTileHelper(AgentBase &agent) {
            // Only player with key can win game
            if (agent.IsInterface() && agent.GetProperty("key_property") == 1.0) {
                EndGame(true);
            }
        }

        void HoleTileHelper(AgentBase &agent, GridPosition &new_position) {
            if (agent.IsInterface()) {
                CreateGrid(BiomeType::Maze, world_width, world_height, ++seed, "maze2");
                new_position.Set(0, 0);
            }
        }

        void ItemHelper(AgentBase &agent, GridPosition &new_position) {
            for (const auto &pair: item_map) {
                //check to see if items position is same as the position the player is moving to
                if (pair.second->GetPosition() == new_position) {
                    //Add item to inventory
                    agent.AddItem(pair.first);
                    break;
                }
            }
        }

        void AgentCollisionHelper(AgentBase &agent) {
            //if player is on same position as agent, game ends
            for (const auto &temp_agent: agent_map) {
                //check to see if the two agents positions being compared are equal,
                //as well as if one agent is a player and one agent is an enemy
                if (temp_agent.second->GetPosition() == agent.GetPosition() &&
                    ((agent.GetName() == "Player" && temp_agent.second->GetName() != "Player") ||
                     (agent.GetName() != "Player" && temp_agent.second->GetName() == "Player")))
                    EndGame(false);
            }
        }


        bool IsTraversable(const AgentBase & /*agent*/, cse491::GridPosition pos) const override {
            size_t tileType = main_grid.At(pos);
            return !(tileType == wall_id || tileType == spike_id || tileType == tar_id || tileType == armory_id || tileType == teleporter_id);
        }

        void AStarAgentHelper(AgentBase &agent)
        {
            if( agent.GetName() == "AStar1" )
            {
                for( const auto &temp_agent : agent_map )
                {
                    //updating AStarAgent's path to the players current location
                    if( temp_agent.second->GetName() == "Player" )
                    {
                        auto &astar_agent = dynamic_cast<walle::AStarAgent&>(agent);
                        astar_agent.SetGoalPosition(temp_agent.second->GetPosition());
                        astar_agent.RecalculatePath();
                        astar_agent.SetActionResult(1);
                        break;
                    }
                }
            }
        }
    };

} // End of namespace group6

```

