/*
** EPITECH PROJECT, 2022
** IndieStudio
** File description:
** Graphical
*/

#include "raylib/REvent.hpp"
#include "Graphical.hpp"

indie::Graphical::Graphical()
{
}

indie::Graphical::~Graphical()
{
}

indie::Scenes indie::Graphical::updateSystem(std::unique_ptr<indie::AScene> &scene)
{
    this->_raylib.displayAll(scene->getEntities());
    scene->events.updateEvents();
}
