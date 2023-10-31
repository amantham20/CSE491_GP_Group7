/**
 * @file TrackingAgent.hpp
 * @author Matt Kight
 *
 * Agent that switches between  user-defined custom movement pattern and
 * tracking a given agent
 */

#pragma once

#include <string>
#include <string_view>
#include <vector>

#include "../core/AgentBase.hpp"
#include "../core/GridPosition.hpp"
#include "AStarAgent.hpp"
#include "PathAgent.hpp"

namespace walle {

/**
 * Agent that switches between  user-defined custom movement pattern and
 * tracking a given agent
 */
class TrackingAgent : public PathAgent {
private:
  PathAgent path_agent;
  AStarAgent tracking_agent;
  cse491::GridPosition startPos;
  std::unique_ptr<AgentBase> target;
  // Possible states TO_START, TRACKING, and PATH
  std::string state = "TO_START"; // TODO REFACTOR TO ENUM?
  double tracking_distance = 50;

public:
  /**
   * Delete default constructor
   */
  TrackingAgent() = delete;

  /**
   * Constructor (vector)
   * @param id unique agent id
   * @param name name of path agent
   * @param offsets collection of offsets to move the agent
   * @attention The sequence of offsets must not be empty
   */
  TrackingAgent(size_t id, std::string const &name,
                std::vector<cse491::GridPosition> &&offsets)
      : PathAgent(id, name, std::move(offsets)),
        path_agent(id, name + "Path", std::move(offsets)),
        tracking_agent(id, name + "A*") {
    path_agent.SetWorld(GetWorld());
    tracking_agent.SetWorld(GetWorld());
  }
  /**
   * Constructor
   * @param id unique agent id
   * @param name name of path agent
   * @param commands sequence of commands to be interpreted as offsets
   * @attention The sequence of offsets must not be empty
   */
  TrackingAgent(size_t id, std::string const &name, std::string_view commands)
      : PathAgent(id, name, StrToOffsets(commands)),
        path_agent(id, name + "Path", StrToOffsets(commands)),
        tracking_agent(id, name + "A*"){};
  /**
   * Destructor
   */
  ~TrackingAgent() override = default;

  /**
   * Checks that the path_agent is able to move arbitrarily
   * Verifies that it can currently index into a valid offset
   * @return true if so; false otherwise
   */
  bool Initialize() override { return path_agent.Initialize(); }

  size_t SelectAction(cse491::WorldGrid const &grid,
                      cse491::type_options_t const &type,
                      cse491::item_set_t const &item_set,
                      cse491::agent_set_t const &agent_set) override {

    // Make sure both of our agents are at our same position
    path_agent.SetPosition(GetPosition());
    tracking_agent.SetPosition(GetPosition());

    if (GetPosition().Distance(target->GetPosition()) < tracking_distance) {
      // We are close enough, follow the target
      state = "TRACKING";
      tracking_agent.SetGoalPosition(target->GetPosition());
      tracking_agent.RecalculatePath();
      return tracking_agent.SelectAction(grid, type, item_set, agent_set);
    }
    // We are not close enough to track we either need to return to start pos or
    // follow path
    if (state != "PATH") {
      if (position == startPos) {
        // We have made it back to start pos, time to start "patrolling again"
        state = "PATH";
        return path_agent.SelectAction(grid, type, item_set, agent_set);
      }
      state = "TO_START";
      if (tracking_agent.GetGoalPosition() != startPos) {
        tracking_agent.SetGoalPosition(startPos);
        tracking_agent.RecalculatePath();
      }
      return tracking_agent.SelectAction(grid, type, item_set, agent_set);
    }
    // Keep patrolling
    return path_agent.SelectAction(grid, type, item_set, agent_set);
  }

  /**
   * Convenience method
   * Applies the current offset to calculate the next position and then adjusts
   * the index
   * @param increment decides whether to move in the forward or backward
   * direction to allow for complex pathing
   * @return Grid position we want to move to
   */
  cse491::GridPosition UpdateAndGetNextPos(bool increment) override {
    return path_agent.UpdateAndGetNextPos(increment);
  }
  /**
   * Set where this agent "patrol area" starts
   * @param gp grid position of position
   * @return self
   */
  TrackingAgent &SetStartPosition(cse491::GridPosition gp) {
    startPos = std::move(gp);
    return *this;
  }

  /**
   * Set where this agent "patrol area" starts
   * @param x x-coor of start pos
   * @param y y-coor of start pos
   * @return self
   */
  TrackingAgent &SetStartPosition(double x, double y) {
    startPos = cse491::GridPosition(x, y);
    return *this;
  }

  /**
   * Set which agent we are following
   * @param agent we want to track
   * @return self
   */
  TrackingAgent &SetTarget(std::unique_ptr<AgentBase> &&agent) {
    target = std::move(agent);
    return *this;
  }

  /**
   * Set how close target has to be to start tracking
   * @param dist to start tracking at
   * @return self
   */
  TrackingAgent &SetTrackingDistance(double dist) {
    tracking_distance = dist;
    return *this;
  }
};
} // namespace walle
