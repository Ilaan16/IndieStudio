/*
** EPITECH PROJECT, 2022
** Indie
** File description:
** SceneOption
*/

#include "EntitiesFactory.hpp"
#include "SceneOption.hpp"
#include "events/Event.hpp"
#include "components/Listener.hpp"

namespace indie {
    SceneOption::SceneOption()
    {
        EntitiesFactory Entities;

        std::vector<std::shared_ptr<Entity>> drawable_ent;
        std::vector<std::shared_ptr<Entity>> clicable_ent;

        std::unique_ptr<MouseEvent> back = std::make_unique<GoScene>(Scenes::MENU);

        _entities.emplace(typeEntity::DRAWABLE, drawable_ent);
        _entities.emplace(typeEntity::CLICKABLE, clicable_ent);
        Entities.createBackground(_entities, "./assets/options/dirt_background.png");
        Entities.createLogo(_entities, "./assets/options/settings.png", "Play", {750.0f, 150.0f, 0.0f}, {427.0f, 79.0f, 0.0f}, {0.0f, 0.0f, 0.0f});
        Entities.createSlider(_entities, "SOUND", {750.0f, 450.0f, 0.0f}, {300.0f, 40.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, {750.0f, 400.0f, 0.0f});
        Entities.createLogo(_entities, "./assets/options/slider.png", "Play", {750.0f, 450.0f, 0.0f}, {15.0f, 40.0f, 0.0f}, {300.0f, 0.0f, 0.0f});
        Entities.createButton(_entities, "FULLSCREEN", {550.0f, 650.0f, 0.0f}, {800.0f, 80.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, {790.0f, 670.0f, 0.0f});
        Entities.createButton(_entities, "BACK", {550.0f, 750.0f, 0.0f}, {800.0f, 80.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, {880.0f, 770.0f, 0.0f});
        this->addEventToLastEntity(MouseButton::MOUSE_BUTTON_LEFT, back);
        events = raylib::REvent({}, {std::make_pair(MouseButton::MOUSE_BUTTON_LEFT, ButtonState::None)});
    }

    void SceneOption::addEventToLastEntity(const MouseButton &mouse, std::unique_ptr<MouseEvent> &evt)
    {
        std::shared_ptr<indie::IComponent> comp = _entities.find(CLICKABLE)->second.back()->getComponents().find(LISTENER)->second;
        std::shared_ptr<indie::Listener> listener = std::static_pointer_cast<Listener, IComponent>(comp);

        listener->addEvent(mouse, evt);
    }

    std::map<typeEntity ,std::vector<std::shared_ptr<indie::Entity>>> &SceneOption::getEntities()
    {
        return (this->_entities);
    }
}