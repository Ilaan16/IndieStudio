/*
** EPITECH PROJECT, 2022
** IndieStudio
** File description:
** Graphical
*/

#include "Graphical.hpp"

indie::Graphical::Graphical()
{
}

indie::Graphical::~Graphical()
{
}

void indie::Graphical::updateSystem(std::unique_ptr<indie::AScene> &scene)
{
    this->_raylib.displayAll(scene->getEntities());
}
