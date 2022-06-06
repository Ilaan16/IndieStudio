/*
** EPITECH PROJECT, 2022
** B-YEP-400-TLS-4-1-indiestudio-ilan.chekroun
** File description:
** Entity
*/

#include "Entity.hpp"
#include <iostream>

indie::Entity::Entity()
{
}

indie::Entity::~Entity()
{
}

void indie::Entity::addVector3D(std::shared_ptr<Entity> &entity, int x, int y, int z, int i)
{
    std::unique_ptr<indie::IComponent> vector = std::make_unique<indie::Vector3D>(x, y, z);
    if (i == 0)
        entity->putComponent(move(vector), indie::VECTOR3D);
    if (i == 1)
        entity->putComponent(move(vector), indie::MOVEMENT);
}

void indie::Entity::addSprite3D(std::shared_ptr<Entity> &entity, const char *filename)
{
    std::unique_ptr<indie::IComponent> sprite3D = std::make_unique<indie::Sprite3D>(filename);
    entity->putComponent(move(sprite3D), indie::TEXTURE3D);
}

void indie::Entity::addModel3D(std::shared_ptr<Entity> &entity, const char *filename)
{
    std::unique_ptr<indie::IComponent> model3D = std::make_unique<indie::Model3D>(filename);
    entity->putComponent(move(model3D), indie::MODEL3D);
}

void indie::Entity::addText(std::shared_ptr<Entity> &entity, const char *text)
{
    std::unique_ptr<indie::IComponent> sprite_text = std::make_unique<indie::SpriteText>(text);
    entity->putComponent(move(sprite_text), indie::TEXT);
}

void indie::Entity::addSprite2D(std::shared_ptr<Entity> &entity, const char *filename)
{
    std::unique_ptr<indie::IComponent> sprite_text = std::make_unique<indie::SpriteText>(filename);
    entity->putComponent(move(sprite_text), indie::TEXTURE2D);
}

void indie::Entity::addIncliAndZoom(std::shared_ptr<Entity> &entity, float x, int y)
{
    std::unique_ptr<indie::IComponent> inclination_zoom = std::make_unique<indie::IncliAndZoom>(x, y);
    entity->putComponent(move(inclination_zoom), indie::CAMUTILS);
}

void indie::Entity::addIAAlgo(std::shared_ptr<Entity> &entity)
{
    std::unique_ptr<indie::IComponent> IA = std::make_unique<indie::IAAlgorithmes>();
    entity->putComponent(move(IA), indie::IA);
}

void indie::Entity::putComponent(std::unique_ptr<indie::IComponent> component, indie::tag tag)
{
    _components.emplace(tag, std::move(component));
}

void indie::Entity::addEventListener(std::shared_ptr<Entity> &entity)
{
    std::unique_ptr<indie::IComponent> Listener = std::make_unique<indie::Listener>(entity);
    entity->putComponent(move(Listener), indie::EVENT);
}

std::map<indie::tag, std::unique_ptr<indie::IComponent>> &indie::Entity::getComponents()
{
    return (this->_components);
}