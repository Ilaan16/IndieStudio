/*
** EPITECH PROJECT, 2022
** indie
** File description:
** Movement
*/

#include "Event.hpp"
#include <raymath.h>
#include <iostream>

namespace indie {
    Movement::Movement(int direction)
    {
        _direction = direction;
    }

    void Movement::useDown(std::unique_ptr<AScene> &ownScene, std::shared_ptr<Entity> &ownEntity) noexcept
    {
        std::shared_ptr<Renderable> renderer = std::static_pointer_cast<Renderable, IComponent>(ownEntity->getComponents().find(indie::RENDERABLE)->second);
        auto entitiesScene = ownScene->getEntities();
        auto mapEntity = entitiesScene.find(typeEntity::MAP)->second.at(0)->getComponents();
        auto rendererMap = dynamic_cast<indie::Renderable *>(mapEntity.find(tag::RENDERABLE)->second.get());


        Vector3D oldPos = renderer->_position;

        if (_direction == 1) {
            renderer->_model._model.transform = MatrixRotateXYZ((Vector3){ DEG2RAD*0, DEG2RAD*0, DEG2RAD*-90 });
            renderer->_position.x += 0.1f;
        }
        if (_direction == 2) {
            renderer->_model._model.transform = MatrixRotateXYZ((Vector3){ DEG2RAD*0, DEG2RAD*0, DEG2RAD*90 });
            renderer->_position.x -= 0.1f;
        }
        if (_direction == 3) {
            renderer->_model._model.transform = MatrixRotateXYZ((Vector3){ DEG2RAD*0, DEG2RAD*0, DEG2RAD*0 });
            renderer->_position.z += 0.1f;
        }
        if (_direction == 4) {
            renderer->_model._model.transform = MatrixRotateXYZ((Vector3){ DEG2RAD*0, DEG2RAD*0, DEG2RAD*180 });
            renderer->_position.z -= 0.1f;
        }

        Texture2D cubicmap = rendererMap->_map.getMap();

        float playerRadius = 0.1f;
        Vector2 playerPos = { renderer->_position.x, renderer->_position.z };
        int playerCellX = (int)(playerPos.x - rendererMap->_position.x + 0.5f);
        int playerCellY = (int)(playerPos.y - rendererMap->_position.z + 0.5f);


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
                if (rendererMap->_map._mapPixels[y*cubicmap.width + x].r == 255 && CheckCollisionCircleRec(playerPos, playerRadius, (Rectangle){ rendererMap->_map._mapPos.x - 0.5f + x*1.0f, rendererMap->_map._mapPos.z - 0.5f + y*1.0f, 1.0f, 1.0f })) {
                    renderer->_position = oldPos;
                }
            }
        }
    }

    void Movement::usePressed(std::unique_ptr<AScene> &ownScene, std::shared_ptr<Entity> &ownEntity) noexcept
    {
    }

    void Movement::useReleased(std::unique_ptr<AScene> &ownScene, std::shared_ptr<Entity> &ownEntity) noexcept
    {
    }
}