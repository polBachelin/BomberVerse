/*
** EPITECH PROJECT, 2021
** indieStudio
** File description:
** Map
*/

#ifndef MAP_HPP_
#define MAP_HPP_

#define MAPWALL  1
#define MAPPATH  0
#define MAPBRICK 2
#define MAPBORDR 3
#define TILESIZE 320

#define MINSIZE 5
#define SIZE_X  (_size)
#define SIZE_Y  (_size + 2)
#define EVEN(a) !(a % 2)
#define ODD(a)  (a % 2)
#define SPAWN1  ((i == 1 || i == 2 || i == SIZE_X - 2 || i == SIZE_X - 3) && j == 1)
#define SPAWN2  ((i == 1 || i == SIZE_X - 2) && j == 2)
#define SPAWN3  ((i == 1 || i == SIZE_X - 2) && j == SIZE_Y - 3)
#define SPAWN4  ((i == 1 || i == 2 || i == SIZE_X - 2 || i == SIZE_X - 3) && j == SIZE_Y - 2)

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <vector>
#include <string>
#include <memory>
#include "Tile.hpp"

#define BLOCKPATHOBJ  (std::string)"./resources/models/minecraft/blocks/cube.obj"
#define WALLTILEPNG   (std::string)"./resources/models/minecraft/blocks/Stone.png"
#define BRICKTILEPNG  (std::string)"./resources/models/minecraft/blocks/Wood.png"
#define PATHTILEPNG   (std::string)"./resources/models/minecraft/blocks/Grass.png"
#define BORDERTILEPNG (std::string)"./resources/models/minecraft/blocks/Cobble.png"

using namespace game::objects;

namespace game::objects {
    class Map {
        public:
            Map(const std::size_t &, const std::size_t &seed = 0);
            ~Map();

            // memeber functions
            void generateSeed();
            void generateMap();
            void generateTales();
            void generateMapTiles();
            void newMap();
            void dump();
            void draw();

            // getters
            std::size_t getSize() const;
            std::size_t getSeed() const;
            std::vector<std::vector<int>> getMap() const;

            // setters
            void setSize(const std::size_t &);
            void setSeed(const std::size_t &);

        protected:
        private:
            std::vector<std::vector<int>> _map;
            std::size_t _size;
            std::size_t _seed;
            std::unique_ptr<Tile> _wall;
            std::unique_ptr<Tile> _path;
            std::unique_ptr<Tile> _brick;
            std::unique_ptr<Tile> _border;
    };
}


#endif /* !MAP_HPP_ */