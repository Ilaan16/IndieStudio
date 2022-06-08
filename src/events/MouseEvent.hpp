/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** MouseEvent.hpp
*/

#pragma once

#include "Entity.hpp"

namespace indie {
    class MouseEvent
    {
    public:
        ~MouseEvent() = default;

        virtual void click(std::shared_ptr<Entity> &ownEntity) noexcept = 0;

    protected:
        double _x;
        double _y;
    };

    class TestMouse : MouseEvent {
        public:
            TestMouse() = default;
            ~TestMouse() = default;

            void click(std::shared_ptr<Entity> &ownEntity) noexcept final;
    };
}