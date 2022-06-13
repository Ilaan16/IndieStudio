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
        Entities.createButton(_entities, "P1", {80.0f, 458.0f, 0.0f}, {304, 40.0f, 0.0f}, {400, 0.0f, 0.0f});
        Entities.createButton(_entities, "P2", {1540.0f, 458.0f, 0.0f}, {304.0f, 40.0f, 0.0f}, {400.0f, 0.0f, 0.0f});
        Entities.createButton(_entities, "P3", {80.0f, 993.0f, 0.0f}, {304.0f, 40.0f, 0.0f}, {400.0f, 0.0f, 0.0f});
        Entities.createButton(_entities, "P4", {1540.0f, 993.0f, 0.0f}, {304.0f, 40.0f, 0.0f}, {400.0f, 0.0f, 0.0f});
        Entities.createButton(_entities, "START", {800.0f, 905.0f, 0.0f}, {400.0f, 40.0f, 0.0f}, {0.0f, 0.0f, 0.0f});
        Entities.createPlayer2D(_entities, "Test", {545.0f, 132.0f, 0.0f}, {200.0f, 400.0f, 0.0f}, {0.0f, 0.0f, 0.0f});
        Entities.createPlayer2D(_entities, "Test", {846.0f, 132.0f, 0.0f}, {200.0f, 400.0f, 0.0f}, {0.0f, 0.0f, 0.0f});
    }

    ChoosePersoScene::~ChoosePersoScene()
    {
    }

    Scenes ChoosePersoScene::run(Scenes const &prevScene)
    {

    }

    std::map<typeEntity ,std::vector<std::shared_ptr<Entity>>> &ChoosePersoScene::getEntities()
    {
        return (this->_entities);
    }

}