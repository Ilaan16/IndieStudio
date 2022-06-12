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
            this->_model = LoadModel(filename.c_str());
        else
            this->_model = LoadModel("");
    }

    RModel::~RModel()
    {
        UnloadModel(this->_model);
    }

    void RModel::draw(const float &x, const float &y, Texture2D texture)
    {   
        //if (this->model != NULL)
        //SetMaterialTexture(*this->model.materials[0], MATERIAL_MAP_DIFFUSE, texture);
    }
}