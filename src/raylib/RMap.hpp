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
                void putBomb(float *x, float *y, float *z, Player *player, Camera3D camera, Texture2D cubicmap, Color *mapPixels, std::vector<Vector3> collision_entity);
                bool checkHit(Vector3 position, float *position1, float *position2, float movement, int *explose, Texture2D cubicmap, Color *mapPix, std::vector<Vector3> collision_entity);
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
