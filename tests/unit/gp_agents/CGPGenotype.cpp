/**
 * This file is part of the Fall 2023, CSE 491 course project.
 * @brief Unit tests for source/Group7_GP_Agent/CGPGenotype.hpp
 **/

// Catch2
#define CATCH_CONFIG_MAIN
#include <catch2/catch_all.hpp>

#include "Group7_GP_Agent/CGPGenotype.hpp"
#include <ranges>

using namespace cowboys;
TEST_CASE("Genotype construction", "[group7][genotype]") {
  SECTION("Parameters constructor") {
    auto genotype = CGPGenotype({8, 4, 2, 10, 2});
    CHECK(genotype.GetNumConnections() == 8 * 10 + (8 + 10) * 10 + (10 + 10) * 4);

    genotype = CGPGenotype({8, 4, 2, 10, 3});
    genotype.InitGenotype();
    CHECK(genotype.GetNumConnections() == 8 * 10 + (8 + 10) * 10 + (8 + 10 + 10) * 4);

    genotype = CGPGenotype({8, 4, 2, 10, 10});
    genotype.InitGenotype();
    CHECK(genotype.GetNumConnections() == 8 * 10 + (8 + 10) * 10 + (8 + 10 + 10) * 4);
  }
}
TEST_CASE("Genotype iterators", "[group7][genotype]") {
  SECTION("Genotype iterators") {
    CGPGenotype genotype({8, 4, 2, 10, 2});
    auto it = genotype.begin();
    CHECK(it->input_connections.size() == 8);
    CHECK(it->function_idx == 0);
    CHECK((++it)->input_connections.size() == 8);

    it = genotype.begin();
    // Layer 1
    for (size_t i = 0; i < 10; ++i) {
      CHECK(it->input_connections.size() == 8);
      CHECK(it->function_idx == 0);
      ++it;
    }
    // Layer 2
    for (size_t i = 0; i < 10; ++i) {
      CHECK(it->input_connections.size() == 18);
      CHECK(it->function_idx == 0);
      ++it;
    }
    // Output layer
    for (size_t i = 0; i < 4; ++i) {
      CHECK(it->input_connections.size() == 20);
      CHECK(it->function_idx == 0);
      ++it;
    }
    CHECK(it == genotype.end());

    // All nodes should have 0 input connections when initialized by default
    bool all_0s = true;
    for (auto it = genotype.begin(); it != genotype.end(); ++it)
      all_0s = all_0s && std::ranges::all_of(it->input_connections, [](char c) { return c == '0'; });
    CHECK(all_0s);
  }
}
TEST_CASE("Genotype mutation", "[group7][genotype]") {
  CGPGenotype genotype({10, 10, 200, 10, 10});
  SECTION("Mutate connections") {
    // Each connection will have a 0% chance of being mutated
    genotype.MutateConnections(0.);
    bool all_0s = true;
    for (auto it = genotype.begin(); it != genotype.end(); ++it)
      all_0s = all_0s && std::ranges::all_of(it->input_connections, [](char c) { return c == '0'; });
    CHECK(all_0s);

    // Each connection will have a 100% chance of being mutated
    genotype.MutateConnections(1.);
    bool all_1s = true;
    for (auto it = genotype.begin(); it != genotype.end(); ++it)
      all_1s = all_1s && std::ranges::all_of(it->input_connections, [](char c) { return c == '1'; });
    CHECK(all_1s);

    // Each connection will have a 0% chance of being mutated
    genotype.MutateConnections(0.);
    all_1s = true;
    for (auto it = genotype.begin(); it != genotype.end(); ++it)
      all_1s = all_1s && std::ranges::all_of(it->input_connections, [](char c) { return c == '1'; });
    CHECK(all_1s);

    // Each connection will have a 50% chance of being mutated
    all_0s = true;
    all_1s = true;
    genotype.MutateConnections(0.5);
    for (auto it = genotype.begin(); it != genotype.end(); ++it) {
      all_0s = all_0s && std::ranges::all_of(it->input_connections, [](char c) { return c == '0'; });
      all_1s = all_1s && std::ranges::all_of(it->input_connections, [](char c) { return c == '1'; });
    }
    // These tests could fail, but it's unlikely: chance of failure = 1 / (2 ^ 196500)
    CHECK_FALSE(all_0s);
    CHECK_FALSE(all_1s);
  }
  SECTION("Mutate functions") {
    bool all_default = true;
    for (auto it = genotype.begin(); it != genotype.end(); ++it) {
      all_default = all_default && it->function_idx == 0;
    }
    CHECK(all_default);

    genotype.MutateFunctions(0., 100);
    all_default = true;
    for (auto it = genotype.begin(); it != genotype.end(); ++it) {
      all_default = all_default && it->function_idx == 0;
    }
    CHECK(all_default);

    genotype.MutateFunctions(1., 100);
    all_default = true;
    for (auto it = genotype.begin(); it != genotype.end(); ++it) {
      all_default = all_default && it->function_idx == 0;
    }
    CHECK_FALSE(all_default);
  }
  SECTION("Mutate outputs") {
    bool all_default = true;
    for (auto it = genotype.begin(); it != genotype.end(); ++it) {
      all_default = all_default && it->default_output == 0;
    }
    CHECK(all_default);

    genotype.MutateOutputs(0., -100, 100);
    all_default = true;
    for (auto it = genotype.begin(); it != genotype.end(); ++it) {
      all_default = all_default && it->default_output == 0;
    }
    CHECK(all_default);

    genotype.MutateOutputs(1., -100, 100);
    all_default = true;
    for (auto it = genotype.begin(); it != genotype.end(); ++it) {
      all_default = all_default && it->default_output == 0;
    }
    CHECK_FALSE(all_default);
  }
}
TEST_CASE("base64", "[group7][base64]") {
  SECTION("ULL") {
    auto max_ull = std::numeric_limits<size_t>::max();
    // 64 bits for ull; 1 char represents 6 bits => 64 / 6 = 10.6666 => 11 chars
    // 64 bits set to all 1s => 10 chars of largest char + another char for left over bits
    // 64 % 6 = 4 => 4 bits left over => 4 bits of 1s => 16th char
    std::string max_encoded_ull = base64::chars.at(15) + std::string(10, base64::chars.at(63));
    CHECK(base64::ULLToB64(max_ull) == max_encoded_ull);
    CHECK(base64::B64ToULL(max_encoded_ull) == max_ull);
  }
  SECTION("Binary") {
    std::string max_encoded_ull = base64::chars.at(15) + std::string(10, base64::chars.at(63));
    CHECK(base64::B2ToB64(std::string(64, '1')) == max_encoded_ull);
    CHECK(base64::B64ToB2(max_encoded_ull) == std::string(64, '1'));
  }
  SECTION("Double") {
    auto rng = std::mt19937(std::random_device{}());
    // Must avoid stoull error
    auto min = std::numeric_limits<int32_t>::min();
    auto max = std::numeric_limits<int32_t>::max();
    auto dist = std::uniform_real_distribution<double>(min, max);
    auto fix_double = [](double d) { return std::stod(std::to_string(d)); };
    for (size_t i = 0; i < 100; ++i) {
      auto d = fix_double(dist(rng));
      CHECK(d == base64::B64ToDouble(base64::DoubleToB64(d)));
    }
    CHECK(0 == base64::B64ToDouble(base64::DoubleToB64(0)));
    CHECK(1 == base64::B64ToDouble(base64::DoubleToB64(1)));
    CHECK(-1 == base64::B64ToDouble(base64::DoubleToB64(-1)));
  }
}
TEST_CASE("Genotype overloads", "[group7][genotype]") {
  SECTION("operator==") {
    auto genotype = CGPGenotype({7, 2, 0, 10, 3});
    auto genotype2 = CGPGenotype({7, 2, 0, 10, 3});
    CHECK(genotype == genotype2);

    genotype2 = CGPGenotype({7, 2, 0, 10, 2});
    CHECK_FALSE(genotype == genotype2);
    CHECK(genotype != genotype2);

    genotype2 = CGPGenotype({7, 2, 0, 10, 3});
    genotype2.MutateConnections(0.5);
    CHECK_FALSE(genotype == genotype2);
    CHECK(genotype != genotype2);

    genotype2 = CGPGenotype({7, 2, 0, 10, 3});
    genotype2.MutateFunctions(0.5, 100);
    CHECK_FALSE(genotype == genotype2);
    CHECK(genotype != genotype2);

    genotype2 = CGPGenotype({7, 2, 0, 10, 3});
    genotype2.MutateOutputs(0.5, -10000, 10000);
    CHECK_FALSE(genotype == genotype2);
    CHECK(genotype != genotype2);
  }
}
TEST_CASE("Genotype configuration", "[group7][genotype]") {
  SECTION("Exporting and configuration") {
    CGPGenotype genotype({8, 4, 10, 10, 2});
    auto exported = genotype.Export();
    CGPGenotype genotype2 = CGPGenotype().Configure(exported);
    CHECK(genotype == genotype2);

    genotype.begin()->function_idx = 1;
    CHECK_FALSE(genotype == genotype2);
    genotype2.begin()->function_idx = 1;
    CHECK(genotype == genotype2);

    genotype.begin()->input_connections = std::vector<char>(8, '1');
    CHECK_FALSE(genotype == genotype2);
    genotype2.begin()->input_connections = std::vector<char>(8, '1');
    CHECK(genotype == genotype2);

    genotype.begin()->input_connections = std::vector<char>(8, '0');
    CHECK_FALSE(genotype == genotype2);
    genotype2 = CGPGenotype().Configure(genotype.Export());
    CHECK(genotype == genotype2);

    genotype.begin()->default_output = 1;
    CHECK_FALSE(genotype == genotype2);
    genotype2.begin()->default_output = 1;
    CHECK(genotype == genotype2);

    //
    // These tests could fail, should be unlikely
    //
    genotype.MutateConnections(0.5);
    CHECK_FALSE(genotype == genotype2);
    genotype2 = CGPGenotype().Configure(genotype.Export());
    CHECK(genotype == genotype2);

    genotype.MutateFunctions(0.5, 100);
    CHECK_FALSE(genotype == genotype2);
    genotype2 = CGPGenotype().Configure(genotype.Export());
    CHECK(genotype == genotype2);

    genotype.MutateOutputs(0.5, -10000, 10000);
    CHECK_FALSE(genotype == genotype2);
    genotype2 = CGPGenotype().Configure(genotype.Export());
    CHECK(genotype == genotype2);
  }
}