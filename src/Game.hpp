/*
** EPITECH PROJECT, 2022
** B-YEP-400-TLS-4-1-indiestudio-ilan.chekroun
** File description:
** Game
*/

#ifndef GAME_HPP_
#define GAME_HPP_

#include "scenes/AScene.hpp"
#include "scenes/SceneSplash.hpp"
#include "scenes/MainScene.hpp"
#include "scenes/SceneOption.hpp"
#include "scenes/SceneMenu.hpp"
#include "scenes/ChoosePersoScene.hpp"
#include "scenes/SceneEnd.hpp"

namespace indie {

    class Game {
        public:
            Game();
            ~Game();

            indie::Scenes updateSystem();
            void manageGame();
            std::unique_ptr<AScene> &getScene();
            static void setScene(const int &id);

        private:
            void callEvent(std::shared_ptr<Entity> &ent, std::pair<KeyboardKey, indie::ButtonState> &key,
                std::unique_ptr<AScene> &scene);
            void callEvent(std::shared_ptr<Entity> &ent, std::pair<MouseButton, indie::ButtonState> &key,
                std::unique_ptr<AScene> &scene);
            static int sceneId;
            std::vector<std::unique_ptr<AScene>> _scenes;
    };
}

#endif /* !GAME_HPP_ */
