/*
** EPITECH PROJECT, 2022
** indie
** File description:
** core
*/

#include "Core.hpp"

Core::Core(int screenWidth, int screenHeight, std::string const &title, std::size_t const fps)
    : _screenWidth(screenWidth), _screenHeight(screenHeight), _title(title), _fps(fps),  _scenePos(Scenes::MENU)
{
    std::cout << 1 << std::endl;
    _vecScenes.emplace_back(std::make_unique<indie::SceneMenu>());
    _vecScenes.emplace_back(std::make_unique<indie::MainScene>());
}

Core::~Core()
{
}

void Core::start()
{
    Raylib lib;
    indie::SceneMenu menu;
    indie::MainScene game;
    std::cout << 2 << std::endl;

    lib.createWindow(_screenWidth, _screenHeight, _title, _fps);
    _raylib.updateSystem(_gameLogic.getScene());
    // while (_scenePos != QUIT) {
    //     _scenePos = _vecScenes.at(_scenePos)->run(lib, _scenePos);
    // }
}