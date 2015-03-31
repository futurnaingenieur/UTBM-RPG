#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "gate.hpp"

Gate::Gate()
{
    for(int i=0;i<20;i++)
    {
        location_from[i]=Vector2f(-1,-1);
        destination_map_filename[i]="none";
        location_to[i]=Vector2f(-1,-1);
    }
}

void Gate::addGate(Vector2f input_location_from,std::string input_destination_map_filename,Vector2f input_location_to)
{
    int i=0;
    while(location_from[i]!=Vector2f(-1,-1) && i<20)
    {
        i++;
    }
    if(i<20)
    {
        location_from[i]=input_location_from;
        destination_map_filename[i]=input_destination_map_filename;
        location_to[i]=input_location_to;
    }
}

void Gate::rebootGate()
{
    for(int i=0;i<20;i++)
    {
        location_from[i]=Vector2f(-1,-1);
        location_to[i]=Vector2f(-1,-1);
    }
}
