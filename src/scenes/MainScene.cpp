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
    createMap();
    EntitiesFactory Entities;
    Entities.createPlayer(_entities,"./assets/characters/character.iqm", "./assets/characters/steve.png");
    createIA();
    std::cout << "Player set" << std::endl;
    createCamera();
    std::cout << "Camera set" << std::endl;
}

indie::MainScene::~MainScene()
{
    //clear objects
}

void indie::MainScene::createPlayer()
{
    std::shared_ptr<Entity> player = std::make_shared<indie::Entity>();
    player->addRenderer();
    _entities.find(indie::DRAWABLE)->second.push_back(player);
    _entities.find(indie::PLAYABLE)->second.push_back(player);
}

void indie::MainScene::createIA()
{
    std::shared_ptr<Entity> IA = std::make_shared<indie::Entity>();
    IA->addRenderer("./assets/characters/character.iqm", "./assets/characters/steve.png", "", 0, {1, 1, 1}, 0, {0, 0, 0}, {0}, {0}, true);
    _entities.find(indie::DRAWABLE)->second.push_back(IA);
}

void indie::MainScene::createMap()
{
}

void indie::MainScene::createCamera()
{
    std::shared_ptr<Entity> camera = std::make_shared<indie::Entity>();
}

std::map<indie::typeEntity, std::vector<std::shared_ptr<indie::Entity>>> &indie::MainScene::getEntities()
{
    return (this->_entities);
}