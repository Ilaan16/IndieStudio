/*
** EPITECH PROJECT, 2022
** IndieStudio
** File description:
** RMap
*/

#ifndef RMAP_HPP_
    #define RMAP_HPP_

    #include <raylib.h>
    #include <vector>
    #include <random>
    #include <raymath.h>
    #include "Player.hpp"

    namespace indie {
        class RMap {
            public:
                RMap(const std::string &image, const std::string &filename_texture);
                ~RMap();
                
                Vector3 _mapPos;
                Color *_mapPixels;
                Texture2D getMap(void);
                void draw(Camera3D camera);
            protected:
            private:
                Player player1;
                Player player2;

                Texture2D _cubicmap;
                Texture2D _texture;
                Model _model;
                Mesh _mesh;
        };
    }

#endif /* !RMAP_HPP_ */
