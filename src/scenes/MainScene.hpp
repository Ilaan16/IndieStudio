/*
** EPITECH PROJECT, 2022
** indie
** File description:
** main
*/

#ifndef mainscenedef
#define mainscenedef

#include "scenes/AScene.hpp"
#include "events/Event.hpp"
#include "raylib/REvent.hpp"

namespace indie
{
    class MainScene : public AScene {
        public:
            MainScene();
            ~MainScene();

            std::map<typeEntity ,std::vector<std::shared_ptr<indie::Entity>>> &getEntities();
            

        protected:
        private:
            void addEventToLastEntity(const KeyboardKey &key, std::shared_ptr<Event> &evt);
    };
}

#endif /* !mainscenedef */
