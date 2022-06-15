/*
** EPITECH PROJECT, 2022
** IndieStudio
** File description:
** RMap
*/

#include "RMap.hpp"
#include <iostream>

namespace indie {
    RMap::RMap()
    {
        Image imMap = LoadImage("assets/map/map.png");
        std::cout << "image load" << std::endl;
        this->_cubicmap = LoadTextureFromImage(imMap);
        std::cout << "Text from image" << std::endl;
        this->_mesh = GenMeshCubicmap(imMap, (Vector3){ 1.0f, 1.0f, 1.0f });
        std::cout << "gen mesh" << std::endl;
        this->_model = LoadModelFromMesh(this->_mesh);
        std::cout << "load model" << std::endl;

        this->_texture = LoadTexture("assets/map/cubicmap_atlas.png");
        this->_model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = this->_texture;

        Color *mapPixels = LoadImageColors(imMap);
        UnloadImage(imMap);
            
        Image imMap1 = LoadImage("assets/map/pixel.png");
        this->_cubicmap_wood = LoadTextureFromImage(imMap1);
        this->_mesh_wood = GenMeshCubicmap(imMap1, (Vector3){ 1.0f, 1.0f, 1.0f });
        this->_model_wood = LoadModelFromMesh(this->_mesh_wood);

        Texture2D texture1 = LoadTexture("assets/map/planche.png");
        this->_model_wood.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = texture1;

        UnloadImage(imMap1);

        this->_mapPos = { -7, 2, -5 };
        this->_mapPos2 = { -6, 2, -4 };
        this->_mapPos3 = { -6, 2, -4 };
    }

    RMap::~RMap()
    {
        //UnloadModel(this->_model);
        //UnloadImageColors(this->_mapPixels);
        UnloadTexture(this->_texture);
        UnloadTexture(this->_cubicmap);
        //UnloadModel(this->_model_wood);
        UnloadTexture(this->_texture_wood);
        UnloadTexture(this->_cubicmap_wood);
    }
    
    std::vector<int> RMap::aleatoire()
    {
        std::vector<int> tab(143, 0);
        std::random_device rd;
        std::default_random_engine eng(rd());
        std::uniform_int_distribution<int> distr(1, 143);

        for (int n = 0, temp = 0; n < 143; n++) {
            temp = (distr(eng));
            if (verif(tab, temp) == 1)
                tab[n] = temp;
        }
        return tab;
    }

    int RMap::verif(std::vector <int> tab, int temp)
    {
        std::vector<int> number {1, 2, 12, 13, 14, 15, 17, 19, 21, 23, 25, 26, 41, 43, 45, 47, 49, 51, 67, 69, 71, 73, 75, 77, 93, 95, 97, 99, 101, 103, 118, 119, 121, 123, 125, 127, 129, 130, 131, 132, 142, 143};
        int result = 1;

        for (int nb = 0; nb < 143; nb++)
            if (temp == tab[nb])
                result = 0;
        for (int nb = 0; nb < 42; nb++)
            if (temp == number[nb])
                result = 0;
        return (result);
    }

    Vector3 RMap::calcul(int number, Vector3 mapPosition2)
    {
        int x = mapPosition2.x;

        for (int nb = 1; nb < number; nb++) {
            if ((nb % 13) == 0) {
                mapPosition2.x = x;
                mapPosition2.z = mapPosition2.z + 1;
            } else {
                mapPosition2.x = mapPosition2.x + 1;
            }
        }

        return (mapPosition2);
    }
    
    void RMap::draw(Camera3D camera)
    {
        BeginMode3D(camera);
        DrawModel(this->_model, this->_mapPos, 1.0f, WHITE);
        for (int nb = 0; nb < 143; nb++) {
            this->_mapPos2 = this->_mapPos3;
            if (tab.at(nb) > 0)
                DrawModel(this->_model_wood, calcul(tab.at(nb), this->_mapPos2), 1.0f, WHITE);
        }
        EndMode3D();
    }
}