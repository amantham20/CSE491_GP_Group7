/**
 * @file SecondWorld.hpp
 * @author Jayson Van Dam
 * @author Kurt LaBlanc
 * @author Satvik Ravipati
 */

#pragma once
#include <algorithm>
#include <nlohmann/json.hpp>

#include "../Agents/PacingAgent.hpp"
#include "../core/WorldBase.hpp"
#include "ProgramExecutor.hpp" //< for attack, item scripts

#include <algorithm>

using cse491::CellType;

namespace group4 {
/// @brief Filename for the first floor grid file
const std::string FIRST_FLOOR_FILENAME = "../assets/grids/group4_maze.grid";

/// @brief Filename for the second floor grid file
const std::string SECOND_FLOOR_FILENAME = "../assets/grids/second_floor.grid";

/// @brief Filename for the last floor grid file
const std::string FINAL_FLOOR_FILENAME = "../assets/grids/third_floor.grid";

/// @brief Filename for item pickup script
///
/// This script modifies properties of the agent collecting the item.
const std::string ITEM_PICKUP_SCRIPT = "../assets/scripts/g4_item_pickup.ws";

/// @brief Filename for agent combat script
/// 
/// When an agent attempts to move into another agent, this attack script runs.
const std::string COMBAT_SCRIPT = "../assets/scripts/g4_agent_attack.ws";

/// @brief Filename for world initialization script
const std::string WORLD_LOAD_SCRIPT = "../assets/scripts/g4_world_load.ws";

/// @brief Filename for second floor initialization script
const std::string WORLD_LOAD_SCRIPT_2 = "../assets/scripts/g4_world_2_load.ws";

/// @brief Filename for final floor initialization script
const std::string WORLD_LOAD_SCRIPT_3 = "../assets/scripts/g4_world_3_load.ws";

/**
 * Creates a world with agents and a win flag
 */
class SecondWorld : public cse491::WorldBase {
 private:
  /// @brief File name for this world grid. Switched when the player gets to the
  /// next level.
  std::string world_filename = "";

  /// @brief File name for agent input JSON file.
  std::string agents_filename = "";

  /**
   * Switches to the next grid file
   * and resets player position and item map.
   * @param agent The player agent
   * @param pos The player position
   */
  void SwitchGrid(cse491::AgentBase& agent, cse491::GridPosition& pos) {
    // Need to clear item_map so that items don't stay for the next floor.
    // Don't clear items held in an inventory.
    // TODO: How do chests interfere with this?
    // this is more or less the example from https://en.cppreference.com/w/cpp/container/map/erase
    for (auto it = item_map.begin(); it != item_map.end(); ){
    	auto& item = it->second;
    	if (item->IsOnGrid()) {
    		// clear this item
    		it = item_map.erase(it);
    	} else if (item->IsOwnedByItem()){
    		// it's owned by a chest: this is currently the only item containing items
    		it = item_map.erase(it);
    	} else {
    		++it;
    	}
    }

    if (world_filename == FIRST_FLOOR_FILENAME) {
      pe.runFile(WORLD_LOAD_SCRIPT_2);
      agents_filename = "../assets/second_floor_input.json";
    } else if (world_filename == SECOND_FLOOR_FILENAME) {
      pe.runFile(WORLD_LOAD_SCRIPT_3);
      agents_filename = "../assets/third_floor_input.json";
    }

    agent.Notify("Going to " + world_filename, "world_switched");

    // Resetting the current new_position to the top left of the new grid.
    pos = cse491::GridPosition(0, 0);
    LoadFromFile(agents_filename);
  }

 protected:
  enum ActionType {
    REMAIN_STILL = 0,
    MOVE_UP,
    MOVE_DOWN,
    MOVE_LEFT,
    MOVE_RIGHT,
    DROP_ITEM,
    WARP_TO_FLOOR_3  // New action for hidden warp tile
  };

  /// Easy access to floor CellType ID.
  size_t floor_id;

  /// Easy access to flag CellType ID.
  size_t flag_id;

  /// Easy access to wall CellType ID.
  size_t wall_id;

  /// Easy access to warp CellType ID.
  size_t hidden_warp_id;

  /// Script executor object.
  worldlang::ProgramExecutor pe;

  /// Vector of the items in this world
  std::map<size_t, std::unique_ptr<cse491::ItemBase>> inventory;

  /// Provide the agent with movement actions.
  void ConfigAgent(cse491::AgentBase& agent) override {
    agent.AddAction("up", MOVE_UP);
    agent.AddAction("down", MOVE_DOWN);
    agent.AddAction("left", MOVE_LEFT);
    agent.AddAction("right", MOVE_RIGHT);
    agent.AddAction("drop", DROP_ITEM);
    // Add the new action for the hidden warp tile
    agent.AddAction("warp", WARP_TO_FLOOR_3);
  }

 public:
  /**
   * Constructor with no arguments
   */
  SecondWorld() : world_filename(FIRST_FLOOR_FILENAME), pe{*this}{
    pe.runFile(WORLD_LOAD_SCRIPT);
  }

  /**
   * Constructor with grid and agent file names
   * @param grid_filename Relative path to grid file
   * @param agent_filename Relative path to agent input.json file
   */
  SecondWorld(std::string grid_filename, std::string agent_filename)
      : world_filename(grid_filename), agents_filename(agent_filename), 
      pe{*this}{
    floor_id =
        AddCellType("floor", "Floor that you can easily walk over.", ' ');
    flag_id = AddCellType("flag", "Goal flag for a game end state", 'g');
    wall_id = AddCellType(
        "wall", "Impenetrable wall that you must find a way around.", '#');
    hidden_warp_id = AddCellType(
        "hidden_warp", "Hidden warp tile that warps to floor 3.", 'u');

    main_grid.Read(grid_filename, type_options);
    LoadFromFile(agent_filename);
  }

  /**
   * Destructor
   */
  ~SecondWorld() = default;

  /**
   * Loads data from a JSON file
   * and adds agents with specified properties into the world.
   * @param input_filename Relative path to input.json file
   */
  void LoadFromFile(const std::string& input_filename) {
    std::ifstream input_file(input_filename);

    if (!input_file.is_open()) {
      std::cerr << "Error: could not open file " << input_filename << std::endl;
      return;
    }

    nlohmann::json data;
    try {
      input_file >> data;
    } catch (const nlohmann::json::parse_error& err) {
      std::cerr << "JSON parsing error: " << err.what() << std::endl;
      return;
    }

    /// The base max health for an agent.
    /// Can be added to by giving the agent specific items,
    /// such as "chocolate_bar", that are specified below.
    const int BASE_MAX_HEALTH = 100;
    for (const auto& agent : data) {
      // May get a json.exception.type_error here if you assign to the wrong C++
      // type, so make sure to nail down what types things are in JSON first! My
      // intuition is that each agent object will have: name: string (C++
      // std::string) x: number (C++ int) y: number (C++ int) entities:
      // array<string> (C++ std::vector<std::string>)
      std::string agent_name = agent.at("name");
      int x_pos = agent.at("x");
      int y_pos = agent.at("y");

      int additional_max_health = 0;
      std::vector<std::string> entities = agent.at("entities");

      for (const auto& entity : entities) {
        // TODO: How should we set the entity properties here?
        // Just adding to MaxHealth now, but this doesn't seem very scalable.
        if (entity == "chocolate_bar") {
          additional_max_health = 10;
        }
      }

      AddAgent<cse491::PacingAgent>(agent_name)
          .SetPosition(x_pos, y_pos)
          .SetProperty("Health", BASE_MAX_HEALTH + additional_max_health);
    }
  }

  /**
   * This function gives us an output.json file
   */
  virtual void Run() override {
    while (!run_over) {
      RunAgents();
    }

    SaveToFile();
  }

  /**
   * This function gives us an output.json file using nlohmann::json library
   */
  void SaveToFile() {
    nlohmann::json output_data;  // json to store the data being outputted

    for (const auto& [agent_id, agent_ptr] : agent_map) {
      auto new_position = agent_ptr->GetPosition();
      std::string agent_name = agent_ptr->GetName();
      double x_pos = new_position.GetX();
      double y_pos = new_position.GetY();

      nlohmann::json agent_data;  // json for each agent
      agent_data["name"] = agent_name;
      agent_data["x"] = x_pos;
      agent_data["y"] = y_pos;

      output_data.push_back(agent_data);  // add it to the json array
    }

    std::ofstream ofs("output.json");  // save it to a file called output.json
    ofs << output_data.dump(2);        // indentation
  }

  /**
   * Drops the item in the agent's inventory
   * @param agent This agent's item we're dropping
   * @param pos The position where the item will be dropped
   */
  void DropItem(cse491::AgentBase& agent, cse491::GridPosition& pos) {

      if (agent.GetInventory().empty()) {
        agent.Notify("Cannot drop any items, inventory is empty.", "item_alert");

    } else {
        // TODO: Remove the item that the agent has selected in his hot bar, instead
        //  of the first item in the agent's inventory
        // Get the item from the SecondWorld inventory
        auto& item = GetItem(agent.GetInventory().at(0));

        agent.Notify("Dropping " + item.GetName(), "item_alert");

        // Set the position and remove item from agent's inventory
        item.SetPosition(pos);
        agent.RemoveItem(item.GetID());

        // Must set the grid back because RemoveItem() doesn't account for that
        item.SetGrid();

    }
  }

  /**
   * Checks to see if there is a flag or item at the agent's current position
   * @param agent The agent
   * @param pos The position
   */
  void CheckPosition(cse491::AgentBase& agent, cse491::GridPosition& pos) {
    // First check to see if agent is on win flag
    if ((type_options[main_grid.At(pos)].HasProperty("Goal")) && (agent.IsInterface())) {
      // Set win flag to true

      agent.Notify("Flag found ", "item_alert");

      agent.Notify("Leaving " + world_filename, "world_switched");

      if (world_filename == FIRST_FLOOR_FILENAME ||
          world_filename == SECOND_FLOOR_FILENAME) {
        // We are currently on floor 1 or 2,
        // so switch to the next world
        // and reset the item_map and player position.
        SwitchGrid(agent, pos);
      } else if (world_filename == FINAL_FLOOR_FILENAME) {
        agent.Notify("Congrats, you won the game!", "congrats_msg");
        run_over = true;
      }

      // then checks if agent is on any items
    } else if ((type_options[main_grid.At(pos)].HasProperty("Warp")) && (agent.IsInterface())) {
      // Agent used the hidden warp tile action
      std::cout << "Hidden warp tile activated! Warping to floor 3."
                << std::endl;

      agent.Notify("Leaving " + world_filename, "world_switched");

      // Update the world to floor 3
      world_filename = FINAL_FLOOR_FILENAME;
      agents_filename = "../assets/third_floor_input.json";

      // Clear item_map for the next floor
      item_map.clear();

      // Reset the current new_position to the top left of the new grid.
      pos = cse491::GridPosition(0, 0);
      main_grid.Read(FINAL_FLOOR_FILENAME, type_options);
      LoadFromFile(agents_filename);

      // Update the agent's position on the new floor
      agent.SetPosition(pos);

    } else {
      auto items_found = FindItemsAt(pos, 0);
      // If there are items at this position
      if (!items_found.empty() && agent.IsInterface()) {
        auto& item_found = GetItem(items_found.at(0));

        // Item is a chest
        if (item_found.HasProperty("Chest")) {

          // Check to see if the chest owns any items
          if (!item_found.GetInventory().empty()) {
            auto temp_inventory = item_found.GetInventory();
            agent.Notify("This is inside the chest: ", "item_alert");
            for (auto x : temp_inventory) {

              // TODO: Minor, but do we want to check if word starts with a vowel to change the wording before the constant?
              agent.Notify("You found the " + GetItem(x).GetName() + " in the " + item_found.GetName());

              agent.AddItem(GetItem(x));
              item_found.RemoveItem(GetItem(x));

            }

            // TODO: Need to determine max size of inventory
            if (agent.GetInventory().size() == 10) {
              agent.Notify(
                  "It looks like your inventory is full, please drop items or "
                  "place them in chests!",
                  "item_alert");
            }

          } else {
            agent.Notify(
                "The chest is empty! Do you want to store any items in here?",
                "item_alert");
          }

        } else {
          if (agent.GetInventory().size() == 10) {
            agent.Notify(
                "It looks like your inventory is full, please drop items or "
                "place them in chests!",
                "item_alert");
          } else {
            agent.Notify("You found " + item_found.GetName() + "!",
                         "item_alert");

            // Add item to the agent's inventory
            agent.AddItem(item_found.GetID());

            item_found.SetPosition(-1, -1);

          }
        }
      }
    }
  }

  /**
   * Allows agents to perform an action and sets each agent's new position
   * @param agent The agent performing the action
   * @param action_id The id that represents the move
   * @return An int that declares if the move is legal or illegal (true / false)
   */
  int DoAction(cse491::AgentBase& agent, size_t action_id) override {
    cse491::GridPosition new_position;
    bool IsDropped = false;
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
      case DROP_ITEM:
        new_position = agent.GetPosition();
        DropItem(agent, new_position);
        IsDropped = true;
        break;
    }

    if (!main_grid.IsValid(new_position)) {
      return false;
    }
    if (!IsTraversable(agent, new_position)){
      return false;
    }

    // At this point, new_position is valid and not going into a wall.
    // Check if there are any agents on this tile:
    auto res = this->FindAgentsAt(new_position);
    if (res.size() && res[0] != agent.GetID()){
        // At least one agent was found (and isn't the player)
        // Take the first agent and attack it.
        pe.setVariable("agent", agent.GetID());
        pe.setVariable("opponent", res[0]);
        pe.runFile(COMBAT_SCRIPT);
        
        // The movement was not legal, so we return false.
        // TODO: Should this return a status indicating that an attack occured,
        // to distinguish moves that do nothing from attacks?
        return false; 
    }
    

    if (!IsDropped) {
        CheckPosition(agent, new_position);
    }
    

    IsDropped = false;
    agent.SetPosition(new_position);
    return true;
  }

  /**
   * Prints the entities in item_set (testing)
   */
  void PrintEntities() {
    for (const auto& [id, item_ptr] : item_map) {
      if (!item_ptr) {
        continue;
      }
      std::cout << item_ptr->GetName() << "\n";
    }
    std::cout << std::endl;
  }
  
  	/// Can walk on all tiles except for walls and water (unless agent has property set)
	bool IsTraversable(const AgentBase & agent, cse491::GridPosition pos) const override {
		if (GetCellTypes().at(main_grid.At(pos)).HasProperty(CellType::CELL_WALL))
			return false;
		else if (GetCellTypes().at(main_grid.At(pos)).HasProperty(CellType::CELL_WATER))
			return agent.HasProperty("Swimmer");
		else
			return true;
	}
};
}  // namespace group4
