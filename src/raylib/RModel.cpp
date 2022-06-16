/*
** EPITECH PROJECT, 2022
** Indie
** File description:
** RTexture3D
*/

#include "RModel.hpp"
#include <iostream>

namespace indie {
    RModel::RModel(const std::string &filename, const std::string &filename_texture)
    {
        this->_model = LoadModel(filename.c_str());
        Texture2D texture = LoadTexture(filename_texture.c_str());
        SetMaterialTexture(&this->_model.materials[0], MATERIAL_MAP_DIFFUSE, texture);
    }

    RModel::~RModel()
    {
        UnloadModel(this->_model);
    }

    void RModel::draw(const float &x, const float &y, const float &z, Camera camera)
    {
        BeginMode3D(camera);
        DrawModelEx(this->_model, (Vector3){ x, y, z }, (Vector3){ 1.0f, 0.0f, 0.0f }, -90.0f, (Vector3){ 5.0f, 5.0f, 5.0f }, WHITE);
        EndMode3D();
    }
}