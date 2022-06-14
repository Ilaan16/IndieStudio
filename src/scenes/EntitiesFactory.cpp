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

    void EntitiesFactory::createLogo(std::map<typeEntity ,std::vector<std::shared_ptr<Entity>>> &_entities, std::string path, std::string text, Vector3D pos, Vector3D rect, Vector3D posRect) {
        std::shared_ptr<Entity> button = std::make_shared<Entity>();
        button->addRenderer("", path, text, 0.0F, pos, 0.0F, rect, posRect);
        _entities.find(DRAWABLE)->second.push_back(button);
    }

    void EntitiesFactory::createButton(std::map<typeEntity ,std::vector<std::shared_ptr<Entity>>> &_entities, std::string text, Vector3D pos, Vector3D rect, Vector3D posRect, Vector3D posText) {
        std::shared_ptr<Entity> button = std::make_shared<Entity>();
        button->addRenderer("", "./assets/menu/buttons.png", text, 50, pos, 0.0F, rect, posRect, posText);
        _entities.find(DRAWABLE)->second.push_back(button);
        _entities.find(CLICKABLE)->second.push_back(button);
    }

    void EntitiesFactory::createSlider(std::map<typeEntity ,std::vector<std::shared_ptr<Entity>>> &_entities, std::string text, Vector3D pos, Vector3D rect, Vector3D posRect, Vector3D posText) {
        std::shared_ptr<Entity> button = std::make_shared<Entity>();
        button->addRenderer("", "./assets/options/slider.png", text, 50, pos, 0.0F, rect, posRect, posText);
        _entities.find(DRAWABLE)->second.push_back(button);
        _entities.find(CLICKABLE)->second.push_back(button);
    }

    void EntitiesFactory::createPlayer2D(std::map<typeEntity ,std::vector<std::shared_ptr<Entity>>> &_entities, std::string text, Vector3D pos, Vector3D rect, Vector3D posRect, Vector3D posText) {
        std::shared_ptr<Entity> button = std::make_shared<Entity>();
        button->addRenderer("", "./assets/choosePerso/players.png", text, 0.0f, pos, 0.0F, rect, posRect, posText);
        _entities.find(DRAWABLE)->second.push_back(button);
        _entities.find(CLICKABLE)->second.push_back(button);
    }

    void EntitiesFactory::createBackground(std::map<typeEntity ,std::vector<std::shared_ptr<Entity>>> &_entities, std::string path)
    {
        std::shared_ptr<Entity> background = std::make_shared<Entity>();
        background->addRenderer("", path, "", 0.0F, {0, 0, 0}, 0.0F, {1920, 1080, 0}, {0, 0, 0});
        _entities.find(DRAWABLE)->second.push_back(background);
    }
}