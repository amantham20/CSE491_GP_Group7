

# File GameReceiver.hpp

[**File List**](files.md) **>** [**DataCollection**](dir_8adf75fe53ae17187785c216cf2633db.md) **>** [**GameReceiver.hpp**](_game_receiver_8hpp.md)

[Go to the documentation of this file](_game_receiver_8hpp.md)

```C++

#pragma once

#include <iostream>
#include "GameData.hpp"
#include "DataReceiver.hpp"
#include "../core/GridPosition.hpp"
#include <unordered_map>
#include <fstream>
#include "JsonBuilder.hpp"

namespace DataCollection {

    class GameReceiver : public DataReceiver<GameData> {
    public:
        GameReceiver() = default;

        ~GameReceiver() override = default;

        void store_GameData(const GameData& gameData) {
            this->storage.push_back(gameData);
        }
    };

}


```

