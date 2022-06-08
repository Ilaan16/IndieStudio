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

    void SceneMenu::startButton()
    {
        std::shared_ptr<Entity> button = std::make_shared<indie::Entity>();
        button->addVector2D(button, 0.0f, 1.0f, 0);
        button->addVector2D(button, 1.0f, 2.0f, 1);
        button->addText(button, "");
        button->addSprite2D(button, "assets/menu/start.png");
    }

    void SceneMenu::settingsButton()
    {
        std::shared_ptr<Entity> button = std::make_shared<indie::Entity>();
        button->addVector2D(button, 0.0f, 1.0f, 0);
        button->addVector2D(button, 1.0f, 2.0f, 1);
        button->addText(button, "");
        button->addSprite2D(button, "assets/menu/settings.png");
    }

    void SceneMenu::quitButton()
    {
        std::shared_ptr<Entity> button = std::make_shared<indie::Entity>();
        button->addVector2D(button, 0.0f, 1.0f, 0);
        button->addVector2D(button, 1.0f, 2.0f, 1);
        button->addText(button, "");
        button->addSprite2D(button, "assets/menu/quit.png");
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