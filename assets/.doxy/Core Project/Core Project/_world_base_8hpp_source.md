

# File WorldBase.hpp

[**File List**](files.md) **>** [**core**](dir_0d27ce74e9bd514c31e1d63efab6b388.md) **>** [**WorldBase.hpp**](_world_base_8hpp.md)

[Go to the documentation of this file](_world_base_8hpp.md)

```C++


#pragma once

#include <cassert>
#include <memory>
#include <string>
#include <vector>

#include "AgentBase.hpp"
#include "Data.hpp"
#include "Entity.hpp"
#include "WorldGrid.hpp"

namespace cse491 {

  class WorldBase {
  protected:
    WorldGrid main_grid;
    type_options_t type_options; 

    item_set_t item_set;     
    agent_set_t agent_set;   

    bool run_over = false;   

    virtual void ConfigAgent(AgentBase & /* agent */) { }

    size_t AddCellType(const std::string & name, const std::string & desc="",
                           char symbol='\0') {
      type_options.push_back(CellType{name, desc, symbol});
      return type_options.size() - 1;
    }

  public:
    WorldBase() {
      // The first cell type (ID 0) should be reserved for errors or empty spots in a grid.
      AddCellType("Unknown", "This is an invalid cell type and should not be reachable.");
    }
    virtual ~WorldBase() = default;

    // -- Accessors --

    [[nodiscard]] size_t GetNumItems() const { return item_set.size(); }

    [[nodiscard]] size_t GetNumAgents() const { return agent_set.size(); }

    [[nodiscard]] Entity & GetItem(size_t id) {
      assert(id < item_set.size());
      return *item_set[id];
    }

    [[nodiscard]] AgentBase & GetAgent(size_t id) {
      assert(id < agent_set.size());
      return *agent_set[id];
    }

    virtual WorldGrid & GetGrid() { return main_grid; }

    virtual const WorldGrid & GetGrid() const { return main_grid; }

    virtual bool GetRunOver() const { return run_over; }

    // -- Agent Management --

    template <typename AGENT_T, typename... PROPERTY_Ts>
    AgentBase & AddAgent(std::string agent_name="None", PROPERTY_Ts... properties) {
      auto agent_ptr = std::make_unique<AGENT_T>(agent_set.size(), agent_name);
      agent_ptr->SetProperties(std::forward<PROPERTY_Ts>(properties)...);
      ConfigAgent(*agent_ptr);
      if (agent_ptr->Initialize() == false) {
        std::cerr << "Failed to initialize agent '" << agent_name << "'." << std::endl;
      }
      agent_set.emplace_back(std::move(agent_ptr));
      return *agent_set.back();
    }


    // -- Action Management --

    virtual int DoAction(AgentBase & agent, size_t action_id) = 0;

    virtual void RunAgents() {
      for (const auto & agent_ptr : agent_set) {
        size_t action_id =
          agent_ptr->SelectAction(main_grid, type_options, item_set, agent_set);
        int result = DoAction(*agent_ptr, action_id);
        agent_ptr->SetActionResult(result);
      }
    }

    virtual void UpdateWorld() { }

    virtual void Run() {
      run_over = false;
      while (!run_over) {
        RunAgents();
        UpdateWorld();
      }
    }

    // CellType management.

    // Return a const vector of all of the possible cell types.
    [[nodiscard]] const type_options_t & GetCellTypes() const { return type_options; }


    [[nodiscard]] size_t GetCellTypeID(const std::string & name) const { 
      for (size_t i=1; i < type_options.size(); ++i) {
        if (type_options[i].name == name) return i;
      }
      return 0;
    }

    [[nodiscard]] const std::string & GetCellTypeName(size_t id) const {
      if (id >= type_options.size()) return type_options[0].name;
      return type_options[id].name;
    }

    [[nodiscard]] char GetCellTypeSymbol(size_t id) const {
      if (id >= type_options.size()) return type_options[0].symbol;
      return type_options[id].symbol;
    }
  };

} // End of namespace cse491

```

