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
#include "components/Listener.hpp"

namespace indie {
    SceneMenu::SceneMenu()
    {
        EntitiesFactory Entities;

        std::vector<std::shared_ptr<Entity>> drawable_ent;
        std::vector<std::shared_ptr<Entity>> clicable_ent;

        std::unique_ptr<MouseEvent> play = std::make_unique<GoScene>(Scenes::PERSO);
        std::unique_ptr<MouseEvent> settings = std::make_unique<GoScene>(Scenes::OPTION, true);
        std::unique_ptr<MouseEvent> quit = std::make_unique<GoScene>(Scenes::QUIT);

        _entities.emplace(typeEntity::DRAWABLE, drawable_ent);
        _entities.emplace(typeEntity::CLICKABLE, clicable_ent);
        Entities.createSound(_entities, "assets/sound/C418 - Minecraft - Minecraft Volume Alpha.mp3");
        Entities.createBackground(_entities, "./assets/menu/background.png");
        Entities.createLogo(_entities, "./assets/menu/title.png", "Play", {620.0f, 150.0f, 0.0f}, {693.0f, 97.0f, 0.0f}, {0.0f, 0.0f, 0.0f});
        Entities.createButton(_entities, "Play", {550.0f, 450.0f, 0.0f}, {800.0f, 80.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, {890.0f, 470.0f, 0.0f});
        this->addEventToLastEntity(MouseButton::MOUSE_BUTTON_LEFT, play);
        Entities.createButton(_entities, "Settings", {550.0f, 550.0f, 0.0f}, {800.0f, 80.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, {830.0f, 570.0f, 0.0f});
        this->addEventToLastEntity(MouseButton::MOUSE_BUTTON_LEFT, settings);
        Entities.createButton(_entities, "Quit", {550.0f, 650.0f, 0.0f}, {800.0f, 80.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, {890.0f, 670.0f, 0.0f});
        this->addEventToLastEntity(MouseButton::MOUSE_BUTTON_LEFT, quit);

        events = raylib::REvent({}, {std::make_pair(MouseButton::MOUSE_BUTTON_LEFT, ButtonState::None)});
    }

    void SceneMenu::addEventToLastEntity(const MouseButton &mouse, std::unique_ptr<MouseEvent> &evt)
    {
        std::shared_ptr<indie::IComponent> comp = _entities.find(CLICKABLE)->second.back()->getComponents().find(LISTENER)->second;
        std::shared_ptr<indie::Listener> listener = std::static_pointer_cast<Listener, IComponent>(comp);

        listener->addEvent(mouse, evt);
    }

    std::map<typeEntity, std::vector<std::shared_ptr<Entity>>> &SceneMenu::getEntities()
    {
        return (this->_entities);
    }
}