#include <iostream>
#include "cacheimgfiles.hpp"

CacheImgFiles::CacheImgFiles()
{
    textures_hero_list[0].loadFromFile("images/img_hero_face.png");
    textures_hero_list[1].loadFromFile("images/img_hero_face_right1.png");
    textures_hero_list[2].loadFromFile("images/img_hero_face_right2.png");
    textures_hero_list[3].loadFromFile("images/img_hero_face_left1.png");
    textures_hero_list[4].loadFromFile("images/img_hero_face_left2.png");

    textures_list[0].loadFromFile("images/texture_none.png");
    textures_list[1].loadFromFile("images/texture_wall.png");
    textures_list[2].loadFromFile("images/texture_bush.png");
    textures_list[3].loadFromFile("images/texture_window.png");
    textures_list[4].loadFromFile("images/texture_barrier.png");
    textures_list[5].loadFromFile("images/texture_roof.png");
    textures_list[6].loadFromFile("images/texture_floor.png");
    textures_list[7].loadFromFile("images/texture_grass.png");
    textures_list[8].loadFromFile("images/texture_tar.png");
    textures_list[9].loadFromFile("images/texture_road.png");
    //.......//

    texture=textures_list[0];
    texture_hero=textures_hero_list[0];
}

void CacheImgFiles::setIndexTexture(int input_index)
{
    texture=textures_list[input_index];
}

void CacheImgFiles::setIndexTextureHero(int input_index)
{
    texture_hero=textures_hero_list[input_index];
}
