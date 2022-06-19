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

            bool collision_entities(Vector3 position_entity, Vector3 position, float size) const;
            void displayCube(model const type, Vector3 const position, Vector3 const size, Color const color) const;
            void displayAll(std::map<typeEntity ,std::vector<std::shared_ptr<Entity>>> &entities);
    };
}

#endif /* !encap */
