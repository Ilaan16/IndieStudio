/*
** EPITECH PROJECT, 2022
** Indie
** File description:
** Listener
*/

#include "Listener.hpp"

namespace indie {
    bool Listener::addEvent(const KeyboardKey &key, std::shared_ptr<Event> &handler)
    {
        auto ret = keyboardEvents.emplace(key, handler);
        return ret.second;
    }

    bool Listener::addEvent(const MouseButton &mouse, std::shared_ptr<MouseEvent> &handler)
    {
        auto ret = mouseEvents.emplace(mouse, handler);
        return ret.second;
    }

    void Listener::checkEvent(const KeyboardKey &key, const ButtonState &state, std::unique_ptr<AScene> &ownScene)
    {
        auto event = keyboardEvents.find(key);
        if (event == keyboardEvents.end())
            return;
        switch(state) {
            case ButtonState::Down:
                event->second->useDown(ownScene, ownEntity);
                break;
            case ButtonState::Pressed:
                event->second->usePressed(ownScene, ownEntity);
                break;
            case ButtonState::Released:
                event->second->useReleased(ownScene, ownEntity);
                break;
        }
    }

    void Listener::checkEvent(const MouseButton &mouse, const ButtonState &state, std::unique_ptr<AScene> &ownScene)
    {
        auto event = mouseEvents.find(mouse);
        if (event == mouseEvents.end())
            return;
        switch(state) {
            case ButtonState::Down:
                event->second->useDown(ownScene, ownEntity);
                break;
            case ButtonState::Pressed:
                event->second->usePressed(ownScene, ownEntity);
                break;
            case ButtonState::Released:
                event->second->useReleased(ownScene, ownEntity);
                break;
            case ButtonState::None:
                event->second->useNone(ownScene, ownEntity);
                break;
        }
    }

    bool Listener::modifyEvent(const KeyboardKey &oldKey, const KeyboardKey &newKey)
    {
        auto place = keyboardEvents.find(oldKey);
        if (place == keyboardEvents.end())
            return false;
        auto ret = keyboardEvents.emplace(newKey, move(place->second));
        if (ret.second == false)
            return false;
        keyboardEvents.erase(place);
        return true;
    }

    bool Listener::modifyEvent(const MouseButton &oldMouse, const MouseButton &newMouse)
    {
        auto place = mouseEvents.find(oldMouse);
        if (place == mouseEvents.end())
            return false;
        auto ret = mouseEvents.emplace(newMouse, move(place->second));
        if (ret.second == false)
            return false;
        mouseEvents.erase(place);
        return true;
    }
}
