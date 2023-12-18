

# File AgentBase.hpp

[**File List**](files.md) **>** [**core**](dir_0d27ce74e9bd514c31e1d63efab6b388.md) **>** [**AgentBase.hpp**](_agent_base_8hpp.md)

[Go to the documentation of this file](_agent_base_8hpp.md)

```C++


#pragma once

#include <cassert>
#include <string>
#include <unordered_map>
#include <utility>

#include "../DataCollection/AgentData.hpp"
#include "Data.hpp"
#include "Entity.hpp"
#include "GridPosition.hpp"
#include "WorldGrid.hpp"

namespace cse491 {

enum State  
{
  Healthy,
  Taking_Damage,
  Dying,
  Deceased
};

class AgentBase : public Entity {
protected:
  std::unordered_map<std::string, size_t> action_map;  
  int action;             
  int action_result = 0;  

  State agent_state = Healthy;  

public:
  AgentBase(size_t id, const std::string &name) : Entity(id, name) {}
  ~AgentBase() = default;  // Already virtual from Entity

  // -- World Interactions --

  virtual bool Initialize() { return true; }

  // -- Entity Overrides --

  bool IsAgent() const override { return true; }

  // -- Agent Interaction --

  State GetAgentState() { return agent_state; }

  void UpdateAgentState(cse491::AgentBase &agent) {
    if (agent.HasProperty("Health")) {
      if (agent.GetProperty<int>("Health") <= agent.GetProperty<int>("Max_Health") &&
          agent.GetProperty<int>("Health") > 3) {
        agent.agent_state = Healthy;
      } else if (agent.GetProperty<int>("Health") <= 3 && agent.GetProperty<int>("Health") > 0) {
        agent.agent_state = Dying;
      } else if (agent.GetProperty<int>("Health") <= 0) {
        agent.agent_state = Deceased;
      }
    }
    if (agent.HasProperty("Taking_Damage")) {
      if (agent.GetProperty<bool>("Taking_Damage") == true) {
        agent.agent_state = Taking_Damage;
      }
    }
  }

  void TakeDamage(cse491::AgentBase &agent) {
    agent.SetProperty<int>(
        "Health", agent.GetProperty<int>("Health") - agent.GetProperty<int>("Taking_Damage"));
    UpdateAgentState(agent);
  }

  // -- Action management --

  [[nodiscard]] bool HasAction(const std::string &action_name) const {
    return action_map.count(action_name);
  }

  [[nodiscard]] size_t GetActionID(const std::string &action_name) const {
    auto it = action_map.find(action_name);
    if (it == action_map.end()) return 0;
    return it->second;
  }

  void storeActionMap(std::string name) {
    DataCollection::AgentData data(name);
    data.StoreAction(action_map);
  }

  [[nodiscard]] virtual GridPosition GetNextPosition() { return Entity::GetPosition(); }

  virtual AgentBase &AddAction(const std::string &action_name, size_t action_id) {
    assert(!HasAction(action_name));  // Cannot add existing action name.
    action_map[action_name] = action_id;
    return *this;
  }

  [[nodiscard]] virtual size_t SelectAction([[maybe_unused]] const WorldGrid &grid,
                                            [[maybe_unused]] const type_options_t &type_options,
                                            [[maybe_unused]] const item_map_t &item_map,
                                            [[maybe_unused]] const agent_map_t &agent_map) {
    return 0;
  }

  [[nodiscard]] int GetActionResult() const { return action_result; }

  void SetActionResult(int result) { action_result = result; }

  virtual void Notify(const std::string & /*message*/, const std::string & /*msg_type*/ = "none") {}

  std::string GetTypeName_impl() const override { return "cse491::AgentBase"; }

  void Serialize_impl(std::ostream &os) const override {
    Entity::Serialize_impl(os);
    SerializeValue(os, action_map);
    SerializeValue(os, action);
    SerializeValue(os, action_result);
    SerializeValue(os, agent_state);
  }

  void Deserialize_impl(std::istream &is) override {
    Entity::Deserialize_impl(is);
    DeserializeValue(is, action_map);
    DeserializeValue(is, action);
    DeserializeValue(is, action_result);
    DeserializeValue(is, agent_state);
  }
};

}  // End of namespace cse491

```

