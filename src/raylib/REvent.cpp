/*
** EPITECH PROJECT, 2022
** Indie
** File description:
** Event
*/

#include <algorithm>
#include <utility>
#include "REvent.hpp"

namespace indie {
    namespace raylib {
        REvent::REvent(const std::vector<std::pair<KeyboardKey, ButtonState>> &keyEvents,
            const std::vector<std::pair<MouseButton, ButtonState>> &mEvents): keyboardEvents(keyEvents), mouseEvents(mEvents)
        {
            SetExitKey(KeyboardKey::KEY_ESCAPE);
        }

        ButtonState REvent::checkState(const KeyboardKey &key)
        {
            if (IsKeyDown(key))
                return ButtonState::Down;
            if (IsKeyPressed(key))
                return ButtonState::Pressed;
            if (IsKeyReleased(key))
                return ButtonState::Released;
            return ButtonState::None;
        }

        ButtonState REvent::checkState(const MouseButton &mouse)
        {
            if (IsMouseButtonDown(mouse))
                return ButtonState::Down;
            if (IsMouseButtonPressed(mouse))
                return ButtonState::Pressed;
            if (IsMouseButtonReleased(mouse))
                return ButtonState::Released;
            return ButtonState::None;
        }

        bool REvent::isHover(const float &x, const float &y, const float &height, const float &width)
        {
            Vector2 mouse = GetMousePosition();
            Rectangle bounds = {x, y, width, height};

            if (CheckCollisionPointRec(mouse, bounds))
                return true;
            return false;
        }

        const std::vector<std::pair<KeyboardKey, ButtonState>> &REvent::getKeyboard() const
        {
            return keyboardEvents;
        }

        const std::vector<std::pair<MouseButton, ButtonState>> &REvent::getMouse() const
        {
            return mouseEvents;
        }

        void REvent::setEvent(const KeyboardKey &oldKey, const KeyboardKey &newKey)
        {
            std::replace_if(keyboardEvents.begin(), keyboardEvents.end(), [&](const std::pair<KeyboardKey, ButtonState> &event) {
                return event.first == oldKey;
            }, std::make_pair(newKey, ButtonState::None));
        }

        void REvent::setEvent(const MouseButton &oldMouse, const MouseButton &newMouse)
        {
            std::replace_if(mouseEvents.begin(), mouseEvents.end(), [&](const std::pair<MouseButton, ButtonState> &event) {
                return event.first == oldMouse;
            }, std::make_pair(newMouse, ButtonState::None));
        }

        void REvent::updateEvents()
        {
            for (auto it = keyboardEvents.begin(); it != keyboardEvents.end(); it++) {
                it->second = checkState(it->first);
            }
            for (auto it = mouseEvents.begin(); it != mouseEvents.end(); it++) {
                it->second = checkState(it->first);
            }
        }
    }
}
