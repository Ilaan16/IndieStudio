/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** MouseEvent.hpp
*/

#pragma once

namespace indie {
    class MouseEvent
    {
    public:
        ~MouseEvent() = default;

        virtual void click() noexcept = 0;
    protected:

        double _x;
        double _y;
    };
}