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
    std::shared_ptr<indie::IComponent> vector = std::make_shared<indie::Vector3D>(x, y, z);
    if (i == 0)
        entity->putComponent(vector, indie::VECTOR3D);
    if (i == 1)
        entity->putComponent(vector, indie::MOVEMENT);
}

void indie::Entity::addVector2D(std::shared_ptr<Entity> &entity, int x, int y, int i)
{
    std::shared_ptr<indie::IComponent> vector = std::make_shared<indie::Vector2D>(x, y);
    if (i == 0)
        entity->putComponent(move(vector), indie::VECTOR2D);
    if (i == 1)
        entity->putComponent(move(vector), indie::MOVEMENT);
}

void indie::Entity::addSprite3D(std::shared_ptr<Entity> &entity, const char *filename)
{
    std::shared_ptr<indie::IComponent> sprite3D = std::make_shared<indie::Sprite3D>(filename);
    entity->putComponent(sprite3D, indie::TEXTURE3D);
}

void indie::Entity::addModel3D(std::shared_ptr<Entity> &entity, const char *filename)
{
    std::shared_ptr<indie::IComponent> model3D = std::make_shared<indie::Model3D>(filename);
    entity->putComponent(model3D, indie::MODEL3D);
}

void indie::Entity::addText(std::shared_ptr<Entity> &entity, const char *text)
{
    std::shared_ptr<indie::IComponent> sprite_text = std::make_shared<indie::SpriteText>(text);
    entity->putComponent(sprite_text, indie::TEXT);
}

void indie::Entity::addSprite2D(std::shared_ptr<Entity> &entity, const char *filename)
{
    std::shared_ptr<indie::IComponent> sprite_text = std::make_shared<indie::SpriteText>(filename);
    entity->putComponent(sprite_text, indie::TEXTURE2D);
}

void indie::Entity::addIncliAndZoom(std::shared_ptr<Entity> &entity, float x, int y)
{
    std::shared_ptr<indie::IComponent> inclination_zoom = std::make_shared<indie::IncliAndZoom>(x, y);
    entity->putComponent(inclination_zoom, indie::CAMUTILS);
}

void indie::Entity::addIAAlgo(std::shared_ptr<Entity> &entity)
{
    std::shared_ptr<indie::IComponent> IA = std::make_shared<indie::IAAlgorithmes>();
    entity->putComponent(IA, indie::IA);
}

void indie::Entity::putComponent(std::shared_ptr<indie::IComponent> component, indie::tag tag)
{
    _components.emplace(tag, component);
}

void indie::Entity::addEventListener(std::shared_ptr<Entity> &entity)
{
    std::unique_ptr<indie::IComponent> Listener = std::make_unique<indie::Listener>(entity);
    entity->putComponent(move(Listener), indie::EVENT);
}

std::map<indie::tag, std::shared_ptr<indie::IComponent>> &indie::Entity::getComponents()
{
    return (this->_components);
}