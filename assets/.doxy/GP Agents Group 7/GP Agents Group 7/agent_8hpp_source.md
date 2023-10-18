

# File agent.hpp

[**File List**](files.md) **>** [**Group7\_GP\_Agent**](dir_2917a1bbf314837e5575b308b680803f.md) **>** [**agent.hpp**](agent_8hpp.md)

[Go to the documentation of this file](agent_8hpp.md)

```C++


#pragma once

#include <cassert>
#include <iostream>
#include <map>
#include <random>
#include <string>

#include "../core/AgentBase.hpp"
#include "./GPAgentSensors.hpp"

namespace cowboys {

class GPAgent : public cse491::AgentBase {
 protected:
  const std::vector<std::string> predefinedMovement = {
      "down",  "down",  "down",  "down",  "right", "right", "up",    "up",
      "up",    "up",    "right", "right", "right", "right", "right", "right",
      "right", "right", "right", "right", "right", "left",  "left",  "left"};

  size_t movementIndex = 0;  

 public:
  GPAgent(size_t id, const std::string &name) : AgentBase(id, name) {
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<int> dist(
        0,
        3);  // size of the random set to 3 as we only have 4 actions initally
  }
  ~GPAgent() override = default;

  bool Initialize() override { return true; }

  size_t SelectAction(
      [[maybe_unused]] const cse491::WorldGrid &grid,
      [[maybe_unused]] const cse491::type_options_t &type_options,
      [[maybe_unused]] const cse491::item_set_t &item_set,
      [[maybe_unused]] const cse491::agent_set_t &agent_set) override {
#ifndef NDEBUG
    Sensors::wallDistance(grid, *this, SensorDirection::LEFT);
    Sensors::wallDistance(grid, *this, SensorDirection::RIGHT);
    Sensors::wallDistance(grid, *this, SensorDirection::ABOVE);
    Sensors::wallDistance(grid, *this, SensorDirection::BELOW);
#endif

    if (movementIndex >= predefinedMovement.size()) {
      return 0;  // do nothing if it is out of bound for defined movement
    }

    auto action = action_map[predefinedMovement[movementIndex++]];
    return action;
  }
};

}  // namespace cowboys

```

