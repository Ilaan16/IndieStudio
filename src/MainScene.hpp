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

            Scenes run(Scenes const &prevScene) final;
            std::map<typeEntity ,std::vector<std::shared_ptr<indie::Entity>>> &getEntities();

            void createPlayer();
            void createCamera();
            void createIA();
        protected:
        private:
    };
}

#endif /* !mainscenedef */
