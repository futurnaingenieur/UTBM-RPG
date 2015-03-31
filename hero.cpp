#include <iostream>
#include <SFML/Graphics.hpp>
#include "map.hpp"
#include "hero.hpp"

#define SPEED 10 /// METTRE SPEED A 10 !!!! SAUF POUR DEBUG/TEST

using namespace sf;

Hero::Hero(RenderWindow* input_window,Map* input_map_base):
    position(Vector2f(200,200)),
    window(input_window),
    map_base(input_map_base)
{
    rectangle.setSize(Vector2f(50,100));
    walk=0;
}

void Hero::moveHeroLeft()
{
    if(walk==0)
    {
        map_base->images_storage.setIndexTextureHero(4);
        walk=1;
    }
    else
    {
        map_base->images_storage.setIndexTextureHero(3);
        walk=0;
    }

    int collision_x=position.x/50;
    int collision_y=position.y/50;
    if((int)position.x%50==0)
        {
            if ((int)position.y%50==0)
            {
                if(map_base->collision_matrix[collision_x-1][collision_y+1]!=0)
                {
                    if(map_base->collision_matrix[collision_x][collision_y+1]==1){position.x-=SPEED;}
                    if(map_base->collision_matrix[collision_x][collision_y+1]==2){position.x-=SPEED;}
                }
            }
            else if(map_base->collision_matrix[collision_x-1][collision_y+1]!=0 && map_base->collision_matrix[collision_x-1][collision_y+2]!=0)
            {
                if(map_base->collision_matrix[collision_x][collision_y+1]==1){position.x-=SPEED;}
                if(map_base->collision_matrix[collision_x][collision_y+1]==2){position.x-=SPEED;}
            }
        }
        else
        {
            if(map_base->collision_matrix[collision_x][collision_y+1]==1){position.x-=SPEED;}
            if(map_base->collision_matrix[collision_x][collision_y+1]==2){position.x-=SPEED;}
        }
    checkGate();
}

void Hero::moveHeroRight()
{
    if(walk==0)
    {
        map_base->images_storage.setIndexTextureHero(2);
        walk=1;
    }
    else
    {
        map_base->images_storage.setIndexTextureHero(1);
        walk=0;
    }

    int collision_x=position.x/50;
    int collision_y=position.y/50;
    if((int)position.x%50==0)
        {
            if ((int)position.y%50==0)
            {
                if(map_base->collision_matrix[collision_x+1][collision_y+1]!=0)
                {
                    if(map_base->collision_matrix[collision_x][collision_y+1]==1){position.x+=SPEED;}
                    if(map_base->collision_matrix[collision_x][collision_y+1]==2){position.x+=SPEED;}
                }
            }
            else if(map_base->collision_matrix[collision_x+1][collision_y+1]!=0 && map_base->collision_matrix[collision_x+1][collision_y+2]!=0)
            {
                if(map_base->collision_matrix[collision_x][collision_y+1]==1){position.x+=SPEED;}
                if(map_base->collision_matrix[collision_x][collision_y+1]==2){position.x+=SPEED;}
            }
        }
        else
        {
            if(map_base->collision_matrix[collision_x][collision_y+1]==1){position.x+=SPEED;}
            if(map_base->collision_matrix[collision_x][collision_y+1]==2){position.x+=SPEED;}
        }
    checkGate();
}

void Hero::moveHeroUp()
{
    if(walk==0)
    {
        map_base->images_storage.setIndexTextureHero(2);
        walk=1;
    }
    else
    {
        map_base->images_storage.setIndexTextureHero(1);
        walk=0;
    }

    int collision_x=position.x/50;
    int collision_y=position.y/50;
    if((int)position.y%50==0)
        {
            if ((int)position.x%50==0)
            {
                if(map_base->collision_matrix[collision_x][collision_y]!=0)
                {
                    if(map_base->collision_matrix[collision_x][collision_y+1]==1){position.y-=SPEED;}
                    if(map_base->collision_matrix[collision_x][collision_y+1]==2){position.y-=SPEED;}
                }
            }
            else if(map_base->collision_matrix[collision_x][collision_y]!=0 && map_base->collision_matrix[collision_x+1][collision_y]!=0)
            {
                if(map_base->collision_matrix[collision_x][collision_y+1]==1){position.y-=SPEED;}
                if(map_base->collision_matrix[collision_x][collision_y+1]==2){position.y-=SPEED;}
            }
        }
        else
        {
            if(map_base->collision_matrix[collision_x][collision_y+1]==1){position.y-=SPEED;}
            if(map_base->collision_matrix[collision_x][collision_y+1]==2){position.y-=SPEED;}
        }
    checkGate();
}

void Hero::moveHeroDown()
{
    if(walk==0)
    {
        map_base->images_storage.setIndexTextureHero(4);
        walk=1;
    }
    else
    {
        map_base->images_storage.setIndexTextureHero(3);
        walk=0;
    }

    int collision_x=position.x/50;
    int collision_y=position.y/50;
    if((int)position.y%50==0)
        {
            if ((int)position.x%50==0)
            {
                if(map_base->collision_matrix[collision_x][collision_y+2]!=0)
                {
                    if(map_base->collision_matrix[collision_x][collision_y+1]==1){position.y+=SPEED;}
                    if(map_base->collision_matrix[collision_x][collision_y+1]==2){position.y+=SPEED;}
                }
            }
            else if(map_base->collision_matrix[collision_x][collision_y+2]!=0 && map_base->collision_matrix[collision_x+1][collision_y+2]!=0)
            {
                if(map_base->collision_matrix[collision_x][collision_y+1]==1){position.y+=SPEED;}
                if(map_base->collision_matrix[collision_x][collision_y+1]==2){position.y+=SPEED;}
            }
        }
        else
        {
            if(map_base->collision_matrix[collision_x][collision_y+1]==1){position.y+=SPEED;}
            if(map_base->collision_matrix[collision_x][collision_y+1]==2){position.y+=SPEED;}
        }
    checkGate();
}

void Hero::checkGate()
{
    int i=0;
    bool loop=true;
    while(i<20 && loop)
    {
        if((int)position.x/50==map_base->map_gate.location_from[i].x
           && (int)(position.y)/50==map_base->map_gate.location_from[i].y)
        {
            loop=false;
            position.x=map_base->map_gate.location_to[i].x * 50;
            position.y=map_base->map_gate.location_to[i].y * 50;
            map_base->setMapFilename(map_base->map_gate.destination_map_filename[i]);
            map_base->getMap();
        }
        else
        {
            i++;
        }
    }
}

void Hero::drawHero()
{
    rectangle.setTexture(&(map_base->images_storage.texture_hero));
    rectangle.setPosition(position);
    window->draw(rectangle);
}
