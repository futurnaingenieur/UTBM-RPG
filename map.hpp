#ifndef MAP_HPP_INCLUDED
#define MAP_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <string>

using namespace sf;

class Map
{
private :
    RenderWindow*window;
    bool matrix[24][16]; /// true : on peut marcher ; false : bloc
    std::string filename; /// on charge un fichier contenant les infos de mapping
public:
    Map(std::string,RenderWindow*); /// décla du constructeur
    void drawMap();
};

#endif // MAP_HPP_INCLUDED
