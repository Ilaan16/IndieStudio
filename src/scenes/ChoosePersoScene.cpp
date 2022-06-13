/*
** EPITECH PROJECT, 2022
** IndieStudio
** File description:
** ChoosePersoScene
*/

#include "scenes/ChoosePersoScene.hpp"
#include "EntitiesFactory.hpp"
#include "Core.hpp"

namespace indie {

    ChoosePersoScene::ChoosePersoScene()
    {
        EntitiesFactory Entities;
        std::vector<std::shared_ptr<Entity>> drawable_ent;
        std::vector<std::shared_ptr<Entity>> clickable_ent;
        _entities.emplace(typeEntity::DRAWABLE, drawable_ent);
        _entities.emplace(typeEntity::CLICKABLE, clickable_ent);
        Entities.createBackground(_entities, "./assets/choosePerso/background.png");
        Entities.createButton(_entities, "P1", {80, 458, 0}, {0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f});
        Entities.createButton(_entities, "P2", {1540, 458, 0}, {0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f});
        Entities.createButton(_entities, "P3", {80, 993, 0}, {0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f});
        Entities.createButton(_entities, "P4", {1540, 993, 0}, {0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f});
        Entities.createButton(_entities, "START", {800, 905, 0}, {0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f});
        Entities.createPlayer2D(_entities, "", {545, 132, 0}, {0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f});
        Entities.createPlayer2D(_entities, "", {846, 132, 0}, {0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f});
    }

    ChoosePersoScene::~ChoosePersoScene()
    {
    }

    std::map<typeEntity ,std::vector<std::shared_ptr<Entity>>> &ChoosePersoScene::getEntities()
    {
        return (this->_entities);
    }

}