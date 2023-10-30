/**
 * This file is part of the Fall 2023, CSE 491 course project.
 * @brief An Agent based on genetic programming.
 * @note Status: PROPOSAL
 **/

#pragma once

#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <unordered_map>

#include "GPAgent_.hpp"
#include "GraphBuilder.hpp"

namespace cowboys {
  /// Don't know the maximum size a state can be, arbitrary large number
  constexpr size_t INPUT_SIZE = 10;

  /// Number of computational layers for each agent
  constexpr size_t NUM_LAYERS = 5;

  /// The number of nodes in each layer
  constexpr size_t NUM_NODES_PER_LAYER = 10;

  /// The number of inputs for each node
  constexpr size_t NUM_NODE_INPUTS = 10;

  /// The number of layers preceding a node's layer that the node can reference
  constexpr size_t LAYERS_BACK = 2;

  /// @brief An agent based on cartesian genetic programming.
  class CGPAgent : public GPAgent_ {
  protected:
    /// The genotype for this agent.
    CGPGenotype genotype;

    /// The decision graph for this agent.
    std::unique_ptr<Graph> decision_graph;

  public:
    CGPAgent(size_t id, const std::string &name) : GPAgent_(id, name) {}
    CGPAgent(size_t id, const std::string &name, const CGPGenotype &genotype)
        : GPAgent_(id, name), genotype(genotype) {}

    /// @brief Setup graph.
    /// @return Success.
    bool Initialize() override {
      auto graph_builder = GraphBuilder();

      // Create a default genotype if one wasn't provided
      if (genotype.GetNumFunctionalNodes() == 0) {
        genotype = CGPGenotype({INPUT_SIZE, action_map.size(), NUM_LAYERS, NUM_NODES_PER_LAYER, LAYERS_BACK}).MutateDefault(0.2);
      }

      // Initialize the decision graph
      decision_graph = graph_builder.CartesianGraph(genotype, FUNCTION_SET);
      return true;
    }

    size_t GetAction(const cse491::WorldGrid &grid, const cse491::type_options_t &type_options,
                     const cse491::item_set_t &item_set, const cse491::agent_set_t &agent_set) override {
      auto inputs = EncodeState(grid, type_options, item_set, agent_set, this, extra_state);
      size_t action_to_take = decision_graph->MakeDecision(inputs, EncodeActions(action_map));
      return action_to_take;
    }

    /// @brief Get the genotype for this agent.
    /// @return A const reference to the genotype for this agent.
    const CGPGenotype &GetGenotype() const { return genotype; }
  };

} // End of namespace cowboys