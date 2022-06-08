/*
** EPITECH PROJECT, 2022
** indie
** File description:
** scenemenu
*/

#include "SceneMenu.hpp"
#include "Core.hpp"
#include <chrono>
#include "Raylib.hpp"

namespace indie
{
    const std::vector<std::string> SceneMenu::_menuText {
        "Start game",
        "Load game",
        "Settings",
        "Quit"
    };

    const std::vector<std::array<std::pair<float, float>, 2>> SceneMenu::_menuPos {
        {{{860.0f, 600.0f}, {200.0f, 50.0f}}},
        {{{860.0f, 700.0f}, {200.0f, 50.0f}}},
        {{{860.0f, 800.0f}, {200.0f, 50.0f}}},
        {{{860.0f, 900.0f}, {200.0f, 50.0f}}}
    };

    SceneMenu::SceneMenu() : _select(menu_e::START)
    {
    }

    SceneMenu::~SceneMenu()
    {
    }

    Scenes SceneMenu::run(Scenes const &prevScene)
    {

    }

    std::map<typeEntity ,std::vector<std::shared_ptr<indie::Entity>>> &indie::SceneMenu::getEntities()
    {
        return (this->_entities);
    }
}