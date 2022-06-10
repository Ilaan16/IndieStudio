/*
** EPITECH PROJECT, 2022
** B-YEP-400-TLS-4-1-indiestudio-ilan.chekroun
** File description:
** Game
*/

#ifndef GAME_HPP_
#define GAME_HPP_

#include "scenes/AScene.hpp"
#include "scenes/MainScene.hpp"
#include "scenes/SceneOption.hpp"
#include "scenes/SceneMenu.hpp"

namespace indie {

    class Game {
        public:
            Game();
            ~Game();

            AScene *updateSystem();
            void manageGame();
            std::unique_ptr<AScene> &getScene();

        private:
            int sceneId;
            std::vector<std::unique_ptr<AScene>> _scenes;
    };
}

#endif /* !GAME_HPP_ */
