/*
** EPITECH PROJECT, 2022
** indie
** File description:
** main
*/

#ifndef mainscenedef
#define mainscenedef

#include "scenes/AScene.hpp"
#include "raylib/RMap.hpp"

namespace indie
{
    class MainScene : public AScene {
        public:
            MainScene();
            ~MainScene();

            std::map<typeEntity ,std::vector<std::shared_ptr<indie::Entity>>> &getEntities();

            void createPlayer();
            void createCamera();
        protected:
        private:
            RMap map;
    };
}

#endif /* !mainscenedef */
