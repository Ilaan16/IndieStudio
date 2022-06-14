/*
** EPITECH PROJECT, 2022
** Indie
** File description:
** RTexture2D
*/

#include "RTexture2D.hpp"
#include <iostream>

namespace indie {
    RTexture2D::RTexture2D(const std::string &filename)
    {
        this->_texture = LoadTexture(filename.c_str());
    }

    RTexture2D::~RTexture2D()
    {
        UnloadTexture(this->_texture);
    }

    void RTexture2D::draw(const float &x, const float &y, Rectangle source)
    {
        // DrawTexture(this->_texture, x, y, WHITE);
        DrawTextureRec(this->_texture, source, {x, y}, WHITE);
    }
}
