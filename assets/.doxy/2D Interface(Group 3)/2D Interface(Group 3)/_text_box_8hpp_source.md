

# File TextBox.hpp

[**File List**](files.md) **>** [**Interfaces**](dir_e52260c07c5ca641bf485ae92612dd08.md) **>** [**TextBox.hpp**](_text_box_8hpp.md)

[Go to the documentation of this file](_text_box_8hpp.md)

```C++


#pragma once

#include<iostream>
#include<SFML/Graphics.hpp>
#include<sstream>

namespace i_2D {

#define DELETE_KEY 8 
#define ENTER_KEY 13 
#define ESCAPE_KEY 27 

    class TextBox {

    private:
        std::unique_ptr<sf::Text> mText;
        std::ostringstream mStreamText; 
        bool isSelected = false; 
        bool hasLimit = true; 
        int limit = 60; 
        // Draw the border around the TextBox
        sf::RectangleShape mBorderRect;

        void InputLogic(int charTyped);

        void DeleteLastChar();

    public:
        TextBox() = default;

        explicit TextBox(const sf::Font &font, int size = 25, sf::Color color = sf::Color::Red, bool sel = false);

        void SetString(const std::string &s);

        void SetFont(const sf::Font &font) {
            mText->setFont(font);
        }

        void SetPosition(sf::Vector2f pos) {
            mText->setPosition(pos);
        }

        void SetLimit(bool ToF) {
            hasLimit = ToF;
        }

        void SetLimit(bool ToF, int lim) {
            hasLimit = ToF;
            limit = lim;
        }

        void SetSelected(bool sel);

        std::string GetText() {
            return mStreamText.str();
        }

        void DrawTo(sf::RenderWindow &window);

        void TypedOn(sf::Event input);

        bool IsSelected() const {
            return isSelected;
        }

        bool Contains(sf::Vector2f point) const {
            return mBorderRect.getGlobalBounds().contains(point);
        }

    };
}


```

