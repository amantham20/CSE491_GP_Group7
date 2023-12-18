

# File JsonBuilder.hpp

[**File List**](files.md) **>** [**DataCollection**](dir_8adf75fe53ae17187785c216cf2633db.md) **>** [**JsonBuilder.hpp**](_json_builder_8hpp.md)

[Go to the documentation of this file](_json_builder_8hpp.md)

```C++

#pragma once

#include <string>
#include <unordered_map>
#include <fstream>
#include "../core/GridPosition.hpp"
#include <nlohmann/json.hpp>

namespace DataCollection{
    class JsonBuilder {
    private:
        nlohmann::json json;  
        nlohmann::json json_array;
    public:
        JsonBuilder() = default;

        ~JsonBuilder() = default;

        void StartArray(std::string title) {
            json_array[title] = nlohmann::json::array();
        }

        void InputToArray(std::string title, nlohmann::json input) {
            json_array[title].push_back(input);
        }

        void AddName(std::string name) {
            json["name"] = name;
        }

        void Addagentname(std::string name) {
            json["agentname"] = name;
        }

        void AddPosition(cse491::GridPosition pos) {
            json["positions"].push_back({{"x", pos.GetX()}, {"y", pos.GetY()}});
        }

        void AddDamage(double damage) {
            json["damage"].push_back(damage);
        }

        nlohmann::json GetJSON() {
            return json;
        }

        void ClearJSON() {
            json.clear();
        }

        nlohmann::json GetJSONArray() {
            return json_array;
        }

        void AddInt(std::string title, int usage) {
            json[title] = usage;
        }

        void WriteToFile(std::ofstream &jsonfilestream, nlohmann::json Json)
        {
            jsonfilestream << Json.dump(4);
        }
    };
} // namespace DataCollection

```

