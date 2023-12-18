

# Class group6::BiomeGenerator



[**ClassList**](annotated.md) **>** [**group6**](namespacegroup6.md) **>** [**BiomeGenerator**](classgroup6_1_1_biome_generator.md)



[More...](#detailed-description)

* `#include <BiomeGenerator.hpp>`





































## Public Functions

| Type | Name |
| ---: | :--- |
|   | [**BiomeGenerator**](#function-biomegenerator) (BiomeType biome, unsigned int width, unsigned int height, unsigned int seed) <br> |
|  void | [**applyPathToGrid**](#function-applypathtogrid) (const std::vector&lt; GridPosition &gt; & path) <br> |
|  std::vector&lt; GridPosition &gt; | [**clearPath**](#function-clearpath) () const<br> |
|  void | [**generate**](#function-generate) () <br> |
|  BiomeType | [**getBiome**](#function-getbiome) () const<br> |
|  unsigned int | [**getSeed**](#function-getseed) () const<br> |
|  void | [**oceanHandler**](#function-oceanhandler) () <br> |
|  void | [**placeDoorTile**](#function-placedoortile) (const size\_t & doorTile) <br> |
|  void | [**placeSpecialTiles**](#function-placespecialtiles) (const size\_t & genericTile, const size\_t & specialTile, double percentage) <br> |
|  void | [**placeTileRandom**](#function-placetilerandom) (const size\_t & tile, const size\_t & spawnTile) <br> |
|  void | [**placeTrees**](#function-placetrees) () <br> |
|  void | [**saveToFile**](#function-savetofile) (const std::string & filename) const<br> |
|  void | [**setTiles**](#function-settiles) (const size\_t & firstTile, const size\_t & secondTile) <br> |
|  void | [**setWorld**](#function-setworld) (WorldBase \* world) <br> |
|   | [**~BiomeGenerator**](#function-biomegenerator) () = default<br> |




























# Detailed Description


Generates a new grid based on a specified biome 


    
## Public Functions Documentation




### function BiomeGenerator 


```C++
group6::BiomeGenerator::BiomeGenerator (
    BiomeType biome,
    unsigned int width,
    unsigned int height,
    unsigned int seed
) 
```



Creates a generator with a grid of the given size and using the given seed 

**Parameters:**


* `biome` The biome of the grid 
* `width` The width of the grid 
* `height` The height of the grid 
* `seed` The seed used for random number generation 




        



### function applyPathToGrid 


```C++
void group6::BiomeGenerator::applyPathToGrid (
    const std::vector< GridPosition > & path
) 
```



Clears the walls out of the grid, guaranteeing a path from the left of the grid, to any point on the rightmost side of the map 

**Parameters:**


* `path` A vector of GridPositions necessary for this path 




        



### function clearPath 


```C++
std::vector< GridPosition > group6::BiomeGenerator::clearPath () const
```



Clears a randomized path from the top left of the grid, to any point on the rightmost side of the map 

**Returns:**

A vector of GridPositions necessary for this path 





        



### function generate 


```C++
void group6::BiomeGenerator::generate () 
```



Generates the grid with two types of tiles 


        



### function getBiome 

```C++
inline BiomeType group6::BiomeGenerator::getBiome () const
```






### function getSeed 

```C++
inline unsigned int group6::BiomeGenerator::getSeed () const
```






### function oceanHandler 


```C++
void group6::BiomeGenerator::oceanHandler () 
```



Handles logic for Ocean biome 


        



### function placeDoorTile 


```C++
void group6::BiomeGenerator::placeDoorTile (
    const size_t & doorTile
) 
```



Generates door tile on grid at [1][1] 

**Parameters:**


* `doorTile` Door Tile 




        



### function placeSpecialTiles 


```C++
void group6::BiomeGenerator::placeSpecialTiles (
    const size_t & genericTile,
    const size_t & specialTile,
    double percentage
) 
```



Generates special tiles on the grid 

**Parameters:**


* `genericTile` The tile that the special tile can spawn on 
* `specialTile` The special tile to generate 
* `percentage` Chance of special tile generating on the generic tile 




        



### function placeTileRandom 


```C++
void group6::BiomeGenerator::placeTileRandom (
    const size_t & tile,
    const size_t & spawnTile
) 
```



Generates random coordinates to place the given tile




**Parameters:**


* `tile` The tile being placed 
* `spawnTile` The type of tile allowed to be replaced 




        



### function placeTrees 


```C++
void group6::BiomeGenerator::placeTrees () 
```



Places trees on the grid 


        



### function saveToFile 


```C++
void group6::BiomeGenerator::saveToFile (
    const std::string & filename
) const
```



Saves the grid to the given filepath 

**Parameters:**


* `filename` The filename the grid will be saved to 




        



### function setTiles 


```C++
void group6::BiomeGenerator::setTiles (
    const size_t & firstTile,
    const size_t & secondTile
) 
```



Sets the tile vector for the biome 

**Parameters:**


* `firstTile` Tile #1 for the biome 
* `secondTile` Tile #2 for the biome 




        



### function setWorld 

```C++
void group6::BiomeGenerator::setWorld (
    WorldBase * world
) 
```






### function ~BiomeGenerator 

```C++
group6::BiomeGenerator::~BiomeGenerator () = default
```




------------------------------
The documentation for this class was generated from the following file `source/Worlds/BiomeGenerator.hpp`

