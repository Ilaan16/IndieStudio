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
#include "components/Rect.hpp"
#include "components/Scale.hpp"
#include "components/SpriteText.hpp"
#include "components/Vector2D.hpp"
#include "components/Vector3D.hpp"
#include "components/IncliAndZoom.hpp"
#include "components/Sprite3D.hpp"
#include "components/Sprite2D.hpp"
#include "components/Model3D.hpp"
#include "components/IAAlgorithmes.hpp"
#include "components/Listener.hpp"

namespace indie 
{
    enum tag {
        TEXTURE2D,
        TEXTURE3D,
        VECTOR3D,
        VECTOR2D,
        IA,
        EVENT,
        CAMUTILS,
        MODEL3D,
        ROTATION,
        TEXT,
        MOVEMENT,
    };

    class Entity {
        public:
            Entity();
            ~Entity();

            std::map<indie::tag, std::shared_ptr<indie::IComponent>> &getComponents();
            void putComponent(std::shared_ptr<indie::IComponent> component, indie::tag tag);
            void addEventListener(std::shared_ptr<Entity> &entity);
            void addVelocity(std::shared_ptr<Entity> &entity);
            void addVector3D(std::shared_ptr<Entity> &entity, int x, int y, int z, int i);
            void addVector2D(std::shared_ptr<Entity> &entity, int x, int y, int i);
            void addRect(std::shared_ptr<Entity> &entity, int x, int y, int h, int l);
            void addSprite3D(std::shared_ptr<Entity> &entity, const char *filename);
            void addSprite2D(std::shared_ptr<Entity> &entity, const char *filename);
            void addModel3D(std::shared_ptr<Entity> &entity, const char *filename);
            void addText(std::shared_ptr<Entity> &entity, const char *text);
            void addIncliAndZoom(std::shared_ptr<Entity> &entity, float x, int y);
            void addIAAlgo(std::shared_ptr<Entity> &entity);
        protected:
            std::map<indie::tag, std::shared_ptr<indie::IComponent>> _components;
        private:
    };
}

#endif /* !ENTITY_HPP_ */
