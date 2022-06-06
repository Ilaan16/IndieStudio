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
    //this->_scenes.push_back(std::make_unique<indie::MainScene>());
    //this->_scenes.push_back(std::make_unique<indie::SceneMenu>());
    this->_scenes.push_back(std::make_unique<indie::SceneOption>());
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

std::unique_ptr<indie::AScene> &indie::Game::getScene()
{
    return (this->_scenes[sceneId]);
}