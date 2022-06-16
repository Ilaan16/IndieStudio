/*
** EPITECH PROJECT, 2022
** IndieStudio
** File description:
** Slider
*/

#include <iostream>
#include <utility>
#include "Event.hpp"
#include "raylib/REvent.hpp"
#include "Game.hpp"

namespace indie
{
    void Slider::useDown(std::unique_ptr<AScene> &ownScene, std::shared_ptr<Entity> &ownEntity) noexcept
    {
        std::shared_ptr<Renderable> renderer = std::static_pointer_cast<Renderable, IComponent>(ownEntity->getComponents().find(indie::RENDERABLE)->second);
        if (raylib::REvent::isHover(renderer->_position.x, renderer->_position.y, renderer->_size.y, renderer->_size.x)) {
            mouse = GetMousePosition();
            if (mouse_last.x == 0)
                mouse_last = mouse;
            if (renderer->_position.x + mouse.x - mouse_last.x < 675)
                renderer->_position.x = 675;
            else if (renderer->_position.x + mouse.x - mouse_last.x > 1235)
                renderer->_position.x = 1235;
            else
                renderer->_position.x += mouse.x - mouse_last.x;
            mouse_last = GetMousePosition();
        }
    }

    void Slider::usePressed(std::unique_ptr<AScene> &ownScene, std::shared_ptr<Entity> &ownEntity) noexcept
    {
    }

    void Slider::useReleased(std::unique_ptr<AScene> &ownScene, std::shared_ptr<Entity> &ownEntity) noexcept
    {
        std::shared_ptr<Renderable> renderer = std::static_pointer_cast<Renderable, IComponent>(ownEntity->getComponents().find(indie::RENDERABLE)->second);
        if (raylib::REvent::isHover(renderer->_position.x, renderer->_position.y, renderer->_size.y, renderer->_size.x))
        {
        }
    }

    void Slider::useNone(std::unique_ptr<AScene> &ownScene, std::shared_ptr<Entity> &ownEntity) noexcept
    {
        std::shared_ptr<Renderable> renderer = std::static_pointer_cast<Renderable, IComponent>(ownEntity->getComponents().find(indie::RENDERABLE)->second);
        mouse_last = GetMousePosition();
        if (raylib::REvent::isHover(renderer->_position.x, renderer->_position.y, renderer->_size.y, renderer->_size.x))
        {
            renderer->_rect.x = 595 + renderer->_size.x;
        } else {
            renderer->_rect.x = 595;
        }
    }
}
