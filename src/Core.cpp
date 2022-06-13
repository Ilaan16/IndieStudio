/*
** EPITECH PROJECT, 2022
** indie
** File description:
** core
*/

#include "Core.hpp"

indie::Core::Core(std::size_t const fps) : _window("Bomberman")
{
}

indie::Core::~Core()
{
}

void indie::Core::start()
{
    while (_scenePos != Scenes::QUIT) {
        _scenePos = _graphical.updateSystem(_gameLogic.getScene());
        _gameLogic.updateSystem();
    }
}