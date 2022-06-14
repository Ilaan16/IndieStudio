/*
** EPITECH PROJECT, 2022
** Indie
** File description:
** RModel
*/

#ifndef RMODEL_HPP_
    #define RMODEL_HPP_

    #include <string>
    #include "raylib.h"

    namespace indie {
        class RModel {
            public:
                RModel(const std::string &filename, const std::string &filename_texture);
                ~RModel();

                void draw(const float &x, const float &y, Camera camera);
            private:
            Model _model;
            Texture2D _texture;
        };
    }

#endif /* !RMODEL_HPP_ */