/*
** EPITECH PROJECT, 2022
** indie
** File description:
** Rtext
*/

#ifndef RTEXT_HPP_
    #define RTEXT_HPP_

    #include <string>
    #include "raylib.h"

    namespace indie {
        class Rtext {
            public:
                Rtext(const std::string &filename, const int fontSize);
                ~Rtext();

                void draw(const float&x, const float &y, const std::string &text, const int &fontSize);
            protected:
            private:
                Font *font;
        };
    }

#endif /* !RTEXT_HPP_ */
