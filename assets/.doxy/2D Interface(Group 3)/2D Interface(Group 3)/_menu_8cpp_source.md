

# File Menu.cpp

[**File List**](files.md) **>** [**Interfaces**](dir_e52260c07c5ca641bf485ae92612dd08.md) **>** [**Menu.cpp**](_menu_8cpp.md)

[Go to the documentation of this file](_menu_8cpp.md)

```C++


#include "Menu.hpp"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

const sf::Vector2f MENU_BUTTON_SIZE({200.f,50.f});
namespace i_2D {

    void Menu::Initialize(sf::Font &font, sf::Vector2f size) {
        sf::Color backgroundcolor = sf::Color::Black;
        sf::Color textcolor = sf::Color::White;
        mFont = &font;
        mWorldSize = size;

        mMenuBar.emplace_back(std::make_unique<Button>(
                "Menu", MENU_BUTTON_SIZE, backgroundcolor, textcolor, font));
        mMenuBar[0]->SetPosition({0,0});
        mMenuBar.emplace_back(std::make_unique<Button>(
                "Inventory", MENU_BUTTON_SIZE, backgroundcolor, textcolor, font));
        mMenuBar[1]->SetPosition({200,0});
        mMenuBar.emplace_back(std::make_unique<Button>(
                "Exit", MENU_BUTTON_SIZE, backgroundcolor, textcolor, font));
        mMenuBar[2]->SetPosition({400,0});
        mMenuBar.emplace_back(std::make_unique<Button>(
                "Normal", MENU_BUTTON_SIZE, backgroundcolor, textcolor, font));
        mMenuBar[3]->SetPosition({600,0});
        mMenuBar.emplace_back(std::make_unique<Button>(
                "Enlarge", MENU_BUTTON_SIZE, backgroundcolor, textcolor, font));
        mMenuBar[4]->SetPosition({800,0});

    }

    void Menu::DrawTo(sf::RenderWindow &window) {
        for( const auto &button : mMenuBar){
            button->DrawTo(window);
        }
        if(mInventory) {
            mInventory->DrawTo(window);
        }
    }

    std::string Menu::HandleMouseMove(sf::RenderWindow &window) {
        std::string s1 = "null";
        for (size_t i = 0; i < mMenuBar.size(); ++i) {
            if (mMenuBar[i]->IsMouseOver(window)) {
                mMenuBar[i]->SetBackColor(sf::Color::Magenta);
            } else {
                mMenuBar[i]->SetBackColor(sf::Color::Black);
            }
        }
        if(mInventory){
            s1 = mInventory->HandleMouseMove(window);
        }
        return s1;
    }
    void Menu::HandleMouseButtonPressed(sf::RenderWindow &window,
                                        const std::vector<std::string> &interfaceAgentInventory) {
        if(mMenuBar[1]->IsMouseOver(window)){
            if(mInventory){
                DeconstructInventory();
            }else {
                ConstructInventory(interfaceAgentInventory);
            }
        }

    }
}



```

