
/*
** EPITECH PROJECT, 2022
** Indie
** File description:
** RAnim
*/

#ifndef RANIM_HPP_
    #define RANIM_HPP_

    #include <string>
    #include <memory>
    #include "raylib.h"
    #include "RModel.hpp"

    namespace indie {
        class RAnim {
            public:
                RAnim(const std::string &filename);
                ~RAnim();

                void draw(RModel &model);
            private:
            ModelAnimation *anims;
            unsigned int animsCount;
            int animFrameCounter;
        };
    }

#endif /* !RANIM_HPP_ */