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
        Entities.createLogo(_entities, "Play", {650.0f, 150.0f, 0.0f}, {558.0f, 78.0f, 0.0f}, {0.0f, 0.0f, 0.0f});
        Entities.createButton(_entities, "Play", {550.0f, 450.0f, 0.0f}, {800.0f, 80.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, {850.0f, 490.0f, 0.0f});
        Entities.createButton(_entities, "Settings", {550.0f, 550.0f, 0.0f}, {800.0f, 80.0f, 0.0f}, {70.0f, 0.0f, 0.0f}, {850.0f, 540.0f, 0.0f});
        Entities.createButton(_entities, "Quit", {550.0f, 650.0f, 0.0f}, {800.0f, 80.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, {850.0f, 590.0f, 0.0f});

        events = raylib::REvent({}, {std::make_pair(MouseButton::MOUSE_BUTTON_LEFT, ButtonState::None)});
        std::unique_ptr<Event> test = std::make_unique<TestKey>();
        listener.addEvent(MOUSE_BUTTON_LEFT, move(test));
    }

    std::map<typeEntity, std::vector<std::shared_ptr<Entity>>> &SceneMenu::getEntities()
    {
        return (this->_entities);
    }
}