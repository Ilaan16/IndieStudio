/*
** EPITECH PROJECT, 2022
** indie
** File description:
** core
*/

#include "Core.hpp"

indie::Core::Core(std::size_t const fps)
{
    //std::cout << 1 << std::endl;
    //_vecScenes.emplace_back(std::make_unique<indie::SceneMenu>());
    //_vecScenes.emplace_back(std::make_unique<indie::MainScene>());
}

indie::Core::~Core()
{
}

void indie::Core::start()
{
    while (_scenePos != QUIT) {
        _gameLogic.updateSystem();
        _raylib.updateSystem(_gameLogic.getScene());
    }
}