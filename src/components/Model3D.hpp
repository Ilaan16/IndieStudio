/*
** EPITECH PROJECT, 2022
** dev
** File description:
** The Model3D component is used by graphical libraries with a graphical interface (such as sfml, sdl2...)
** to draw the sprite according to the file given by the '_file' properties.
*/

#ifndef MODEL3D_HPP_
    #define MODEL3D_HPP_

    #include <string>

    #include "IComponent.hpp"

    namespace indie {
        class Model3D : public IComponent {
            public:
                Model3D(const std::string& file = "") : _file(file) {}

                /* TO ENSURE A FUNCTIONNAL USE OF ALL FILE, IMAGE MUST BE IN .bmp FORMAT */
                std::string _file;
            
            /* AN ENTITY MUST HAVE 3D AND TEXT VERSION TO ENSURE THAT ALL LIBRARIES CAN DREW IT */
        };
    }

#endif /* !MODEL3D_HPP_ */
