/*
** EPITECH PROJECT, 2022
** indie
** File description:
** main
*/

#include "scenes/MainScene.hpp"
#include "EntitiesFactory.hpp"
#include "components/Listener.hpp"
#include "Core.hpp"
#include <vector>

indie::MainScene::MainScene()
{
    std::vector<std::shared_ptr<Entity>> drawable_ent;
    std::vector<std::shared_ptr<Entity>> movable_ent;
    std::vector<std::shared_ptr<Entity>> playable_ent;

    std::unique_ptr<Event> move_right = std::make_unique<Movement>(1);
    std::unique_ptr<Event> move_left = std::make_unique<Movement>(2);
    std::unique_ptr<Event> move_down = std::make_unique<Movement>(3);
    std::unique_ptr<Event> move_up = std::make_unique<Movement>(4);

    std::unique_ptr<Event> move_right2 = std::make_unique<Movement>(1);
    std::unique_ptr<Event> move_left2 = std::make_unique<Movement>(2);
    std::unique_ptr<Event> move_down2 = std::make_unique<Movement>(3);
    std::unique_ptr<Event> move_up2 = std::make_unique<Movement>(4);

    _entities.emplace(typeEntity::DRAWABLE, drawable_ent);
    _entities.emplace(typeEntity::MOVABLE, movable_ent);
    _entities.emplace(typeEntity::PLAYABLE, playable_ent);

    EntitiesFactory Entities;

    Entities.createSound(_entities, "assets/sound/C418 - Aria Math, but its an EPIC Soundtrack.mp3");

    Entities.createPlayer(_entities,"./assets/characters/character.iqm", "./assets/characters/steve.png", {-6.0f, 2.0f, 6.0f}, 0.0F, {1920, 1080, 0});
    this->addEventToLastEntity(KeyboardKey::KEY_RIGHT, move_right);
    this->addEventToLastEntity(KeyboardKey::KEY_LEFT, move_left);
    this->addEventToLastEntity(KeyboardKey::KEY_DOWN, move_down);
    this->addEventToLastEntity(KeyboardKey::KEY_UP, move_up);

    Entities.createPlayer(_entities,"./assets/characters/character.iqm", "./assets/characters/steve.png", {6.0f, 2.0f, 6.0f}, 0.0F, {1920, 1080, 0});
    this->addEventToLastEntity(KeyboardKey::KEY_D, move_right2);
    this->addEventToLastEntity(KeyboardKey::KEY_A, move_left2);
    this->addEventToLastEntity(KeyboardKey::KEY_S, move_down2);
    this->addEventToLastEntity(KeyboardKey::KEY_W, move_up2);

    Entities.createMap(_entities,"", "assets/map/cubicmap_atlas.png", {0, 0, 0}, 0.0F, {1920, 1080, 0}, "assets/map/map.png");

    std::vector<std::pair<KeyboardKey, ButtonState>> input;
    input.push_back(std::make_pair(KeyboardKey::KEY_RIGHT, ButtonState::None));
    input.push_back(std::make_pair(KeyboardKey::KEY_LEFT, ButtonState::None));
    input.push_back(std::make_pair(KeyboardKey::KEY_DOWN, ButtonState::None));
    input.push_back(std::make_pair(KeyboardKey::KEY_UP, ButtonState::None));

    input.push_back(std::make_pair(KeyboardKey::KEY_D, ButtonState::None));
    input.push_back(std::make_pair(KeyboardKey::KEY_A, ButtonState::None));
    input.push_back(std::make_pair(KeyboardKey::KEY_S, ButtonState::None));
    input.push_back(std::make_pair(KeyboardKey::KEY_W, ButtonState::None));
    

    events = raylib::REvent({input}, {});
}

void indie::MainScene::addEventToLastEntity(const KeyboardKey &key, std::unique_ptr<Event> &evt)
{
    std::shared_ptr<indie::IComponent> comp = _entities.find(MOVABLE)->second.back()->getComponents().find(LISTENER)->second;
    std::shared_ptr<indie::Listener> listener = std::static_pointer_cast<Listener, IComponent>(comp);

    listener->addEvent(key, evt);
}

indie::MainScene::~MainScene()
{
    //clear objects
}

std::map<indie::typeEntity, std::vector<std::shared_ptr<indie::Entity>>> &indie::MainScene::getEntities()
{
    return (this->_entities);
}