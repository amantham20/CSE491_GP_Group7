

# File GPAgentSensors.hpp

[**File List**](files.md) **>** [**Agents**](dir_425e53e3c77c59c8573ea1fd0ff9622a.md) **>** [**GP**](dir_24320de467b989ce68b31a9ae5cbbd05.md) **>** [**GPAgentSensors.hpp**](_g_p_agent_sensors_8hpp.md)

[Go to the documentation of this file](_g_p_agent_sensors_8hpp.md)

```C++


#pragma once

#include "../../core/WorldGrid.hpp"

// #define DEBUG

namespace cowboys {

static constexpr int WALL =
    2;  // TODO: work with world teams to better define impenetrable objects
// FIXME: Group 1 has made a class that can check if a position is penetrable
// or not. We This will be used instead

enum SensorDirection { LEFT, RIGHT, ABOVE, BELOW };

class Sensors {
 private:
  [[maybe_unused]] static void debugPosition(const std::string &/*printstring*/) {
#ifndef NDEBUG
//    std::cout << printstring << std::endl;
#endif
  }

 public:
  Sensors() = default;

  ~Sensors() = default;

  static int wallDistance(const cse491::WorldGrid &grid,
                          const cse491::AgentBase &agent,
                          SensorDirection direction) {
    int distance = 0;
    cse491::GridPosition position = agent.GetPosition();

    while (grid.IsValid(position) && grid.At(position) != WALL) {
      if (direction == LEFT) {
        position = position.ToLeft();
      } else if (direction == RIGHT) {
        position = position.ToRight();
      } else if (direction == ABOVE) {
        position = position.Above();
      } else if (direction == BELOW) {
        position = position.Below();
      }
      distance++;
    }

    std::string directionStr;
    if (direction == LEFT) {
      directionStr = "left";
    } else if (direction == RIGHT) {
      directionStr = "right";
    } else if (direction == ABOVE) {
      directionStr = "top";
    } else if (direction == BELOW) {
      directionStr = "bottom";
    }

    debugPosition(directionStr +
                  " distance to the wall:  " + std::to_string(distance - 1));

    return distance - 1;
  }

  // make a function that takes in a string and maps the SensorDirectionEnum
  static SensorDirection getSensorDirectionEnum(const std::string &direction) {
    if (direction == "getLeft") {
      return SensorDirection::LEFT;
    } else if (direction == "getRight") {
      return SensorDirection::RIGHT;
    } else if (direction == "getUp") {
      return SensorDirection::ABOVE;
    } else if (direction == "getDown") {
      return SensorDirection::BELOW;
    }

    throw std::invalid_argument("Invalid direction");
    return SensorDirection::LEFT;
  }
};
}  // namespace cowboys

```

