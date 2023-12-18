

# File TrackingAgent.hpp

[**File List**](files.md) **>** [**Agents**](dir_425e53e3c77c59c8573ea1fd0ff9622a.md) **>** [**TrackingAgent.hpp**](_tracking_agent_8hpp.md)

[Go to the documentation of this file](_tracking_agent_8hpp.md)

```C++


#pragma once

#include "../core/AgentBase.hpp"
#include "../core/GridPosition.hpp"
#include "AStarAgent.hpp"
#include "PathAgent.hpp"
#include "AgentLibary.hpp"

#include <memory>
#include <limits>
#include <string>
#include <string_view>
#include <type_traits>
#include <unordered_set>
#include <variant>
#include <vector>

namespace walle {

class Alerter {
 private:
    cse491::WorldBase *world_ptr_;

    std::unordered_set<size_t> agent_network_set_;

 public:
    // Must be constructed with an associated world
    Alerter() = delete;
    explicit Alerter(cse491::WorldBase *world_ptr);
    Alerter(cse491::WorldBase *world_ptr, size_t id);
    void AddAgent(size_t id);
    void RemoveAgent(size_t id);
    void AlertAllTrackingAgents(size_t caller_id);

    std::unordered_set<size_t> const &GetNetworkSet() const { return agent_network_set_; }
}; // Alerter

enum class TrackingState { RETURNING_TO_START, TRACKING, PATROLLING };

template<typename T>
concept TrackingAgentInner_Type = std::is_same_v<PathAgent, T> || std::is_same_v<AStarAgent, T>;

class TrackingAgent : public cse491::AgentBase {
 private:
    std::variant<PathAgent, AStarAgent> inner_;

    TrackingState state_ = TrackingState::PATROLLING;

    std::vector<cse491::GridPosition> offsets_;

    cse491::GridPosition start_pos_;

    Entity *target_ = nullptr;

    double tracking_distance_ = 50;

    std::shared_ptr<Alerter> alerter_ = nullptr;

 public:
    TrackingAgent() = delete;

    TrackingAgent(size_t id, std::string const &name)
        : cse491::AgentBase(id, name),
          inner_(std::in_place_type<PathAgent>, id, name) {}

    TrackingAgent(size_t id,
                  std::string const &name,
                  std::vector<cse491::GridPosition> &&offsets,
                  std::shared_ptr<Alerter> &&alerter = nullptr)
        : cse491::AgentBase(id, name),
          inner_(std::in_place_type<PathAgent>, id, name, offsets),
          offsets_(offsets),
          alerter_(alerter) {}

    TrackingAgent(size_t id,
                  std::string const &name,
                  std::string_view commands,
                  std::shared_ptr<Alerter> &&alerter = nullptr)
        : cse491::AgentBase(id, name),
          inner_(std::in_place_type<PathAgent>, id, name, commands),
          offsets_(StrToOffsets(commands)),
          alerter_(alerter) {}

    ~TrackingAgent() override {
        RemoveFromAlerter();
    }

    bool Initialize() override {
        SetStartPosition(GetPosition());
        if (property_map.contains("path")) {
            auto view = GetProperty<std::basic_string_view<char>>("path");
            offsets_ = StrToOffsets(view);
            std::get<PathAgent>(inner_).SetProperty("path", view);
            std::get<PathAgent>(inner_).SetWorld(GetWorld());
            std::get<PathAgent>(inner_).SetPosition(GetPosition());

            if (property_map.contains("alerter")) {
                auto alerter_property = GetProperty<std::shared_ptr<Alerter>>("alerter");
                AddToAlerter(alerter_property);
            }
            return std::get<PathAgent>(inner_).Initialize();
        }
        return false;
    }

    void MakeAlerter() {
        alerter_ = std::make_shared<Alerter>(&GetWorld(), id);
    }

    void AddToAlerter(std::shared_ptr<Alerter> alerter) {
        assert(alerter != nullptr);
        alerter->AddAgent(id);
        alerter_ = alerter;
    }

    void RemoveFromAlerter() {
        if (alerter_ != nullptr) {
            alerter_->RemoveAgent(id);
            alerter_ = nullptr;
        }
    }

    [[nodiscard]] std::shared_ptr<Alerter> GetAlerter() const {
        return alerter_;
    }

    void CallAlerter(size_t agent_id) {
        if (alerter_ != nullptr) {
            alerter_->AlertAllTrackingAgents(agent_id);
        }
    }

    void UpdateState(bool alerting = true) {
        SetPosition(std::visit([](TrackingAgentInner_Type auto const &agent) { return agent.GetPosition(); }, inner_));
        switch (state_) {
            // Tracking can transition only to Returning
            case TrackingState::TRACKING: {
                // Reached goal position
                if (GetPosition() == std::get<AStarAgent>(inner_).GetGoalPosition()) {
                    if (target_ != nullptr && GetPosition().Distance(target_->GetPosition()) < tracking_distance_) {
                        // Target is still in range of goal position so
                        std::get<AStarAgent>(inner_).SetGoalPosition(target_->GetPosition());

                        // Alert all trackers
                        if (alerting) {
                            CallAlerter(id);
                        }
                    } else {
                        state_ = TrackingState::RETURNING_TO_START;
                        std::get<AStarAgent>(inner_).SetGoalPosition(start_pos_);
                    }
                    std::get<AStarAgent>(inner_).RecalculatePath();
                    std::get<AStarAgent>(inner_).SetActionResult(1);
                }
                break;
            }

                // Returning can transition to either Patrolling or Tracking
            case TrackingState::RETURNING_TO_START: {
                // Within tracking range, start tracking again
                if (target_ != nullptr && GetPosition().Distance(target_->GetPosition()) < tracking_distance_) {
                    state_ = TrackingState::TRACKING;
                    std::get<AStarAgent>(inner_).SetGoalPosition(target_->GetPosition());
                    std::get<AStarAgent>(inner_).RecalculatePath();
                    std::get<AStarAgent>(inner_).SetActionResult(1);

                    // Alert other trackers
                    if (alerting) {
                        CallAlerter(id);
                    }
                }

                    // Returned to the beginning, start patrolling again
                else if (GetPosition() == start_pos_) {
                    state_ = TrackingState::PATROLLING;
                    inner_.emplace<PathAgent>(id, name);
                    std::get<PathAgent>(inner_).SetPosition(GetPosition());
                    std::get<PathAgent>(inner_).SetPath(std::vector(offsets_));

                    // Inner world_ptr needs to be reset
                    SetWorld(GetWorld());
                }
                break;
            }

                // Patrolling can transition only to Tracking
            case TrackingState::PATROLLING: {
                // Within tracking range, needs internal object replacement
                if (target_ != nullptr && GetPosition().Distance(target_->GetPosition()) < tracking_distance_) {
                    state_ = TrackingState::TRACKING;
                    inner_.emplace<AStarAgent>(id, name);
                    // Set internal AStarAgent's position to the outer position
                    std::get<AStarAgent>(inner_).SetPosition(GetPosition());
                    std::get<AStarAgent>(inner_).SetGoalPosition(target_->GetPosition());

                    // Inner world_ptr needs to be set
                    SetWorld(GetWorld());

                    std::get<AStarAgent>(inner_).RecalculatePath();
                    std::get<AStarAgent>(inner_).SetActionResult(1);

                    // Alert all other trackers
                    if (alerting) {
                        CallAlerter(id);
                    }
                }
                break;
            }
        }
    }

    [[nodiscard]] cse491::GridPosition GetNextPosition() override {
        auto pos = std::get<PathAgent>(inner_).GetNextPosition();
        std::get<PathAgent>(inner_).SetPosition(pos);
        return pos;
    }

    size_t SelectInnerAction(PathAgent &agent,
                             cse491::WorldGrid const &grid,
                             cse491::type_options_t const &type,
                             cse491::item_map_t const &item_set,
                             cse491::agent_map_t const &agent_set) {
        return agent.SelectAction(grid, type, item_set, agent_set);
    }

    size_t SelectInnerAction(AStarAgent &agent,
                             cse491::WorldGrid const &grid,
                             cse491::type_options_t const &type,
                             cse491::item_map_t const &item_set,
                             cse491::agent_map_t const &agent_set) {
        auto next_pos = agent.GetNextPosition();
        auto res = agent.SelectAction(grid, type, item_set, agent_set);
        agent.SetPosition(next_pos);
        return res;
    }

    size_t SelectAction(cse491::WorldGrid const &grid,
                        cse491::type_options_t const &type,
                        cse491::item_map_t const &item_set,
                        cse491::agent_map_t const &agent_set) override {
        UpdateState();
        return std::visit([&](TrackingAgentInner_Type auto &agent) {
                              return SelectInnerAction(agent, grid, type, item_set, agent_set);
                          },
                          inner_);
    }

    TrackingAgent &SetStartPosition(cse491::GridPosition pos) {
        start_pos_ = pos;
        return *this;
    }

    TrackingAgent &SetStartPosition(double x, double y) {
        start_pos_ = cse491::GridPosition(x, y);
        return *this;
    }

    TrackingAgent &SetTarget(Entity *agent) {
        target_ = agent;
        return *this;
    }

    [[nodiscard]] double GetTrackingDistance() const { return tracking_distance_; }

    TrackingAgent &SetTrackingDistance(double dist) {
        tracking_distance_ = dist;
        return *this;
    }

    TrackingAgent &SetWorld(cse491::WorldBase &in_world) override {
        Entity::SetWorld(in_world);
        std::visit([&in_world](TrackingAgentInner_Type auto &agent) {
            agent.SetWorld(in_world);
            std::as_const(in_world).ConfigAgent(agent);
        }, inner_);
        return *this;
    }

    TrackingState GetState() {
        return state_;
    }

    TrackingAgent &SetPath(std::vector<cse491::GridPosition> offsets) {
        offsets_ = std::move(offsets);
        if (offsets_.empty()) {
            std::ostringstream what;
            what << "TrackingAgent cannot have empty path. If you meant to make the agent stay still, use \"x\"";
            throw std::invalid_argument(what.str());
        }
        return *this;
    }

    TrackingAgent &SetPath(std::string_view offsets) {
        return SetPath(StrToOffsets(offsets));
    }

    std::vector<cse491::GridPosition> const &GetPath() const { return offsets_; }

    cse491::Entity const *GetTarget() const { return target_; }

}; // TrackingAgent

Alerter::Alerter(cse491::WorldBase *world_ptr) : world_ptr_(world_ptr) { assert(world_ptr != nullptr); }

Alerter::Alerter(cse491::WorldBase *world_ptr, size_t id) : world_ptr_(world_ptr) {
    assert(world_ptr != nullptr);
    AddAgent(id);
}

void Alerter::AddAgent(size_t id) {
    // Note: GetAgent already handles checking that the agent exists, but we must type-check
    assert(dynamic_cast<TrackingAgent *>(&(world_ptr_->GetAgent(id))) != nullptr);
    agent_network_set_.insert(id);
}

void Alerter::RemoveAgent(size_t id) {
    agent_network_set_.erase(id);
}

void Alerter::AlertAllTrackingAgents(size_t caller_id) {
    for (auto id : agent_network_set_) {
        // Do not update the caller who gave the alert
        if (caller_id == id) {
            continue;
        }
        auto &tracking_agent = DownCastAgent<TrackingAgent>(world_ptr_->GetAgent(id));
        // UpdateState sets an agent's TrackingState to TRACKING if it is within some distance of the goal_pos
        // if this distance is positive infinity, then the state will always be reset (given that there IS a goal_pos)
        // Important: UpdateState must be called with alerting == false in order to
        // avoid infinite recursion from recursively calling AlertAllTrackingAgents
        double old_tracking_dist = tracking_agent.GetTrackingDistance();
        tracking_agent.SetTrackingDistance(std::numeric_limits<double>::infinity());
        tracking_agent.UpdateState(false);
        tracking_agent.SetTrackingDistance(old_tracking_dist);
    }
}

} // namespace walle

```

