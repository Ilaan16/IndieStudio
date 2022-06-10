/*
** EPITECH PROJECT, 2022
** IndieStudio
** File description:
** ChoosePersoScene
*/

#ifndef CHOOSEPERSOSCENE_HPP_
#define CHOOSEPERSOSCENE_HPP_

#include "scenes/AScene.hpp"
#include <array>
#include <unordered_map>

namespace indie
{
    class ChoosePersoScene : public AScene {
        public:
            ChoosePersoScene();
            ~ChoosePersoScene();

            void createBackground();
            void createButton(const char *path ,const char *text, Vector3D pos);
            Scenes run(Scenes const &prevScene) final;
            std::map<typeEntity ,std::vector<std::shared_ptr<indie::Entity>>> &getEntities();
        protected:
        private:
    };
}

#endif /* !CHOOSEPERSOSCENE_HPP_ */
