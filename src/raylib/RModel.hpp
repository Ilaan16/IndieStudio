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
                RModel(const std::string &filename);
                ~RModel();

                void draw(const float &x, const float &y, Texture2D texture);
            private:
            Model model;
        };
    }

#endif /* !RMODEL_HPP_ */