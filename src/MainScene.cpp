/*
** EPITECH PROJECT, 2022
** indie
** File description:
** main
*/

#include "MainScene.hpp"
#include "Core.hpp"

indie::MainScene::MainScene()
{
    _entities.push_back(createPlayer());
    std::cout << "Player set" << std::endl;
    _entities.push_back(createCamera());
    std::cout << "Camera set" << std::endl;
    _entities.push_back(createIA());
    std::cout << "IA set" << std::endl;
}

indie::MainScene::~MainScene()
{
    //clear objects
}

Scenes indie::MainScene::run(Raylib &lib, Scenes const &prevScene)
{
    Camera camera = { { 0.0f, 10.0f, 10.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 1.0f, 0.0f }, 45.0f, 0 };

    Vector3 playerPosition = { 0.0f, 1.0f, 2.0f };
    Vector3 playerSize = { 1.0f, 2.0f, 1.0f };
    Color playerColor = GREEN;

    Vector3 enemyBoxPos = { -4.0f, 1.0f, 0.0f };
    Vector3 enemyBoxSize = { 2.0f, 2.0f, 2.0f };

    Vector3 enemySpherePos = { 4.0f, 0.0f, 0.0f };
    float enemySphereSize = 1.5f;

    bool collision = false;

    while (lib.gameLoop()) {
        if (lib.isKeyDown(KEY_RIGHT)) playerPosition.x += 0.2f;
        else if (lib.isKeyDown(KEY_LEFT)) playerPosition.x -= 0.2f;
        else if (lib.isKeyDown(KEY_DOWN)) playerPosition.z += 0.2f;
        else if (lib.isKeyDown(KEY_UP)) playerPosition.z -= 0.2f;

        collision = false;

        if (CheckCollisionBoxes(
            (BoundingBox){(Vector3){ playerPosition.x - playerSize.x/2,
                                     playerPosition.y - playerSize.y/2,
                                     playerPosition.z - playerSize.z/2 },
                          (Vector3){ playerPosition.x + playerSize.x/2,
                                     playerPosition.y + playerSize.y/2,
                                     playerPosition.z + playerSize.z/2 }},
            (BoundingBox){(Vector3){ enemyBoxPos.x - enemyBoxSize.x/2,
                                     enemyBoxPos.y - enemyBoxSize.y/2,
                                     enemyBoxPos.z - enemyBoxSize.z/2 },
                          (Vector3){ enemyBoxPos.x + enemyBoxSize.x/2,
                                     enemyBoxPos.y + enemyBoxSize.y/2,
                                     enemyBoxPos.z + enemyBoxSize.z/2 }})) collision = true;

        if (CheckCollisionBoxSphere(
            (BoundingBox){(Vector3){ playerPosition.x - playerSize.x/2,
                                     playerPosition.y - playerSize.y/2,
                                     playerPosition.z - playerSize.z/2 },
                          (Vector3){ playerPosition.x + playerSize.x/2,
                                     playerPosition.y + playerSize.y/2,
                                     playerPosition.z + playerSize.z/2 }},
            enemySpherePos, enemySphereSize)) collision = true;

        if (collision) playerColor = RED;
        else playerColor = GREEN;

        BeginDrawing();
        ClearBackground(RAYWHITE);
        BeginMode3D(lib.getCamera());

        lib.printCube(Raylib::BASIC, enemyBoxPos, enemyBoxSize, DARKGRAY);
        lib.printCube(Raylib::WIRES, enemyBoxPos, enemyBoxSize, DARKGRAY);


        lib.printSphere(Raylib::BASIC, enemySpherePos, enemySphereSize, {0,0}, GRAY);
        lib.printSphere(Raylib::WIRES, enemySpherePos, enemySphereSize, {16, 16}, DARKGRAY);

        DrawCubeV(playerPosition, playerSize, playerColor);
        lib.printGrid(10, 1);
        lib.printFps({10, 10});

        EndMode3D();
        EndDrawing();
    }
    ClearBackground(RAYWHITE);
    return (Scenes::MENU);
}

std::unique_ptr<indie::Entity> indie::MainScene::createPlayer()
{
    std::unique_ptr<Entity> player = std::make_unique<indie::Entity>();
    player->addVector3D(player, 0.0f, 1.0f, 2.0f);
    player->addVector3D(player, 1.0f, 2.0f, 1.0f);
    player->addSprite3D(player, "");
    player->addModel3D(player, "");
    return (player);
}

std::unique_ptr<indie::Entity> indie::MainScene::createIA()
{
    std::unique_ptr<Entity> IA = std::make_unique<indie::Entity>();
    IA->addVector3D(IA, 0.0f, 1.0f, 2.0f);
    IA->addVector3D(IA, 1.0f, 2.0f, 1.0f);
    IA->addSprite3D(IA, "");
    IA->addModel3D(IA, "");
    IA->addIAAlgo(IA);
    return (IA);
}

std::unique_ptr<indie::Entity> indie::MainScene::createCamera()
{
    std::unique_ptr<Entity> camera = std::make_unique<indie::Entity>();
    camera->addVector3D(camera, 10, 10, 10);
    camera->addVector3D(camera, 10, 10, 10);
    camera->addVector3D(camera, 10, 10, 10);
    camera->addIncliAndZoom(camera, 10, 0);
    return (camera);
}