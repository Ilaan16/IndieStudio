/*
** EPITECH PROJECT, 2022
** Indie
** File description:
** RShape
*/

#ifndef RSHAPE_HPP_
    #define RSHAPE_HPP_

    #include <string>
    #include "raylib.h"

    namespace indie {
        class RShape {
            public:
                RShape(const std::string &filename);
                ~RShape();

                void draw(const float &x, const float &y, Camera camera);
                Texture2D _texture;
                Mesh _mesh;
                Model _model;
            private:
        };
    }

#endif /* !RSHAPE_HPP_ */