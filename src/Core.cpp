/*
** EPITECH PROJECT, 2022
** indie
** File description:
** core
*/

#include "Core.hpp"
#include "Raylib.hpp"
#include "AScene.hpp"
#include "SceneMenu.hpp"
#include "MainScene.hpp"


Core::Core(int screenWidth, int screenHeight, std::string const &title, std::size_t const fps)
    : _screenWidth(screenWidth), _screenHeight(screenHeight), _title(title), _fps(fps),  _scenePos(Scenes::MENU)
{
    _vecScenes.emplace_back(std::make_unique<indie::menu::SceneMenu>());
    _vecScenes.emplace_back(std::make_unique<indie::MainScene>());
}

Core::~Core()
{
}

void Core::start()
{
    Raylib lib;
    indie::menu::SceneMenu menu;
    indie::MainScene game;

    lib.createWindow(_screenWidth, _screenHeight, _title, _fps);
    // while (_scenePos != QUIT) {
    //     _scenePos = _vecScenes.at(_scenePos)->run(lib, _scenePos);
    // }
}