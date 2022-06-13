/*
** EPITECH PROJECT, 2022
** indie
** File description:
** scenemenu
*/

#include "SceneMenu.hpp"
#include "Core.hpp"
#include <chrono>
#include "Raylib.hpp"
#include "EntitiesFactory.hpp"

namespace indie {
    SceneMenu::SceneMenu()
    {
        EntitiesFactory Entities;
        std::vector<std::shared_ptr<Entity>> drawable_ent;
        std::vector<std::shared_ptr<Entity>> clicable_ent;
        _entities.emplace(typeEntity::DRAWABLE, drawable_ent);
        _entities.emplace(typeEntity::CLICKABLE, clicable_ent);
        Entities.createBackground(_entities, "./assets/menu/background.png");
        Entities.createLogo(_entities, "Play", {620.0f, 150.0f, 0.0f}, {693.0f, 97.0f, 0.0f}, {0.0f, 0.0f, 0.0f});
        Entities.createButton(_entities, "Play", {550.0f, 450.0f, 0.0f}, {800.0f, 80.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, {890.0f, 470.0f, 0.0f});
        Entities.createButton(_entities, "Settings", {550.0f, 550.0f, 0.0f}, {800.0f, 80.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, {830.0f, 570.0f, 0.0f});
        Entities.createButton(_entities, "Quit", {550.0f, 650.0f, 0.0f}, {800.0f, 80.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, {890.0f, 670.0f, 0.0f});
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