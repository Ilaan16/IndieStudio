/*
** EPITECH PROJECT, 2022
** Indie
** File description:
** Event
*/

#ifndef REVENT_HPP_
    #define REVENT_HPP_

    #include <vector>
    #include <utility>
    #include "raylib.h"

namespace indie {
    enum class ButtonState
    {
        None = -1,
        Pressed = 0,
        Down,
        Released
    };

    namespace raylib {
        class REvent {
            public:
                REvent(const std::vector<std::pair<KeyboardKey, ButtonState>> &keyEvents = {},
                    const std::vector<std::pair<MouseButton, ButtonState>> &mEvents = {});
                ~REvent() = default;

                static ButtonState checkState(const KeyboardKey &key);
                static ButtonState checkState(const MouseButton &mouse);

                static bool isHover(const float &x, const float &y, const float &height, const float &width);

                static Vector2 getMousePosition();

                const std::vector<std::pair<KeyboardKey, ButtonState>> &getKeyboard() const;
                const std::vector<std::pair<MouseButton, ButtonState>> &getMouse() const;

                void setEvent(const KeyboardKey &oldKey, const KeyboardKey &newKey);
                void setEvent(const MouseButton &oldMouse, const MouseButton &newMouse);

                void updateEvents();

            private:
                std::vector<std::pair<KeyboardKey, ButtonState>> keyboardEvents;
                std::vector<std::pair<MouseButton, ButtonState>> mouseEvents;
        };
    }
}

#endif /* !EVENT_HPP_ */
