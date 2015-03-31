#ifndef ELEMENT_HPP_INCLUDED
#define ELEMENT_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <string>

using namespace sf;

class Element
{
private:
    Vector2f dimensions;
public:
    RectangleShape rectangle;
    Element(int,int);
    void setTexture(Texture);
    void setPosition(Vector2f);
};

#endif // ELEMENT_HPP_INCLUDED
