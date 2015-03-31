#include <SFML/Graphics.hpp>
#include <string>
#include "element.hpp"

using namespace sf;

Element::Element(int input_x,int input_y)
{
    dimensions.x=input_x;
    dimensions.y=input_y;
    rectangle.setSize(dimensions);
}

void Element::setTexture(Texture input_texture)
{
    rectangle.setTexture(&input_texture);
}

void Element::setPosition(Vector2f input_position)
{
    rectangle.setPosition(input_position);
}
