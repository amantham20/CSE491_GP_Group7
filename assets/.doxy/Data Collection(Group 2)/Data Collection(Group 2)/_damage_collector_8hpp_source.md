

# File DamageCollector.hpp

[**File List**](files.md) **>** [**DataCollection**](dir_8adf75fe53ae17187785c216cf2633db.md) **>** [**DamageCollector.hpp**](_damage_collector_8hpp.md)

[Go to the documentation of this file](_damage_collector_8hpp.md)

```C++

#pragma once

#include <unordered_map>
#include <string>
#include <vector>
#include <numeric>
#include <fstream>
#include "JsonBuilder.hpp"

namespace DataCollection {

     class DamageCollector {
     private:
         std::unordered_map<std::string, std::vector<double>> damageData;  // Damage storage map of item name to damage amounts
     public:
         DamageCollector() = default;

         void RecordDamageResult(const std::string& itemName, double damageAmt) {
             damageData[itemName].push_back(damageAmt);
         }

         std::vector<double>& GetDamageAmounts(std::string itemName) {
             if (damageData.contains(itemName)) {
                 return damageData[itemName];
             } else {
                 // Created only once, subsequent calls will reference this
                 static std::vector<double> empty;
                 return empty;
             }
         }

        double CalculateAverageDamage(const std::string& itemName) {
             if (damageData.contains(itemName)) {
                 std::vector<double>& damages = damageData[itemName];
                 return std::accumulate(damages.begin(), damages.end(), 0.0) / damages.size();
             }

             return -1.0;
         }

         void WriteToDamageFile(std::string path) {
             std::ofstream jsonfilestream(path);
             JsonBuilder json_builder;
             for (auto& damage : damageData) {
                 json_builder.AddName(damage.first);
                 for (auto& damageAmt : damage.second) {
                     json_builder.AddDamage(damageAmt);
                 }
             }
         }
     };
}

```

