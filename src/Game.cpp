/*
** EPITECH PROJECT, 2022
** B-YEP-400-TLS-4-1-indiestudio-ilan.chekroun
** File description:
** Game
*/

#include "Game.hpp"
#include <iostream>
#include "components/Listener.hpp"
#include "raylib/RMusicManager.hpp"

int indie::Game::sceneId = 0;

indie::Game::Game(raylib::Window &window)
{
    std::unique_ptr<indie::AScene> splashScene = std::make_unique<indie::SceneSplash>();
    std::unique_ptr<indie::AScene> menuScene = std::make_unique<indie::SceneMenu>();
    std::unique_ptr<indie::AScene> persoScene = std::make_unique<indie::ChoosePersoScene>();
    std::unique_ptr<indie::AScene> mainScene = std::make_unique<indie::MainScene>();
    std::unique_ptr<indie::AScene> optionScene = std::make_unique<indie::SceneOption>(window);
    std::unique_ptr<indie::AScene> endScene = std::make_unique<indie::SceneEnd>();
    this->_scenes.push_back(move(splashScene));
    this->_scenes.push_back(move(menuScene));
    this->_scenes.push_back(move(persoScene));
    this->_scenes.push_back(move(mainScene));
    this->_scenes.push_back(move(optionScene));
    this->_scenes.push_back(move(endScene));
    splashTimer = std::chrono::steady_clock::now();
}

indie::Game::~Game()
{
}

indie::Scenes indie::Game::updateSystem()
{
    std::vector<std::pair<KeyboardKey, indie::ButtonState>> keys = _scenes[sceneId]->events.getKeyboard();
    std::vector<std::pair<MouseButton, indie::ButtonState>> mouses = _scenes[sceneId]->events.getMouse();
    std::vector<std::shared_ptr<Entity>> &_move = _scenes[sceneId]->getEntities().find(MOVABLE)->second;
    std::vector<std::shared_ptr<Entity>> &click = _scenes[sceneId]->getEntities().find(CLICKABLE)->second;
    for (auto key = keys.begin(); key != keys.end(); key++)
        for (auto ent = _move.begin(); ent != _move.end(); ent++) {
            callEvent(*ent, *key, _scenes[sceneId]);
        }

    for (auto mouse = mouses.begin(); mouse != mouses.end(); mouse++)
        for (auto ent = click.begin(); ent != click.end(); ent++) {
            callEvent(*ent, *mouse, _scenes[sceneId]);
        }
    if (sceneId == 5) {
        std::unique_ptr<indie::AScene> mainScene = std::make_unique<indie::MainScene>();
        _scenes.erase(_scenes.begin()+3);
        _scenes.emplace(_scenes.begin()+3, move(mainScene));
    }
    return static_cast<Scenes>(sceneId);
}

void indie::Game::callEvent(std::shared_ptr<Entity> &ent, std::pair<KeyboardKey, indie::ButtonState> &key,
    std::unique_ptr<AScene> &scene)
{
    auto comp = ent->getComponents().find(LISTENER);
    if (comp == ent->getComponents().end())
        return;
    std::shared_ptr<Listener> listener = std::static_pointer_cast<Listener, IComponent>(comp->second);
    listener->checkEvent(key.first, key.second, scene);
}

void indie::Game::callEvent(std::shared_ptr<Entity> &ent, std::pair<MouseButton, indie::ButtonState> &key,
    std::unique_ptr<AScene> &scene)
{
    auto comp = ent->getComponents().find(LISTENER);
    if (comp == ent->getComponents().end())
        return;
    std::shared_ptr<Listener> listener = std::static_pointer_cast<Listener, IComponent>(comp->second);
    listener->checkEvent(key.first, key.second, scene);
}

void indie::Game::setScene(const int &id)
{
    sceneId = id;
}

indie::Scenes indie::Game::manageGame()
{
    if (sceneId == 0) {
        if (std::chrono::duration_cast<std::chrono::seconds>(std::chrono::steady_clock::now() - splashTimer).count() >= 3) {
            sceneId = 1;
            return Scenes::MENU;
        }
        return Scenes::SPLASH;
    }
    return updateSystem();
}

std::unique_ptr<indie::AScene> &indie::Game::getScene()
{
    return (this->_scenes[this->sceneId]);
}

int &indie::Game::getSceneId()
{
    return (sceneId);
}