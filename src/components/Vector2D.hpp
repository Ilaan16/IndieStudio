/*
** EPITECH PROJECT, 2022
** dev
** File description:
** The Vector3D component give the position of the displayed component (Sprite2D/SpriteText/HUDText).
** The component contain '_x' and '_y' properties for the x and y position of the sprite in the window/terminal
** and a property '_z' for the layer position in the window.
*/

#ifndef VECTOR2D_HPP_
    #define VECTOR2D_HPP_

    #include "IComponent.hpp"

    namespace indie {
        class Vector2D : public IComponent {
            public:
                Vector2D(float x = 0, float y = 0) : _x(x), _y(y) {}

                float _x;
                float _y;

            /* x and y position in the architecture works as followed:
            - Each entities will be considered as a one-by-one square.
            - The entities position will consider that the scene is composed of cell of one-by-one so the positions will be like 0,0 or 0,1 or 1,0...
            - If an entity need to be displayed between two cells, you can use float value. For example, an entity who need to be displayed between the 0,0 cell and 0,1 could have the position x=0 and y=0.5
            This system is usefull for an easier handle of graphical library with non graphical interface such as ncurses
            */
        };
    }

#endif /* !VECTOR2D_HPP_ */