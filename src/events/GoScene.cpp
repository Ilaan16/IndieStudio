/*
** EPITECH PROJECT, 2022
** Indie
** File description:
** GoScene
*/

#include <iostream>
#include <utility>
#include <algorithm>
#include "Event.hpp"
#include "raylib/REvent.hpp"
#include "Game.hpp"

namespace indie {
    void GoScene::useDown(std::unique_ptr<AScene> &ownScene, std::shared_ptr<Entity> &ownEntity) noexcept
    {
        std::shared_ptr<Renderable> renderer = std::static_pointer_cast<Renderable, IComponent>(ownEntity->getComponents().find(indie::RENDERABLE)->second);
        if (raylib::REvent::isHover(renderer->_position.x, renderer->_position.y, renderer->_size.y, renderer->_size.x))
            renderer->_rect.y = renderer->_size.y * 2;
        else
            renderer->_rect.y = 0;
    }

    void GoScene::usePressed(std::unique_ptr<AScene> &ownScene, std::shared_ptr<Entity> &ownEntity) noexcept
    {
    }

    void GoScene::useReleased(std::unique_ptr<AScene> &ownScene, std::shared_ptr<Entity> &ownEntity) noexcept
    {
        auto isMusic = [](std::shared_ptr<Entity> current) {
            auto comps = current->getComponents();
            auto it = comps.find(MUSIC);
            return it != comps.end();
        };
        std::shared_ptr<Renderable> renderer = std::static_pointer_cast<Renderable, IComponent>(ownEntity->getComponents().find(indie::RENDERABLE)->second);

        if (raylib::REvent::isHover(renderer->_position.x, renderer->_position.y, renderer->_size.y, renderer->_size.x)) {
            std::vector<std::shared_ptr<Entity>> entities = ownScene->getEntities().find(DRAWABLE)->second;
            auto entityIt = find_if(entities.begin(), entities.end(), isMusic).base();
            std::shared_ptr<Renderable> music = std::static_pointer_cast<Renderable, IComponent>((*entityIt)->getComponents().find(MUSIC)->second);

            if (keepTime)
                music->_music.markTime();

            music->_music.resetMusic();
            Game::setScene(static_cast<int>(scene));
        }
    }

    void GoScene::useNone(std::unique_ptr<AScene> &ownScene, std::shared_ptr<Entity> &ownEntity) noexcept
    {
        std::shared_ptr<Renderable> renderer = std::static_pointer_cast<Renderable, IComponent>(ownEntity->getComponents().find(indie::RENDERABLE)->second);
        if (raylib::REvent::isHover(renderer->_position.x, renderer->_position.y, renderer->_size.y, renderer->_size.x))
            renderer->_rect.y = renderer->_size.y;
        else
            renderer->_rect.y = 0;
    }
}
