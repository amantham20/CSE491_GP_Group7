#pragma once

#include <bitset>
#include <cassert>
#include <format>
#include <iostream>
#include <random>
#include <stdexcept>
#include <string>
#include <vector>

namespace cowboys {

  /// The separator between each parameter in the header, defining the cartesian graph.
  constexpr char HEADER_SEP = ',';
  /// The separator between the header and the genotype.
  constexpr char HEADER_END = ';';
  /// The separator between each attribute in a node.
  constexpr char NODE_GENE_SEP = '.';
  /// The separator between each node in the genotype.
  constexpr char NODE_SEP = ':';

  /// @brief A namespace for base64 encoding and decoding. Does not convert to and from base64 in the typical way. Only
  /// guarantees that x == b64_inv(b64(x)), aside from doubles which have problems with precision, so x ~=
  /// b64_inv(b64(x)).
  namespace base64 {
    /// The characters used to represent digits in base64.
    static std::string chars = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ+/";

    /// @brief Converts a number in base10 to base64.
    /// @param ull The number to convert.
    /// @return The number in base64 as a string.
    static std::string ULLToB64(size_t ull) {
      std::string result = "";
      if (ull == 0)
        return "0";
      while (ull > 0) {
        result = chars[ull % 64] + result;
        ull /= 64;
      }
      return result;
    }

    /// @brief Converts a number in base64 to base10.
    /// @param num_base64 The number in base64 as a string.
    /// @return The number in base10.
    static size_t B64ToULL(std::string num_base64) {
      size_t result = 0;
      for (size_t i = 0; i < num_base64.size(); ++i) {
        const char ch = num_base64[i];
        const size_t coeff = std::pow(64, num_base64.size() - i - 1);
        result += chars.find(ch) * coeff;
      }
      return result;
    }

    /// @brief Converts a binary string to a base64 string.
    /// @param binary A string of 1s and 0s representing binary.
    /// @return The binary string in base64.
    static std::string B2ToB64(const std::string &binary) {
      // 2^6 = 64, so we can encode 6 bits at a time

      size_t remainder = binary.size() % 6;
      if (remainder != 0) {
        // Pad the binary string with 0s to make it divisible by 6
        return B2ToB64(std::string(6 - remainder, '0') + binary);
      }

      std::string result = "";
      for (size_t i = 0; i < binary.size(); i += 6) {
        std::string buffer = binary.substr(i, 6);
        size_t ull = std::bitset<6>(buffer).to_ulong();
        result += chars[ull];
      }
      return result;
    }

    /// @brief Converts a base64 string to a binary string.
    /// @param base64 A string of base64 characters.
    /// @return The base64 string in binary.
    static std::string B64ToB2(std::string base64) {
      std::string result = "";
      for (size_t i = 0; i < base64.size(); ++i) {
        const char ch = base64[i];
        const size_t ull = chars.find(ch);
        result += std::bitset<6>(ull).to_string();
      }
      // Remove leading 0s and return result: https://stackoverflow.com/a/31226728/13430191
      return result.erase(0, std::min(result.find_first_not_of('0'), result.size() - 1));
    }

    /// @brief Converts a double to a base64 string. Assumes that the stoull(to_string(value)) is possible. Only
    /// guarantees that x ~= b64_inv(b64(x)) due to precision errors. Empirically accurate up to 3 decimal places, e.g.
    /// round(x, 3) = round(b64_inv(b64(x)), 3).
    /// @param value The double to convert.
    /// @return The double in base64.
    static std::string DoubleToB64(double value) {
      std::string double_str = std::to_string(value);

      // Sign
      // Store if it is positive or negative using the first base64 character or the second
      assert(chars.size() > 2);
      char sign_b64 = value < 0 ? chars[1] : chars[0];
      // Remove the negative sign if it exists
      if (value < 0)
        double_str.erase(0, 1);

      // Decimal point
      size_t decimal_loc = std::min(double_str.find('.'), double_str.size());
      // Remove the decimal point (does nothing if decimal_loc == double_str.size())
      double_str.erase(decimal_loc, 1);
      // Store decimal location using 1 base64 character (arbitrary choice, assumes decimal_loc < 64)
      char decimal_loc_b64 = chars[decimal_loc];

      // ULL
      // Take the rest of the string as a ULL
      size_t ull = std::stoull(double_str);
      // Convert to base64
      std::string ull_b64 = ULLToB64(ull);
      // Return decimal location and ULL
      return std::string({decimal_loc_b64, sign_b64}) + ull_b64;
    }

    /// @brief Converts a base64 string to a double. See @ref DoubleToB64 for precision issues.
    /// @param value The base64 string to convert.
    /// @return The base64 string as a double.
    static double B64ToDouble(const std::string &value) {
      assert(value.size() > 0);
      // Get decimal location
      size_t decimal_loc = chars.find(value[0]);
      // Get sign
      assert(chars.size() > 2);
      double sign = value[1] == chars[0] ? 1 : -1;
      // Get ULL
      std::string ull = std::to_string(B64ToULL(value.substr(2)));
      // Insert decimal point
      ull.insert(decimal_loc, ".");
      // Return double
      return sign * std::stod(ull);
    }
  } // namespace base64

  struct CGPNodeGene {
    /// The connections per node. '1' means connected, '0' means not connected.
    std::vector<char> input_connections{};

    /// The index of the function the node uses.
    size_t function_idx{0};

    /// The default output of the node.
    double default_output{0};

    /// @brief Compare two CGPNodeGenes for equality.
    /// @param other The other CGPNodeGene to compare to.
    /// @return True if the two CGPNodeGenes are equal, false otherwise.
    inline bool operator==(const CGPNodeGene &other) const {
      return input_connections == other.input_connections && function_idx == other.function_idx &&
             default_output == other.default_output;
    }
  };

  struct CGPParameters {
    /// The number of inputs to the graph.
    size_t num_inputs;
    /// The number of outputs from the graph.
    size_t num_outputs;
    /// The number of middle layers in the graph.
    size_t num_layers;
    /// The number of nodes per middle layer.
    size_t num_nodes_per_layer;
    /// The number of layers backward that a node can connect to.
    size_t layers_back;

    /// Default constructor
    CGPParameters() = default;

    /// Constructor for the cartesian graph parameters.
    CGPParameters(size_t num_inputs, size_t num_outputs, size_t num_layers, size_t num_nodes_per_layer,
                  size_t layers_back)
        : num_inputs(num_inputs), num_outputs(num_outputs), num_layers(num_layers),
          num_nodes_per_layer(num_nodes_per_layer), layers_back(layers_back) {}

    /// @brief Returns the number of functional nodes in the graph.
    /// @return The number of functional nodes in the graph.
    size_t GetFunctionalNodeCount() const { return num_layers * num_nodes_per_layer + num_outputs; }

    /// @brief Check if two CGPParameters are equal.
    /// @param other The other CGPParameters to compare to.
    /// @return True if the two CGPParameters are equal, false otherwise.
    inline bool operator==(const CGPParameters &other) const {
      return num_inputs == other.num_inputs && num_outputs == other.num_outputs && num_layers == other.num_layers &&
             num_nodes_per_layer == other.num_nodes_per_layer && layers_back == other.layers_back;
    }
  };

  class CGPGenotype {
  protected:
    /// The parameters of the cartesian graph.
    CGPParameters params;

    /// The node configurations.
    std::vector<CGPNodeGene> nodes;

    /// The random number generator.
    std::mt19937 rng;

  private:
    /// @brief Encodes the header into a string.
    /// @return The encoded header.
    std::string EncodeHeader() {
      return std::format("{}{}{}{}{}{}{}{}{}", params.num_inputs, HEADER_SEP, params.num_outputs, HEADER_SEP,
                         params.num_layers, HEADER_SEP, params.num_nodes_per_layer, HEADER_SEP, params.layers_back);
    }

    /// @brief Decodes the header of the genotype.
    void DecodeHeader(const std::string &header) {
      // Parse header and save to member variables
      std::vector<size_t> header_parts;
      size_t start_pos = 0;
      size_t comma_pos = header.find(HEADER_SEP, start_pos);
      while (comma_pos != std::string::npos) {
        header_parts.push_back(std::stoull(header.substr(start_pos, comma_pos - start_pos)));
        start_pos = comma_pos + 1;
        comma_pos = header.find(HEADER_SEP, start_pos);
      }
      header_parts.push_back(std::stoull(header.substr(start_pos)));

      if (header_parts.size() != 5)
        throw std::runtime_error(
            std::format("Invalid genotype: Header should have 5 parameters but found {}.", header_parts.size()));

      params.num_inputs = header_parts.at(0);
      params.num_outputs = header_parts.at(1);
      params.num_layers = header_parts.at(2);
      params.num_nodes_per_layer = header_parts.at(3);
      params.layers_back = header_parts.at(4);
    }

    /// @brief Encodes the genotype into a string.
    /// @return The encoded genotype.
    std::string EncodeGenotype() {
      std::string genotype = "";
      for (const CGPNodeGene &node : nodes) {
        // Input Connections
        genotype += base64::B2ToB64(std::string(node.input_connections.begin(), node.input_connections.end()));
        genotype += NODE_GENE_SEP;
        // Function index
        genotype += base64::ULLToB64(node.function_idx);
        genotype += NODE_GENE_SEP;
        // Default output
        genotype += base64::DoubleToB64(node.default_output);
        // End of node
        genotype += NODE_SEP;
      }
      return genotype;
    }

    /// @brief Decodes the genotype string and configures the node genes. Node gene vector should be initialized
    /// before calling this.
    void DecodeGenotype(const std::string &genotype) {
      size_t node_gene_start = 0;
      size_t node_gene_end = genotype.find(NODE_SEP, node_gene_start);
      size_t node_idx = 0;
      while (node_gene_end != std::string::npos) {
        // Parse the node gene
        std::string node_gene = genotype.substr(node_gene_start, node_gene_end - node_gene_start);
        assert(node_idx < nodes.size());
        auto &current_node = nodes[node_idx];

        //
        // Input Connections
        //
        size_t sep_pos = node_gene.find(NODE_GENE_SEP);
        assert(sep_pos != std::string::npos);
        std::string input_connections_b64 = node_gene.substr(0, sep_pos);
        std::string input_connections_b2 = base64::B64ToB2(input_connections_b64);
        auto &input_connections = current_node.input_connections;
        // If there were leading bits that were 0 when converted to base 64, they were dropped. Add them back.
        std::string input_connections_str = std::string(input_connections.cbegin(), input_connections.cend());
        assert(input_connections.size() >= input_connections_b2.size()); // Invalid genotype if this fails
        input_connections_b2 =
            std::string(input_connections.size() - input_connections_b2.size(), '0') + input_connections_b2;
        assert(input_connections.size() == input_connections_b2.size());
        for (size_t i = 0; i < input_connections_b2.size(); ++i) {
          input_connections[i] = input_connections_b2[i];
        }
        node_gene = node_gene.substr(sep_pos + 1);

        //
        // Function index
        //
        sep_pos = node_gene.find(NODE_GENE_SEP);
        std::string function_idx_str = node_gene.substr(0, std::min(sep_pos, node_gene.size()));
        current_node.function_idx = base64::B64ToULL(function_idx_str);
        node_gene = node_gene.substr(sep_pos + 1);

        //
        // Default output
        //
        sep_pos = node_gene.find(NODE_GENE_SEP);
        assert(sep_pos == std::string::npos); // Should be the last attribute
        std::string default_output_str = node_gene.substr(0, std::min(sep_pos, node_gene.size()));
        current_node.default_output = base64::B64ToDouble(default_output_str);

        // Move to next node gene
        node_gene_start = node_gene_end + 1;
        node_gene_end = genotype.find(NODE_SEP, node_gene_start);
        ++node_idx;
      }
    }

  public:
    CGPGenotype() = default;
    CGPGenotype(const CGPParameters &parameters) : params(parameters) { InitGenotype(); }
    ~CGPGenotype() = default;

    /// @brief Configures the genotype from the encoded string.
    /// @param encoded_genotype The encoded genotype.
    /// @return This genotype.
    CGPGenotype &Configure(const std::string &encoded_genotype) {
      // Separate header and genotype
      size_t newline_pos = encoded_genotype.find(HEADER_END);
      if (newline_pos == std::string::npos)
        throw std::runtime_error("Invalid genotype: No newline character found.");
      std::string header = encoded_genotype.substr(0, newline_pos);
      std::string genotype = encoded_genotype.substr(newline_pos + 1);

      // Parse header and save to member variables
      DecodeHeader(header);

      // Initialize the genotype
      InitGenotype();

      // Decode genotype
      DecodeGenotype(genotype);

      // Check if the number of functional nodes is correct
      assert(nodes.size() == params.GetFunctionalNodeCount());

      return *this;
    }

    /// @brief Returns the iterator to the beginning of the node configurations.
    /// @return The iterator to the beginning of the node configurations.
    std::vector<CGPNodeGene>::iterator begin() { return nodes.begin(); }

    /// @brief Returns the iterator to the end of the node configurations.
    /// @return The iterator to the end of the node configurations.
    std::vector<CGPNodeGene>::iterator end() { return nodes.end(); }

    /// @brief Returns the const iterator to the beginning of the node configurations.
    /// @return The const iterator to the beginning of the node configurations.
    std::vector<CGPNodeGene>::const_iterator begin() const { return nodes.begin(); }

    /// @brief Returns the const iterator to the end of the node configurations.
    /// @return The const iterator to the end of the node configurations.
    std::vector<CGPNodeGene>::const_iterator end() const { return nodes.end(); }

    /// @brief Returns the const iterator to the beginning of the node configurations.
    /// @return The const iterator to the beginning of the node configurations.
    std::vector<CGPNodeGene>::const_iterator cbegin() const { return nodes.cbegin(); }

    /// @brief Returns the const iterator to the end of the node configurations.
    /// @return The const iterator to the end of the node configurations.
    std::vector<CGPNodeGene>::const_iterator cend() const { return nodes.cend(); }

    /// @brief Returns the number of possible connections in the graph.
    /// @return The number of possible connections in the graph.
    size_t GetNumConnections() const {
      size_t num_connections = 0;
      for (const CGPNodeGene &node : nodes) {
        num_connections += node.input_connections.size();
      }
      return num_connections;
    }

    /// @brief Set the parameters of the cartesian graph.
    /// @param params The parameters of the cartesian graph. Basically a 5-tuple.
    void SetParameters(const CGPParameters &params) { this->params = params; }

    /// @brief Returns the number of inputs to the graph.
    /// @return The number of inputs to the graph.
    size_t GetNumInputs() const { return params.num_inputs; }

    /// @brief Returns the number of outputs from the graph.
    /// @return The number of outputs from the graph.
    size_t GetNumOutputs() const { return params.num_outputs; }

    /// @brief Returns the number of middle layers in the graph.
    /// @return The number of middle layers in the graph.
    size_t GetNumLayers() const { return params.num_layers; }

    /// @brief Returns the number of nodes per middle layer.
    /// @return The number of nodes per middle layer.
    size_t GetNumNodesPerLayer() const { return params.num_nodes_per_layer; }

    /// @brief Returns the number of layers backward that a node can connect to.
    /// @return The number of layers backward that a node can connect to.
    size_t GetLayersBack() const { return params.layers_back; }

    /// @brief Returns the number of functional (non-input) nodes in the graph.
    /// @return The number of functional (non-input) nodes in the graph.
    size_t GetNumFunctionalNodes() const { return nodes.size(); }

    /// @brief Initializes an empty genotype with the cartesian graph parameters.
    void InitGenotype() {
      // Clear node configurations
      nodes.clear();

      // Input nodes won't have any inputs and no function, so they are skipped

      // Start at 1 to account for the input layer
      for (size_t i = 1; i < params.num_layers + 1; i++) {
        for (size_t j = 0; j < params.num_nodes_per_layer; j++) {
          // Count up possible input connections from each layer backwards
          size_t valid_layers_back = std::min(params.layers_back, i);
          size_t num_input_connections = valid_layers_back * params.num_nodes_per_layer;
          if (i <= params.layers_back) {
            num_input_connections -= params.num_nodes_per_layer;
            num_input_connections += params.num_inputs;
          }
          // Create empty connections
          std::vector<char> input_connections(num_input_connections, '0');
          // Add the node configuration. With default values
          nodes.push_back({input_connections});
        }
      }

      // Output layer can have a different number of nodes, do the same as above
      size_t output_layer_idx = params.num_layers + 1;
      for (size_t i = 0; i < params.num_outputs; i++) {
        size_t valid_layers_back = std::min(params.layers_back, output_layer_idx);
        size_t num_input_connections = valid_layers_back * params.num_nodes_per_layer;
        if (output_layer_idx <= params.layers_back) {
          num_input_connections -= params.num_nodes_per_layer;
          num_input_connections += params.num_inputs;
        }
        std::vector<char> input_connections(num_input_connections, '0');
        nodes.push_back({input_connections});
      }
    }

    /// @brief Exports this genotype into a string representation.
    /// @return The string representation of this genotype.
    std::string Export() {
      std::string header = EncodeHeader();
      std::string genotype = EncodeGenotype();
      return header + HEADER_END + genotype;
    }

    /// @brief Sets the seed of the random number generator.
    void SetSeed(size_t seed) { rng.seed(seed); }

    /// @brief Mutates the genotype by flipping the connections with a given probability between 0 and 1.
    /// @param mutation_rate The probability of flipping a connection.
    void MutateConnections(double mutation_rate) {
      assert(mutation_rate >= 0.0 && mutation_rate <= 1.0);
      std::uniform_real_distribution<double> dist(0.0, 1.0);
      for (CGPNodeGene &node : nodes) {
        for (char &connection : node.input_connections) {
          if (dist(rng) < mutation_rate) {
            // Flip the connection
            connection = connection == '0' ? '1' : '0';
          }
        }
      }
    }

    /// @brief Mutates the genotype by changing the function of each node with a given probability between 0 and 1.
    /// @param mutation_rate The probability of changing the function of a node.
    /// @param num_functions The number of functions available to the nodes.
    void MutateFunctions(double mutation_rate, size_t num_functions) {
      assert(mutation_rate >= 0.0 && mutation_rate <= 1.0);
      std::uniform_real_distribution<double> dist(0.0, 1.0);
      std::uniform_int_distribution<size_t> dist_func(0, num_functions - 1);
      for (CGPNodeGene &node : nodes) {
        if (dist(rng) < mutation_rate) {
          // Mutate the function
          node.function_idx = dist_func(rng);
        }
      }
    }

    /// @brief Mutates the genotype, changing the default output of nodes with probability between 0 and 1.
    /// @param mutation_rate Value between 0 and 1 representing the probability of mutating each value.
    /// @param min The minimum value to generate for mutation.
    /// @param max The maximum value to generate for mutation.
    void MutateOutputs(double mutation_rate, double min, double max) {
      assert(mutation_rate >= 0.0 && mutation_rate <= 1.0);
      std::uniform_real_distribution<double> dist(0.0, 1.0);
      std::uniform_real_distribution<double> dist_output(min, max);
      for (CGPNodeGene &node : nodes) {
        if (dist(rng) < mutation_rate) {
          // Mutate the output
          // Wrap in stod(to_string(.)) to reliably export and import from string
          node.default_output = std::stod(std::to_string(dist_output(rng)));
        }
      }
    }

    /// @brief Check if two CGPGenotypes are equal. CGPParameters and CGPNodeGenes should be equal.
    /// @param other The other CGPGenotype to compare to.
    /// @return True if the two CGPGenotypes are equal, false otherwise.
    inline bool operator==(const CGPGenotype &other) const {
      if (params != other.params) // Compare CGPParameters for equality
        return false;
      if (std::ranges::size(nodes) != std::ranges::size(other.nodes)) // # of genes should be equal
        return false;
      bool all_same = true;
      for (auto it = cbegin(), it2 = other.cbegin(); it != end(); ++it, ++it2) {
        all_same = all_same && (*it == *it2); // Compare CGPNodeGenes for equality
      }
      return all_same;
    }
  };
} // namespace cowboys