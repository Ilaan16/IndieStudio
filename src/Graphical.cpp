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

void indie::Graphical::updateSystem(int sceneId, std::unique_ptr<indie::AScene> &scene)
{
    BeginDrawing();
    this->_raylib.displayAll(sceneId, scene->getEntities());
    if (sceneId == 3) {
        scene->update(scene->getEntities());
    }
    EndDrawing();
    scene->events.updateEvents();
}
