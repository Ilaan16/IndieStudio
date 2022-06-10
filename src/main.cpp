/*
** EPITECH PROJECT, 2022
** indie
** File description:
** main
*/

#include "raylib.h"
#include <iostream>
#include <stdlib.h>
int* aleatoire();

Vector3 calcul(int number)
{
    Vector3 mapPosition2 = { -6, 2, -4 };
    int x = mapPosition2.x;

    for (int nb = 1; nb != number; nb++) {
        if ((nb % 13) == 0) {
             mapPosition2.x = x - 1;
             mapPosition2.z = mapPosition2.z + 1;
        }
        mapPosition2.x = mapPosition2.x + 1;
    }

    return (mapPosition2);
}

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;
    int *number = aleatoire();

    InitWindow(screenWidth, screenHeight, "map");

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

    Color *mapPixels1 = LoadImageColors(imMap1);
    UnloadImage(imMap1);

    Vector3 mapPosition = { -7, 2, -5 };

    SetCameraMode(camera, CAMERA_ORBITAL);

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();

            ClearBackground(RAYWHITE);

            BeginMode3D(camera);
                DrawModel(model, mapPosition, 1.0f, WHITE);
                for (int nb = 0; nb != 143; nb++) {
                    DrawModel(model1, calcul(67), 1.0f, WHITE);
                }
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
