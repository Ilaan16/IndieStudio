/*
** EPITECH PROJECT, 2022
** Indie
** File description:
** RModel
*/

#ifndef RTEXTURE2D_HPP_
    #define RTEXTURE2D_HPP_

    #include <string>
    #include "raylib.h"

    namespace indie {
        class RModel {
            public:
                RModel(const std::string &filename);
                ~RModel();

                void draw(const float &x, const float &y);
            private:
            Model model;
        };
    }

#endif /* !RTEXTURE2D_HPP_ */