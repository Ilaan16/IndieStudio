/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** Event.hpp
*/

#ifndef KEYBOARD_HPP_
    #define KEYBOARD_HPP_

    #include "raylib/Event.hpp"
    #include "Entity.hpp"

namespace indie {
    class Entity;

    class KeyboardEvent {
        public:
            ~KeyboardEvent() = default;

            virtual void useKey(std::shared_ptr<Entity> &ownEntity) noexcept = 0;
    };

    class TestKey : KeyboardEvent {
        public:
            TestKey() = default;
            ~TestKey() = default;

            void useKey(std::shared_ptr<Entity> &ownEntity) noexcept final;
    };
}

#endif