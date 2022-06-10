/*
** EPITECH PROJECT, 2022
** indi
** File description:
** RText
*/

#include "Rtext.hpp"

namespace indie {
    Rtext::Rtext(const std::string &filename, const int &fontSize)
    {
        this->font = LoadFontEx(filename.c_str(), fontSize, 0, 0);
    }

    Rtext::~Rtext()
    {
    }

    void Rtext::draw(const float &x, const float &y, const std::string &text, const int &fontSize)
    {
        DrawTextEx(this->font, text.c_str(), {x, y}, fontSize, 0, BLACK);
    }
}