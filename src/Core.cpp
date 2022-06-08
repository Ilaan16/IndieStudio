/*
** EPITECH PROJECT, 2022
** indie
** File description:
** core
*/

#include "Core.hpp"

indie::Core::Core(std::size_t const fps)
    : _fps(fps),  _scenePos(Scenes::MENU)
{

}

indie::Core::~Core()
{
}

void indie::Core::start()
{
    std::cout << 2 << std::endl;

    while (_scenePos != QUIT) {
        _raylib.updateSystem(_gameLogic.getScene());
    }
}