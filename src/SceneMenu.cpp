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

namespace menu {
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

    Scenes SceneMenu::run(Raylib &lib, Scenes const &prevScene)
    {
        bool enter = 0;

        while (!lib.isKeyReleased(KEY_ENTER) && lib.gameLoop()) {
            if (lib.isKeyPressed(KEY_ENTER))
                enter = !enter;
            if (lib.isKeyPressed(KEY_DOWN))
                _select = (_select + 1) % (QUIT + 1);
            if (lib.isKeyPressed(KEY_UP))
                _select = !_select ? QUIT : _select - 1;
            BeginDrawing();
            for (auto &i : _menuPos)
                lib.printRectangle(Raylib::BASIC, i.at(0), i.at(1), {ORANGE, ORANGE});
            lib.printRectangle(Raylib::GRADIENT, _menuPos.at(_select).at(0), _menuPos.at(_select).at(1), {RED, RED});
            if (enter)
                lib.printRectangle(Raylib::GRADIENT, _menuPos.at(_select).at(0), _menuPos.at(_select).at(1), {PINK, PINK});
            for (std::size_t i = 0; i <= QUIT; ++i)
                lib.printText(_menuText[i], _menuPos[i].at(0), 20, BLACK);
            EndDrawing();
        }
        if (_select == QUIT)
            return (_returnScene.at(static_cast<menu_e>(_select)));
        return (_returnScene.at(static_cast<menu_e>(_select)));
    }
}