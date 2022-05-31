/*
** EPITECH PROJECT, 2022
** dev
** File description:
** The IAAlgorithmes component is used by graphical libraries with a graphical interface (such as sfml, sdl2...)
** to draw the sprite according to the file given by the '_file' properties.
*/

#ifndef IAALGORITHMES_HPP_
    #define IAALGORITHMES_HPP_

    #include <string>

    #include "IComponent.hpp"

    namespace indie {
        class IAAlgorithmes : public IComponent {
            public:
                IAAlgorithmes() {}

                /* TO ENSURE A FUNCTIONNAL USE OF ALL FILE, IMAGE MUST BE IN .bmp FORMAT */
            
            /* AN ENTITY MUST HAVE 3D AND TEXT VERSION TO ENSURE THAT ALL LIBRARIES CAN DREW IT */
        };
    }

#endif /* !IAALGORITHMES_HPP_ */