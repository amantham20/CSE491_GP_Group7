

# File Menu.hpp

[**File List**](files.md) **>** [**Interfaces**](dir_e52260c07c5ca641bf485ae92612dd08.md) **>** [**Menu.hpp**](_menu_8hpp.md)

[Go to the documentation of this file](_menu_8hpp.md)

```C++


#pragma once

#include <SFML/Graphics.hpp>
#include "Button.hpp"
#include <vector>
#include <memory>
#include "Inventory.hpp"

namespace i_2D {
    const int MAX_NUMBER_OF_ITEMS_MENU_ITEMS = 3;

    class Menu {
    private:
        std::vector<std::unique_ptr<Button>> mMenuBar;
        std::unique_ptr<Inventory> mInventory; 
        sf::Font * mFont; 
        sf::Vector2f mWorldSize; 

    public:
        void SetInventoryItemDisplay(sf::Texture &texture){
            if(mInventory) mInventory->SetItemDisplay(texture);
        }
        void Initialize(sf::Font &font,sf::Vector2f size);
        void DrawTo(sf::RenderWindow &window);
        std::string HandleMouseMove(sf::RenderWindow &window);
        void HandleMouseButtonPressed(sf::RenderWindow &window,
                                      const std::vector<std::string> &interfaceAgentInventory);
        std::vector<std::unique_ptr<Button>> &GetMenu()
        {
            return mMenuBar;
        }
        void SetWorldSize(sf::Vector2f size){
            mWorldSize = size;
        }

        bool IsInventoryOpen(){
            if(mInventory){
                return true;
            }else return false;
        }

        void ConstructInventory(const std::vector<std::string> &interfaceAgentInventory){
            mInventory = std::make_unique<Inventory>(mWorldSize);
            mInventory->ConstructInventory(*mFont, interfaceAgentInventory);
        }

        void DeconstructInventory(){
            mInventory.reset();
        }

    };
}

```

