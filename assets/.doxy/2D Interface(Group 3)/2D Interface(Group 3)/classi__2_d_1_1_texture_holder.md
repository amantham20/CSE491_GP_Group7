

# Class i\_2D::TextureHolder



[**ClassList**](annotated.md) **>** [**i\_2D**](namespacei__2_d.md) **>** [**TextureHolder**](classi__2_d_1_1_texture_holder.md)










































## Public Functions

| Type | Name |
| ---: | :--- |
|  std::map&lt; char, sf::Texture &gt; | [**GenerativeWorldTexture**](#function-generativeworldtexture) () <br>_This function loads texture for the generative world images group 6._  |
|  const sf::Texture & | [**GetTexture**](#function-gettexture) (std::string id) <br>_Returns a held texture matching the given id._  |
|  void | [**LoadTexture**](#function-loadtexture) (std::string id, std::string file\_name) <br>_Stores a texture under the given id/name;._  |
|  std::map&lt; char, sf::Texture &gt; | [**ManualWorldTexture**](#function-manualworldtexture) () <br>_This function loads texture for the manual world images group 8._  |
|  std::map&lt; char, sf::Texture &gt; | [**MazeTexture**](#function-mazetexture) () <br>_This function loads texture for the maze world images - Default maze._  |
|  std::map&lt; char, sf::Texture &gt; | [**SecondWorldTexture**](#function-secondworldtexture) () <br>_This function loads texture for the second world images group 4._  |
|   | [**TextureHolder**](#function-textureholder) () = default<br> |
|   | [**~TextureHolder**](#function-textureholder) () = default<br> |




























## Public Functions Documentation




### function GenerativeWorldTexture 

_This function loads texture for the generative world images group 6._ 
```C++
std::map< char, sf::Texture > i_2D::TextureHolder::GenerativeWorldTexture () 
```





**Returns:**

std::map&lt; name, texture&gt; returns the map, key is the name of the texture and values is the actual texture 





        



### function GetTexture 

_Returns a held texture matching the given id._ 
```C++
const sf::Texture & i_2D::TextureHolder::GetTexture (
    std::string id
) 
```





**Parameters:**


* `id` Identifier/Name of the texture stored. 



**Returns:**

The sf::Texture matching the id. 





        



### function LoadTexture 

_Stores a texture under the given id/name;._ 
```C++
void i_2D::TextureHolder::LoadTexture (
    std::string id,
    std::string file_name
) 
```





**Parameters:**


* `id` Identifier used to reference this texture in the future. 
* `file_name` File to load the texture from. 




        



### function ManualWorldTexture 

_This function loads texture for the manual world images group 8._ 
```C++
std::map< char, sf::Texture > i_2D::TextureHolder::ManualWorldTexture () 
```





**Returns:**

std::map&lt; name, texture&gt; returns the map, key is the name of the texture and values is the actual texture 





        



### function MazeTexture 

_This function loads texture for the maze world images - Default maze._ 
```C++
std::map< char, sf::Texture > i_2D::TextureHolder::MazeTexture () 
```





**Returns:**

std::map&lt; name, texture&gt; returns the map, key is the name of the texture and values is the actual texture 





        



### function SecondWorldTexture 

_This function loads texture for the second world images group 4._ 
```C++
std::map< char, sf::Texture > i_2D::TextureHolder::SecondWorldTexture () 
```





**Returns:**

std::map&lt; name, texture&gt; returns the map, key is the name of the texture and values is the actual texture 





        



### function TextureHolder 

```C++
i_2D::TextureHolder::TextureHolder () = default
```






### function ~TextureHolder 

```C++
i_2D::TextureHolder::~TextureHolder () = default
```




------------------------------
The documentation for this class was generated from the following file `source/Interfaces/TextureHolder.hpp`

