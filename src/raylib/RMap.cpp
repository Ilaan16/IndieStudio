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
        _isbomb = false;
        _explosion = false;

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

    RMap::~RMap()
    {
        UnloadModel(this->_model);
        UnloadImageColors(this->_mapPixels);
        UnloadTexture(this->_texture);
        UnloadTexture(this->_cubicmap);
    }


    Player RMap::collision(Player player, KeyboardKey right, KeyboardKey left, KeyboardKey down, KeyboardKey up)
    {
        Vector3 oldPos = player._playerPosition;
        
        if (IsKeyDown(right)) {
            player._modelPlayer.transform = MatrixRotateXYZ((Vector3){ DEG2RAD*0, DEG2RAD*0, DEG2RAD*-90 });
            player._playerPosition.x += 0.1f;
        } else if (IsKeyDown(left)) {
            player._modelPlayer.transform = MatrixRotateXYZ((Vector3){ DEG2RAD*0, DEG2RAD*0, DEG2RAD*90 });
            player._playerPosition.x -= 0.1f;
        } else if (IsKeyDown(down)) {
            player._modelPlayer.transform = MatrixRotateXYZ((Vector3){ DEG2RAD*0, DEG2RAD*0, DEG2RAD*0 });
            player._playerPosition.z += 0.1f;
        } else if (IsKeyDown(up)) {
            player._modelPlayer.transform = MatrixRotateXYZ((Vector3){ DEG2RAD*0, DEG2RAD*0, DEG2RAD* 180});
            player._playerPosition.z -= 0.1f;
        }

        float playerRadius = 0.1f;
        Vector2 playerPos = { player._playerPosition.x, player._playerPosition.z };
        int playerCellX = (int)(playerPos.x - _mapPos.x + 0.5f);
        int playerCellY = (int)(playerPos.y - _mapPos.z + 0.5f);


        if (playerCellX < 0) {
            playerCellX = 0;
        } else if (playerCellX >= _cubicmap.width) {
            playerCellX = _cubicmap.width - 1;
        }
        if (playerCellY < 0) {
            playerCellY = 0;
        } else if (playerCellY >= _cubicmap.height) {
            playerCellY = _cubicmap.height - 1;
        }

        for (int y = 0; y < _cubicmap.height; y++) {
            for (int x = 0; x < _cubicmap.width; x++) {
                if (_mapPixels[y*_cubicmap.width + x].r == 255 && CheckCollisionCircleRec(playerPos, playerRadius, (Rectangle){ _mapPos.x - 0.5f + x*1.0f, _mapPos.z - 0.5f + y*1.0f, 1.0f, 1.0f })) {
                    player._playerPosition = oldPos;
                }
            }
        }

        return (player);
    }

    bool RMap::checkHit(float *position1, float *position2, float movement)
    {
        *(position2) += movement;
        float playerRadius = 0.1f;
        Vector2 playerPos = { *(position1), *(position2) };
        int playerCellX = (int)(playerPos.x - _mapPos.x + 0.5f);
        int playerCellY = (int)(playerPos.y - _mapPos.z + 0.5f);


        if (playerCellX < 0) {
            playerCellX = 0;
        } else if (playerCellX >= _cubicmap.width) {
            playerCellX = _cubicmap.width - 1;
        }
        if (playerCellY < 0) {
            playerCellY = 0;
        } else if (playerCellY >= _cubicmap.height) {
            playerCellY = _cubicmap.height - 1;
        }

        for (int y = 0; y < _cubicmap.height; y++) {
            for (int x = 0; x < _cubicmap.width; x++) {
                if (_mapPixels[y*_cubicmap.width + x].r == 255 && CheckCollisionCircleRec(playerPos, playerRadius, (Rectangle){ _mapPos.x - 0.5f + x*1.0f, _mapPos.z - 0.5f + y*1.0f, 1.0f, 1.0f })) {
                    *(position2) -= movement;
                    return (false);
                }
            }
        }
        return (true);
    }


    Player RMap::putBomb(Player player, KeyboardKey action)
    {
        if (IsKeyDown(action) && player._putBomb == false) {
            player._putBomb = true;
            player.StartTimer(&player._timer, player._life);
            player._tnt = player._playerPosition;
            player._up._bomb = player._playerPosition;
            player._down._bomb = player._playerPosition;
            player._left._bomb = player._playerPosition;
            player._right._bomb = player._playerPosition;
        }

        player.UpdateTimer(&player._timer);

        if (player._putBomb == true && !player.TimerDone(&player._timer)) {
            DrawCubeV(player._tnt, { 1.0f, 1.0f, 1.0f }, RED);
        }

        if (player.TimerDone(&player._timer)) {
            player._putBomb = false;
            if (checkHit(&player._up._bomb.x, &player._up._bomb.z, -0.1f) == true) {
                DrawCubeV(player._up._bomb, { 1.0f, 2.0f, 1.0f }, RED);
            }
            if (checkHit(&player._down._bomb.x, &player._down._bomb.z, 0.1f) == true) {
                DrawCubeV(player._down._bomb, { 1.0f, 2.0f, 1.0f }, RED);
            }
            if (checkHit(&player._left._bomb.z, &player._left._bomb.x, -0.1f) == true) {
                DrawCubeV(player._left._bomb, { 1.0f, 2.0f, 1.0f }, RED);
            }
            if (checkHit(&player._right._bomb.z, &player._right._bomb.x, 0.1f) == true) {
                DrawCubeV(player._right._bomb, { 1.0f, 2.0f, 1.0f }, RED);
            }
        }
        return (player);
    }


    void RMap::draw(Camera3D camera)
    {

        player1 = collision(player1, KEY_D, KEY_A, KEY_S, KEY_W);
        player2 = collision(player2, KEY_RIGHT, KEY_LEFT, KEY_DOWN, KEY_UP);
        
        BeginMode3D(camera);
        DrawModel(this->_model, this->_mapPos, 1.0f, WHITE);

        player1 = putBomb(player1, KEY_ENTER);
        player2 = putBomb(player2, KEY_SPACE);


        DrawModelEx(player1._modelPlayer, player1._playerPosition, (Vector3){ 1.0f, 0.0f, 0.0f }, -90.0f, player1._playerSize, WHITE);
        DrawModelEx(player2._modelPlayer, player2._playerPosition, (Vector3){ 1.0f, 0.0f, 0.0f }, -90.0f, player2._playerSize, WHITE);
        EndMode3D();
    }
}