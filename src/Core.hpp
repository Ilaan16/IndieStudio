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
#include "raylib/Window.hpp"

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
            indie::menu_e _scenePos;
            std::string _title;
            std::size_t _fps;
            indie::raylib::Window _window;
            indie::Graphical _graphical;
            indie::Game _gameLogic;
    };
}

#endif /* !coredef */
