/*
** EPITECH PROJECT, 2022
** B-YEP-400-TLS-4-1-indiestudio-ilan.chekroun
** File description:
** Game
*/

#include "Game.hpp"

indie::Game::Game()
{
    this->sceneId = 0;
    std::unique_ptr<indie::AScene> menuScene = std::make_unique<indie::SceneMenu>();
    std::unique_ptr<indie::AScene> persoScene = std::make_unique<indie::ChoosePersoScene>();
    std::unique_ptr<indie::AScene> mainScene = std::make_unique<indie::MainScene>();
    std::unique_ptr<indie::AScene> optionScene = std::make_unique<indie::MainScene>();
    this->_scenes.push_back(move(menuScene));
    this->_scenes.push_back(move(persoScene));
    this->_scenes.push_back(move(mainScene));
    this->_scenes.push_back(move(optionScene));
}

indie::Game::~Game()
{
}

void indie::Game::updateSystem()
{
    std::vector<std::pair<KeyboardKey, indie::ButtonState>> keys = _scenes[sceneId]->events.getKeyboard();
    std::vector<std::pair<MouseButton, indie::ButtonState>> mouses = _scenes[sceneId]->events.getMouse();

    for (auto it = keys.begin(); it != keys.end(); it++)
        _scenes[sceneId]->listener.checkEvent(it->first, it->second, _scenes[sceneId]);
    for (auto it = mouses.begin(); it != mouses.end(); it++)
        if (_scenes[sceneId]->events.isHover(0, 0, 121, 900))
            _scenes[sceneId]->listener.checkEvent(it->first, it->second, _scenes[sceneId]);
}

void indie::Game::manageGame()
{

}

std::unique_ptr<indie::AScene> &indie::Game::getScene()
{
    return (this->_scenes[this->sceneId]);
}