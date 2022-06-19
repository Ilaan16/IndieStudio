/*
** EPITECH PROJECT, 2022
** B-YEP-400-TLS-4-1-indiestudio-ilan.chekroun
** File description:
** Entity
*/

#ifndef ENTITY_HPP_
#define ENTITY_HPP_

#include <vector>
#include <memory>
#include <map>
#include "components/IComponent.hpp"
#include "components/Renderable.hpp"
#include "components/IAAlgorithmes.hpp"

namespace indie
{
    enum tag {
        RENDERABLE,
        MOVEMENT,
        LISTENER,
        MUSIC
    };

    class Entity {
        public:
            Entity();
            ~Entity();

            std::map<indie::tag, std::shared_ptr<indie::IComponent>> &getComponents();
            void putComponent(std::shared_ptr<indie::IComponent> component, indie::tag tag);
            void addRenderer(std::string model = "", std::string texture = "", std::string text = "", std::string image = "",
                float fontSize = 0, indie::Vector3D position = {0}, float angle = 0, indie::Vector3D size = {0}, indie::Vector3D rect = {0}, indie::Vector3D posText = {0}, bool is3D = false, std::string animation = "");
            void addMusic(const std::string &path);
            void addListener(std::shared_ptr<Entity> &entity);
            void addIAAlgo(std::shared_ptr<Entity> &entity);
        protected:
            std::map<indie::tag, std::shared_ptr<indie::IComponent>> _components;
        private:
    };
}

#endif /* !ENTITY_HPP_ */
