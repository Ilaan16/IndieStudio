/*
** EPITECH PROJECT, 2022
** B-YEP-400-TLS-4-1-indiestudio-ilan.chekroun
** File description:
** Entity
*/

#include <iostream>
#include "components/Listener.hpp"
#include "Entity.hpp"

indie::Entity::Entity()
{
}

indie::Entity::~Entity()
{
}

void indie::Entity::addRenderer(std::string model, std::string texture, std::string text, std::string image,
    float fontSize, indie::Vector3D position, float angle, indie::Vector3D size, indie::Vector3D rect, indie::Vector3D posText, bool is3D, std::string animation)
{
    std::shared_ptr<indie::IComponent> renderer = std::make_shared<indie::Renderable>(model, texture, text, image, fontSize, position, angle, size, rect, posText, is3D, animation);
    this->putComponent(renderer, indie::RENDERABLE);
}

void indie::Entity::addMusic(const std::string &path)
{
    std::shared_ptr<indie::IComponent> renderer = std::make_shared<indie::Renderable>("", path);
    this->putComponent(renderer, indie::RENDERABLE);
    this->putComponent(renderer, indie::MUSIC);
}

void indie::Entity::addListener(std::shared_ptr<Entity> &entity)
{
    std::shared_ptr<indie::IComponent> listener = std::make_shared<indie::Listener>(entity);
    putComponent(listener, indie::LISTENER);
}

void indie::Entity::putComponent(std::shared_ptr<indie::IComponent> component, indie::tag tag)
{
    _components.emplace(tag, component);
}

std::map<indie::tag, std::shared_ptr<indie::IComponent>> &indie::Entity::getComponents()
{
    return (this->_components);
}