#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "game.hpp"
#include "map.hpp"
#include "hero.hpp"
#include "actionlistener.hpp"

using namespace sf;

Game::Game(){}

void Game::launch()
{
    std::cout<<"\n\n   *** RPG UTBM CONSOLE ***\n\n\nLaunching process with success\n"<<std::endl;

    RenderWindow window(VideoMode(1200,800,32),"GAME");
    window.setFramerateLimit(60);

    Map map_base("maps/map_riverotte_north.map",&window);
    map_base.getMap();

    Hero hero(&window,&map_base);

    ActionListener al(&window,&hero,&map_base);

    /*Music music;
    if(music.openFromFile("musics/music_1.ogg"))
        music.play();*/

    while(window.isOpen())
    {
        window.clear();

        al.listen();

        map_base.drawMap();
        hero.drawHero();
        window.display();
    }

    std::cout<<"\n\nEnd process with success\n\n\n"<<std::endl;
    std::cout<<"   *** THANK YOU ***\n\n\n\n"<<std::endl;
}
