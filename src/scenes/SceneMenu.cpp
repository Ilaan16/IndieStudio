/*
** EPITECH PROJECT, 2022
** indie
** File description:
** scenemenu
*/

#include "scenes/SceneMenu.hpp"
#include "Core.hpp"
#include <chrono>
#include "Raylib.hpp"
#include "EntitiesFactory.hpp"

namespace indie {
    SceneMenu::SceneMenu()
    {
        std::vector<std::shared_ptr<Entity>> drawable_ent;
        _entities.emplace(typeEntity::DRAWABLE, drawable_ent);
        EntitiesFactory::createBackground(_entities, "/assets/menu/background.png");
        EntitiesFactory::createButton(_entities, "Play", {0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f});
        EntitiesFactory::createButton(_entities, "Settings", {0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f});
        EntitiesFactory::createButton(_entities, "Quit", {0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f});
    }

    SceneMenu::~SceneMenu()
    {
    }

    Scenes SceneMenu::run(Scenes const &prevScene)
    {
        return Scenes::QUIT;
    }

    std::map<typeEntity, std::vector<std::shared_ptr<Entity>>> &SceneMenu::getEntities()
    {
        return (this->_entities);
    }
}