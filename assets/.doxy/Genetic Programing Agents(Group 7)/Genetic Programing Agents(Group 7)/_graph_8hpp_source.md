

# File Graph.hpp

[**File List**](files.md) **>** [**Agents**](dir_425e53e3c77c59c8573ea1fd0ff9622a.md) **>** [**GP**](dir_24320de467b989ce68b31a9ae5cbbd05.md) **>** [**Graph.hpp**](_graph_8hpp.md)

[Go to the documentation of this file](_graph_8hpp.md)

```C++


#pragma once

#include <algorithm>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

#include "../../core/AgentBase.hpp"
#include "../AgentLibary.hpp"
#include "GraphNode.hpp"

namespace cowboys {
  using GraphLayer = std::vector<std::shared_ptr<GraphNode>>;

  class Graph {
  protected:
    std::vector<GraphLayer> layers;

  public:
    Graph() = default;
    ~Graph() = default;

    size_t GetNodeCount() const {
      return std::accumulate(layers.cbegin(), layers.cend(), 0,
                             [](size_t sum, const auto &layer) { return sum + layer.size(); });
    }

    size_t GetLayerCount() const { return layers.size(); }

    size_t MakeDecision(const std::vector<double> &inputs, const std::vector<size_t> &actions) {
      if (layers.size() == 0)
        return actions.at(0);

      // Set inputs of input layer
      size_t i = 0;
      for (auto &node : layers[0]) {
        double input = 0;
        if (i < inputs.size())
          input = inputs.at(i);
        node->SetDefaultOutput(input);
        ++i;
      }

      // Get output of last layer
      std::vector<double> outputs;
      for (auto &node : layers.back()) {
        outputs.push_back(node->GetOutput());
      }

      // Choose the action with the highest output
      auto max_output = std::max_element(outputs.cbegin(), outputs.cend());
      size_t index = std::distance(outputs.cbegin(), max_output);

      // If index is out of bounds, return the last action
      size_t action = 0;
      if (index >= actions.size())
        action = actions.back();
      else // Otherwise, return the action at the index
        action = actions.at(index);
      return action;
    }

    void AddLayer(const GraphLayer &layer) { layers.push_back(layer); }

    std::vector<std::shared_ptr<GraphNode>> GetFunctionalNodes() const {
      std::vector<std::shared_ptr<GraphNode>> functional_nodes;
      for (size_t i = 1; i < layers.size(); ++i) {
        functional_nodes.insert(functional_nodes.cend(), layers.at(i).cbegin(), layers.at(i).cend());
      }
      return functional_nodes;
    }

    std::vector<std::shared_ptr<GraphNode>> GetNodes() const {
      std::vector<std::shared_ptr<GraphNode>> all_nodes;
      for (auto &layer : layers) {
        all_nodes.insert(all_nodes.cend(), layer.cbegin(), layer.cend());
      }
      return all_nodes;
    }
  };

  std::vector<size_t> EncodeActions(const std::unordered_map<std::string, size_t> &action_map) {
    std::vector<size_t> actions;
    for (const auto &[action_name, action_id] : action_map) {
      actions.push_back(action_id);
    }
    // Sort the actions so that they are in a consistent order.
    std::sort(actions.begin(), actions.end());
    return actions;
  }

  std::vector<double> EncodeState(const cse491::WorldGrid &grid, const cse491::type_options_t & /*type_options*/,
                                  const cse491::item_map_t & /*item_set*/, const cse491::agent_map_t & /*agent_set*/,
                                  const cse491::AgentBase *agent,
                                  const std::unordered_map<std::string, double> &extra_agent_state) {
    std::vector<double> inputs;

    auto current_position = agent->GetPosition();

    double current_state = grid.At(current_position);
    double above_state = grid.IsValid(current_position.Above()) ? grid.At(current_position.Above()) : 0.;
    double below_state = grid.IsValid(current_position.Below()) ? grid.At(current_position.Below()) : 0.;
    double left_state = grid.IsValid(current_position.ToLeft()) ? grid.At(current_position.ToLeft()) : 0.;
    double right_state = grid.IsValid(current_position.ToRight()) ? grid.At(current_position.ToRight()) : 0.;

    double prev_action = extra_agent_state.at("previous_action");
    double starting_x = extra_agent_state.at("starting_x");
    double starting_y = extra_agent_state.at("starting_y");
    auto starting_pos = cse491::GridPosition(starting_x, starting_y);
    auto path = walle::GetShortestPath(agent->GetPosition(), starting_pos, agent->GetWorld(), *agent);
    double distance_from_start = path.size();

    inputs.insert(inputs.end(), {prev_action, starting_x, starting_y, distance_from_start, current_state, above_state, below_state, left_state, right_state});

    return inputs;
  }

} // namespace cowboys

```

