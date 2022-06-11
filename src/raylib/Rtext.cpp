/*
** EPITECH PROJECT, 2022
** indi
** File description:
** RText
*/

#include "Rtext.hpp"
#include <iostream>

namespace indie {
    Rtext::Rtext(const std::string &filename, const int fontSize)
    {
        // if (filename != "") {
        //     *this->font = LoadFontEx(filename.c_str(), fontSize, 0, 0);
        // } else
        this->font = NULL;
    }

    Rtext::~Rtext()
    {
        UnloadFont(*this->font);
    }

    void Rtext::draw(const float &x, const float &y, const std::string &text, const int &fontSize)
    {
        if (this->font != NULL)
            DrawTextEx(*this->font, text.c_str(), {x, y}, fontSize, 0, BLACK);
    }
}