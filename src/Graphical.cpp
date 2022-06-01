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

int indie::Graphical::updateSystem(std::unique_ptr<indie::AScene> &scene)
{
    scene->getEntities();
}

void indie::Graphical::destroyGame()
{

}

indie::IEvent *indie::Graphical::translateEvent()
{

}