/*
** EPITECH PROJECT, 2022
** Indie
** File description:
** GoScene
*/

#include <iostream>
#include <utility>
#include "Event.hpp"
#include "raylib/REvent.hpp"
#include "Game.hpp"

namespace indie {
    void GoScene::useDown(std::unique_ptr<AScene> &ownScene, std::shared_ptr<Entity> &ownEntity) noexcept
    {
        std::shared_ptr<Renderable> renderer = std::static_pointer_cast<Renderable, IComponent>(ownEntity->getComponents().find(indie::RENDERABLE)->second);
        if (raylib::REvent::isHover(renderer->_position.x, renderer->_position.y, renderer->_size.y, renderer->_size.x))
            std::cout << "Test Down" << std::endl;
    }

    void GoScene::usePressed(std::unique_ptr<AScene> &ownScene, std::shared_ptr<Entity> &ownEntity) noexcept
    {
    }

    void GoScene::useReleased(std::unique_ptr<AScene> &ownScene, std::shared_ptr<Entity> &ownEntity) noexcept
    {
        std::shared_ptr<Renderable> renderer = std::static_pointer_cast<Renderable, IComponent>(ownEntity->getComponents().find(indie::RENDERABLE)->second);
        if (raylib::REvent::isHover(renderer->_position.x, renderer->_position.y, renderer->_size.y, renderer->_size.x)) {
            Game::setScene(static_cast<int>(scene));
            std::cout << "ID: " << static_cast<int>(scene) << std::endl;
        }
    }

    void GoScene::useNone(std::unique_ptr<AScene> &ownScene, std::shared_ptr<Entity> &ownEntity) noexcept
    {
        std::shared_ptr<Renderable> renderer = std::static_pointer_cast<Renderable, IComponent>(ownEntity->getComponents().find(indie::RENDERABLE)->second);
        if (raylib::REvent::isHover(renderer->_position.x, renderer->_position.y, renderer->_size.y, renderer->_size.x))
            std::cout << "Test Hover" << std::endl;
    }
}
