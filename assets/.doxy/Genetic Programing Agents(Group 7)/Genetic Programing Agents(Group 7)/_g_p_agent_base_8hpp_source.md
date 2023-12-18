

# File GPAgentBase.hpp

[**File List**](files.md) **>** [**Agents**](dir_425e53e3c77c59c8573ea1fd0ff9622a.md) **>** [**GP**](dir_24320de467b989ce68b31a9ae5cbbd05.md) **>** [**GPAgentBase.hpp**](_g_p_agent_base_8hpp.md)

[Go to the documentation of this file](_g_p_agent_base_8hpp.md)

```C++


#pragma once

#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <unordered_map>

#include "tinyxml2.h"

#include "../../core/AgentBase.hpp"

namespace cowboys {
  class GPAgentBase : public cse491::AgentBase {
  protected:
    std::unordered_map<std::string, double> extra_state; 
    unsigned int seed = 0;                               
    std::mt19937 rng{seed};                              
    std::uniform_real_distribution<double> uni_dist;     
    std::normal_distribution<double> norm_dist;          

  public:
    GPAgentBase(size_t id, const std::string &name) : AgentBase(id, name) {
      Reset();
    }
    ~GPAgentBase() = default;

    bool Initialize() override { return true; }

    size_t SelectAction(const cse491::WorldGrid &grid, const cse491::type_options_t &type_options,
                        const cse491::item_map_t &item_set, const cse491::agent_map_t &agent_set) override {
      // Update extra state information before action
      if (extra_state["starting_x"] == std::numeric_limits<double>::max()) {
        auto pos = GetPosition();
        extra_state["starting_x"] = pos.GetX();
        extra_state["starting_y"] = pos.GetY();
      }

      size_t action = GetAction(grid, type_options, item_set, agent_set);

      // Update extra state information after action
      extra_state["previous_action"] = action;

      return action;
    }

    virtual size_t GetAction(const cse491::WorldGrid &grid, const cse491::type_options_t &type_options,
                             const cse491::item_map_t &item_set, const cse491::agent_map_t &agent_set) = 0;

    const std::unordered_map<std::string, double> GetExtraState() const { return extra_state; }

    virtual void MutateAgent(double mutation_rate = 0.8) = 0;

    virtual void Copy(const GPAgentBase &other) = 0;

    virtual void PrintAgent(){

    };

    virtual void SerializeGP(tinyxml2::XMLDocument &doc, tinyxml2::XMLElement *parentElem, double fitness = -1) = 0;

    virtual std::string Export() { return ""; }

    virtual void Reset(bool /*hard*/ = false) {
      extra_state["previous_action"] = 0;
      extra_state["starting_x"] = std::numeric_limits<double>::max();
      extra_state["starting_y"] = std::numeric_limits<double>::max();
    };

    //    virtual void crossover(const GPAgentBase &other) {};
    virtual void Import(const std::string &genotype) = 0;

    // -- Random Number Generation --

    void SetSeed(unsigned int seed) {
      this->seed = seed;
      rng.seed(seed);
    }

    unsigned int GetSeed() const { return seed; }

    double GetRandom() { return uni_dist(rng); }

    double GetRandom(double max) { return GetRandom() * max; }

    double GetRandom(double min, double max) {
      assert(max > min);
      return min + GetRandom(max - min);
    }

    size_t GetRandomULL(size_t max) { return static_cast<size_t>(GetRandom(max)); }

    double GetRandomNormal() { return norm_dist(rng); }

    double GetRandomNormal(double mean, double sd = 1.0) {
      assert(sd > 0);
      return mean + norm_dist(rng) * sd;
    }
  };

} // End of namespace cowboys

```

