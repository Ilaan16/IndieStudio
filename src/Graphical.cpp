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

void indie::Graphical::updateSystem(int *sceneId, std::unique_ptr<indie::AScene> &scene)
{
    BeginDrawing();
    this->_raylib.displayAll(scene->getEntities());
    scene->update(sceneId, scene->getEntities());
    EndDrawing();
    scene->events.updateEvents();
}
