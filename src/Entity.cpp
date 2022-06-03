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

void indie::Entity::addVector3D(std::unique_ptr<Entity> &entity, int x, int y, int z)
{
    std::unique_ptr<indie::IComponent> vector = std::make_unique<indie::Vector3D>(x, y, z);
    entity->putComponent(move(vector));
}

void indie::Entity::addSprite3D(std::unique_ptr<Entity> &entity, const char *filename)
{
    std::unique_ptr<indie::IComponent> sprite3D = std::make_unique<indie::Sprite3D>(filename);
    entity->putComponent(move(sprite3D));
}

void indie::Entity::addModel3D(std::unique_ptr<Entity> &entity, const char *filename)
{
    std::unique_ptr<indie::IComponent> model3D = std::make_unique<indie::Model3D>(filename);
    entity->putComponent(move(model3D));
}

void indie::Entity::addText(std::unique_ptr<Entity> &entity, const char *text)
{
    std::unique_ptr<indie::IComponent> sprite_text = std::make_unique<indie::SpriteText>(text);
    entity->putComponent(move(sprite_text));
}

void indie::Entity::addIncliAndZoom(std::unique_ptr<Entity> &entity, float x, int y)
{
    std::unique_ptr<indie::IComponent> inclination_zoom = std::make_unique<indie::IncliAndZoom>(x, y);
    entity->putComponent(move(inclination_zoom));
}

void indie::Entity::addIAAlgo(std::unique_ptr<Entity> &entity)
{
    std::unique_ptr<indie::IComponent> IA = std::make_unique<indie::IAAlgorithmes>();
    entity->putComponent(move(IA));
}

void indie::Entity::putComponent(std::unique_ptr<indie::IComponent> component)
{
    _components.push_back(std::move(component));
}

std::vector<std::unique_ptr<indie::IComponent>> &indie::Entity::getComponents()
{
    return (this->_components);
}