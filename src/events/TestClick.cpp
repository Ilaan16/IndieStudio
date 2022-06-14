/*
** EPITECH PROJECT, 2022
** Indie
** File description:
** TestKey
*/

#include <iostream>
#include "Event.hpp"
#include "raylib/REvent.hpp"

namespace indie {
    void TestClick::useDown(std::unique_ptr<AScene> &ownScene, std::shared_ptr<Entity> &ownEntity) noexcept
    {
        std::shared_ptr<Renderable> renderer = std::static_pointer_cast<Renderable, IComponent>(ownEntity->getComponents().find(indie::RENDERABLE)->second);
        if (raylib::REvent::isHover(renderer->_rect.x, renderer->_rect.y, renderer->_size.x, renderer->_size.y))
            std::cout << "Test Down" << std::endl;
    }

    void TestClick::usePressed(std::unique_ptr<AScene> &ownScene, std::shared_ptr<Entity> &ownEntity) noexcept
    {
        std::shared_ptr<Renderable> renderer = std::static_pointer_cast<Renderable, IComponent>(ownEntity->getComponents().find(indie::RENDERABLE)->second);
        if (raylib::REvent::isHover(renderer->_rect.x, renderer->_rect.y, renderer->_size.x, renderer->_size.y))
            std::cout << "Test Pressed" << std::endl;
    }

    void TestClick::useReleased(std::unique_ptr<AScene> &ownScene, std::shared_ptr<Entity> &ownEntity) noexcept
    {
        std::shared_ptr<Renderable> renderer = std::static_pointer_cast<Renderable, IComponent>(ownEntity->getComponents().find(indie::RENDERABLE)->second);
        if (raylib::REvent::isHover(renderer->_rect.x, renderer->_rect.y, renderer->_size.x, renderer->_size.y))
            std::cout << "Test Released" << std::endl;
    }

    void TestClick::useNone(std::unique_ptr<AScene> &ownScene, std::shared_ptr<Entity> &ownEntity) noexcept
    {
        std::shared_ptr<Renderable> renderer = std::static_pointer_cast<Renderable, IComponent>(ownEntity->getComponents().find(indie::RENDERABLE)->second);
        if (raylib::REvent::isHover(renderer->_rect.x, renderer->_rect.y, renderer->_size.x, renderer->_size.y))
            std::cout << "Test Hover" << std::endl;
    }
}
