

# File GraphNode.hpp

[**File List**](files.md) **>** [**Agents**](dir_425e53e3c77c59c8573ea1fd0ff9622a.md) **>** [**GP**](dir_24320de467b989ce68b31a9ae5cbbd05.md) **>** [**GraphNode.hpp**](_graph_node_8hpp.md)

[Go to the documentation of this file](_graph_node_8hpp.md)

```C++

#pragma once

// Macro for parallel execution, add -DPARALLEL flag to CMAKE_CXX_FLAGS when building to enable
#if PARALLEL
#include <execution>
#define PAR std::execution::par,
#else
#define PAR
#endif

#include <algorithm>
#include <array>
#include <cmath>
#include <execution>
#include <functional>
#include <limits>
#include <memory>
#include <numeric>
#include <optional>
#include <ranges>
#include <stdexcept>
#include <string>
#include <vector>

#include "../../core/AgentBase.hpp"
#include "../../core/WorldBase.hpp"
#include "../AgentLibary.hpp"
#include "GPAgentSensors.hpp"

namespace cowboys {
  class GraphNode; 
  using InnerFunction = double (*)(const GraphNode &, const cse491::AgentBase &);
  struct NodeFunction {
    InnerFunction function{nullptr};
    const cse491::AgentBase *agent{nullptr};
    double operator()(const GraphNode &node) const { return function(node, *agent); }
    bool IsNull() const { return function == nullptr; }
  };

  class GraphNode : public std::enable_shared_from_this<GraphNode> {
  protected:
    std::vector<std::shared_ptr<GraphNode>> inputs;

    NodeFunction function_pointer;

    double default_output{0};

    std::vector<GraphNode *> outputs;

    mutable double cached_output{0};

    mutable bool cached_output_valid{false};

    void AddOutput(GraphNode *node) { outputs.push_back(node); }

    void RecursiveInvalidateCache() const {
      cached_output_valid = false;
      for (auto &output : outputs) {
        output->RecursiveInvalidateCache();
      }
    }

  public:
    GraphNode() = default;
    ~GraphNode() = default;

    GraphNode(double default_value) : default_output{default_value} {}
    GraphNode(NodeFunction function) : function_pointer{function} {}
    GraphNode(InnerFunction function) : function_pointer{function} {}

    double GetOutput() const {
      if (cached_output_valid)
        return cached_output;

      double result = default_output;
      // Invoke function pointer if it exists
      if (!function_pointer.IsNull()) {
        result = function_pointer(*this);
      }

      // Cache the output
      cached_output = result;
      cached_output_valid = true;

      return result;
    }

    std::vector<double> GetInputValues() const {
      std::vector<double> values;
      values.reserve(inputs.size());
      std::transform(inputs.cbegin(), inputs.cend(), std::back_inserter(values),
                     [](const auto &node) { return node->GetOutput(); });
      return values;
    }

    template <size_t N> std::optional<std::vector<double>> GetInputValues(const std::array<size_t, N> &indices) const {
      size_t max_index = *std::max_element(indices.cbegin(), indices.cend());
      if (max_index >= inputs.size())
        return std::nullopt;
      std::vector<double> values;
      values.reserve(N);
      std::transform(indices.cbegin(), indices.cend(), std::back_inserter(values),
                     [this](const auto &index) { return inputs.at(index)->GetOutput(); });
      return values;
    }

    void SetFunctionPointer(NodeFunction function) {
      function_pointer = function;
      RecursiveInvalidateCache();
    }

    void SetFunctionPointer(InnerFunction inner_function) {
      function_pointer = NodeFunction{inner_function};
      RecursiveInvalidateCache();
    }

    void AddInput(std::shared_ptr<GraphNode> node) {
      inputs.push_back(node);
      // Add a weak pointer to this node to the input node's outputs
      node->AddOutput(this);
      RecursiveInvalidateCache();
    }

    void AddInputs(const std::vector<std::shared_ptr<GraphNode>> &nodes) {
      inputs.insert(inputs.cend(), nodes.cbegin(), nodes.cend());
      RecursiveInvalidateCache();
    }

    void SetInputs(std::vector<std::shared_ptr<GraphNode>> nodes) {
      inputs = nodes;
      RecursiveInvalidateCache();
    }

    void SetDefaultOutput(double value) {
      if (default_output != value) {
        default_output = value;
        RecursiveInvalidateCache();
      }
    }

    double GetDefaultOutput() const { return default_output; }

    bool IsCacheValid() const { return cached_output_valid; }
  };

  double Sum(const GraphNode &node, const cse491::AgentBase &) {
    auto vals = node.GetInputValues();
    return std::reduce(PAR vals.cbegin(), vals.cend(), 0.);
  }

  double And(const GraphNode &node, const cse491::AgentBase &) {
    auto vals = node.GetInputValues();
    return std::any_of(vals.cbegin(), vals.cend(), [](const double val) { return val == 0.; }) ? 0. : 1.;
  }

  double AnyEq(const GraphNode &node, const cse491::AgentBase &) {
    std::vector<double> vals = node.GetInputValues();
    if (vals.size() == 0)
      return node.GetDefaultOutput();
    for (size_t i = 1; i < vals.size(); ++i) {
      if (vals.at(0) == vals.at(i))
        return 1.;
    }
    return 0.;
  }

  double Not(const GraphNode &node, const cse491::AgentBase &) {
    auto vals = node.GetInputValues<1>(std::array<size_t, 1>{0});
    if (!vals.has_value())
      return node.GetDefaultOutput();
    return (*vals)[0] == 0. ? 1. : 0.;
  }

  double Gate(const GraphNode &node, const cse491::AgentBase &) {
    auto vals = node.GetInputValues<2>(std::array<size_t, 2>{0, 1});
    if (!vals.has_value())
      return node.GetDefaultOutput();
    return (*vals)[1] != 0. ? (*vals)[0] : 0.;
  }

  double Sin(const GraphNode &node, const cse491::AgentBase &) {
    std::vector<double> vals = node.GetInputValues();
    return std::transform_reduce(PAR vals.cbegin(), vals.cend(), 0., std::plus{},
                                 [](const double val) { return std::sin(val); });
  }

  double Cos(const GraphNode &node, const cse491::AgentBase &) {
    std::vector<double> vals = node.GetInputValues();
    return std::transform_reduce(PAR vals.cbegin(), vals.cend(), 0., std::plus{},
                                 [](const double val) { return std::cos(val); });
  }

  double Product(const GraphNode &node, const cse491::AgentBase &) {
    auto vals = node.GetInputValues();
    return std::reduce(PAR vals.cbegin(), vals.cend(), 1., std::multiplies{});
  }

  double Reciprocal(const GraphNode &node, const cse491::AgentBase &) {
    auto vals = node.GetInputValues();
    return std::transform_reduce(PAR vals.cbegin(), vals.cend(), 0., std::plus{},
                                 [](const double val) { return 1. / (val + std::numeric_limits<double>::epsilon()); });
  }

  double Exp(const GraphNode &node, const cse491::AgentBase &) {
    std::vector<double> vals = node.GetInputValues();
    return std::transform_reduce(PAR vals.cbegin(), vals.cend(), 0., std::plus{},
                                 [](const double val) { return std::exp(val); });
  }

  double LessThan(const GraphNode &node, const cse491::AgentBase &) {
    std::vector<double> vals = node.GetInputValues();
    return std::is_sorted(vals.begin(), vals.end(), std::less{});
  }

  double GreaterThan(const GraphNode &node, const cse491::AgentBase &) {
    std::vector<double> vals = node.GetInputValues();
    return std::is_sorted(vals.begin(), vals.end(), std::greater{});
  }

  double Max(const GraphNode &node, const cse491::AgentBase &) {
    std::vector<double> vals = node.GetInputValues();
    if (vals.empty())
      return node.GetDefaultOutput();
    return *std::max_element(vals.cbegin(), vals.cend());
  }

  double Min(const GraphNode &node, const cse491::AgentBase &) {
    std::vector<double> vals = node.GetInputValues();
    if (vals.empty())
      return node.GetDefaultOutput();
    return *std::min_element(vals.cbegin(), vals.cend());
  }

  double NegSum(const GraphNode &node, const cse491::AgentBase &agent) { return -Sum(node, agent); }

  double Square(const GraphNode &node, const cse491::AgentBase &) {
    std::vector<double> vals = node.GetInputValues();
    return std::transform_reduce(PAR vals.cbegin(), vals.cend(), 0., std::plus{},
                                 [](const double val) { return val * val; });
  }

  double PosClamp(const GraphNode &node, const cse491::AgentBase &) {
    std::vector<double> vals = node.GetInputValues();
    return std::transform_reduce(PAR vals.cbegin(), vals.cend(), 0., std::plus{},
                                 [](const double val) { return std::max(0., val); });
  }

  double NegClamp(const GraphNode &node, const cse491::AgentBase &) {
    std::vector<double> vals = node.GetInputValues();
    return std::transform_reduce(PAR vals.cbegin(), vals.cend(), 0., std::plus{},
                                 [](const double val) { return std::min(0., val); });
  }

  double Sqrt(const GraphNode &node, const cse491::AgentBase &) {
    std::vector<double> vals = node.GetInputValues();
    return std::transform_reduce(PAR vals.cbegin(), vals.cend(), 0., std::plus{},
                                 [](const double val) { return std::sqrt(std::max(0., val)); });
  }

  double WallDistanceUp(const GraphNode &, const cse491::AgentBase &agent) {
    return Sensors::wallDistance(agent.GetWorld().GetGrid(), agent, SensorDirection::ABOVE);
  }

  double WallDistanceDown(const GraphNode &, const cse491::AgentBase &agent) {
    return Sensors::wallDistance(agent.GetWorld().GetGrid(), agent, SensorDirection::BELOW);
  }

  double WallDistanceLeft(const GraphNode &, const cse491::AgentBase &agent) {
    return Sensors::wallDistance(agent.GetWorld().GetGrid(), agent, SensorDirection::LEFT);
  }

  double WallDistanceRight(const GraphNode &, const cse491::AgentBase &agent) {
    return Sensors::wallDistance(agent.GetWorld().GetGrid(), agent, SensorDirection::RIGHT);
  }

  double AStarDistance(const GraphNode &node, const cse491::AgentBase &agent) {
    //
    // The outputs of the first two connections are the x and y coordinates of the goal position. It'd probably be rare
    // for agents to randomly use it in a useful way. Most of the time when it IS used, there is no input connections
    // and thus the default output is used, so it isn't REALLY being used. Other times when it does have input
    // connections, the agent has a lower fitness, so it probably wasn't making good use of it.
    //
    // Decided to make an easier way A* can be used by agents by giving the A* distance from the agent's start position
    // as an input. This can still be used in the off chance it is useful.
    auto vals = node.GetInputValues<2>(std::array<size_t, 2>{0, 1});
    if (!vals.has_value())
      return node.GetDefaultOutput();
    auto vals2 = *vals;
    auto goal_position = cse491::GridPosition(vals2[0], vals2[1]);
    auto path = walle::GetShortestPath(agent.GetPosition(), goal_position, agent.GetWorld(), agent);
    return path.size();
  }

  static const std::vector<InnerFunction> NODE_FUNCTION_SET{
      nullptr,  Sum,         And, AnyEq, Not,    Gate,   Sin,      Cos,      Product, Exp,
      LessThan, GreaterThan, Max, Min,   NegSum, Square, PosClamp, NegClamp, Sqrt};
  static const std::vector<InnerFunction> SENSOR_FUNCTION_SET{WallDistanceUp, WallDistanceDown, WallDistanceLeft,
                                                              WallDistanceRight, AStarDistance};

  static const std::vector<InnerFunction> FUNCTION_SET = []() {
    std::vector<InnerFunction> functions;
    functions.reserve(NODE_FUNCTION_SET.size() + SENSOR_FUNCTION_SET.size());
    functions.insert(functions.cend(), NODE_FUNCTION_SET.cbegin(), NODE_FUNCTION_SET.cend());
    functions.insert(functions.cend(), SENSOR_FUNCTION_SET.cbegin(), SENSOR_FUNCTION_SET.cend());
    return functions;
  }();
} // namespace cowboys

```

