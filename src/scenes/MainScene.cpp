/*
** EPITECH PROJECT, 2022
** indie
** File description:
** main
*/

#include "MainScene.hpp"
#include "Core.hpp"

indie::MainScene::MainScene()
{
    _entities.emplace(std::vector<type>{type::MOVABLE, type::DRAWABLE, type::PLAYABLE}, createPlayer());
    std::cout << "Player set" << std::endl;
    _entities.emplace(std::vector<type>{}, createCamera());
    std::cout << "Camera set" << std::endl;
    _entities.emplace(std::vector<type>{}, createIA());
    std::cout << "IA set" << std::endl;
}

indie::MainScene::~MainScene()
{
    //clear objects
}

Scenes indie::MainScene::run(Raylib &lib, Scenes const &prevScene)
{

}

std::unique_ptr<indie::Entity> indie::MainScene::createPlayer()
{
    std::unique_ptr<Entity> player = std::make_unique<indie::Entity>();
    player->addVector3D(player, 0.0f, 1.0f, 2.0f, 0);
    player->addVector3D(player, 1.0f, 2.0f, 1.0f, 1);
    player->addSprite3D(player, "");
    player->addModel3D(player, "");
    return (player);
}

std::unique_ptr<indie::Entity> indie::MainScene::createIA()
{
    std::unique_ptr<Entity> IA = std::make_unique<indie::Entity>();
    IA->addVector3D(IA, 0.0f, 1.0f, 2.0f, 0);
    IA->addVector3D(IA, 1.0f, 2.0f, 1.0f, 1);
    IA->addSprite3D(IA, "");
    IA->addModel3D(IA, "");
    IA->addIAAlgo(IA);
    return (IA);
}

std::unique_ptr<indie::Entity> indie::MainScene::createCamera()
{
    std::unique_ptr<Entity> camera = std::make_unique<indie::Entity>();
    camera->addVector3D(camera, 10, 10, 10, 1);
    camera->addVector3D(camera, 10, 10, 10, 1);
    camera->addVector3D(camera, 10, 10, 10, 1);
    camera->addIncliAndZoom(camera, 10, 0);
    return (camera);
}

std::map<std::vector<indie::type>, std::unique_ptr<indie::Entity>> &indie::MainScene::getEntities()
{
    return (this->_entities);
}