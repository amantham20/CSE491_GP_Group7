

# File Button.hpp

[**File List**](files.md) **>** [**Interfaces**](dir_e52260c07c5ca641bf485ae92612dd08.md) **>** [**Button.hpp**](_button_8hpp.md)

[Go to the documentation of this file](_button_8hpp.md)

```C++


#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <memory>

namespace i_2D {
    /***
     * @class Button
     *
     * @brief Simple RectangleShape and a Text inside the shape
     * Responsive rectangles on the Renderwindow that handles mouse's hover and click events
     */
    class Button {
    private:
        sf::RectangleShape button;
        std::unique_ptr<sf::Text> text;


    public:
        Button(const std::string &t, sf::Vector2f size, sf::Color bgColor,
               sf::Color textColor, const sf::Font &font);

        void SetString(const std::string &s){
            text->setString(s);
        }

        void SetMFont(const sf::Font &font);

        void SetFont(const sf::Font &font) {
            text->setFont(font);
        }

        void SetButtonSize(sf::Vector2f size){
            button.setSize(size);
        }

        void SetBackColor(sf::Color color){
            button.setFillColor(color);
        }

        void SetTextColor(sf::Color color){
            text->setFillColor(color);
        }

        void SetPosition(sf::Vector2f pos);

        void DrawTo(sf::RenderWindow &window){
            window.draw(button);
            window.draw(*text);
        }

        bool IsMouseOver(sf::RenderWindow &window);
    };
}


```

