/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** Event.hpp
*/

#ifndef KEYBOARD_HPP
    #define KEYBOARD_HPP

    #include "raylib/Event.hpp"

namespace indie
{
    class KeyBoardEvent {
    public:
        ~KeyBoardEvent() = default;

        virtual void useKey() noexcept = 0;
    };
}

#endif KEYBOARD_HPP
