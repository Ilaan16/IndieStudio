/*
** EPITECH PROJECT, 2022
** Indie
** File description:
** SceneSplash
*/

#include "EntitiesFactory.hpp"
#include "SceneSplash.hpp"
#include "events/Event.hpp"
#include "components/Listener.hpp"

namespace indie {
    SceneSplash::SceneSplash()
    {
        EntitiesFactory Entities;

        std::vector<std::shared_ptr<Entity>> drawable_ent;
        std::vector<std::shared_ptr<Entity>> clicable_ent;

        std::unique_ptr<MouseEvent> back = std::make_unique<GoScene>(Scenes::MENU);

        _entities.emplace(typeEntity::DRAWABLE, drawable_ent);
        _entities.emplace(typeEntity::CLICKABLE, clicable_ent);
        Entities.createBackground(_entities, "./assets/splash/bg.png");
        Entities.createLogo(_entities, "./assets/splash/logo.png", "Play", {700.0f, 250.0f, 0.0f}, {500.0f, 500.0f, 0.0f}, {0.0f, 0.0f, 0.0f});
    }

    void SceneSplash::addEventToLastEntity(const MouseButton &mouse, std::unique_ptr<MouseEvent> &evt)
    {
        std::shared_ptr<indie::IComponent> comp = _entities.find(CLICKABLE)->second.back()->getComponents().find(LISTENER)->second;
        std::shared_ptr<indie::Listener> listener = std::static_pointer_cast<Listener, IComponent>(comp);

        listener->addEvent(mouse, evt);
    }

    std::map<typeEntity ,std::vector<std::shared_ptr<indie::Entity>>> &SceneSplash::getEntities()
    {
        return (this->_entities);
    }
    
    void indie::SceneSplash::update(std::map<indie::typeEntity, std::vector<std::shared_ptr<indie::Entity>>> &entity)
    {
    }
}