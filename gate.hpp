#ifndef GATE_HPP_INCLUDED
#define GATE_HPP_INCLUDED
#include <SFML/Graphics.hpp>
#include <string>

using namespace sf;

class Gate
{
private:

public:
    Vector2f location_from[20];
    std::string destination_map_filename[20];
    Vector2f location_to[];

    Gate();
    void addGate(Vector2f,std::string,Vector2f);
    void rebootGate();
};

#endif // GATE_HPP_INCLUDED
