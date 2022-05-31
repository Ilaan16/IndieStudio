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
    std::unique_ptr<indie::AScene> mainScene = std::make_unique<indie::SceneOption>();
    std::unique_ptr<indie::AScene> optionScene = std::make_unique<indie::MainScene>();
    this->_scenes.push_back(move(mainScene));
}

indie::Game::~Game()
{
}

indie::AScene *indie::Game::updateSystem()
{

}

void indie::Game::manageGame()
{

}

indie::AScene *indie::Game::initGame()
{
    
}

void indie::Game::destroyGame()
{

}

std::unique_ptr<indie::AScene> indie::Game::getScene()
{
    return (move(this->_scenes[sceneId]));
}