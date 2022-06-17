/*
** EPITECH PROJECT, 2022
** indie
** File description:
** Action
*/

#include <iostream>
#include "Event.hpp"

namespace indie {
    void Action::useDown(std::unique_ptr<AScene> &ownScene, std::shared_ptr<Entity> &ownEntity) noexcept
    {
    }

    void Action::usePressed(std::unique_ptr<AScene> &ownScene, std::shared_ptr<Entity> &ownEntity) noexcept
    {
    }

    void Action::useReleased(std::unique_ptr<AScene> &ownScene, std::shared_ptr<Entity> &ownEntity) noexcept
    {
        std::shared_ptr<Renderable> renderer = std::static_pointer_cast<Renderable, IComponent>(ownEntity->getComponents().find(indie::RENDERABLE)->second);
        if (renderer->_inventory._putBomb == false) {
            renderer->_inventory._explosion = 4;
            renderer->_inventory._putBomb = true;
            renderer->_inventory.StartTimer(&renderer->_inventory._timer, renderer->_inventory._life);
            renderer->_inventory._tnt = {renderer->_position.x, renderer->_position.y, renderer->_position.z};
            renderer->_inventory._up._bomb = {renderer->_position.x, renderer->_position.y, renderer->_position.z};
            renderer->_inventory._down._bomb = {renderer->_position.x, renderer->_position.y, renderer->_position.z};
            renderer->_inventory._left._bomb = {renderer->_position.x, renderer->_position.y, renderer->_position.z};
            renderer->_inventory._right._bomb = {renderer->_position.x, renderer->_position.y, renderer->_position.z};
            renderer->_inventory._explosion = 4;
            renderer->_inventory._up_stillalive = true;
            renderer->_inventory._down_stillalive = true;
            renderer->_inventory._left_stillalive = true;
            renderer->_inventory._right_stillalive = true;
            std::cout << "Test Released" << std::endl;
        }
    }
}
