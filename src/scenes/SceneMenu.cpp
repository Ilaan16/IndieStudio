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

namespace indie {
    SceneMenu::SceneMenu()
    {
        std::vector<std::shared_ptr<Entity>> drawable_ent;
        _entities.emplace(typeEntity::DRAWABLE, drawable_ent);
        createBackground();
        startButton();
    }

    SceneMenu::~SceneMenu()
    {
    }

    void SceneMenu::createBackground()
    {
        std::shared_ptr<Entity> background = std::make_shared<indie::Entity>();
        background->addRenderer("", "assets/menu/background.png", "", 0, {0.0f, 1.0f, 0.0f});
        _entities.find(indie::DRAWABLE)->second.push_back(background);
    }

    void SceneMenu::startButton()
    {
        std::shared_ptr<Entity> button = std::make_shared<indie::Entity>();
        button->addRenderer("", "assets/menu/buttons.png", "start", 0, {400.0f, 400, 0.0f}, 1, {0.0f, 0.0f, 0});
        _entities.find(indie::DRAWABLE)->second.push_back(button);
    }

    Scenes SceneMenu::run(Scenes const &prevScene)
    {
        return Scenes::QUIT;
    }

    std::map<indie::typeEntity, std::vector<std::shared_ptr<indie::Entity>>> &indie::SceneMenu::getEntities()
    {
        return (this->_entities);
    }
}