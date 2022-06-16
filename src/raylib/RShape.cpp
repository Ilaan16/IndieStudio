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
        this->_mesh = GenMeshCube(50, 50, 50);
        this->_model = LoadModelFromMesh(_mesh);
        SetMaterialTexture(&this->_model.materials[0], MATERIAL_MAP_DIFFUSE, this->_texture);
    }

    RShape::~RShape()
    {
        UnloadTexture(this->_texture);
        UnloadModel(this->_model);
    }

    void RShape::draw(const float &x, const float &y, Camera camera)
    {
        BeginMode3D(camera);
        DrawModelEx(this->_model, (Vector3){ 0.0f, 0.0f, 0.0f }, (Vector3){ 1.0f, 0.0f, 0.0f }, -90.0f, (Vector3){ 5.0f, 5.0f, 5.0f }, WHITE);
        EndMode3D();
    }
}