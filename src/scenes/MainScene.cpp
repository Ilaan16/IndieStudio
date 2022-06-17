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
    Entities.createSound(_entities, "assets/sound/C418 - Aria Math, but its an EPIC Soundtrack.mp3");
    Entities.createPlayer(_entities,"./assets/characters/character.iqm", "./assets/characters/steve.png", {2, 2, 2}, 0.0F, {1920, 1080, 0});
    Entities.createPlayer(_entities,"./assets/characters/character.iqm", "./assets/characters/steve.png", {-6.0f, 2.0f, 6.0f}, 0.0F, {1920, 1080, 0});
    Entities.createMap(_entities,"", "assets/map/cubicmap_atlas.png", {0, 0, 0}, 0.0F, {1920, 1080, 0}, "assets/map/map.png");
}

indie::MainScene::~MainScene()
{
    //clear objects
}

std::map<indie::typeEntity, std::vector<std::shared_ptr<indie::Entity>>> &indie::MainScene::getEntities()
{
    return (this->_entities);
}