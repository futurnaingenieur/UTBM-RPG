#ifndef CACHEIMGFILES_HPP_INCLUDED
#define CACHEIMGFILES_HPP_INCLUDED

#include <SFML/Graphics.hpp>

using namespace sf;

class CacheImgFiles
{
public:
    Texture textures_list[10];
    Texture textures_hero_list[5];

    Texture texture_hero;
    Texture texture;
    CacheImgFiles();
    void setIndexTexture(int);
    void setIndexTextureHero(int);
};

#endif // CACHEIMGFILES_HPP_INCLUDED
