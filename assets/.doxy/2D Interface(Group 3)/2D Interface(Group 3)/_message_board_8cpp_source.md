

# File MessageBoard.cpp

[**File List**](files.md) **>** [**Interfaces**](dir_e52260c07c5ca641bf485ae92612dd08.md) **>** [**MessageBoard.cpp**](_message_board_8cpp.md)

[Go to the documentation of this file](_message_board_8cpp.md)

```C++


#include "MessageBoard.hpp"

namespace i_2D {

    MessageBoard::MessageBoard(sf::Font &font) {

        mText = std::make_unique<sf::Text>(font);
        mText->setString("Welcome!");
        mText->setCharacterSize(35);
        mText->setFillColor(sf::Color::Blue);
        mText->setPosition({5, 125});
        mStartTime = std::chrono::system_clock::now();
    }

    void MessageBoard::DrawTo(sf::RenderWindow &window) {
        if (std::chrono::duration_cast<std::chrono::milliseconds>(
                std::chrono::system_clock::now() - mStartTime).count() > 10000) {
            mText->setString("");
        } else window.draw(*mText);
    }

}

```

