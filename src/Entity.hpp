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
#include "components/IComponent.hpp"
#include "components/Rect.hpp"
#include "components/Scale.hpp"
#include "components/SpriteText.hpp"
#include "components/Vector3D.hpp"
#include "components/IncliAndZoom.hpp"
#include "components/Sprite3D.hpp"
#include "components/Model3D.hpp"
#include "components/IAAlgorithmes.hpp"

namespace indie 
{
    class Entity {
        public:
            Entity();
            ~Entity();

            std::vector<std::unique_ptr<IComponent>> &getComponents();
            void putComponent(std::unique_ptr<indie::IComponent> component);
            void addEventListener(std::unique_ptr<Entity> &entity);
            void addVelocity(std::unique_ptr<Entity> &entity);
            void addVector3D(std::unique_ptr<Entity> &entity, int x, int y, int z);
            void addRect(std::unique_ptr<Entity> &entity, int x, int y, int h, int l);
            void addSprite3D(std::unique_ptr<Entity> &entity, const char *filename);
            void addModel3D(std::unique_ptr<Entity> &entity, const char *filename);
            void addText(std::unique_ptr<Entity> &entity, const char *text);
            void addIncliAndZoom(std::unique_ptr<Entity> &entity, float x, int y);
            void addIAAlgo(std::unique_ptr<Entity> &entity);
        protected:
            std::vector<std::unique_ptr<indie::IComponent>> _components;
        private:
    };
}

#endif /* !ENTITY_HPP_ */
