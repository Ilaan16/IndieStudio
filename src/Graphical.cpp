/*
** EPITECH PROJECT, 2022
** IndieStudio
** File description:
** Graphical
*/

#include "Graphical.hpp"

indie::Graphical::Graphical()
{
    _raylib.createWindow(1920, 1080, "Independant Game", 60);
}

indie::Graphical::~Graphical()
{
}

int indie::Graphical::updateSystem(std::unique_ptr<indie::AScene> &scene)
{
    this->_raylib.displayAll(scene->getEntities());
}
