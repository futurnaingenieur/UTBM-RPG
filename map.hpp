#ifndef MAP_HPP_INCLUDED
#define MAP_HPP_INCLUDED
#include <string>
#include "cacheimgfiles.hpp"
#include "gate.hpp"

using namespace sf;

class Map
{
private:
    RenderWindow* window;
    std::string map_filename;
public:
    Gate map_gate;
    int collision_matrix[24][16];
    char tile_set_matrix[24][16];
    CacheImgFiles images_storage;
    Map(std::string,RenderWindow*);
    void setMapFilename(std::string);
    void getMap();
    void drawMap();
};

#endif // MAP_HPP_INCLUDED
