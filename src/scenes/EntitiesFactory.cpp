/*
** EPITECH PROJECT, 2022
** IndieStudio
** File description:
** EntitiesFactory
*/

#include "EntitiesFactory.hpp"

namespace indie {
    EntitiesFactory::EntitiesFactory()
    {
    }

    EntitiesFactory::~EntitiesFactory()
    {
    }

    void EntitiesFactory::createButton(std::map<typeEntity ,std::vector<std::shared_ptr<Entity>>> &_entities, std::string text, Vector3D pos, Vector3D rect, Vector3D posRect) {
        std::shared_ptr<Entity> button = std::make_shared<Entity>();
        button->addRenderer("", "assets/menu/buttons.png", text, 0.0F, pos, 0.0F, posRect, rect);
        _entities.find(DRAWABLE)->second.push_back(button);
        _entities.find(CLICKABLE)->second.push_back(button);
    }

    void EntitiesFactory::createPlayer2D(std::map<typeEntity ,std::vector<std::shared_ptr<Entity>>> &_entities, std::string text, Vector3D pos, Vector3D rect, Vector3D posRect) {
        std::shared_ptr<Entity> button = std::make_shared<Entity>();
        button->addRenderer("", "assets/choosePerso/players.png", text, 0.0F, pos, 0.0F, posRect, rect);
        _entities.find(DRAWABLE)->second.push_back(button);
        _entities.find(CLICKABLE)->second.push_back(button);
    }

    void EntitiesFactory::createBackground(std::map<typeEntity ,std::vector<std::shared_ptr<Entity>>> &_entities, std::string path)
    {
        std::shared_ptr<Entity> background = std::make_shared<Entity>();
        background->addRenderer("", path, "", 0, {0.0f, 1.0f, 0.0f});
        _entities.find(DRAWABLE)->second.push_back(background);
    }
}