#ifndef HERO_HPP_INCLUDED
#define HERO_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <string>
#include "map.hpp"
#include "element.hpp"

using namespace sf;

class Hero
{
private:
    int walk;
    Vector2f position;
    RenderWindow* window;
    Map* map_base;
public:
    RectangleShape rectangle;
    Hero(RenderWindow*,Map*);
    void moveHeroLeft();
    void moveHeroRight();
    void moveHeroUp();
    void moveHeroDown();
    void checkGate();
    void fixPosition();
    void drawHero();
};

#endif // HERO_HPP_INCLUDED
