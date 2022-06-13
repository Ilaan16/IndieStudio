/*
** EPITECH PROJECT, 2022
** Indie
** File description:
** SceneOption
*/

#include "scenes/SceneOption.hpp"

namespace indie {
    SceneOption::SceneOption()
    {
        std::vector<std::shared_ptr<Entity>> drawable_ent;
        std::vector<std::shared_ptr<Entity>> movable_ent;
        std::vector<std::shared_ptr<Entity>> playable_ent;
        std::vector<std::shared_ptr<Entity>> clickable_ent;
        _entities.emplace(typeEntity::DRAWABLE, drawable_ent);
        _entities.emplace(typeEntity::MOVABLE, movable_ent);
        _entities.emplace(typeEntity::PLAYABLE, playable_ent);
        _entities.emplace(typeEntity::CLICKABLE, playable_ent);
        createButton();
        createSlider();
    }

    SceneOption::~SceneOption()
    {
    }

    Scenes SceneOption::run(Scenes const &prevScene)
    {

    }

    void SceneOption::createButton()
    {
        std::shared_ptr<Entity> button = std::make_shared<indie::Entity>();
        button->addRenderer();
        _entities.find(indie::DRAWABLE)->second.push_back(button);
        _entities.find(indie::CLICKABLE)->second.push_back(button);
    }

    void SceneOption::createSlider()
    {
        std::shared_ptr<Entity> slider = std::make_shared<indie::Entity>();
        slider->addRenderer();
        _entities.find(indie::DRAWABLE)->second.push_back(slider);
        _entities.find(indie::CLICKABLE)->second.push_back(slider);
    }

    std::map<typeEntity ,std::vector<std::shared_ptr<indie::Entity>>> &SceneOption::getEntities()
    {
        return (this->_entities);
    }
}