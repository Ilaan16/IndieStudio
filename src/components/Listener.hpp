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
    #include "events/KeyBoardEvent.hpp"
    #include "events/MouseEvent.hpp"

namespace indie {
    class Listener : public IComponent {
        public:
            Listener(std::shared_ptr<Entity> &ownEntity): ownEntity(ownEntity) {}
            ~Listener() = default;

            bool addKeyboard(const KeyboardKey &key, std::unique_ptr<KeyBoardEvent> handler);
            void checkKeyboard(const KeyboardKey &key);
            bool modifyKey(const KeyboardKey &oldKey, const KeyboardKey &newKey);
            bool addMouse(const MouseButton &mouse, std::unique_ptr<MouseEvent> handler);
            void checkMouse(const MouseButton &mouse);
            bool modifyMouse(const MouseButton &oldMouse, const MouseButton &newMouse);

        private:
            std::unordered_map<KeyboardKey, std::unique_ptr<KeyBoardEvent>> keyboardEvents;
            std::unordered_map<MouseButton, std::unique_ptr<MouseEvent>> mouseEvents;
            std::shared_ptr<Entity> ownEntity;
    };
}

#endif /* !LISTENER_HPP_ */
