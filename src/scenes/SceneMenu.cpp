/*
** EPITECH PROJECT, 2022
** indie
** File description:
** scenemenu
*/

#include "SceneMenu.hpp"
#include "Core.hpp"
#include <chrono>
#include "Raylib.hpp"
#include "EntitiesFactory.hpp"
#include "events/Event.hpp"

namespace indie {
    SceneMenu::SceneMenu()
    {
        EntitiesFactory Entities;

        std::vector<std::shared_ptr<Entity>> drawable_ent;
        std::vector<std::shared_ptr<Entity>> clicable_ent;

        _entities.emplace(typeEntity::DRAWABLE, drawable_ent);
        _entities.emplace(typeEntity::CLICKABLE, clicable_ent);
        Entities.createBackground(_entities, "./assets/menu/background.png");
        Entities.createLogo(_entities, "Play", {700.0f, 150.0f, 0.0f}, {558.0f, 78.0f, 0.0f}, {0.0f, 0.0f, 0.0f});
        Entities.createButton(_entities, "Play", {800.0f, 450.0f, 0.0f}, {400.0f, 40.0f, 0.0f}, {0.0f, 0.0f, 0.0f});
        Entities.createButton(_entities, "Settings", {800.0f, 500.0f, 0.0f}, {400.0f, 40.0f, 0.0f}, {0.0f, 0.0f, 0.0f});
        Entities.createButton(_entities, "Quit", {800.0f, 550.0f, 0.0f}, {400.0f, 40.0f, 0.0f}, {0.0f, 0.0f, 0.0f});
    }

        events = raylib::REvent({}, {std::make_pair(MouseButton::MOUSE_BUTTON_LEFT, ButtonState::None)});
        std::unique_ptr<Event> test = std::make_unique<TestKey>();
        listener.addEvent(MOUSE_BUTTON_LEFT, move(test));
    }

    std::map<typeEntity, std::vector<std::shared_ptr<Entity>>> &SceneMenu::getEntities()
    {
        return (this->_entities);
    }
}