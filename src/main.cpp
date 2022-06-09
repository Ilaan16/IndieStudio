/*
** EPITECH PROJECT, 2022
** indie
** File description:
** main
*/

#include "raylib.h"
#include <iostream>
#include <stdlib.h>

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;
    float nb = 0;
    int times = 60;
    char const *num_char;

    InitWindow(screenWidth, screenHeight, "map");

    Camera camera = { { 0, 18, 8 }, { 0.0f, -2.0f, 0.0f }, { 0.0f, 1.0f, 0.0f }, 50.0f, 0 };

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

    Color *mapPixels1 = LoadImageColors(imMap1);
    UnloadImage(imMap1);

    Vector3 mapPosition = { -7, 2, -5 };
    Vector3 mapPosition1 = { 4, 2, -4 };
    Vector3 mapPosition2 = { 4, 2, -4 };

    SetCameraMode(camera, CAMERA_ORBITAL);

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        mapPosition1 = mapPosition2;
        nb += GetFrameTime();
        times = 60 - (int)nb;
        std::string tmp = std::to_string(times);
        num_char = tmp.c_str();

        BeginDrawing();

            ClearBackground(RAYWHITE);

            BeginMode3D(camera);
                DrawModel(model, mapPosition, 1.0f, WHITE);
                for (int nb = 0; nb != 11; nb++) {
                    DrawModel(model1, mapPosition1, 1.0f, WHITE);
                    mapPosition1.z = mapPosition1.z + 1;
                }
                DrawText(num_char, 200, 0, 40, BLACK);
            EndMode3D();

        EndDrawing();
    }

    UnloadImageColors(mapPixels);
    UnloadTexture(cubicmap);
    UnloadTexture(texture);
    UnloadModel(model);
    CloseWindow();
    return 0;
}
