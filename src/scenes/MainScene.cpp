/*
** EPITECH PROJECT, 2022
** indie
** File description:
** main
*/

#include "scenes/MainScene.hpp"
#include "EntitiesFactory.hpp"
#include "Core.hpp"

indie::MainScene::MainScene()
{
    std::vector<std::shared_ptr<Entity>> drawable_ent;
    std::vector<std::shared_ptr<Entity>> movable_ent;
    std::vector<std::shared_ptr<Entity>> playable_ent;
    _entities.emplace(typeEntity::DRAWABLE, drawable_ent);
    _entities.emplace(typeEntity::MOVABLE, movable_ent);
    _entities.emplace(typeEntity::PLAYABLE, playable_ent);
    EntitiesFactory Entities;
    Entities.createPlayer(_entities,"./assets/characters/character.iqm", "./assets/characters/steve.png", {2, 2, 2}, 0.0F, {1920, 1080, 0});
    std::cout << "Player set" << std::endl;
    Entities.createMap(_entities,"", "assets/map/cubicmap_atlas.png", {0, 0, 0}, 0.0F, {1920, 1080, 0}, "assets/map/map.png");
    createCamera();
    std::cout << "Camera set" << std::endl;
}

indie::MainScene::~MainScene()
{
    //clear objects
}

void indie::MainScene::createCamera()
{
    std::shared_ptr<Entity> camera = std::make_shared<indie::Entity>();
}

std::map<indie::typeEntity, std::vector<std::shared_ptr<indie::Entity>>> &indie::MainScene::getEntities()
{
    return (this->_entities);
}