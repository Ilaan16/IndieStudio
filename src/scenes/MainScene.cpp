/*
** EPITECH PROJECT, 2022
** indie
** File description:
** main
*/

#include "scenes/MainScene.hpp"
#include "Core.hpp"

indie::MainScene::MainScene()
{
    std::vector<std::shared_ptr<Entity>> drawable_ent;
    std::vector<std::shared_ptr<Entity>> movable_ent;
    std::vector<std::shared_ptr<Entity>> playable_ent;
    _entities.emplace(typeEntity::DRAWABLE, drawable_ent);
    _entities.emplace(typeEntity::MOVABLE, movable_ent);
    _entities.emplace(typeEntity::PLAYABLE, playable_ent);
    createPlayer();
    std::cout << "Player set" << std::endl;
    createCamera();
    std::cout << "Camera set" << std::endl;
    createIA();
    std::cout << "IA set" << std::endl;
}

indie::MainScene::~MainScene()
{
    //clear objects
}

Scenes indie::MainScene::run(Scenes const &prevScene)
{

}

void indie::MainScene::createPlayer()
{
    std::shared_ptr<Entity> player = std::make_shared<indie::Entity>();
    player->addVector3D(player, 0.0f, 1.0f, 2.0f, 0);
    player->addVector3D(player, 1.0f, 2.0f, 1.0f, 1);
    player->addSprite3D(player, "");
    player->addModel3D(player, "");
    _entities.find(indie::DRAWABLE)->second.push_back(player);
    _entities.find(indie::MOVABLE)->second.push_back(player);
    _entities.find(indie::PLAYABLE)->second.push_back(player);
}

void indie::MainScene::createIA()
{
    std::shared_ptr<Entity> IA = std::make_shared<indie::Entity>();
    IA->addVector3D(IA, 0.0f, 1.0f, 2.0f, 0);
    IA->addVector3D(IA, 1.0f, 2.0f, 1.0f, 1);
    IA->addSprite3D(IA, "");
    IA->addModel3D(IA, "");
    IA->addIAAlgo(IA);
}

void indie::MainScene::createCamera()
{
    std::shared_ptr<Entity> camera = std::make_shared<indie::Entity>();
    camera->addVector3D(camera, 10, 10, 10, 1);
    camera->addVector3D(camera, 10, 10, 10, 1);
    camera->addVector3D(camera, 10, 10, 10, 1);
    camera->addIncliAndZoom(camera, 10, 0);
}

std::map<indie::typeEntity, std::vector<std::shared_ptr<indie::Entity>>> &indie::MainScene::getEntities()
{
    return (this->_entities);
}