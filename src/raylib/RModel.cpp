/*
** EPITECH PROJECT, 2022
** Indie
** File description:
** RTexture3D
*/

#include "RModel.hpp"
#include <iostream>

namespace indie {
    RModel::RModel(const std::string &filename)
    {
        this->model = LoadModel(filename.c_str());
    }

    RModel::~RModel()
    {
        UnloadModel(this->model);
    }

    void RModel::draw(const float &x, const float &y, Texture2D texture)
    {
        SetMaterialTexture(&this->model.materials[0], MATERIAL_MAP_DIFFUSE, texture);
    }
}