/*
** EPITECH PROJECT, 2022
** dev
** File description:
** The Sprite3D component is used by graphical libraries with a graphical interface (such as sfml, sdl2...)
** to draw the sprite according to the file given by the '_file' properties.
*/

#ifndef SPRITE3D_HPP_
    #define SPRITE3D_HPP_

    #include <string>

    #include "IComponent.hpp"

    namespace indie {
        class Sprite3D : public IComponent {
            public:
                Sprite3D(const std::string& file = "") : _file(file) {}

                /* TO ENSURE A FUNCTIONNAL USE OF ALL FILE, IMAGE MUST BE IN .bmp FORMAT */
                std::string _file;
            
            /* AN ENTITY MUST HAVE 3D AND TEXT VERSION TO ENSURE THAT ALL LIBRARIES CAN DREW IT */
        };
    }

#endif /* !SPRITE3D_HPP_ */
