/*
** EPITECH PROJECT, 2022
** indie
** File description:
** main
*/

#ifndef mainscenedef
#define mainscenedef

#include "scenes/AScene.hpp"

namespace indie
{
    class MainScene : public AScene {
        public:
            MainScene();
            ~MainScene();

            std::map<typeEntity ,std::vector<std::shared_ptr<indie::Entity>>> &getEntities();

            void createMap();
            void createPlayer();
            void createCamera();
            void createIA();
        protected:
        private:
    };
}

#endif /* !mainscenedef */
