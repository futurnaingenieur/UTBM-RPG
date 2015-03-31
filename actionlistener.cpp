#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include "actionlistener.hpp"

using namespace sf;

ActionListener::ActionListener(RenderWindow* input_window, Hero* input_hero,Map* input_map_base)
{
    window=input_window;
    hero=input_hero;
    map_base=input_map_base;
}

void ActionListener::listen()
{
    Event event;

    while(window->pollEvent(event))
        {
            switch(event.type)
            {
            case Event::Closed:
                window->close();
                break;
            case Event::KeyPressed:
                if(Keyboard::isKeyPressed(Keyboard::Escape))
                    window->close();
                if(Keyboard::isKeyPressed(Keyboard::Left))
                    hero->moveHeroLeft();
                if(Keyboard::isKeyPressed(Keyboard::Right))
                    hero->moveHeroRight();
                if(Keyboard::isKeyPressed(Keyboard::Up))
                    hero->moveHeroUp();
                if(Keyboard::isKeyPressed(Keyboard::Down))
                    hero->moveHeroDown();
                if(Keyboard::isKeyPressed(Keyboard::A))
                {
                    map_base->setMapFilename("maps/map_debug.map");
                    map_base->getMap();
                }
                if(Keyboard::isKeyPressed(Keyboard::Z))
                {
                    map_base->setMapFilename("maps/map_1.map");
                    map_base->getMap();
                }
                if(Keyboard::isKeyPressed(Keyboard::E))
                {
                    map_base->setMapFilename("maps/map_2.map");
                    map_base->getMap();
                }
                break;
            case Event::KeyReleased:
                map_base->images_storage.setIndexTextureHero(0);
                break;
            default:
                break;
            }
        }
}
