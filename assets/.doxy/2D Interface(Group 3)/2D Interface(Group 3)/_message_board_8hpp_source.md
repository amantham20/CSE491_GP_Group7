

# File MessageBoard.hpp

[**File List**](files.md) **>** [**Interfaces**](dir_e52260c07c5ca641bf485ae92612dd08.md) **>** [**MessageBoard.hpp**](_message_board_8hpp.md)

[Go to the documentation of this file](_message_board_8hpp.md)

```C++


#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <memory>
#include <chrono>

namespace i_2D {

    class MessageBoard {

    private:
        std::unique_ptr<sf::Text> mText;
        std::chrono::time_point<std::chrono::system_clock> mStartTime;

    public:
        explicit MessageBoard(sf::Font &font);

        void DrawTo(sf::RenderWindow &window);

        void Send(const std::string &message) {
            mText->setString(message);
            mStartTime = std::chrono::system_clock::now();
        }
    };
}


```

