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
#include "IComponent.hpp"
#include "Rect.hpp"
#include "Scale.hpp"
#include "SpriteText.hpp"
#include "Vector3D.hpp"
#include "IncliAndZoom.hpp"

namespace indie 
{
    class Entity {
        public:
            Entity();
            ~Entity();

            void putComponent(std::unique_ptr<indie::IComponent> component);
            void addEventListener(std::unique_ptr<Entity> &entity);
            void addVelocity(std::unique_ptr<Entity> &entity);
            void addVector3D(std::unique_ptr<Entity> &entity, int x, int y, int z);
            void addRect(std::unique_ptr<Entity> &entity, int x, int y, int h, int l);
            void addSprite2D(std::unique_ptr<Entity> &entity, const char *filename);
            void addText(std::unique_ptr<Entity> &entity, const char *text);
            void addIncliAndZoom(std::unique_ptr<Entity> &entity, float x, int y);
        protected:
        private:
            std::vector<std::unique_ptr<indie::IComponent>> _components;
    };
}

#endif /* !ENTITY_HPP_ */
