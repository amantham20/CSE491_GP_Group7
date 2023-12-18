

# File DamageData.hpp

[**File List**](files.md) **>** [**DataCollection**](dir_8adf75fe53ae17187785c216cf2633db.md) **>** [**DamageData.hpp**](_damage_data_8hpp.md)

[Go to the documentation of this file](_damage_data_8hpp.md)

```C++

#pragma once

#include <memory>
#include <utility>
#include "../core/Entity.hpp"
#include "../core/AgentBase.hpp"

namespace DataCollection {

    class DamageData {
    private:
        std::shared_ptr<cse491::AgentBase> agent;   
        std::shared_ptr<cse491::Entity> source;     
        int amount;                                 

    public:
        DamageData(std::shared_ptr<cse491::AgentBase> agnt,
                   std::shared_ptr<cse491::Entity> src,
                   int amt) : agent(std::move(agnt)), source(std::move(src)), amount(amt) {}

        ~DamageData() = default;
    };
}

```

