

# File WorldBase.hpp

[**File List**](files.md) **>** [**core**](dir_0d27ce74e9bd514c31e1d63efab6b388.md) **>** [**WorldBase.hpp**](_world_base_8hpp.md)

[Go to the documentation of this file](_world_base_8hpp.md)

```C++


#pragma once

#include <algorithm>
#include <cassert>
#include <memory>
#include <queue>
#include <random>
#include <sstream>
#include <string>
#include <vector>

#include "../DataCollection/AgentReciever.hpp"
#include "AgentBase.hpp"
#include "Data.hpp"
#include "DataCollection/DataManager.hpp"
#include "Interfaces/NetWorth/client/ClientInterface.hpp"
#include "Interfaces/NetWorth/client/ClientManager.hpp"
#include "Interfaces/NetWorth/client/ControlledAgent.hpp"
#include "Interfaces/NetWorth/server/ServerManager.hpp"
#include "ItemBase.hpp"
#include "WorldGrid.hpp"

// Forward declaration
namespace worldlang {
class ProgramExecutor;
}

namespace cse491 {
class DataReceiver;

class WorldBase {
public:
  static constexpr size_t npos = static_cast<size_t>(-1);
  netWorth::ServerManager *server_manager = nullptr;  
  netWorth::ClientManager *client_manager = nullptr;  

  virtual void ConfigAgent(AgentBase & /* agent */) const {}

protected:
  std::unordered_map<size_t, WorldGrid> grids;

  WorldGrid &main_grid;         
  type_options_t type_options;  

  item_map_t item_map;        
  agent_map_t agent_map;      
  size_t last_entity_id = 0;  

  bool run_over = false;      
  bool world_running = true;  

  std::string action;  
  std::shared_ptr<DataCollection::AgentReceiver> agent_receiver;

  unsigned int seed;                          
  std::mt19937 random_gen;                    
  std::uniform_real_distribution<> uni_dist;  
  std::normal_distribution<> norm_dist;       

  size_t NextEntityID() { return ++last_entity_id; }

  virtual void ConfigAgent(AgentBase & /* agent */) {}

  size_t AddCellType(const std::string &name, const std::string &desc = "", char symbol = '\0') {
    type_options.push_back(CellType{name, desc, symbol});
    return type_options.size() - 1;
  }

public:
  WorldBase(unsigned int seed = 0) : grids(), main_grid(grids[0]), seed(seed) {
    // The first cell type (ID 0) should be reserved for errors or empty spots in a grid.
    AddCellType("Unknown", "This is an invalid cell type and should not be reachable.");

    // Initialize the random number generator.
    if (seed == 0) {
      std::random_device rd;  // An expensive "true" random number generator.
      seed = rd();            // Change the seed to a random value.
    }
    random_gen.seed(seed);
  }

  virtual ~WorldBase() = default;

  virtual void Reset() {
    item_map.clear();
    agent_map.clear();
    last_entity_id = 0;
    run_over = false;
  }

  // -- Accessors --

  [[nodiscard]] size_t GetNumItems() const { return item_map.size(); }

  [[nodiscard]] size_t GetNumAgents() const { return agent_map.size(); }

  [[nodiscard]] bool HasItem(size_t id) const { return item_map.count(id); }

  [[nodiscard]] bool HasAgent(size_t id) const { return agent_map.count(id); }

  [[nodiscard]] ItemBase &GetItem(size_t id) {
    assert(HasItem(id));
    return *item_map[id];
  }

  [[nodiscard]] AgentBase &GetAgent(size_t id) {
    assert(HasAgent(id));
    return *agent_map[id];
  }

  [[nodiscard]] size_t GetItemID(const std::string &name) {
    for (auto &[id, ptr] : item_map) {
      if (ptr->GetName() == name) return id;
    }
    return npos;
  }

  [[nodiscard]] size_t GetAgentID(const std::string &name) {
    for (auto &[id, ptr] : agent_map) {
      if (ptr->GetName() == name) return id;
    }
    return npos;
  }

  virtual WorldGrid &GetGrid() { return main_grid; }
  virtual WorldGrid &GetGrid(size_t grid_id) { return grids[grid_id]; }

  virtual const WorldGrid &GetGrid() const { return main_grid; }
  virtual const WorldGrid &GetGrid(size_t grid_id) const { return grids.at(grid_id); }

  virtual bool GetRunOver() const { return run_over; }

  // -- Random Number Generation --

  unsigned int GetSeed() const { return seed; }

  double GetRandom() { return uni_dist(random_gen); }

  double GetRandom(double max) { return GetRandom() * max; }

  double GetRandom(double min, double max) {
    assert(max > min);
    return min + GetRandom(max - min);
  }

  double GetRandomNormal() { return norm_dist(random_gen); }

  double GetRandomNormal(double mean, double sd = 1.0) {
    assert(sd > 0);
    return mean + norm_dist(random_gen) * sd;
  }

  // -- Agent Management --

  AgentBase &AddConfiguredAgent(std::unique_ptr<AgentBase> agent_ptr) {
    std::mutex agent_map_lock;
    agent_map_lock.lock();
    agent_ptr->SetWorld(*this);
    if (agent_ptr->Initialize() == false) {
      std::cerr << "Failed to initialize agent '" << agent_ptr->GetName() << "'." << std::endl;
    }
    AgentBase & agentReturn = *agent_map[agent_ptr->GetID()];
    agent_map[agent_ptr->GetID()] = std::move(agent_ptr);
    agent_map_lock.unlock();
    return agentReturn;
  }


  template <typename AGENT_T, typename... PROPERTY_Ts>
  AgentBase &AddAgent(std::string agent_name = "None", PROPERTY_Ts... properties) {
    std::mutex agent_map_lock;
    agent_map_lock.lock();
    const size_t agent_id = NextEntityID();
    auto agent_ptr = std::make_unique<AGENT_T>(agent_id, agent_name);
    agent_ptr->SetWorld(*this);
    agent_ptr->SetProperties(std::forward<PROPERTY_Ts>(properties)...);
    ConfigAgent(*agent_ptr);
    if (agent_ptr->Initialize() == false) {
      std::cerr << "Failed to initialize agent '" << agent_name << "'." << std::endl;
    }
    agent_map[agent_id] = std::move(agent_ptr);
    AgentBase &agentReturn = *agent_map[agent_id];
    agent_map_lock.unlock();
    return agentReturn;
  }

  ItemBase &AddItem(std::unique_ptr<ItemBase> item_ptr) {
    assert(item_ptr);                // item_ptr must not be null.
    assert(item_ptr->GetID() != 0);  // item_ptr must have had a non-zero ID assigned.
    item_ptr->SetWorld(*this);
    size_t item_id = item_ptr->GetID();
    item_map[item_id] = std::move(item_ptr);
    return *item_map[item_id];
  }

  template <typename ITEM_T = ItemBase, typename... PROPERTY_Ts>
  ItemBase &AddItem(std::string item_name = "None", PROPERTY_Ts... properties) {
    auto item_ptr = std::make_unique<ITEM_T>(NextEntityID(), item_name);
    item_ptr->SetProperties(std::forward<PROPERTY_Ts>(properties)...);
    return AddItem(std::move(item_ptr));
  }

  WorldBase &RemoveAgent(size_t agent_id) {
    agent_map.erase(agent_id);
    return *this;
  }

  WorldBase &RemoveItem(size_t item_id) {
    item_map.erase(item_id);
    return *this;
  }

  WorldBase &RemoveAgent(std::string agent_name = "None") {
    assert(agent_name != "Interface");  // We are not allowed to remove interfaces.
    return RemoveAgent(GetAgentID(agent_name));
  }

  WorldBase &RemoveItem(std::string item_name) { return RemoveItem(GetItemID(item_name)); }

  WorldBase &AddItemToGrid(size_t item_id, GridPosition pos, size_t grid_id = 0) {
    item_map[item_id]->SetPosition(pos, grid_id);
    return *this;
  }

  // -- Action Management --

  virtual int DoAction(AgentBase &agent, size_t action_id) = 0;

  virtual void RunAgents() {
    for (auto &[id, agent_ptr] : agent_map) {
      size_t action_id = agent_ptr->SelectAction(main_grid, type_options, item_map, agent_map);
      agent_ptr->storeActionMap(agent_ptr->GetName());
      int result = DoAction(*agent_ptr, action_id);
      agent_ptr->SetActionResult(result);
    }
  }

  virtual void RunClientAgents() {
    for (auto &[id, agent_ptr] : agent_map) {
      size_t action_id = agent_ptr->SelectAction(main_grid, type_options, item_map, agent_map);
      agent_ptr->storeActionMap(agent_ptr->GetName());
      int result = DoAction(*agent_ptr, action_id);
      agent_ptr->SetActionResult(result);
    }

    // Deserialize agents
    std::string data = client_manager->getSerializedAgents();
    if (data.substr(0, 18) == ":::START agent_set") {
      std::istringstream is(data);
      DeserializeAgentSet(is, client_manager);
    }
  }

  virtual void RunServerAgents() {
    std::set<size_t> to_delete;

    for (auto &[id, agent_ptr] : agent_map) {
      // wait until clients have connected to run
      while (!server_manager->hasAgentsPresent() || !world_running) {
      }

      // select action and send to client
      size_t action_id = agent_ptr->SelectAction(main_grid, type_options, item_map, agent_map);
      server_manager->writeToActionMap(id, action_id);
      agent_ptr->storeActionMap(agent_ptr->GetName());
      int result = DoAction(*agent_ptr, action_id);
      agent_ptr->SetActionResult(result);

      // mark agent for deletion if client disconnects
      if (action_id == 9999) to_delete.insert(id);
    }

    // delete agents
    for (size_t id : to_delete) {
      RemoveAgent(id);
    }

    // send updates to client for deleted agents
    if (!to_delete.empty()) {
      std::ostringstream os;
      SerializeAgentSet(os);
      std::string data = os.str();
      server_manager->setSerializedAgents(data);
      server_manager->setNewAgent(true);
      server_manager->sendGameUpdates();
    }
  }

  void CollectData() {
    for (const auto &[id, agent_ptr] : agent_map) {
      DataCollection::DataManager::GetInstance().GetAgentReceiver().StoreData(
          agent_ptr->GetName(), agent_ptr->GetPosition(), agent_ptr->GetActionResult());
    }
  }

  virtual void UpdateWorld() {}

  virtual void Run() {
    run_over = false;
    while (!run_over) {
      RunAgents();
      CollectData();
      UpdateWorld();
    }
  }

  virtual void RunClient(netWorth::ClientManager *manager) {
    run_over = false;
    client_manager = manager;
    while (!run_over) {
      if (world_running) {
        RunClientAgents();
        CollectData();
        UpdateWorld();
      }
    }
  }

  virtual void RunServer(netWorth::ServerManager *manager) {
    run_over = false;
    server_manager = manager;
    while (!run_over) {
      if (world_running) {
        RunServerAgents();
        CollectData();
        UpdateWorld();
      }
    }
  }

  virtual void SetWorldRunning(bool running) { world_running = running; }

  // CellType management.

  // Return a const vector of all of the possible cell types.
  [[nodiscard]] const type_options_t &GetCellTypes() const { return type_options; }

  [[nodiscard]] size_t GetCellTypeID(const std::string &name) const {
    for (size_t i = 1; i < type_options.size(); ++i) {
      if (type_options[i].name == name) return i;
    }
    return 0;
  }

  [[nodiscard]] const std::string &GetCellTypeName(size_t id) const {
    if (id >= type_options.size()) return type_options[0].name;
    return type_options[id].name;
  }

  [[nodiscard]] char GetCellTypeSymbol(size_t id) const {
    if (id >= type_options.size()) return type_options[0].symbol;
    return type_options[id].symbol;
  }

  // -- Grid Analysis Helpers --

  [[nodiscard]] virtual std::vector<size_t> FindItemsAt(GridPosition pos,
                                                        size_t grid_id = 0) const {
    std::vector<size_t> item_ids;
    for (const auto &[id, item_ptr] : item_map) {
      if (item_ptr->IsOnGrid(grid_id) && item_ptr->GetPosition() == pos) item_ids.push_back(id);
    }
    return item_ids;
  }

  [[nodiscard]] virtual std::vector<size_t> FindAgentsAt(GridPosition pos,
                                                         size_t grid_id = 0) const {
    std::vector<size_t> agent_ids;
    for (const auto &[id, agent_ptr] : agent_map) {
      if (agent_ptr->IsOnGrid(grid_id) && agent_ptr->GetPosition() == pos) agent_ids.push_back(id);
    }
    return agent_ids;
  }

  [[nodiscard]] virtual std::vector<size_t> FindItemsNear(GridPosition pos, double dist = 1.0,
                                                          size_t grid_id = 0) const {
    std::vector<size_t> item_ids;
    for (const auto &[id, item_ptr] : item_map) {
      if (item_ptr->IsOnGrid(grid_id) && item_ptr->GetPosition().IsNear(pos, dist)) {
        item_ids.push_back(id);
      }
    }
    return item_ids;
  }

  [[nodiscard]] virtual std::vector<size_t> FindAgentsNear(GridPosition pos, double dist = 1.0,
                                                           size_t grid_id = 0) const {
    std::vector<size_t> agent_ids;
    for (const auto &[id, agent_ptr] : agent_map) {
      if (agent_ptr->IsOnGrid(grid_id) && agent_ptr->GetPosition().IsNear(pos, dist)) {
        agent_ids.push_back(id);
      }
    }
    return agent_ids;
  }

  [[nodiscard]] virtual bool IsTraversable(const AgentBase & /*agent*/,
                                           cse491::GridPosition /*pos*/) const {
    return true;
  }

  // -- Network Serialization and Deserialization --

  void SerializeAgentSet(std::ostream &os) {
    os << ":::START agent_set\n";
    SerializeValue(os, agent_map.size());

    for (const auto &[agent_id, agent_ptr] : agent_map) {
      SerializeValue(os, *agent_ptr);
    }
    os << ":::END agent_set\n";
  }

  void DeserializeAgentSet(std::istream &is, netWorth::ClientManager *manager) {
    // find beginning of agent_set serialization
    std::string read;
    std::getline(is, read, '\n');
    if (read != ":::START agent_set") {
      std::cerr << "Could not find start of agent_set serialization" << std::endl;
      return;
    }

    size_t client_id = manager->getClientID();

    // Remove all agents other than the interface
    std::vector<size_t> to_delete;
    for (auto & [agent_id, agent_ptr] : agent_map) {
      if (agent_id != client_id) to_delete.push_back(agent_id);
    }

    for (size_t agent_id : to_delete) {
      RemoveAgent(agent_id);
    }

    // reset last_entity_id; start from the beginning
    last_entity_id = 0;

    // Load the number of agents saved.
    size_t server_last_entity_id = DeserializeAs<size_t>(is);

    // client id NOT in agent map yet if ID = 0
    // append to end of set
    if (client_id == 0) client_id = server_last_entity_id;

    // Load back in all agents.
    for (size_t i = 0; i < server_last_entity_id; i++) {
      // First, check to see if we've hit the end of the agent_set
      // Because we are looking at last entity id (and not total size), we may have
      //  gaps in our agent_set
      auto tmp_pos = is.tellg();
      std::getline(is, read, '\n');
      if(read == ":::END agent_set"){
        if(last_entity_id < client_id) last_entity_id = client_id;
        return;
      }
      else is.seekg(tmp_pos);
      auto agent_ptr = std::make_unique<netWorth::ControlledAgent>(0, "temp");
      DeserializeValue(is, *agent_ptr);
      agent_ptr->SetProperty("manager", manager);

      if (agent_ptr->GetID() >= last_entity_id) last_entity_id = agent_ptr->GetID();

      // If this agent is the client interface, skip it (we already have it).
      if (agent_ptr->GetID() == client_id) { continue; }

      AddConfiguredAgent(std::move(agent_ptr));
    }

    // find end of agent_set deserialization
    std::getline(is, read, '\n');
    if (read != ":::END agent_set") {
      std::cerr << "Could not find end of agent_set serialization" << std::endl;
      return;
    }
  }

  void SerializeItemSet(std::ostream &os) {
    os << ":::START item_set\n";
    SerializeValue(os, item_map.size());

    for (const auto &item : item_map) {
      item.second->Serialize(os);
    }
    os << ":::END item_set\n";
  }

  void DeserializeItemSet(std::istream &is) {
    // find beginning of item_set serialization
    std::string read;
    std::getline(is, read, '\n');
    if (read != ":::START item_set") {
      std::cerr << "Could not find start of item_set serialization" << std::endl;
      return;
    }

    // how many items?
    size_t size;
    DeserializeValue(is, size);

    // read each item
    for (size_t i = 0; i < size; i++) {
      auto item = std::make_unique<ItemBase>(agent_map.size() + i, "");
      DeserializeValue(is, *item);
      AddItem(std::move(item));
    }

    // find end of item_set serialization
    std::getline(is, read, '\n');
    if (read != ":::END item_set") {
      std::cerr << "Could not find end of item_set serialization" << std::endl;
      return;
    }
  }

  void Serialize(std::ostream &os) {
    main_grid.Serialize(os);
    SerializeAgentSet(os);
    SerializeItemSet(os);
  }

  void Deserialize(std::istream &is, netWorth::ClientManager *manager) {
    main_grid.Deserialize(is);
    DeserializeAgentSet(is, manager);
    DeserializeItemSet(is);
  }

  // Needs access to most things here so this is easiest way to do so
  friend worldlang::ProgramExecutor;
};

}  // End of namespace cse491

```

