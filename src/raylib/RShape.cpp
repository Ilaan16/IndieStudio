/*
** EPITECH PROJECT, 2022
** Indie
** File description:
** RTexture3D
*/

#include "RShape.hpp"
#include <iostream>

namespace indie {
    RShape::RShape(const std::string &filename)
    {
        this->_texture = LoadTexture(filename.c_str());
    }

    RShape::~RShape()
    {
        UnloadTexture(this->_texture);
    }

    void RShape::draw(const float &x, const float &y, Camera camera)
    {
        BeginMode3D(camera);
        DrawCubeTexture(this->_texture, (Vector3){ 0.0f, 0.0f, 0.0f }, 50, 50, 50, WHITE);
        EndMode3D();
    }
}