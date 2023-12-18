

# File TextBox.cpp

[**File List**](files.md) **>** [**Interfaces**](dir_e52260c07c5ca641bf485ae92612dd08.md) **>** [**TextBox.cpp**](_text_box_8cpp.md)

[Go to the documentation of this file](_text_box_8cpp.md)

```C++


#include "TextBox.hpp"

namespace i_2D {

    TextBox::TextBox(const sf::Font &font, int size, sf::Color color, bool sel) {

        mText = std::make_unique<sf::Text>(font);
        mText->setCharacterSize(size);
        mText->setFillColor(color);
        mText->setPosition({10, 650});
        isSelected = sel;
        if (!isSelected)
            mText->setString("Press Click!");

    }

    void TextBox::SetString(const std::string &s) {
        mText->setString(s);
        mStreamText.str("");
        mStreamText << s;
    }

    void TextBox::SetSelected(bool sel) {
        isSelected = sel;
        if (!sel) {
            std::string t = mStreamText.str();
            std::string newT;
            for (char i: t) {
                newT += i;
            }
            mText->setString((newT));
        }
    }

    void TextBox::TypedOn(sf::Event input) {
        if (isSelected) {
            int charTyped = static_cast<int>(input.text.unicode);
            if (charTyped < 128) {
                if (hasLimit) {
                    if (static_cast<int>(mStreamText.str().length()) < limit) {
                        InputLogic(charTyped);
                    } else if (static_cast<int>(mStreamText.str().length()) >= limit && charTyped == DELETE_KEY) {
                        DeleteLastChar();
                    }
                } else {
                    InputLogic(charTyped);
                }
            }
        }
    }

    void TextBox::InputLogic(int charTyped) {
        if (isSelected) {
            if (charTyped != DELETE_KEY && charTyped != ENTER_KEY && charTyped != ESCAPE_KEY) {
                    mStreamText << static_cast<char>(charTyped);
            } else if (charTyped == DELETE_KEY) {
                if (mStreamText.str().length() > 0) {
                    DeleteLastChar();
                }
            }
        }

        mText->setString(mStreamText.str() + "_");
    }

    void TextBox::DeleteLastChar() {
        std::string t = mStreamText.str();
        mStreamText.str("");
        mStreamText << t.substr(0,t.size()-1);
        mText->setString(mStreamText.str());
    }

    void TextBox::DrawTo(sf::RenderWindow &window) {

        mBorderRect.setSize(sf::Vector2f(800, 50));
        //Subtracts the vector (5, 5) from the position of mTextBox. This creates a new position
        // slightly to the left and up from the original position, effectively creating a margin.

        mBorderRect.setPosition(mText->getPosition() - sf::Vector2f(5, 5));
        mBorderRect.setFillColor(sf::Color(200, 200, 200));
        mBorderRect.setOutlineThickness(2.0f);  //  thickness of the border
        mBorderRect.setOutlineColor(sf::Color::Black);

        window.draw(mBorderRect);
        window.draw(*mText);

    }

}

```

