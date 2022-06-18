/*
** EPITECH PROJECT, 2022
** IndieStudio
** File description:
** ChoosePersoScene
*/

#include "scenes/ChoosePersoScene.hpp"
#include "EntitiesFactory.hpp"
#include "Core.hpp"
#include "components/Listener.hpp"

namespace indie {

    ChoosePersoScene::ChoosePersoScene()
    {
        EntitiesFactory Entities;

        std::vector<std::shared_ptr<Entity>> drawable_ent;
        std::vector<std::shared_ptr<Entity>> clickable_ent;

        std::unique_ptr<MouseEvent> start = std::make_unique<GoScene>(Scenes::GAME, true);
        std::unique_ptr<MouseEvent> back = std::make_unique<GoScene>(Scenes::MENU);

        _entities.emplace(typeEntity::DRAWABLE, drawable_ent);
        _entities.emplace(typeEntity::CLICKABLE, clickable_ent);
        Entities.createSound(_entities, "assets/sound/C418 - Aria Math, but its an EPIC Soundtrack.mp3");
        Entities.createBackground(_entities, "./assets/choosePerso/background.png");
        Entities.createButton(_entities, "P1", {30.0f, 436.0f, 0.0f}, {392.0f, 80.0f, 0.0f}, {1408, 0.0f, 0.0f}, {201.0f, 457.0f, 0.0f});
        Entities.createButton(_entities, "P2", {1498.0f, 436.0f, 0.0f}, {392.0f, 80.0f, 0.0f}, {1408.0f, 0.0f, 0.0f}, {1669.0f, 457.0f, 0.0f});
        Entities.createButton(_entities, "P3", {30.0f, 978.0f, 0.0f}, {392.0f, 80.0f, 0.0f}, {1408.0f, 0.0f, 0.0f}, {201.0f, 999.0f, 0.0f});
        Entities.createButton(_entities, "P4", {1498.0f, 978.0f, 0.0f}, {392.0f, 80.0f, 0.0f}, {1408.0f, 0.0f, 0.0f}, {1669.0f, 999.0f, 0.0f});
        Entities.createButton(_entities, "return", {532.0f, 892.0f, 0.0f}, {392.0f, 80.0f, 0.0f}, {1408.0f, 0.0f, 0.0f}, {626.0f, 913.0f, 0.0f});
        this->addEventToLastEntity(MouseButton::MOUSE_BUTTON_LEFT, back);
        Entities.createButton(_entities, "start", {962.0f, 892.0f, 0.0f}, {392.0f, 80.0f, 0.0f}, {1408.0f, 0.0f, 0.0f}, {1075.0f, 913.0f, 0.0f});
        this->addEventToLastEntity(MouseButton::MOUSE_BUTTON_LEFT, start);
        Entities.createPlayer2D(_entities, "", {561.5f, 112.0f, 0.0f}, {200.0f, 288.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f});

        events = raylib::REvent({}, {std::make_pair(MouseButton::MOUSE_BUTTON_LEFT, ButtonState::None)});
    }

    void ChoosePersoScene::addEventToLastEntity(const MouseButton &mouse, std::unique_ptr<MouseEvent> &evt)
    {
        std::shared_ptr<indie::IComponent> comp = _entities.find(CLICKABLE)->second.back()->getComponents().find(LISTENER)->second;
        std::shared_ptr<indie::Listener> listener = std::static_pointer_cast<Listener, IComponent>(comp);

        listener->addEvent(mouse, evt);
    }

    ChoosePersoScene::~ChoosePersoScene()
    {
    }

    std::map<typeEntity ,std::vector<std::shared_ptr<Entity>>> &ChoosePersoScene::getEntities()
    {
        return (this->_entities);
    }

}