/*
** EPITECH PROJECT, 2022
** IndieStudio
** File description:
** SceneEnd
*/

#include "scenes/SceneEnd.hpp"
#include "EntitiesFactory.hpp"
#include "Core.hpp"

namespace indie {

    SceneEnd::SceneEnd()
    {
        EntitiesFactory Entities;
        std::vector<std::shared_ptr<Entity>> drawable_ent;
        std::vector<std::shared_ptr<Entity>> clickable_ent;
        _entities.emplace(typeEntity::DRAWABLE, drawable_ent);
        _entities.emplace(typeEntity::CLICKABLE, clickable_ent);
        Entities.createBackground(_entities, "./assets/end/background.png");
        Entities.createButton(_entities, "restart", {555.0f, 842.5f, 0.0f}, {392.0f, 80.0f, 0.0f}, {1408, 0.0f, 0.0f}, {632.0f, 863.0f, 0.0f});
        Entities.createButton(_entities, "exit", {991.0f, 842.5f, 0.0f}, {392.0f, 80.0f, 0.0f}, {1408, 0.0f, 0.0f}, {1125.0f, 863.0f, 0.0f});
    }

    SceneEnd::~SceneEnd()
    {
    }

    std::map<typeEntity ,std::vector<std::shared_ptr<Entity>>> &SceneEnd::getEntities()
    {
        return (this->_entities);
    }
}