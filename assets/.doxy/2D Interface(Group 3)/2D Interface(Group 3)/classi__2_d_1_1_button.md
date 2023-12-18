

# Class i\_2D::Button



[**ClassList**](annotated.md) **>** [**i\_2D**](namespacei__2_d.md) **>** [**Button**](classi__2_d_1_1_button.md)










































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**Button**](#function-button) (const std::string & t, sf::Vector2f size, sf::Color bgColor, sf::Color textColor, const sf::Font & font) <br>_Construct the text with font. Then set text and shape properties with params._  |
|  void | [**DrawTo**](#function-drawto) (sf::RenderWindow & window) <br>_draws the button onto the window_  |
|  bool | [**IsMouseOver**](#function-ismouseover) (sf::RenderWindow & window) <br>_checks if mouse position is in a button_  |
|  void | [**SetBackColor**](#function-setbackcolor) (sf::Color color) <br>_set the background color of the button_  |
|  void | [**SetButtonSize**](#function-setbuttonsize) (sf::Vector2f size) <br>_set the button size_  |
|  void | [**SetFont**](#function-setfont) (const sf::Font & font) <br>_set the font of the button_  |
|  void | [**SetMFont**](#function-setmfont) (const sf::Font & font) <br>_set the font of the button_  |
|  void | [**SetPosition**](#function-setposition) (sf::Vector2f pos) <br>_set the position of the button_  |
|  void | [**SetString**](#function-setstring) (const std::string & s) <br>_set the string of the button_  |
|  void | [**SetTextColor**](#function-settextcolor) (sf::Color color) <br>_set the text color of the string_  |




























## Public Functions Documentation




### function Button 

_Construct the text with font. Then set text and shape properties with params._ 
```C++
i_2D::Button::Button (
    const std::string & t,
    sf::Vector2f size,
    sf::Color bgColor,
    sf::Color textColor,
    const sf::Font & font
) 
```



Constructs the button




**Parameters:**


* `t` the string to be displayed by button 
* `size` the size of the rectangle shape 
* `bgColor` the background color of the shape 
* `textColor` the color of the text 
* `font` the font style 




        



### function DrawTo 

_draws the button onto the window_ 
```C++
inline void i_2D::Button::DrawTo (
    sf::RenderWindow & window
) 
```





**Parameters:**


* `window` 




        



### function IsMouseOver 

_checks if mouse position is in a button_ 
```C++
bool i_2D::Button::IsMouseOver (
    sf::RenderWindow & window
) 
```





**Parameters:**


* `window` 



**Returns:**

returns turn if mouse position is in the button 





        



### function SetBackColor 

_set the background color of the button_ 
```C++
inline void i_2D::Button::SetBackColor (
    sf::Color color
) 
```





**Parameters:**


* `color` 




        



### function SetButtonSize 

_set the button size_ 
```C++
inline void i_2D::Button::SetButtonSize (
    sf::Vector2f size
) 
```





**Parameters:**


* `size` 




        



### function SetFont 

_set the font of the button_ 
```C++
inline void i_2D::Button::SetFont (
    const sf::Font & font
) 
```





**Parameters:**


* `font` 




        



### function SetMFont 

```C++
void i_2D::Button::SetMFont (
    const sf::Font & font
) 
```






### function SetPosition 

_set the position of the button_ 
```C++
void i_2D::Button::SetPosition (
    sf::Vector2f pos
) 
```





**Parameters:**


* `pos` position on the window 




        



### function SetString 

_set the string of the button_ 
```C++
inline void i_2D::Button::SetString (
    const std::string & s
) 
```





**Parameters:**


* `s` label of the button 




        



### function SetTextColor 

_set the text color of the string_ 
```C++
inline void i_2D::Button::SetTextColor (
    sf::Color color
) 
```





**Parameters:**


* `color` 




        

------------------------------
The documentation for this class was generated from the following file `source/Interfaces/Button.hpp`

