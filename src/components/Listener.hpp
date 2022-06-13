/*
** EPITECH PROJECT, 2022
** Indie
** File description:
** Listener
*/

#ifndef LISTENER_HPP_
    #define LISTENER_HPP_

    #include <unordered_map>
    #include "IComponent.hpp"
    #include "events/KeyboardEvent.hpp"
    #include "events/MouseEvent.hpp"
    #include "Entity.hpp"

namespace indie {
    class Entity;
    class KeyboardEvent;
    class MouseEvent;

    class Listener : public IComponent {
        public:
            Listener(std::shared_ptr<Entity> &ownEntity): ownEntity(ownEntity) {}
            ~Listener() = default;

            bool addKeyboard(const KeyboardKey &key, std::unique_ptr<KeyboardEvent> handler);
            void checkKeyboard(const KeyboardKey &key);
            bool modifyKey(const KeyboardKey &oldKey, const KeyboardKey &newKey);
            bool addMouse(const MouseButton &mouse, std::unique_ptr<MouseEvent> handler);
            void checkMouse(const MouseButton &mouse);
            bool modifyMouse(const MouseButton &oldMouse, const MouseButton &newMouse);

        private:
            std::unordered_map<KeyboardKey, std::unique_ptr<KeyboardEvent>> keyboardEvents;
            std::unordered_map<MouseButton, std::unique_ptr<MouseEvent>> mouseEvents;
            std::shared_ptr<Entity> ownEntity;
    };
}

#endif /* !LISTENER_HPP_ */
