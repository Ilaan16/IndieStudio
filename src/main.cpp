/*
** EPITECH PROJECT, 2022
** indie
** File description:
** main
*/

#include "raylib.h"
#include <iostream>
#include <stdlib.h>
#include <random>

std::vector <int> aleatoire();

Vector3 calcul(int number, Vector3 mapPosition2)
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


int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    Vector3 direction = { 1.0f, 0.0f, 0.0f };
    std::vector<int> tab = aleatoire();

    for (int nb = 0; nb != 143; nb++) {
        std::cout << tab[nb] << "; ";
    }

    InitWindow(screenWidth, screenHeight, "map");
    Camera camera = { { 0, 18, 8 }, { 0, -2, 0 }, { 0, 1, 0 }, 50, 0 };


    Vector3 playerPosition = { -6.0f, 2.0f, 6.0f };
    Vector3 playerSize = { 2.0f, 2.0f, 2.0f };
    Model modelPlayer = LoadModel("assets/characters/character.iqm");
    Texture2D texturePlayer = LoadTexture("assets/characters/steve.png");
    SetMaterialTexture(&modelPlayer.materials[0], MATERIAL_MAP_DIFFUSE, texturePlayer);


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

    Vector3 mapPosition = { -7, 2, -5 };
    Vector3 mapPosition2 = { -6, 2, -4 };


    SetCameraMode(camera, CAMERA_ORBITAL);
    SetTargetFPS(60);


    while (!WindowShouldClose())
    {
        Vector3 oldPos = playerPosition;

        if (IsKeyDown(KEY_RIGHT)) {
            direction = { 1.0f, 0.0f, 0.0f };
            playerPosition.x += 0.1f;
        } else if (IsKeyDown(KEY_LEFT)) {
            direction = { 1.0f, 0.0f, 0.0f };
            playerPosition.x -= 0.1f;
        } else if (IsKeyDown(KEY_DOWN)) { 
            direction = { 1.0f, 0.0f, 0.0f };
            playerPosition.z += 0.1f;
        } else if (IsKeyDown(KEY_UP)) {
            direction = { 1.0f, 0.0f, 0.0f };
            playerPosition.z -= 0.1f;
        }

        float playerRadius = 0.1f;
        Vector2 playerPos = { playerPosition.x, playerPosition.z };
        int playerCellX = (int)(playerPos.x - mapPosition.x + 0.5f);
        int playerCellY = (int)(playerPos.y - mapPosition.z + 0.5f);


        if (playerCellX < 0) {
            playerCellX = 0;
        } else if (playerCellX >= cubicmap.width) {
            playerCellX = cubicmap.width - 1;
        }
        if (playerCellY < 0) {
            playerCellY = 0;
        } else if (playerCellY >= cubicmap.height) {
            playerCellY = cubicmap.height - 1;
        }

        for (int y = 0; y < cubicmap.height; y++) {
            for (int x = 0; x < cubicmap.width; x++) {
                if (mapPixels[y*cubicmap.width + x].r == 255 && CheckCollisionCircleRec(playerPos, playerRadius, (Rectangle){ mapPosition.x - 0.5f + x*1.0f, mapPosition.z - 0.5f + y*1.0f, 1.0f, 1.0f })) {
                    playerPosition = oldPos;
                }
            }
        }
        BeginDrawing();

            ClearBackground(RAYWHITE);

            BeginMode3D(camera);
                DrawModel(model, mapPosition, 1.0f, WHITE);
                for (int nb = 0; nb < 143; nb++) {
                    if (tab.at(nb) > 0) {
                        Vector3 posWood = calcul(tab.at(nb), mapPosition2);
                        if (CheckCollisionCircleRec(playerPos, playerRadius, (Rectangle){ posWood.x - 0.5f, posWood.z - 0.5f, 1.0f, 1.0f }))
                            playerPosition = oldPos;
                        DrawModel(model1, posWood, 1.0f, WHITE);
                    }
                }
                DrawModelEx(modelPlayer, playerPosition, (Vector3){ 1.0f, 0.0f, 0.0f }, -90.0f, playerSize, WHITE);
            EndMode3D();

            DrawTextureEx(cubicmap, (Vector2){ GetScreenWidth() - cubicmap.width*4.0f - 20, 20.0f }, 0.0f, 4.0f, WHITE);
            DrawRectangleLines(GetScreenWidth() - cubicmap.width*4 - 20, 20, cubicmap.width*4, cubicmap.height*4, GREEN);
            DrawRectangle(GetScreenWidth() - cubicmap.width*4 - 20 + playerCellX*4, 20 + playerCellY*4, 4, 4, RED);
        EndDrawing();
    }

    UnloadImageColors(mapPixels);
    UnloadTexture(cubicmap);
    UnloadTexture(texture);
    UnloadModel(model);
    CloseWindow();
    return 0;
}