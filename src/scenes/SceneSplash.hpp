/*
** EPITECH PROJECT, 2022
** Indie
** File description:
** SceneSplash
*/

#ifndef SCENESPLASH_HPP_
    #define SCENESPLASH_HPP_

    #include "scenes/AScene.hpp"
    #include "raylib/REvent.hpp"
    #include "events/Event.hpp"

namespace indie
{
    class SceneSplash : public AScene {
        public:
            SceneSplash();
            ~SceneSplash() = default;

            std::map<typeEntity ,std::vector<std::shared_ptr<indie::Entity>>> &getEntities();
            void update(std::map<indie::typeEntity, std::vector<std::shared_ptr<indie::Entity>>> &entity);
        private:
            void addEventToLastEntity(const MouseButton &mouse, std::unique_ptr<MouseEvent> &evt);
    };
}
#endif /* !SCENESPLASH_HPP_ */
