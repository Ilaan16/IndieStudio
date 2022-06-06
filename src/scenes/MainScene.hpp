/*
** EPITECH PROJECT, 2022
** indie
** File description:
** main
*/

#ifndef mainscenedef
#define mainscenedef

#include "AScene.hpp"

namespace indie
{
    class MainScene : public AScene {
        public:
            MainScene();
            ~MainScene();

            Scenes run(Raylib &lib, Scenes const &prevScene) final;
            std::map<std::vector<indie::type>, std::shared_ptr<indie::Entity>> &getEntities();

            std::shared_ptr<Entity> createPlayer();
            std::shared_ptr<Entity> createCamera();
            std::shared_ptr<Entity> createIA();
        private:
    };
}

#endif /* !mainscenedef */
