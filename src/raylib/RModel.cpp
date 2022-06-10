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
        if (filename != "")
            *this->model = LoadModel(filename.c_str());
        else
            this->model = NULL;
    }

    RModel::~RModel()
    {
        UnloadModel(*this->model);
    }

    void RModel::draw(const float &x, const float &y, Texture2D texture)
    {   
        //if (this->model != NULL)
        //SetMaterialTexture(*this->model.materials[0], MATERIAL_MAP_DIFFUSE, texture);
    }
}