/*
** EPITECH PROJECT, 2022
** indie
** File description:
** Movement
*/

#include "Event.hpp"
#include <iostream>

namespace indie {
    Movement::Movement(int direction)
    {
        _direction = direction;
    }

    void Movement::useDown(std::unique_ptr<AScene> &ownScene, std::shared_ptr<Entity> &ownEntity) noexcept
    {
        std::shared_ptr<Renderable> renderer = std::static_pointer_cast<Renderable, IComponent>(ownEntity->getComponents().find(indie::RENDERABLE)->second);
        std::cout << "Test Down" << std::endl;
        if (_direction == 1)
            renderer->_position.x += 0.1f;
        if (_direction == 2)
            renderer->_position.x -= 0.1f;
        if (_direction == 3)
            renderer->_position.z += 0.1f;
        if (_direction == 4)
            renderer->_position.z -= 0.1f;
    }

    void Movement::usePressed(std::unique_ptr<AScene> &ownScene, std::shared_ptr<Entity> &ownEntity) noexcept
    {
        std::cout << "Test Pressed" << std::endl;
    }

    void Movement::useReleased(std::unique_ptr<AScene> &ownScene, std::shared_ptr<Entity> &ownEntity) noexcept
    {
        std::cout << "Test Released" << std::endl;
    }
}
