/*
** EPITECH PROJECT, 2022
** indie
** File description:
** core
*/

#ifndef coredef
#define coredef

#include <utility>
#include <string>
#include <memory>
#include "scenes/AScene.hpp"
#include "Raylib.hpp"
#include "scenes/SceneMenu.hpp"
#include "scenes/MainScene.hpp"
#include "Graphical.hpp"
#include "Game.hpp"

namespace indie {
    class Core {
        public:
            Core();
            ~Core();
            void start();

        protected:
        private:
            std::vector<std::unique_ptr<indie::AScene>> _vecScenes;
            Scenes _scenePos;
            indie::Game _gameLogic;
            indie::Graphical _raylib;
    };
}

#endif /* !coredef */
