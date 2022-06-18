/*
** EPITECH PROJECT, 2022
** Indie
** File description:
** FullScreen
*/

#include "Event.hpp"

namespace indie
{
    void FullScreen::useDown(std::unique_ptr<AScene> &ownScene, std::shared_ptr<Entity> &ownEntity) noexcept
    {
        std::shared_ptr<Renderable> renderer = std::static_pointer_cast<Renderable, IComponent>(ownEntity->getComponents().find(indie::RENDERABLE)->second);
        if (raylib::REvent::isHover(renderer->_position.x, renderer->_position.y, renderer->_size.y, renderer->_size.x))
            renderer->_rect.y = renderer->_size.y * 2;
        else
            renderer->_rect.y = 0;
    }

    void FullScreen::usePressed(std::unique_ptr<AScene> &ownScene, std::shared_ptr<Entity> &ownEntity) noexcept
    {
    }

    void FullScreen::useReleased(std::unique_ptr<AScene> &ownScene, std::shared_ptr<Entity> &ownEntity) noexcept
    {
        std::shared_ptr<Renderable> renderer = std::static_pointer_cast<Renderable, IComponent>(ownEntity->getComponents().find(indie::RENDERABLE)->second);
        if (raylib::REvent::isHover(renderer->_position.x, renderer->_position.y, renderer->_size.y, renderer->_size.x))
        {
            window.toggleFull();
            if (window.isFullScreen())
                renderer->_strString = "FULLSCREEN ON";
            else
                renderer->_strString = "FULLSCREEN OFF";
        }
    }

    void FullScreen::useNone(std::unique_ptr<AScene> &ownScene, std::shared_ptr<Entity> &ownEntity) noexcept
    {
        std::shared_ptr<Renderable> renderer = std::static_pointer_cast<Renderable, IComponent>(ownEntity->getComponents().find(indie::RENDERABLE)->second);
        if (raylib::REvent::isHover(renderer->_position.x, renderer->_position.y, renderer->_size.y, renderer->_size.x))
            renderer->_rect.y = renderer->_size.y;
        else
            renderer->_rect.y = 0;
    }
}