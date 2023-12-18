

# File GameData.hpp

[**File List**](files.md) **>** [**DataCollection**](dir_8adf75fe53ae17187785c216cf2633db.md) **>** [**GameData.hpp**](_game_data_8hpp.md)

[Go to the documentation of this file](_game_data_8hpp.md)

```C++

#pragma once

#include <vector>
#include"../core/GridPosition.hpp"
namespace DataCollection{
    class GameData{
    private:
        /* number of collisions */
        int numOfCol;

        std::vector<int>collisions;
        std::vector<size_t>shortestPathAction; 
        std::vector<cse491::GridPosition>shortestPathPos;
    public:
        GameData() = default;

        ~GameData() = default;

        int getNumOfCol() const {
            return numOfCol;
        }

        void setNumOfCol(int value) {
            numOfCol = value;
        }

        void StoreCollision(int collision) {
            collisions.push_back(collision);
        }

        const std::vector<int>& GetCollisions() const {
            return collisions;
        }

        void StoreShortestPathAction(size_t action) {
            shortestPathAction.push_back(action);
        }

        const std::vector<size_t>& GetShortestPathActions() const {
            return shortestPathAction;
        }

        void StoreShortestPathPos(const cse491::GridPosition pos) {
            shortestPathPos.push_back(pos);
        }

        const std::vector<cse491::GridPosition> GetShortestPathPos() const {
            return shortestPathPos;
        }
    };
    }



```

