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
    SceneOption::SceneOption(raylib::Window &window)
    {
        EntitiesFactory Entities;

        std::vector<std::shared_ptr<Entity>> drawable_ent;
        std::vector<std::shared_ptr<Entity>> clicable_ent;

        std::shared_ptr<MouseEvent> back = std::make_shared<GoScene>(Scenes::MENU, true);
        std::shared_ptr<MouseEvent> full = std::make_shared<FullScreen>(window);
        std::shared_ptr<MouseEvent> slider = std::make_shared<Slider>(window);

        _entities.emplace(typeEntity::DRAWABLE, drawable_ent);
        _entities.emplace(typeEntity::CLICKABLE, clicable_ent);
        Entities.createSound(_entities, "assets/sound/C418 - Minecraft - Minecraft Volume Alpha.mp3");
        Entities.createBackground(_entities, "./assets/options/dirt_background.png");
        Entities.createLogo(_entities, "./assets/options/settings.png", "Play", {750.0f, 150.0f, 0.0f}, {427.0f, 79.0f, 0.0f}, {0.0f, 0.0f, 0.0f});
        Entities.createSlider(_entities, "Sound", {660.0f, 400.0f, 0.0f}, {595.0f, 80.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, {863.0f, 420.0f, 0.0f});
        Entities.createLogo(_entities, "./assets/options/slider.png", "Play", {1235.0f, 400.0f, 0.0f}, {29.0f, 80.0f, 0.0f}, {595.0f, 0.0f, 0.0f});
        this->addEventToLastEntity(MouseButton::MOUSE_BUTTON_LEFT, slider);
        Entities.createButton(_entities, "FULLSCREEN: OFF", {660.0f, 520.0f, 0.0f}, {600.0f, 80.0f, 0.0f}, {804.0f, 0.0f, 0.0f}, {730.0f, 540.0f, 0.0f});
        this->addEventToLastEntity(MouseButton::MOUSE_BUTTON_LEFT, full);
        Entities.createButton(_entities, "return", {660.0f, 640.0f, 0.0f}, {600.0f, 80.0f, 0.0f}, {804.0f, 0.0f, 0.0f}, {867.0f, 660.0f, 0.0f});
        this->addEventToLastEntity(MouseButton::MOUSE_BUTTON_LEFT, back);
        events = raylib::REvent({}, {std::make_pair(MouseButton::MOUSE_BUTTON_LEFT, ButtonState::None)});
    }

    void SceneOption::addEventToLastEntity(const MouseButton &mouse, std::shared_ptr<MouseEvent> &evt)
    {
        std::shared_ptr<indie::IComponent> comp = _entities.find(CLICKABLE)->second.back()->getComponents().find(LISTENER)->second;
        std::shared_ptr<indie::Listener> listener = std::static_pointer_cast<Listener, IComponent>(comp);

        listener->addEvent(mouse, evt);
    }

    std::map<typeEntity ,std::vector<std::shared_ptr<indie::Entity>>> &SceneOption::getEntities()
    {
        return (this->_entities);
    }

    void indie::SceneOption::update(int *sceneId, std::map<indie::typeEntity, std::vector<std::shared_ptr<indie::Entity>>> &entity)
    {
    }
}