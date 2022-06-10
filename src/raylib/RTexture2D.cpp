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
        this->texture = LoadTexture(filename.c_str());
    }

    RTexture2D::~RTexture2D()
    {
        UnloadTexture(this->texture);
    }

    void RTexture2D::draw(const float &x, const float &y)
    {
        DrawTexture(this->texture, x, y, WHITE);
    }
}
