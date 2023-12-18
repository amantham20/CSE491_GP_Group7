

# File AgentLibary.hpp

[**File List**](files.md) **>** [**Agents**](dir_425e53e3c77c59c8573ea1fd0ff9622a.md) **>** [**AgentLibary.hpp**](_agent_libary_8hpp.md)

[Go to the documentation of this file](_agent_libary_8hpp.md)

```C++


#pragma once

#include <map>
#include <queue>
#include <regex>
#include <sstream>
#include <tuple>
#include <vector>

#include "../core/AgentBase.hpp"
#include "../core/WorldBase.hpp"

namespace walle {

    struct Node {
        cse491::GridPosition position; 
        double g;                      
        double h; 
        std::shared_ptr<Node>
            parent; 

        Node(const cse491::GridPosition &position, double g, double h,
            std::shared_ptr<Node> parent)
            : position(position), g(g), h(h), parent(std::move(parent)) {}

        [[nodiscard]] double f() const { return g + h; }
    };

    struct CompareNodes {
        bool operator()(const std::shared_ptr<walle::Node> &a,
                        const std::shared_ptr<walle::Node> &b) const {
            return a->f() > b->f();
        }
    };

    inline std::vector<cse491::GridPosition>
    GetShortestPath(const cse491::GridPosition &start,
                    const cse491::GridPosition &end, const cse491::WorldBase &world,
                    const cse491::AgentBase &agent) {
    // Generated with the help of chat.openai.com
    const size_t rows = world.GetGrid().GetWidth();
    const size_t cols = world.GetGrid().GetHeight();
    std::vector<cse491::GridPosition> path;
    // If the start or end is not valid then return empty list
    if (!(world.GetGrid().IsValid(start) && world.GetGrid().IsValid(end)))
        return path;

    // Define possible movements (up, down, left, right)
    const int dx[] = {-1, 1, 0, 0};
    const int dy[] = {0, 0, -1, 1};

    // Create a 2D vector to store the cost to reach each cell
    std::vector<std::vector<double>> cost(rows,
                                            std::vector<double>(cols, INT_MAX));

    // Create an open list as a priority queue
    std::priority_queue<std::shared_ptr<walle::Node>,
                        std::vector<std::shared_ptr<walle::Node>>,
                        walle::CompareNodes>
        openList;

    // Create the start and end nodes
    auto startNode = std::make_shared<walle::Node>(start, 0, 0, nullptr);
    auto endNode = std::make_shared<walle::Node>(end, 0, 0, nullptr);

    openList.push(startNode);
    cost[start.CellX()][start.CellY()] = 0;

    while (!openList.empty()) {
        auto current = openList.top();
        openList.pop();

        if (current->position == endNode->position) {

        // Reached the goal, reconstruct the path
        while (current != nullptr) {
            path.push_back(current->position);
            current = current->parent;
        }
        break;
        }

        // Explore the neighbors
        for (int i = 0; i < 4; ++i) {
            cse491::GridPosition newPos(current->position.GetX() + dx[i],
                                        current->position.GetY() + dy[i]);
            // Check if the neighbor is within bounds and is a valid move
            if (world.GetGrid().IsValid(newPos) &&
                world.IsTraversable(agent, newPos)) {
                double newG =
                    current->g + 1; // Assuming a cost of 1 to move to a neighbor
                double newH = std::abs(newPos.GetX() - endNode->position.GetX()) +
                    std::abs(newPos.GetY() -
                        endNode->position.GetY()); // Manhattan distance

                if (newG + newH < cost[newPos.CellX()][newPos.CellY()]) {
                    auto neighbor =
                        std::make_shared<walle::Node>(newPos, newG, newH, current);
                    openList.push(neighbor);
                    cost[newPos.CellX()][newPos.CellY()] = newG + newH;
                }
            }
        }
    }
    return path;
    }

    inline std::vector<cse491::GridPosition>
    StrToOffsets(std::string_view commands) {
        std::vector<cse491::GridPosition> positions;

        // Regex capturing groups logically mean the following:
        // Group 0: whole regex
        // Group 1: `steps` and `*` pair (optional)(unused)
        // Group 2: `steps` (optional)
        // Group 3: `*` (optional, only matches when Group 2 matches)
        // Group 4: direction
        std::regex pattern("(([1-9]\\d*)(\\*?))?([nswex])");
        std::istringstream iss{std::string(commands)};
        iss >> std::skipws;

        std::string single_command;
        while (iss >> single_command) {
            std::smatch pattern_match;
            if (std::regex_match(single_command, pattern_match, pattern)) {
                int steps = 1;

                if (pattern_match[2].length() > 0) {
                    std::istringstream step_val(pattern_match[1].str());
                    step_val >> steps;
                }

                bool multiply = pattern_match[3].length() > 0;

                char direction = pattern_match[4].str()[0];

                cse491::GridPosition base_pos;
                switch (direction) {
                    // Move up
                    case 'n': {
                        if (multiply) {
                            positions.push_back(base_pos.Above(steps));
                        } else {
                            for (int i = 0; i < steps; ++i) {
                                positions.push_back(base_pos.Above());
                            }
                        }
                        break;
                    }

                    // Move down
                    case 's': {
                        if (multiply) {
                            positions.push_back(base_pos.Below(steps));
                        } else {
                            for (int i = 0; i < steps; ++i) {
                                positions.push_back(base_pos.Below());
                            }
                        }
                        break;
                    }

                    // Move left
                    case 'w': {
                        if (multiply) {
                            positions.push_back(base_pos.ToLeft(steps));
                        } else {
                            for (int i = 0; i < steps; ++i) {
                                positions.push_back(base_pos.ToLeft());
                            }
                        }
                        break;
                    }

                    // Move right
                    case 'e': {
                        if (multiply) {
                            positions.push_back(base_pos.ToRight(steps));
                        } else {
                            for (int i = 0; i < steps; ++i) {
                                positions.push_back(base_pos.ToRight());
                            }
                        }
                        break;
                    }

                    // Stay
                    case 'x': {
                        // Using the `*` does nothing to scale the offset since it's scaling {0,
                        // 0}
                        steps = multiply ? 1 : steps;

                        for (int i = 0; i < steps; ++i) {
                            positions.push_back(base_pos);
                        }
                    }
                }
            } else {
                std::ostringstream what;
                what << "Incorrectly formatted argument: " << single_command;
                throw std::invalid_argument(what.str());
            }

            iss >> std::skipws;
        }
        return positions;
    }

    template<typename T>
    concept Agent_Type = std::is_base_of_v<cse491::AgentBase, T>;

    template<typename T>
    T &DownCastAgent(cse491::Entity &entity) requires(Agent_Type<T>) {
        assert(dynamic_cast<T *>(&entity)!=nullptr);
        return static_cast<T &>(entity);
    }

} // namespace walle

```

