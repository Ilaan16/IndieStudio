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
            
            std::unique_ptr<Entity> createPlayer();
            std::unique_ptr<Entity> createCamera();
            std::unique_ptr<Entity> createIA();
        protected:
        private:
    };
}

#endif /* !mainscenedef */
