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
        button->addRenderer("", path, text, 0.0F, pos, 0.0F, rect, posRect, {0}, false);
        button->addListener(button);
        _entities.find(DRAWABLE)->second.push_back(button);
        _entities.find(CLICKABLE)->second.push_back(button);
    }

    void EntitiesFactory::createButton(std::map<typeEntity ,std::vector<std::shared_ptr<Entity>>> &_entities, std::string text, Vector3D pos, Vector3D rect, Vector3D posRect, Vector3D posText) {
        std::shared_ptr<Entity> button = std::make_shared<Entity>();
        button->addRenderer("", "./assets/menu/buttons.png", text, 50, pos, 0.0F, rect, posRect, posText, false);
        button->addListener(button);
        _entities.find(DRAWABLE)->second.push_back(button);
        _entities.find(CLICKABLE)->second.push_back(button);
    }

    void EntitiesFactory::createSlider(std::map<typeEntity ,std::vector<std::shared_ptr<Entity>>> &_entities, std::string text, Vector3D pos, Vector3D rect, Vector3D posRect, Vector3D posText) {
        std::shared_ptr<Entity> button = std::make_shared<Entity>();
        button->addRenderer("", "./assets/options/slider.png", text, 50, pos, 0.0F, rect, posRect, posText, false);
        button->addListener(button);
        _entities.find(DRAWABLE)->second.push_back(button);
        _entities.find(CLICKABLE)->second.push_back(button);
    }

    void EntitiesFactory::createPlayer2D(std::map<typeEntity ,std::vector<std::shared_ptr<Entity>>> &_entities, std::string text, Vector3D pos, Vector3D rect, Vector3D posRect, Vector3D posText) {
        std::shared_ptr<Entity> button = std::make_shared<Entity>();
        button->addRenderer("", "./assets/choosePerso/players.png", text, 0.0f, pos, 0.0F, rect, posRect, posText, false);
        _entities.find(DRAWABLE)->second.push_back(button);
        _entities.find(CLICKABLE)->second.push_back(button);
    }

    void EntitiesFactory::createBackground(std::map<typeEntity ,std::vector<std::shared_ptr<Entity>>> &_entities, std::string path)
    {
        std::shared_ptr<Entity> background = std::make_shared<Entity>();
        background->addRenderer("", path, "", 0.0F, {0, 0, 0}, 0.0F, {1920, 1080, 0}, {0, 0, 0}, {0, 0, 0}, false);
        _entities.find(DRAWABLE)->second.push_back(background);
    }

    void EntitiesFactory::createPlayer(std::map<typeEntity ,std::vector<std::shared_ptr<Entity>>> &_entities, std::string model, std::string texture)
    {
        std::shared_ptr<Entity> player = std::make_shared<Entity>();
        player->addRenderer(model, texture, "", 0.0F, {0, 0, 0}, 0.0F, {1920, 1080, 0}, {0, 0, 0}, {0, 0, 0}, true);
        _entities.find(DRAWABLE)->second.push_back(player);
    }

    void EntitiesFactory::createShape(std::map<typeEntity ,std::vector<std::shared_ptr<Entity>>> &_entities, std::string texture)
    {
        std::shared_ptr<Entity> bomb = std::make_shared<Entity>();
        bomb->addRenderer("", texture, "", 0.0F, {0, 0, 0}, 0.0F, {1920, 1080, 0}, {0, 0, 0}, {0, 0, 0}, true);
        _entities.find(DRAWABLE)->second.push_back(bomb);
    }

    void EntitiesFactory::createSound(std::map<typeEntity ,std::vector<std::shared_ptr<Entity>>> &_entities, std::string sound)
    {
        std::shared_ptr<Entity> music = std::make_shared<Entity>();
        music->addRenderer("", sound, "", 0.0F, {0, 0, 0}, 0.0F, {1920, 1080, 0}, {0, 0, 0}, {0, 0, 0}, false);
        _entities.find(DRAWABLE)->second.push_back(music);
    }
}
