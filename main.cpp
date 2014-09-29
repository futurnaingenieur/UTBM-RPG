#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;

int main(int argc,char**argv)
{
    RenderWindow window(VideoMode(1200,800,32),"UTBM RPG");
    window.setFramerateLimit(60);

    Event event;

    while(window.isOpen())
    {
        window.clear();

        while(window.pollEvent(event))
        {
            switch(event.type)
            {
            case Event::Closed:
                window.close();
                break;
            default:
                break;
            }
        }
        window.display();
    }
}
