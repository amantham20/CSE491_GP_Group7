

# File MainInterface.hpp

[**File List**](files.md) **>** [**Interfaces**](dir_e52260c07c5ca641bf485ae92612dd08.md) **>** [**MainInterface.hpp**](_main_interface_8hpp.md)

[Go to the documentation of this file](_main_interface_8hpp.md)

```C++


#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/Graphics/Transformable.hpp"
#include <iostream>
#include <vector>
#include <sstream>
#include "Button.hpp"
#include "Menu.hpp"
#include <memory>

#include "../core/Data.hpp"
#include "../core/InterfaceBase.hpp"
#include "TextureHolder.hpp"
#include "TextBox.hpp"
#include "MessageBoard.hpp"


namespace i_2D {

    using namespace cse491;


    class MainInterface : public virtual InterfaceBase {

    private:
        sf::RenderWindow mWindow; 
        float const MIN_SIZE_CELL = 16; 

        // Menu and message vars
        Menu mMenu; 
        sf::Font mFont; 
        std::unique_ptr<TextBox> mTextBox; 
        std::unique_ptr<MessageBoard> mMessageBoard; 
        std::vector<std::string> mAgentInventory;

        // Texture vars
        TextureHolder mTextureHolder; 
        std::map<char, sf::Texture> mTexturesDefault; 
        std::map<char, sf::Texture> mTexturesSecondWorld; 
        std::map<char, sf::Texture> mTexturesManualWorld; 
        std::map<char, sf::Texture> mTexturesGenerativeWorld; 
        std::map<char, sf::Texture> mTexturesCurrent; 

        // Render range vars
        sf::Vector2i mPlayerPosition = sf::Vector2i(0, 0); 
        bool mGridSizeLarge = false; 
        int const ROW = 9; 
        int const COL = 20; 

        int mGridWidth = 0; 
        int mGridHeight = 0; 

        double mInputWaitTime = 0.5f;  

        size_t HandleKeyEvent(const sf::Event &event);

        void CalculateDrawSpace(const WorldGrid &grid, float cellSize, float &drawSpaceWidth, float &drawSpaceHeight,
                                float &drawCenterX, float &drawCenterY);

        sf::Vector2f CalculateCellSize(const WorldGrid &grid);

        void HandleResize(const sf::Event &event, const WorldGrid &grid);

        void ChooseTexture();

        std::vector<std::string> LargeDisplayGrid(const std::vector<std::string> &symbol_grid);

        void MouseClickEvent(const sf::Event &event,const size_t entity_id, const item_map_t &item_map);

        void DrawAgentCell(sf::RenderTexture &renderTexture, sf::RectangleShape &cellRect, sf::RectangleShape &cell,
                           sf::Texture &agent);

        void
        SwitchCellSelect(sf::RenderTexture &renderTexture, sf::RectangleShape &cellRect, sf::RectangleShape &cell,
                         char symbol);

        void DrawWall(sf::RenderTexture &renderTexture, sf::RectangleShape &cellRect, sf::Texture &wallTexture);

        void DrawTimer();

        void DrawHealthInfo();

    public:
        MainInterface(size_t id, const std::string &name);

        ~MainInterface() = default;


        std::vector<std::string> CreateVectorMaze(
                const WorldGrid &grid,
                const type_options_t &type_options,
                const item_map_t &item_map,
                const agent_map_t &agent_map);

        void DrawGrid(const WorldGrid &grid, const type_options_t &type_options,
                      const item_map_t &item_map, const agent_map_t &agent_map);
        
        void setMInputWaitTime(double mInputWaitTime);
        void SetLargeGrid(bool b){ mGridSizeLarge = b; } 

        bool Initialize() override {
            return true;
        }

        size_t SelectAction(const WorldGrid &grid,
                            const type_options_t &type_options,
                            const item_map_t &item_map,
                            const agent_map_t &agent_map) override;


        void Notify(const std::string &message,
                    const std::string & /*msg_type*/= "none") override {
            std::cout << message << std::endl;
            mMessageBoard->Send(message);
        }

        void CheckLargerGrid();
    };

} // End of namespace 2D


```

