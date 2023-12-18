

# File CGPAgent.hpp

[**File List**](files.md) **>** [**Agents**](dir_425e53e3c77c59c8573ea1fd0ff9622a.md) **>** [**GP**](dir_24320de467b989ce68b31a9ae5cbbd05.md) **>** [**CGPAgent.hpp**](_c_g_p_agent_8hpp.md)

[Go to the documentation of this file](_c_g_p_agent_8hpp.md)

```C++


#pragma once

#include <cassert>
#include <iostream>
#include <map>
#include <random>
#include <string>

#include "GPAgentBase.hpp"
#include "GraphBuilder.hpp"

namespace cowboys {
  constexpr size_t INPUT_SIZE = 9;

  constexpr size_t NUM_LAYERS = 3;

  constexpr size_t NUM_NODES_PER_LAYER = 2;

  constexpr size_t LAYERS_BACK = 2;

  class CGPAgent : public GPAgentBase {
  protected:
    CGPGenotype genotype;

    std::unique_ptr<Graph> decision_graph;



  public:
    CGPAgent(size_t id, const std::string &name) : GPAgentBase(id, name) {}
    CGPAgent(size_t id, const std::string &name, const CGPGenotype &genotype)
        : GPAgentBase(id, name), genotype(genotype) {}


    void PrintAgent() override {
      std::cout << "Genotype: " << genotype.Export() << std::endl;
    }

    void MutateAgent(double mutation = 0.8) override {
      auto graph_builder = GraphBuilder();

      genotype.MutateDefault(mutation, *this);

      decision_graph = graph_builder.CartesianGraph(genotype, FUNCTION_SET, this);
    }
    bool Initialize() override {

      // Create a default genotype if none was provided in the constructor
      if (genotype.GetNumFunctionalNodes() == 0) {
        genotype = CGPGenotype({INPUT_SIZE, action_map.size(), NUM_LAYERS, NUM_NODES_PER_LAYER, LAYERS_BACK});
      }

      // Mutate the beginning genotype, might not want this.
      MutateAgent(0.2);

      return true;
    }

    size_t GetAction(const cse491::WorldGrid &grid, const cse491::type_options_t &type_options,
                     const cse491::item_map_t &item_set, const cse491::agent_map_t &agent_set) override {
      auto inputs = EncodeState(grid, type_options, item_set, agent_set, this, extra_state);
      size_t action_to_take = decision_graph->MakeDecision(inputs, EncodeActions(action_map));
      return action_to_take;
    }

    void SerializeGP(tinyxml2::XMLDocument &doc, tinyxml2::XMLElement *parentElem, double fitness = -1) override {
      auto agentElem = doc.NewElement("CGPAgent");
      parentElem->InsertEndChild(agentElem);

      auto genotypeElem = doc.NewElement("genotype");
      genotypeElem->SetText(genotype.Export().c_str());
      if (fitness != -1)
        genotypeElem->SetAttribute("fitness", fitness);

      genotypeElem->SetAttribute("seed" , seed);

      agentElem->InsertEndChild(genotypeElem);

    }

    std::string Export() override { return genotype.Export(); }

    void Import(const std::string &genotype) override {
      this->genotype.Configure(genotype);
      decision_graph = GraphBuilder().CartesianGraph(this->genotype, FUNCTION_SET, this);
    }

    const CGPGenotype &GetGenotype() const { return genotype; }


    void Configure(const CGPAgent &other) {
      genotype = other.GetGenotype();
      decision_graph = GraphBuilder().CartesianGraph(genotype, FUNCTION_SET, this);
    }

    void Copy(const GPAgentBase &other) override {
      assert(dynamic_cast<const CGPAgent *>(&other) != nullptr);
      Configure(dynamic_cast<const CGPAgent &>(other));
    }

    double GetComplexity() const {
      double connection_complexity =
          static_cast<double>(genotype.GetNumConnections()) / genotype.GetNumPossibleConnections();

      double functional_nodes = genotype.GetNumFunctionalNodes();

      // Just needed some function such that connection_complexity + node_complexity grows as the number of nodes grows, this function makes the increase more gradual.
      double node_complexity = std::log(functional_nodes) / 5;

      double complexity = connection_complexity + node_complexity;
      return complexity;
    }
  };

} // End of namespace cowboys

```

