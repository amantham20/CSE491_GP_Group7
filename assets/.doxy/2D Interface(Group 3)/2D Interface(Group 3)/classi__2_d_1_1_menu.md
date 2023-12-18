

# Class i\_2D::Menu



[**ClassList**](annotated.md) **>** [**i\_2D**](namespacei__2_d.md) **>** [**Menu**](classi__2_d_1_1_menu.md)










































## Public Functions

| Type | Name |
| ---: | :--- |
|  void | [**ConstructInventory**](#function-constructinventory) (const std::vector&lt; std::string &gt; & interfaceAgentInventory) <br>_Builds an inventory._  |
|  void | [**DeconstructInventory**](#function-deconstructinventory) () <br>_Destroy the inventory object._  |
|  void | [**DrawTo**](#function-drawto) (sf::RenderWindow & window) <br>_draws each menu button to the window_  |
|  std::vector&lt; std::unique\_ptr&lt; [**Button**](classi__2_d_1_1_button.md) &gt; &gt; & | [**GetMenu**](#function-getmenu) () <br>_Getter for MenuBar._  |
|  void | [**HandleMouseButtonPressed**](#function-handlemousebuttonpressed) (sf::RenderWindow & window, const std::vector&lt; std::string &gt; & interfaceAgentInventory) <br>_check if the mouse click the exit button closes window accordingly_  |
|  std::string | [**HandleMouseMove**](#function-handlemousemove) (sf::RenderWindow & window) <br>_check for mouse hoovering over the menu buttons change button color accordingly_  |
|  void | [**Initialize**](#function-initialize) (sf::Font & font, sf::Vector2f size) <br>_initialize the buttons at the top of the window_  |
|  bool | [**IsInventoryOpen**](#function-isinventoryopen) () <br>_Check if the inventory interface is open._  |
|  void | [**SetInventoryItemDisplay**](#function-setinventoryitemdisplay) (sf::Texture & texture) <br> |
|  void | [**SetWorldSize**](#function-setworldsize) (sf::Vector2f size) <br>_Keep track of the world's size._  |




























## Public Functions Documentation




### function ConstructInventory 

```C++
inline void i_2D::Menu::ConstructInventory (
    const std::vector< std::string > & interfaceAgentInventory
) 
```






### function DeconstructInventory 

```C++
inline void i_2D::Menu::DeconstructInventory () 
```






### function DrawTo 

_draws each menu button to the window_ 
```C++
void i_2D::Menu::DrawTo (
    sf::RenderWindow & window
) 
```





**Parameters:**


* `window` the main window of the graphic interface 




        



### function GetMenu 

_Getter for MenuBar._ 
```C++
inline std::vector< std::unique_ptr< Button > > & i_2D::Menu::GetMenu () 
```





**Returns:**

MenuBar 





        



### function HandleMouseButtonPressed 

_check if the mouse click the exit button closes window accordingly_ 
```C++
void i_2D::Menu::HandleMouseButtonPressed (
    sf::RenderWindow & window,
    const std::vector< std::string > & interfaceAgentInventory
) 
```





**Parameters:**


* `window` the main window of the graphic interface 




        



### function HandleMouseMove 

_check for mouse hoovering over the menu buttons change button color accordingly_ 
```C++
std::string i_2D::Menu::HandleMouseMove (
    sf::RenderWindow & window
) 
```





**Parameters:**


* `window` the main window of the graphic interface 




        



### function Initialize 

```C++
void i_2D::Menu::Initialize (
    sf::Font & font,
    sf::Vector2f size
) 
```






### function IsInventoryOpen 

_Check if the inventory interface is open._ 
```C++
inline bool i_2D::Menu::IsInventoryOpen () 
```





**Returns:**

True if inventory interface is on, otherwise false 





        



### function SetInventoryItemDisplay 


```C++
inline void i_2D::Menu::SetInventoryItemDisplay (
    sf::Texture & texture
) 
```





**Parameters:**


* `texture` 




        



### function SetWorldSize 

_Keep track of the world's size._ 
```C++
inline void i_2D::Menu::SetWorldSize (
    sf::Vector2f size
) 
```





**Parameters:**


* `size` Size of the world 




        

------------------------------
The documentation for this class was generated from the following file `source/Interfaces/Menu.hpp`

