/*
** EPITECH PROJECT, 2022
** Indie
** File description:
** RTexture3D
*/

#include "RModel.hpp"
#include <iostream>

namespace indie {
    RModel::RModel(const std::string &filename, Texture2D texture)
    {
        this->_model = LoadModel(filename.c_str());
        SetMaterialTexture(&this->_model.materials[0], MATERIAL_MAP_DIFFUSE, texture);
    }

    RModel::~RModel()
    {
        UnloadModel(this->_model);
    }

    void RModel::draw(const float &x, const float &y)
    {
        DrawModelEx(this->_model, {x, y}, (Vector3){ 1.0f, 0.0f, 0.0f }, -90.0f, (Vector3){ 1.0f, 1.0f, 1.0f }, WHITE);
    }
}