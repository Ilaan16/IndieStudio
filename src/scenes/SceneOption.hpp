/*
** EPITECH PROJECT, 2022
** Indie
** File description:
** SceneOption
*/

#ifndef SCENEOPTION_HPP_
    #define SCENEOPTION_HPP_

    #include "scenes/AScene.hpp"

namespace indie
{
    class SceneOption : public AScene {
        public:
            SceneOption();
            ~SceneOption();

            std::map<typeEntity ,std::vector<std::shared_ptr<indie::Entity>>> &getEntities();

            void createButton();
            void createSlider();
        private:
    };
}
#endif /* !SCENEOPTION_HPP_ */
