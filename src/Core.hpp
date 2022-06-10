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
            Core(std::size_t const fps = 60);
            ~Core();
            void start();

        protected:
        private:
            std::vector<std::unique_ptr<indie::AScene>> _vecScenes;
            int _screenWidth;
            int _screenHeight;
            Scenes _scenePos;
            std::string _title;
            std::size_t _fps;
            indie::Game _gameLogic;
            indie::Graphical _raylib;
    };
}

#endif /* !coredef */
