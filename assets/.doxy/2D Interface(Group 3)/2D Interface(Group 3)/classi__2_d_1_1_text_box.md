

# Class i\_2D::TextBox



[**ClassList**](annotated.md) **>** [**i\_2D**](namespacei__2_d.md) **>** [**TextBox**](classi__2_d_1_1_text_box.md)



[More...](#detailed-description)






































## Public Functions

| Type | Name |
| ---: | :--- |
|  bool | [**Contains**](#function-contains) (sf::Vector2f point) const<br>_Checks if a point is within the_ [_**TextBox**_](classi__2_d_1_1_text_box.md) _._ |
|  void | [**DrawTo**](#function-drawto) (sf::RenderWindow & window) <br>_Draws the text to the render window._  |
|  std::string | [**GetText**](#function-gettext) () <br>_Get the string that was input by user._  |
|  bool | [**IsSelected**](#function-isselected) () const<br>_Checks if_ [_**TextBox**_](classi__2_d_1_1_text_box.md) _is active._ |
|  void | [**SetFont**](#function-setfont) (const sf::Font & font) <br>_Set the font of the_ [_**TextBox**_](classi__2_d_1_1_text_box.md) _._ |
|  void | [**SetLimit**](#function-setlimit-12) (bool ToF) <br>_Set the limit of the_ [_**TextBox**_](classi__2_d_1_1_text_box.md) _._ |
|  void | [**SetLimit**](#function-setlimit-22) (bool ToF, int lim) <br>_Set the limit of the_ [_**TextBox**_](classi__2_d_1_1_text_box.md) _._ |
|  void | [**SetPosition**](#function-setposition) (sf::Vector2f pos) <br>_The position of the_ [_**TextBox**_](classi__2_d_1_1_text_box.md) _._ |
|  void | [**SetSelected**](#function-setselected) (bool sel) <br>_Setter for isSelected, updates the text displayed in the box._  |
|  void | [**SetString**](#function-setstring) (const std::string & s) <br>_Set the string of the text._  |
|   | [**TextBox**](#function-textbox-12) () = default<br> |
|   | [**TextBox**](#function-textbox-22) (const sf::Font & font, int size=25, sf::Color color=sf::Color::Red, bool sel=false) <br>_Constructor._  |
|  void | [**TypedOn**](#function-typedon) (sf::Event input) <br>_TypedOn event handler._  |




























# Detailed Description


is where users write to interface and the world 


    
## Public Functions Documentation




### function Contains 

_Checks if a point is within the_ [_**TextBox**_](classi__2_d_1_1_text_box.md) _._
```C++
inline bool i_2D::TextBox::Contains (
    sf::Vector2f point
) const
```





**Parameters:**


* `point` an xy point to check the location of 



**Returns:**

True if the point is in bounds, False otherwise 





        



### function DrawTo 

_Draws the text to the render window._ 
```C++
void i_2D::TextBox::DrawTo (
    sf::RenderWindow & window
) 
```





**Parameters:**


* `window` The render window to be drawn on 




        



### function GetText 

_Get the string that was input by user._ 
```C++
inline std::string i_2D::TextBox::GetText () 
```





**Returns:**

Return the string 





        



### function IsSelected 

_Checks if_ [_**TextBox**_](classi__2_d_1_1_text_box.md) _is active._
```C++
inline bool i_2D::TextBox::IsSelected () const
```





**Returns:**

True if active, else False 





        



### function SetFont 

_Set the font of the_ [_**TextBox**_](classi__2_d_1_1_text_box.md) _._
```C++
inline void i_2D::TextBox::SetFont (
    const sf::Font & font
) 
```





**Parameters:**


* `font` The font to be set to 




        



### function SetLimit [1/2]

_Set the limit of the_ [_**TextBox**_](classi__2_d_1_1_text_box.md) _._
```C++
inline void i_2D::TextBox::SetLimit (
    bool ToF
) 
```





**Parameters:**


* `ToF` True of False 




        



### function SetLimit [2/2]

_Set the limit of the_ [_**TextBox**_](classi__2_d_1_1_text_box.md) _._
```C++
inline void i_2D::TextBox::SetLimit (
    bool ToF,
    int lim
) 
```





**Parameters:**


* `ToF` True or False 
* `lim` The limit of the [**TextBox**](classi__2_d_1_1_text_box.md) 




        



### function SetPosition 

_The position of the_ [_**TextBox**_](classi__2_d_1_1_text_box.md) _._
```C++
inline void i_2D::TextBox::SetPosition (
    sf::Vector2f pos
) 
```





**Parameters:**


* `pos` The position to be set to 




        



### function SetSelected 

_Setter for isSelected, updates the text displayed in the box._ 
```C++
void i_2D::TextBox::SetSelected (
    bool sel
) 
```





**Parameters:**


* `sel` whether the [**TextBox**](classi__2_d_1_1_text_box.md) is to be set selected or not 




        



### function SetString 

_Set the string of the text._ 
```C++
void i_2D::TextBox::SetString (
    const std::string & s
) 
```





**Parameters:**


* `s` The string to be set to 




        



### function TextBox [1/2]

```C++
i_2D::TextBox::TextBox () = default
```






### function TextBox [2/2]

_Constructor._ 
```C++
explicit i_2D::TextBox::TextBox (
    const sf::Font & font,
    int size=25,
    sf::Color color=sf::Color::Red,
    bool sel=false
) 
```





**Parameters:**


* `font` The font used by [**TextBox**](classi__2_d_1_1_text_box.md) 
* `size` The size of the text 
* `color` The color of the text 
* `sel` Set the activity of [**TextBox**](classi__2_d_1_1_text_box.md) 




        



### function TypedOn 

_TypedOn event handler._ 
```C++
void i_2D::TextBox::TypedOn (
    sf::Event input
) 
```





**Parameters:**


* `input` the new text that has been typed into the [**TextBox**](classi__2_d_1_1_text_box.md) 




        

------------------------------
The documentation for this class was generated from the following file `source/Interfaces/TextBox.hpp`

