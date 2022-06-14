/*
** EPITECH PROJECT, 2022
** Indie
** File description:
** RAnim
*/

#ifndef RANIM_HPP_
    #define RANIM_HPP_

    #include <string>
    #include "raylib.h"

    namespace indie {
        class RAnim {
            public:
                RAnim(const std::string &filename);
                ~RAnim();

                void draw(const float &x, const float &y, Model model);
            private:
            ModelAnimation *anims;
            unsigned int animsCount;
            int animFrameCounter;
        };
    }

#endif /* !RANIM_HPP_ */