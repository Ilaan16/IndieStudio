/*
** EPITECH PROJECT, 2022
** indie
** File description:
** main
*/

#include "MainScene.hpp"
#include "Core.hpp"

MainScene::MainScene()
{
    //init objects
}

MainScene::~MainScene()
{
    //clear objects
}

Scenes MainScene::run(Raylib &lib, Scenes const &prevScene)
{
    const Vector3 playerSize = {1.0f, 2.0f, 1.0f};
    const Vector3 enemyBoxPos = {-4.0f, 1.0f, 0.0f};
    const Vector3 enemyBoxSize = {2.0f, 2.0f, 2.0f};

    Vector3 enemySpherePos = {4.0f, 0.0f, 0.0f};
    float enemySphereSize = 1.5f;

    Vector3 playerPosition = {0.0f, 1.0f, 2.0f};
    Color playerColor = GREEN;

    while (lib.gameLoop()) {
        BeginDrawing();
        BeginMode3D(lib.getCamera());
        lib.printCube(Raylib::WIRES, enemyBoxPos, enemyBoxSize, DARKGRAY);
        lib.printSphere(Raylib::BASIC, enemySpherePos, enemySphereSize, {0,0}, GRAY);
        lib.printSphere(Raylib::WIRES, enemySpherePos, enemySphereSize, {16, 16}, DARKGRAY);

        DrawCubeV(playerPosition, playerSize, playerColor);
        lib.printGrid(10, 1);
        lib.printFps({10, 10});

        EndMode3D();
        EndDrawing();
    }
    return (Scenes::QUIT);
}