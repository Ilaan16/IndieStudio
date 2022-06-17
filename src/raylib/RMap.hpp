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
                RMap();
                ~RMap();

                void draw(Camera3D camera);
                Player collision(Player player, KeyboardKey right, KeyboardKey left, KeyboardKey down, KeyboardKey up);
                Player putBomb(Player player, KeyboardKey action);
                bool checkHit(Vector3 position, float *position1, float *position2, float movement, int *explose);
            protected:
            private:
                Player player1;
                Player player2;

                Color *_mapPixels;
                Texture2D _cubicmap;
                Texture2D _texture;
                Model _model;
                Mesh _mesh;

                Vector3 _mapPos;
        };
    }

#endif /* !RMAP_HPP_ */
