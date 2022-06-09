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

void indie::Entity::addRenderer(std::string model, std::string texture, std::string text,
                float fontSize, indie::Vector3D position, float angle, indie::Vector3D size)
{
    std::shared_ptr<indie::IComponent> renderer = std::make_shared<indie::Randerable>(model, texture, text, fontSize, position, angle, size);
    this->putComponent(renderer, indie::RANDERABLE);
}

void indie::Entity::putComponent(std::shared_ptr<indie::IComponent> component, indie::tag tag)
{
    _components.emplace(tag, component);
}

std::map<indie::tag, std::shared_ptr<indie::IComponent>> &indie::Entity::getComponents()
{
    return (this->_components);
}