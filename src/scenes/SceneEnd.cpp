/*
** EPITECH PROJECT, 2022
** IndieStudio
** File description:
** SceneEnd
*/

#include "scenes/SceneEnd.hpp"
#include "EntitiesFactory.hpp"
#include "Core.hpp"
#include "components/Listener.hpp"


namespace indie {

    SceneEnd::SceneEnd()
    {
        EntitiesFactory Entities;

        std::vector<std::shared_ptr<Entity>> drawable_ent;
        std::vector<std::shared_ptr<Entity>> clickable_ent;

        std::shared_ptr<MouseEvent> restart = std::make_shared<GoScene>(Scenes::PERSO);
        std::shared_ptr<MouseEvent> exit = std::make_shared<GoScene>(Scenes::MENU);

        _entities.emplace(typeEntity::DRAWABLE, drawable_ent);
        _entities.emplace(typeEntity::CLICKABLE, clickable_ent);
        Entities.createSound(_entities, "assets/sound/C418 - Sweden - Minecraft Volume Alpha.mp3");
        Entities.createBackground(_entities, "./assets/end/background.png");
        Entities.createButton(_entities, "restart", {555.0f, 842.5f, 0.0f}, {392.0f, 80.0f, 0.0f}, {1408, 0.0f, 0.0f}, {632.0f, 863.0f, 0.0f});
        this->addEventToLastEntity(MouseButton::MOUSE_BUTTON_LEFT, restart);
        Entities.createButton(_entities, "exit", {991.0f, 842.5f, 0.0f}, {392.0f, 80.0f, 0.0f}, {1408, 0.0f, 0.0f}, {1125.0f, 863.0f, 0.0f});
        this->addEventToLastEntity(MouseButton::MOUSE_BUTTON_LEFT, exit);

        events = raylib::REvent({}, {std::make_pair(MouseButton::MOUSE_BUTTON_LEFT, ButtonState::None)});
    }

    void SceneEnd::addEventToLastEntity(const MouseButton &mouse, std::shared_ptr<MouseEvent> &evt)
    {
        std::shared_ptr<indie::IComponent> comp = _entities.find(CLICKABLE)->second.back()->getComponents().find(LISTENER)->second;
        std::shared_ptr<indie::Listener> listener = std::static_pointer_cast<Listener, IComponent>(comp);

        listener->addEvent(mouse, evt);
    }

    SceneEnd::~SceneEnd()
    {
    }

    std::map<typeEntity ,std::vector<std::shared_ptr<Entity>>> &SceneEnd::getEntities()
    {
        return (this->_entities);
    }
}