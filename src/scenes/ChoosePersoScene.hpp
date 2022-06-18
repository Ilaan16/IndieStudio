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
#include "raylib/REvent.hpp"
#include "events/Event.hpp"

namespace indie
{
    class ChoosePersoScene : public AScene {
        public:
            ChoosePersoScene();
            ~ChoosePersoScene();

            std::map<typeEntity ,std::vector<std::shared_ptr<indie::Entity>>> &getEntities();
            void update(std::map<indie::typeEntity, std::vector<std::shared_ptr<indie::Entity>>> &entity);
        protected:
        private:
            void addEventToLastEntity(const MouseButton &mouse, std::shared_ptr<MouseEvent> &evt);
            std::size_t _select;
    };
}

#endif /* !CHOOSEPERSOSCENE_HPP_ */
