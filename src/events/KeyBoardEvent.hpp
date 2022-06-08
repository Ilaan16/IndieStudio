/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** Event.hpp
*/

#ifndef KEYBOARD_HPP
    #define KEYBOARD_HPP

    #include "raylib/Event.hpp"
    #include "Entity.hpp"

namespace indie
{
    class KeyBoardEvent {
        public:
            ~KeyBoardEvent() = default;

            virtual void useKey(std::shared_ptr<Entity> &ownEntity) noexcept = 0;
    };

    class TestKey : KeyBoardEvent {
        public:
            TestKey() = default;
            ~TestKey() = default;

            void useKey(std::shared_ptr<Entity> &ownEntity) noexcept final;
    };
}

#endif KEYBOARD_HPP
