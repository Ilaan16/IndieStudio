/*
** EPITECH PROJECT, 2022
** IndieStudio
** File description:
** RMap
*/

#include "RMap.hpp"
#include <iostream>

namespace indie {

    RMap::RMap(const std::string &image, const std::string &filename_texture)
    {
        Image imMap = LoadImage(image.c_str());
        std::cout << "image load" << std::endl;
        this->_cubicmap = LoadTextureFromImage(imMap);
        std::cout << "Text from image" << std::endl;
        this->_mesh = GenMeshCubicmap(imMap, (Vector3){ 1.0f, 1.0f, 1.0f });
        std::cout << "gen mesh" << std::endl;
        this->_model = LoadModelFromMesh(this->_mesh);
        std::cout << "load model" << std::endl;

        this->_texture = LoadTexture(filename_texture.c_str());
        this->_model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = this->_texture;

        _mapPixels = LoadImageColors(imMap);
        UnloadImage(imMap);

        this->_mapPos = { -7, 2, -5 };
    }

    Texture2D RMap::getMap(void)
    {
        return (_cubicmap);
    }

    RMap::~RMap()
    {
        UnloadModel(this->_model);
        UnloadImageColors(this->_mapPixels);
        UnloadTexture(this->_texture);
        UnloadTexture(this->_cubicmap);
    }

    void RMap::draw(Camera3D camera)
    {
        BeginMode3D(camera);
        DrawModel(this->_model, this->_mapPos, 1.0f, WHITE);
        EndMode3D();
    }
}