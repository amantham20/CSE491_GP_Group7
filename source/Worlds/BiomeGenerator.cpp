/**
 * @file BiomeGenerator.cpp
 * @author Paul Schulte, Milan Mihailovic, ChatGPT
 */

#include "BiomeGenerator.hpp"

#include <cmath>
#include <tuple>
#include <random>

using namespace group6;
using namespace cse491;

using std::vector;

/**
 * Creates a generator with a grid of the given size and using the given seed
 * @param biome  The biome of the grid
 * @param width  The width of the grid
 * @param height The height of the grid
 * @param seed   The seed used for random number generation
 */
BiomeGenerator::BiomeGenerator(BiomeType biome, unsigned int width, unsigned int height, unsigned int seed) : biome(biome), width(width), height(height), seed(seed) {
    if (biome == BiomeType::Maze) {
        setTiles(floor_id, wall_id);
    } else if (biome == BiomeType::Grasslands) {
        setTiles(grass_id, dirt_id);
    }

    perlinNoise = PerlinNoise(seed);
    grid.Resize(width, height);
}

/**
 * Generates the grid with two types of tiles
 */
void BiomeGenerator::generate() {
    size_t tile1 = tiles[0];
    size_t tile2 = tiles[1];

    for (unsigned int y = 0; y < height; y++) {
        for (unsigned int x = 0; x < width; x++) {
            const double val = perlinNoise.noise2D(x * frequency / width, y * frequency / height);
            grid.At(x, y) = val < 0 ? tile1 : tile2;
        }
    }


    if (biome == BiomeType::Maze) {
        placeSpecialTiles(tile1, spike_id, 0.02); // Placing spike tiles
        placeSpecialTiles(tile1, tar_id, 0.05); // Placing tar tiles
        placeDoorTile(door_id); // placing door tile
        placeKeyTile(key_id); // placing key tile
    }

    if (biome == BiomeType::Grasslands) {
//        placeTrees(); // Placing tree tiles
    }
}

/**
 * Generates random coordinate to place Key tile
 * @param keyTile  Door Tile
 */
void BiomeGenerator::placeKeyTile(const size_t &keyTile) {
    bool counter = false;
    while (!counter) {
        std::random_device rd;
        std::mt19937 gen(rd());

        std::uniform_int_distribution<int> x_distribution(width / 2, width - 1);
        std::uniform_int_distribution<int> y_distribution(height / 2, height - 1);
        int random_x = x_distribution(gen);
        int random_y = y_distribution(gen);

        if (grid.At(random_x, random_y) == floor_id) {
            grid.At(random_x, random_y) = keyTile;
            counter = true;
        }
    }
}

/**
 * Generates door tile on grid at [1][1]
 * @param doorTile  Door Tile
 */
void BiomeGenerator::placeDoorTile(const size_t &doorTile) {
    grid.At(1, 1) = doorTile;
}

/**
 * Generates special tiles on the grid
 * @param genericTile  The tile that the special tile can spawn on
 * @param specialTile The special tile to generate
 * @param percentage Chance of special tile generating on the generic tile
 */
void BiomeGenerator::placeSpecialTiles(const size_t &genericTile, const size_t &specialTile, double percentage) {
    std::vector<std::pair<int, int>> floorPositions;
    for (unsigned int x = 0; x < width; ++x) {
        for (unsigned int y = 0; y < height; ++y) {
            if (grid.At(x, y) == genericTile) {
                floorPositions.emplace_back(x, y);
            }
        }
    }

    int numSpikes = floorPositions.size() * percentage;
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(floorPositions.begin(), floorPositions.end(), g);

    // Convert some generic floor tiles to special tiles
    for (int i = 0; i < numSpikes; ++i) {
        grid.At(floorPositions[i].first, floorPositions[i].second) = specialTile;
    }

}

/**
 * Clears a randomized path from the top left of the
 * grid, to any point on the rightmost side of the map
 * @return A vector of GridPositions necessary for this path
 */
std::vector<GridPosition> BiomeGenerator::clearPath() const {
    std::vector<GridPosition> path;

    GridPosition current(0, 0);
    path.push_back(current);

    while (current.GetX() < width - 1) {
        int randDirection = rand() % 3; // 0: Right, 1: Up, 2: Down

        // Choose next point based on random direction
        GridPosition next = current;
        if (randDirection == 0) {
            next = next.ToRight();
        } else if (randDirection == 1) {
            if (next.GetY() > 0) // Ensure within grid bounds
                next = next.Above();
        } else {
            if (next.GetY() < height - 1) // Ensure within grid bounds
                next = next.Below();
        }

        // If the next point is the same as the current, then we chose an invalid direction
        // (like trying to go up at the top edge), so just skip this iteration.
        if (next != current) {
            path.push_back(next);
            current = next;
        }
    }

    return path;
}

/**
 * Clears the walls out of the grid, guaranteeing a path from the
 * left of the grid, to any point on the rightmost side of the map
 * @param path A vector of GridPositions necessary for this path
 */
void BiomeGenerator::applyPathToGrid(const std::vector<GridPosition> &path) {
    for (const GridPosition &p: path) {
        grid.At(p.GetX(), p.GetY()) = floor_id;
    }
}

/**
 * Saves the grid to the given filepath
 * @param filename The filename the grid will be saved to
 */
void BiomeGenerator::saveToFile(const std::string &filename) const {
    type_options_t types = type_options_t();

    //TODO: Remove when refactoring
    types.push_back(CellType{"floor", "Floor that you can easily walk over.", ' '});
    types.push_back(CellType{"wall", "Impenetrable wall that you must find a way around.", '#'});
    types.push_back(CellType{"spike", "Dangerous spike that resets the game.", 'X'});
    types.push_back(CellType{"tar", "Slow tile that makes you take two steps to get through it", 'O'});
    types.push_back(CellType{"key", "item that can be picked up to unlock door and escape maze", 'K'});
    types.push_back(CellType{"door", "Door that can be walked through only with possession of key to leave maze", 'D'});
    types.push_back(CellType{"grass", "Grass you can walk on.", 'M'});
    types.push_back(CellType{"dirt", "Dirt you can walk on.", '~'});
    types.push_back(CellType{"tree", "A tree that blocks the way.", 't'});


    grid.Write(filename, types);

}

/**
 * Sets the tile vector for the biome
 * @param firstTile Tile #1 for the biome
 * @param secondTile Tile #2 for the biome
 */
void BiomeGenerator::setTiles(const size_t &firstTile, const size_t &secondTile) {
    tiles.clear();
    tiles.push_back(firstTile);
    tiles.push_back(secondTile);
}

void BiomeGenerator::placeTrees() {

    std::vector<std::pair<int, int>> grassPositions;
    for (unsigned int x = 0; x < width; ++x) {
        for (unsigned int y = 0; y < height; ++y) {
            if (grid.At(x, y) == grass_id) {
                grassPositions.emplace_back(x, y);
            }
        }
    }

    // Random number generation setup
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dis(0.0, 1.0);

    // Chance of tree appearing on a grass tile
    const double treeChance = 0.1; // 10% chance for a tree to appear on any grass tile

    for (const auto& position : grassPositions) {
        // Randomly decide if a tree should be placed
        if (dis(gen) < treeChance) {
            grid.At(position.first, position.second) = 't'; // Replace 'M' with 't' for tree
        }
    }
}


