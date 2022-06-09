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

namespace indie {
    SceneMenu::SceneMenu()
    {
        createBackground();
        createButton("./assets/menu/button.png", Vector2D(0, 0), Vector2D(0, 0));
        createButton("./assets/menu/button.png", Vector2D(0, 200), Vector2D(200, 100));
        createButton("./assets/menu/button.png", Vector2D(0, 300), Vector2D(200, 100));
    }

    SceneMenu::~SceneMenu()
    {
    }

    void SceneMenu::createBackground()
    {
        std::shared_ptr<Entity> background = std::make_shared<indie::Entity>();
        background->addVector2D(background, 0.0f, 1.0f, 0);
        background->addSprite2D(background, "assets/menu/background.png");
    }

    void SceneMenu::createButton(const char *path, Vector2D pos, Vector2D rect)
    {
        std::shared_ptr<Entity> button = std::make_shared<indie::Entity>();
        button->addVector2D(button, 0.0f, 1.0f, 0);
        button->addVector2D(button, pos._x, pos._y, 0);
        button->addVector2D(button, rect._x, rect._y, 1);
        button->addSprite2D(button, path);
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