/*
** EPITECH PROJECT, 2022
** indie
** File description:
** core
*/

#include "Core.hpp"

Core::Core(std::size_t const fps)
    : _fps(fps),  _scenePos(Scenes::MENU)
{

}

Core::~Core()
{
}

void Core::start()
{
    std::cout << 2 << std::endl;

    while (_scenePos != QUIT) {
        _gameLogic.updateSystem();
        _raylib.updateSystem(_gameLogic.getScene());
    }
}