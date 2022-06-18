/*
** EPITECH PROJECT, 2022
** IndieStudio
** File description:
** RMap
*/

#include "RMap.hpp"

namespace indie {
    RMap::RMap(const std::string &image, const std::string &filename_texture)
    {

        Image imMap = LoadImage(image.c_str());
        std::cout << "image load" << std::endl;
        this->_cubicmap = LoadTextureFromImage(imMap);
        Mesh mesh = GenMeshCubicmap(imMap, (Vector3){ 1.0f, 1.0f, 1.0f });
        Model model = LoadModelFromMesh(mesh);

        this->_texture = LoadTexture("assets/map/cubicmap_atlas.png");
        model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = this->_texture;

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

    bool RMap::checkHit(Vector3 position, float *position1, float *position2, float movement, int *explose, Texture2D cubicmap, Color *mapPix)
    {
        *(position2) += movement;
        float playerRadius = 0.1f;
        Vector2 playerPos = { position.x, position.z };
        int playerCellX = (int)(position1 - position2 + 0.5f);
        int playerCellY = (int)(position2 - position1 + 0.5f);

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
                if (mapPix[y*cubicmap.width + x].r == 255 && CheckCollisionCircleRec(playerPos, playerRadius, (Rectangle){ _mapPos.x - 0.5f + x*1.0f, _mapPos.z - 0.5f + y*1.0f, 1.0f, 1.0f })) {
                    return (false);
                }
            }
        }
        return (true);
    }


    void RMap::putBomb(float *x, float *y, float *z, Player *player, Camera3D camera, Texture2D cubicmap, Color *mapPixels)
    {
        BeginMode3D(camera);
        (*player).UpdateTimer(&(*player)._timer);
        if ((*player)._putBomb == true && !(*player).TimerDone(&(*player)._timer)) {
            DrawCubeV((*player)._tnt, { 1.0f, 1.0f, 1.0f }, RED);
        }

        if ((*player).TimerDone(&(*player)._timer) && ((*player)._explosion > 0 || (*player)._putBomb == true)) {
            (*player)._putBomb = false;
            if ((*player)._up_stillalive == true) {
                (*player)._up_stillalive = checkHit((*player)._up._bomb, &(*player)._up._bomb.x, &(*player)._up._bomb.z, -0.2f, &(*player)._explosion, cubicmap, mapPixels);
                DrawCubeV((*player)._up._bomb, { 1.0f, 2.0f, 1.0f }, RED);
            }
            if ((*player)._down_stillalive == true) {
                (*player)._down_stillalive = checkHit((*player)._down._bomb, &(*player)._down._bomb.x, &(*player)._down._bomb.z, 0.2f, &(*player)._explosion, cubicmap, mapPixels);
                DrawCubeV((*player)._down._bomb, { 1.0f, 2.0f, 1.0f }, RED);
            }
            if ((*player)._left_stillalive == true) {
                (*player)._left_stillalive = checkHit((*player)._left._bomb, &(*player)._left._bomb.z, &(*player)._left._bomb.x, -0.2f, &(*player)._explosion, cubicmap, mapPixels);
                DrawCubeV((*player)._left._bomb, { 1.0f, 2.0f, 1.0f }, RED);
            }
            if ((*player)._right_stillalive == true) {
                (*player)._right_stillalive = checkHit((*player)._right._bomb, &(*player)._right._bomb.z, &(*player)._right._bomb.x, 0.2f, &(*player)._explosion, cubicmap, mapPixels);
                DrawCubeV((*player)._right._bomb, { 1.0f, 2.0f, 1.0f }, RED);
            }
        }
        EndMode3D();
    }


    void RMap::draw(Camera3D camera)
    {
        BeginMode3D(camera);
        DrawModel(this->_model, this->_mapPos, 1.0f, WHITE);
        EndMode3D();
    }
}