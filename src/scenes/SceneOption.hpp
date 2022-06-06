/*
** EPITECH PROJECT, 2022
** Indie
** File description:
** SceneOption
*/

#ifndef SCENEOPTION_HPP_
    #define SCENEOPTION_HPP_

    #include "AScene.hpp"

namespace indie
{
    class SceneOption : public AScene {
        public:
            SceneOption();
            ~SceneOption();

            Scenes run(Raylib &lib, Scenes const &prevScene) final;
            std::map<std::vector<indie::type>, std::shared_ptr<indie::Entity>> &getEntities();

            std::shared_ptr<Entity> createButton();
            std::shared_ptr<Entity> createSlider();
        private:
    };
}
#endif /* !SCENEOPTION_HPP_ */
