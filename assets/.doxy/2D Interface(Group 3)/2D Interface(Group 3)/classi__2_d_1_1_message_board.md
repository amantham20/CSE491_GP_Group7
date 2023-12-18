

# Class i\_2D::MessageBoard



[**ClassList**](annotated.md) **>** [**i\_2D**](namespacei__2_d.md) **>** [**MessageBoard**](classi__2_d_1_1_message_board.md)



[More...](#detailed-description)






































## Public Functions

| Type | Name |
| ---: | :--- |
|  void | [**DrawTo**](#function-drawto) (sf::RenderWindow & window) <br>_Draws the message board onto the render window._  |
|   | [**MessageBoard**](#function-messageboard) (sf::Font & font) <br>_Construct the message board._  |
|  void | [**Send**](#function-send) (const std::string & message) <br>_Set the text of the message board._  |




























# Detailed Description


is where the backend and users communicate by words 


    
## Public Functions Documentation




### function DrawTo 

_Draws the message board onto the render window._ 
```C++
void i_2D::MessageBoard::DrawTo (
    sf::RenderWindow & window
) 
```





**Parameters:**


* `window` The render window to be drawn on 




        



### function MessageBoard 

_Construct the message board._ 
```C++
explicit i_2D::MessageBoard::MessageBoard (
    sf::Font & font
) 
```





**Parameters:**


* `font` The font used by message borad 




        



### function Send 

_Set the text of the message board._ 
```C++
inline void i_2D::MessageBoard::Send (
    const std::string & message
) 
```





**Parameters:**


* `message` The message to set the text to 




        

------------------------------
The documentation for this class was generated from the following file `source/Interfaces/MessageBoard.hpp`

