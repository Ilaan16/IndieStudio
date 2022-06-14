/*
** EPITECH PROJECT, 2022
** Indie
** File description:
** Listener
*/

#ifndef LISTENER_HPP_
    #define LISTENER_HPP_

    #include <unordered_map>
    #include "events/Event.hpp"

namespace indie {
    class Listener : public IComponent {
        public:
            Listener(std::shared_ptr<Entity> &ent): ownEntity(ent) {}
            ~Listener() = default;

            bool addEvent(const KeyboardKey &key, std::unique_ptr<Event> &handler);
            bool addEvent(const MouseButton &mouse, std::unique_ptr<MouseEvent> &handler);

            void checkEvent(const KeyboardKey &key, const ButtonState &state, std::unique_ptr<AScene> &ownScene);
            void checkEvent(const MouseButton &mouse, const ButtonState &state, std::unique_ptr<AScene> &ownScene);

            bool modifyEvent(const KeyboardKey &oldKey, const KeyboardKey &newKey);
            bool modifyEvent(const MouseButton &oldMouse, const MouseButton &newMouse);

        private:
            std::unordered_map<KeyboardKey, std::unique_ptr<indie::Event>> keyboardEvents;
            std::unordered_map<MouseButton, std::unique_ptr<indie::MouseEvent>> mouseEvents;
            std::shared_ptr<Entity> ownEntity;
    };
}

#endif /* !LISTENER_HPP_ */
