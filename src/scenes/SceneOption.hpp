/*
** EPITECH PROJECT, 2022
** Indie
** File description:
** SceneOption
*/

#ifndef SCENEOPTION_HPP_
    #define SCENEOPTION_HPP_

    #include "scenes/AScene.hpp"
    #include "raylib/REvent.hpp"
    #include "events/Event.hpp"
    #include "raylib/Window.hpp"

namespace indie
{
    class SceneOption : public AScene {
        public:
            SceneOption(raylib::Window &window);
            ~SceneOption() = default;

            std::map<typeEntity ,std::vector<std::shared_ptr<indie::Entity>>> &getEntities();
        private:
            void addEventToLastEntity(const MouseButton &mouse, std::shared_ptr<MouseEvent> &evt);
    };
}
#endif /* !SCENEOPTION_HPP_ */
