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

            Raylib() = default;
            ~Raylib() = default;

            void displayAll(std::map<typeEntity ,std::vector<std::shared_ptr<Entity>>> &entities);
    };
}

#endif /* !encap */
