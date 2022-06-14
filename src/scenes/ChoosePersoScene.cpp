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
        Entities.createButton(_entities, "P1", {30.0f, 436.0f, 0.0f}, {392.0f, 80.0f, 0.0f}, {1408, 0.0f, 0.0f}, {201.0f, 457.0f, 0.0f});
        Entities.createButton(_entities, "P2", {1498.0f, 436.0f, 0.0f}, {392.0f, 80.0f, 0.0f}, {1408.0f, 0.0f, 0.0f}, {1669.0f, 457.0f, 0.0f});
        Entities.createButton(_entities, "P3", {30.0f, 978.0f, 0.0f}, {392.0f, 80.0f, 0.0f}, {1408.0f, 0.0f, 0.0f}, {201.0f, 999.0f, 0.0f});
        Entities.createButton(_entities, "P4", {1498.0f, 978.0f, 0.0f}, {392.0f, 80.0f, 0.0f}, {1408.0f, 0.0f, 0.0f}, {1669.0f, 999.0f, 0.0f});
        Entities.createButton(_entities, "START", {763.0f, 892.0f, 0.0f}, {392.0f, 80.0f, 0.0f}, {1408.0f, 0.0f, 0.0f}, {888.0f, 913.0f, 0.0f});
        Entities.createPlayer2D(_entities, "", {561.5f, 112.0f, 0.0f}, {200.0f, 288.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f});
    }

    ChoosePersoScene::~ChoosePersoScene()
    {
    }

    std::map<typeEntity ,std::vector<std::shared_ptr<Entity>>> &ChoosePersoScene::getEntities()
    {
        return (this->_entities);
    }

}