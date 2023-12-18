

# Class i\_2D::Inventory



[**ClassList**](annotated.md) **>** [**i\_2D**](namespacei__2_d.md) **>** [**Inventory**](classi__2_d_1_1_inventory.md)










































## Public Functions

| Type | Name |
| ---: | :--- |
|  void | [**ConstructInventory**](#function-constructinventory) (sf::Font & font, const std::vector&lt; std::string &gt; & interfaceAgentInventory) <br>_Build an inventory window and an inventory list._  |
|  void | [**DrawTo**](#function-drawto) (sf::RenderWindow & window) <br>_Draws the inventory onto the render window._  |
|  std::string | [**HandleMouseMove**](#function-handlemousemove) (sf::RenderWindow & window) <br>_Handle the mouse move event._  |
|   | [**Inventory**](#function-inventory) (const sf::Vector2f size) <br>_Constructor - save the value of the world's dimension._  |
|  void | [**SetItemDisplay**](#function-setitemdisplay) (sf::Texture & texture) <br>_Set the Displayed item's texture._  |
|  void | [**SetSize**](#function-setsize) (const sf::Vector2f size) <br>_Set the value saved as the world's dimension._  |




























## Public Functions Documentation




### function ConstructInventory 

_Build an inventory window and an inventory list._ 
```C++
void i_2D::Inventory::ConstructInventory (
    sf::Font & font,
    const std::vector< std::string > & interfaceAgentInventory
) 
```





**Parameters:**


* `font` The font used by the inventory list 




        



### function DrawTo 

_Draws the inventory onto the render window._ 
```C++
void i_2D::Inventory::DrawTo (
    sf::RenderWindow & window
) 
```





**Parameters:**


* `window` The render window of the world 




        



### function HandleMouseMove 

_Handle the mouse move event._ 
```C++
std::string i_2D::Inventory::HandleMouseMove (
    sf::RenderWindow & window
) 
```





**Parameters:**


* `window` The render window of the world 




        



### function Inventory 

```C++
inline explicit i_2D::Inventory::Inventory (
    const sf::Vector2f size
) 
```






### function SetItemDisplay 

```C++
inline void i_2D::Inventory::SetItemDisplay (
    sf::Texture & texture
) 
```






### function SetSize 

```C++
inline void i_2D::Inventory::SetSize (
    const sf::Vector2f size
) 
```




------------------------------
The documentation for this class was generated from the following file `source/Interfaces/Inventory.hpp`

