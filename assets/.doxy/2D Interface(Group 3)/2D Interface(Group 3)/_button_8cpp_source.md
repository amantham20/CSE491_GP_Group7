

# File Button.cpp

[**File List**](files.md) **>** [**Interfaces**](dir_e52260c07c5ca641bf485ae92612dd08.md) **>** [**Button.cpp**](_button_8cpp.md)

[Go to the documentation of this file](_button_8cpp.md)

```C++


#include "Button.hpp"

namespace i_2D {
    Button::Button(const std::string &t, sf::Vector2f size, sf::Color bgColor,
                   sf::Color textColor, const sf::Font &font) {
        text = std::make_unique<sf::Text>(font);

        text->setString(t);
        text->setFillColor(textColor);

        button.setSize(size);
        button.setFillColor(bgColor);
    }

    void Button::SetMFont(const sf::Font &font) {
        text = std::make_unique<sf::Text>(font);
    }

    void Button::SetPosition(sf::Vector2f pos) {
        button.setPosition(pos);
        float xPos = (pos.x + button.getGlobalBounds().width / 2) - (text->getLocalBounds().width / 2);
        float yPos = (pos.y + button.getGlobalBounds().height / 2) - (text->getLocalBounds().height / 2);
        text->setPosition({xPos, yPos});
    }

    bool Button::IsMouseOver(sf::RenderWindow &window) {
        float mouseX = sf::Mouse::getPosition(window).x;
        float mouseY = sf::Mouse::getPosition(window).y;

        float btnPosX = button.getPosition().x;
        float btnPosY = button.getPosition().y;

        float btnXPosWidth = button.getPosition().x + button.getLocalBounds().width;
        float btnYPosHeight = button.getPosition().y + button.getLocalBounds().height;

        if (mouseX < btnXPosWidth && mouseX > btnPosX && mouseY < btnYPosHeight && mouseY > btnPosY) {
            return true;
        }
        return false;
    }
}

```

