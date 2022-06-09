/*
** EPITECH PROJECT, 2022
** Indie
** File description:
** RTexture2D
*/

#include "RTexture2D.hpp"

namespace indie {
    RTexture2D::RTexture2D(const std::string &filename)
    {
        texture = LoadTexture(filename.c_str());
    }

    RTexture2D::~RTexture2D()
    {
        UnloadTexture(texture);
    }

    void RTexture2D::draw(const float &x, const float &y)
    {
        DrawTexture(texture, x, y, WHITE);
    }
}
