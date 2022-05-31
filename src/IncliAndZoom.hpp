/*
** EPITECH PROJECT, 2022
** dev
** File description:
** The IncliAndZoom
*/

#ifndef INCLIANDZOOM_HPP_
    #define INCLIANDZOOM_HPP_

    #include "IComponent.hpp"

    namespace indie {
        class IncliAndZoom : public IComponent {
            public:
                IncliAndZoom(float x = 0, int y = 0) : _x(x), _y(y) {}

                float _x;
                float _y;
        };
    }

#endif /* !INCLIANDZOOM_HPP_ */
