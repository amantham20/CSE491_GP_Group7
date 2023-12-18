

# File Inventory.hpp

[**File List**](files.md) **>** [**Interfaces**](dir_e52260c07c5ca641bf485ae92612dd08.md) **>** [**Inventory.hpp**](_inventory_8hpp.md)

[Go to the documentation of this file](_inventory_8hpp.md)

```C++


#pragma once

#include <SFML/Graphics.hpp>
#include "Button.hpp"
#include <vector>
#include <memory>

namespace i_2D {
    /***
     * @class Inventory
     *
     * @brief Represent the inventory of entities.
     *
     * An interface/visual representation of an inventory.
     */
    class Inventory {
    private:
        std::unique_ptr<sf::RectangleShape> mCanvas;
        std::vector<std::vector<std::unique_ptr<Button>>> mListOfButtons;
        sf::Vector2f mWorldSize; 
        int mCol=0; 
        int mRow=0; 

        std::vector<std::string> mItems; 
        std::unique_ptr<sf::Texture> mItemDisplay; 

    public:
        void SetItemDisplay(sf::Texture &texture){
            if(mItemDisplay) mItemDisplay.reset();
            mItemDisplay = std::make_unique<sf::Texture>(texture);
        }
        explicit Inventory(const sf::Vector2f size) : mWorldSize(size) {}
        void SetSize(const sf::Vector2f size) {
            mWorldSize = size;
        }
        void ConstructInventory(sf::Font &font,const std::vector<std::string> &interfaceAgentInventory);
        void DrawTo(sf::RenderWindow &window);
        std::string HandleMouseMove(sf::RenderWindow &window);
    };
}


```

