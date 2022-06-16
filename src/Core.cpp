/*
** EPITECH PROJECT, 2022
** indie
** File description:
** core
*/

#include "Core.hpp"

indie::Core::Core(std::size_t const fps) : _window("Bombermine")
{
}

indie::Core::~Core()
{
}

void indie::Core::start()
{
    while (_scenePos != Scenes::QUIT && !_window.closing()) {
        _graphical.updateSystem(_gameLogic.getSceneId(), _gameLogic.getScene());
        _scenePos = _gameLogic.updateSystem();
        _window.clear();
    }
}