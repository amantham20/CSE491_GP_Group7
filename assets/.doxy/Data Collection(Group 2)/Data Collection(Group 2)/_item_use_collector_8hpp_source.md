

# File ItemUseCollector.hpp

[**File List**](files.md) **>** [**DataCollection**](dir_8adf75fe53ae17187785c216cf2633db.md) **>** [**ItemUseCollector.hpp**](_item_use_collector_8hpp.md)

[Go to the documentation of this file](_item_use_collector_8hpp.md)

```C++

#pragma once

#include <unordered_map>
#include <string>
#include <algorithm>
#include "JsonBuilder.hpp"

namespace DataCollection {

    class ItemUseCollector {
    private:
        std::unordered_map<std::string, int> usageData;  
    public:
        ItemUseCollector() = default;

        const std::unordered_map<std::string, int>& GetUsageData() {
            return usageData;
        }

        int GetNumberOfItems() {
            return usageData.size();
        }

        void IncrementItemUsage(const std::string& itemName) {
            usageData[itemName]++;
        }

        std::string GetMostFrequent() {
            if (!usageData.empty()) {
                auto maxItr = std::max_element(usageData.begin(), usageData.end(),
                        [](const auto& firstItem, const auto& secondItem) {
                            return firstItem.second < secondItem.second;
                        }
                );

                return maxItr->first;
            }

            return "";
        }

        std::string GetLeastFrequent() {
            if (!usageData.empty()) {
                auto maxItr = std::min_element(usageData.begin(), usageData.end(),
                        [](const auto& firstItem, const auto& secondItem) {
                            return firstItem.second < secondItem.second;
                        }
                );

                return maxItr->first;
            }

            return "";
        }

        void WriteToItemUseFile(std::string path)
        {
            JsonBuilder json_builder;
            std::ofstream jsonfilestream(path);
            json_builder.StartArray("items");
            for (auto& usage: usageData) {
                json_builder.AddName(usage.first);
                json_builder.AddInt("amountOfUses", usage.second);
                json_builder.InputToArray("items", json_builder.GetJSON());
                json_builder.ClearJSON();
            }
            json_builder.WriteToFile(jsonfilestream, json_builder.GetJSONArray());
            jsonfilestream.close();
        }
    };
}

```

