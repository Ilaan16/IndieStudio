/*
** EPITECH PROJECT, 2022
** Indie
** File description:
** RTexture2D
*/

#ifndef RTEXTURE2D_HPP_
    #define RTEXTURE2D_HPP_

    #include <string>
    #include "raylib.h"

namespace indie {

    class RTexture2D {
        public:
            RTexture2D(const std::string &filename);
            ~RTexture2D();

            void draw(const float &x, const float &y, Rectangle source);
        private:
            Texture2D _texture;
    };
}

#endif /* !RTEXTURE2D_HPP_ */
