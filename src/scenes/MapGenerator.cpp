/*
** EPITECH PROJECT, 2022
** IndieStudio
** File description:
** MapGenerator
*/

#include "MapGenerator.hpp"

namespace indie {
    MapGenerator::MapGenerator()
    {
    }

    MapGenerator::~MapGenerator()
    {
    }

    int MapGenerator::verif(std::vector <int> tab, int temp)
    {
        std::vector<int> number {1, 2, 12, 13, 14, 15, 17, 19, 21, 23, 25, 26, 41, 43, 45, 47, 49, 51, 67, 69, 71, 73, 75, 77, 93, 95, 97, 99, 101, 103, 118, 119, 121, 123, 125, 127, 129, 130, 131, 132, 142, 143};
        int result = 1;

        for (int nb = 0; nb < 143; nb++) {
            if (temp == tab[nb])
                result = 0;
        }

        for (int nb = 0; nb < 42; nb++) {
            if (temp == number[nb])
                result = 0;
        }

        return (result);
    }

    std::vector<int> MapGenerator::aleatoire()
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

    Vector3 MapGenerator::calcul(int number, Vector3 mapPosition2)
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

    void MapGenerator::createMap()
    {
        std::vector<int> tab = this->aleatoire();

        for (int nb = 0; nb != 143; nb++) {
            std::cout << tab[nb] << "; ";
        }

        Camera camera = { { 0, 18, 8 }, { 0, -2, 0 }, { 0, 1, 0 }, 50, 0 };

        Image imMap = LoadImage("assets/map.png");
        Texture2D cubicmap = LoadTextureFromImage(imMap);
        Mesh mesh = GenMeshCubicmap(imMap, (Vector3){ 1.0f, 1.0f, 1.0f });
        Model model = LoadModelFromMesh(mesh);

        Texture2D texture = LoadTexture("assets/cubicmap_atlas.png");
        model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = texture;

        Color *mapPixels = LoadImageColors(imMap);
        UnloadImage(imMap);
        
        Image imMap1 = LoadImage("assets/pixel.png");
        Texture2D cubicmap1 = LoadTextureFromImage(imMap1);
        Mesh mesh1 = GenMeshCubicmap(imMap1, (Vector3){ 1.0f, 1.0f, 1.0f });
        Model model1 = LoadModelFromMesh(mesh1);

        Texture2D texture1 = LoadTexture("assets/planche.png");
        model1.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = texture1;

        UnloadImage(imMap1);

        Vector3D mapPosition = { -7, 2, -5 };
        Vector3D mapPosition2 = { -6, 2, -4 };
        Vector3D mapPosition3 = { -6, 2, -4 };

        SetCameraMode(camera, CAMERA_ORBITAL);

        SetTargetFPS(60);


        while (!WindowShouldClose())
        {
            BeginDrawing();

                ClearBackground(RAYWHITE);

                BeginMode3D(camera);
                    DrawModel(model, mapPosition, 1.0f, WHITE);
                    for (int nb = 0; nb < 143; nb++) {
                        mapPosition2 = mapPosition3;
                        if (tab.at(nb) > 0)
                            DrawModel(model1, calcul(tab.at(nb), mapPosition2), 1.0f, WHITE);
                    }
                EndMode3D();

            EndDrawing();
        }

        UnloadImageColors(mapPixels);
        UnloadTexture(cubicmap);
        UnloadTexture(texture);
        UnloadModel(model);
        CloseWindow();
    }
}