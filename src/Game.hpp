/*
** EPITECH PROJECT, 2022
** B-YEP-400-TLS-4-1-indiestudio-ilan.chekroun
** File description:
** Game
*/

#ifndef GAME_HPP_
#define GAME_HPP_

#include "AScene.hpp"
#include "MainScene.hpp"
#include "SceneOption.hpp"
#include "SceneMenu.hpp"

namespace indie {

    class Game {
        public:
            Game();
            ~Game();

            AScene *updateSystem();
            void manageGame();
            AScene *initGame();
            void destroyGame();
            std::unique_ptr<AScene> &getScene();
        protected:
        private:
            int sceneId;
            std::vector<std::unique_ptr<AScene>> _scenes;
    };
}

#endif /* !GAME_HPP_ */
