/*
** EPITECH PROJECT, 2022
** Indie
** File description:
** Raylib
*/

#ifndef encap
#define encap

#include <cstddef>
#include <string>
#include <utility>
#include <memory>
#include <iostream>
#include <unordered_map>
#include <functional>
#include "scenes/AScene.hpp"
#include <raymath.h>
#include "raylib.h"

namespace indie {
    class Raylib {
        public:
            enum model {
                BASIC,
                GRADIENT,
                LINES,
                WIRES
            };

            Raylib() = default;
            ~Raylib() = default;

            Model rotateModel(Model entity, int angle) const;
            bool collision_entities(Vector3 position_entity, Vector3 position, float size) const;
            bool collision_image(Vector2 position_entity, Vector3 _mapPos, float entity_raidus, int x, int y) const;
            void displayCube(model const type, Vector3 const position, Vector3 const size, Color const color) const;
            void displayAll(std::map<typeEntity ,std::vector<std::shared_ptr<Entity>>> &entities);
    };
}

#endif /* !encap */
