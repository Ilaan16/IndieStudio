/*
** EPITECH PROJECT, 2022
** Indie
** File description:
** Listener
*/

#include <memory>
#include "Listener.hpp"

namespace indie {
    bool Listener::addKeyboard(const KeyboardKey &key, std::unique_ptr<KeyboardEvent> handler)
    {
        auto ret = keyboardEvents.emplace(key, move(handler));
        return ret.second;
    }

    bool Listener::addMouse(const MouseButton &mouse, std::unique_ptr<MouseEvent> handler)
    {
        auto ret = mouseEvents.emplace(mouse, move(handler));
        return ret.second;
    }

    void Listener::checkKeyboard(const KeyboardKey &key)
    {
        auto event = keyboardEvents.find(key);
        if (event == keyboardEvents.end())
            return;
        event->second->useKey(ownEntity);
    }

    void Listener::checkMouse(const MouseButton &mouse)
    {
        auto event = mouseEvents.find(mouse);
        if (event == mouseEvents.end())
            return;
        event->second->click(ownEntity);
    }

    bool Listener::modifyKey(const KeyboardKey &oldKey, const KeyboardKey &newKey)
    {
        auto place = keyboardEvents.find(oldKey);
        if (place == keyboardEvents.end())
            return false;
        auto ret = keyboardEvents.emplace(newKey, move(place->second));
        if (ret.second == false)
            return false;
        keyboardEvents.erase(place);
    }

    bool Listener::modifyMouse(const MouseButton &oldMouse, const MouseButton &newMouse)
    {
        auto place = mouseEvents.find(oldMouse);
        if (place == mouseEvents.end())
            return false;
        auto ret = mouseEvents.emplace(newMouse, move(place->second));
        if (ret.second == false)
            return false;
        mouseEvents.erase(place);
    }
}
