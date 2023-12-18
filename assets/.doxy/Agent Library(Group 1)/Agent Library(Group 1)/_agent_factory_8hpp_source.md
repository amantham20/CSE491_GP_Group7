

# File AgentFactory.hpp

[**File List**](files.md) **>** [**Agents**](dir_425e53e3c77c59c8573ea1fd0ff9622a.md) **>** [**AgentFactory.hpp**](_agent_factory_8hpp.md)

[Go to the documentation of this file](_agent_factory_8hpp.md)

```C++


#pragma once

#include "../core/AgentBase.hpp"
#include "AStarAgent.hpp"
#include "PacingAgent.hpp"
#include "PathAgent.hpp"
#include "TrackingAgent.hpp"
#include "AgentLibary.hpp"

#include "../core/Entity.hpp"
#include "../core/WorldBase.hpp"

namespace walle {

// Forward-declare since it's easier to understand how AddXAgent works 
// when the structs are defined nearby
struct PacingAgentData;
struct PathAgentData;
struct AStarAgentData;
struct TrackingAgentData;

class AgentFactory {
private:
    cse491::WorldBase &world;   

public:
    AgentFactory() = delete;

    explicit AgentFactory(cse491::WorldBase &world) : world(world) {}

    AStarAgent &AddAStarAgent(const AStarAgentData &agent_data);
    cse491::PacingAgent &AddPacingAgent(const PacingAgentData &agent_data);
    TrackingAgent &AddTrackingAgent(const TrackingAgentData &agent_data);
    PathAgent &AddPathAgent(const PathAgentData &agent_data);

}; // class AgentFactory

struct BaseAgentData {
    std::string name;

    cse491::GridPosition position;

    char symbol = '*';
};

struct PacingAgentData : public BaseAgentData {
    bool vertical = false;
};

cse491::PacingAgent &AgentFactory::AddPacingAgent(const PacingAgentData &agent_data) {
    auto &entity = world.AddAgent<cse491::PacingAgent>(agent_data.name).SetPosition(agent_data.position).SetProperty(
        "symbol",
        agent_data.symbol);
    auto &agent = DownCastAgent<cse491::PacingAgent>(entity);
    agent.SetVertical(agent_data.vertical);
    return agent;
}

struct PathAgentData : public BaseAgentData {
    int index;

    std::string string_path;

    std::vector<cse491::GridPosition> vector_path;
};

PathAgent &AgentFactory::AddPathAgent(const PathAgentData &agent_data) {
    auto &entity = world.AddAgent<walle::PathAgent>(agent_data.name).SetPosition(agent_data.position).SetProperty(
        "symbol",
        agent_data.symbol);
    auto &agent = DownCastAgent<walle::PathAgent>(entity);
    if (!agent_data.string_path.empty()) {
        agent.SetProperty<std::basic_string_view<char>>("path",
                                                    agent_data.string_path); // TODO add another option to provide grid point
    } else {
        agent.SetPath(agent_data.vector_path);
    }
    agent.Initialize();
    return agent;
}

struct AStarAgentData : public BaseAgentData {
    int recalculate_after_x_turns = 5;

    cse491::GridPosition goal_pos;
};

AStarAgent &AgentFactory::AddAStarAgent(const AStarAgentData &agent_data) {
    auto &entity = world.AddAgent<walle::AStarAgent>(agent_data.name).SetPosition(agent_data.position).SetProperty(
        "symbol",
        agent_data.symbol);
    auto &agent = DownCastAgent<walle::AStarAgent>(entity);
    agent.SetGoalPosition(agent_data.goal_pos);
    agent.SetRecalculate(agent_data.recalculate_after_x_turns);
    return agent;
}

struct TrackingAgentData : public BaseAgentData {
    std::vector<cse491::GridPosition> vector_path;

    std::string string_path;

    cse491::Entity *target;

    int tracking_distance = 5;

    cse491::GridPosition start_pos;

    std::shared_ptr<Alerter> alerter = nullptr;

    TrackingAgentData() = default;

    TrackingAgentData(std::string name,
                    cse491::GridPosition curr_pos,
                    char symbol,
                    std::string path,
                    cse491::Entity * target,
                    int tracking_dist,
                    cse491::GridPosition start_pos,
                    std::shared_ptr<Alerter> alerter)
        : BaseAgentData({std::move(name), curr_pos, symbol}),
        vector_path(StrToOffsets(path)),
        string_path(std::move(path)),
        target(target),
        tracking_distance(tracking_dist),
        start_pos(start_pos),
        alerter(alerter) {}
};

TrackingAgent &AgentFactory::AddTrackingAgent(const TrackingAgentData &agent_data) {
    auto &entity = world.AddAgent<walle::TrackingAgent>(agent_data.name).SetPosition(agent_data.position).SetProperty(
        "symbol",
        agent_data.symbol);
    auto &agent = DownCastAgent<TrackingAgent>(entity);
    if (!agent_data.string_path.empty()) {
        agent.SetProperty<std::basic_string_view<char>>("path", agent_data.string_path);
    } else {
        agent.SetPath(agent_data.vector_path);
    }
    agent.SetTarget(agent_data.target);
    agent.SetTrackingDistance(agent_data.tracking_distance);
    agent.SetStartPosition(agent_data.start_pos);
    if (agent_data.alerter != nullptr) {
        agent.SetProperty("alerter", agent_data.alerter);
    }
    agent.Initialize();
    return agent;
}

} // namespace walle

```

