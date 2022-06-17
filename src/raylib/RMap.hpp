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
                bool checkHit(float *position1, float *position2, float movement);
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

                float _life;


                bool _explosion;
                bool _isbomb;
                Vector3 _positionBomb;

                Vector3 _bomb_up;
                Vector3 _bomb_down;
                Vector3 _bomb_right;
                Vector3 _bomb_left;
        };
    }

#endif /* !RMAP_HPP_ */
