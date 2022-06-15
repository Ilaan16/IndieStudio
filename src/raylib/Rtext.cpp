/*
** EPITECH PROJECT, 2022
** indi
** File description:
** RText
*/

#include "Rtext.hpp"
#include <iostream>

namespace indie {
    Rtext::Rtext(const int fontSize)
    {
        this->font = LoadFontEx("./assets/menu/Minecrafter.Reg.ttf", fontSize, 0, 0);
    }

    Rtext::~Rtext()
    {
        UnloadFont(this->font);
    }

    void Rtext::draw(const float &x, const float &y, const std::string &text, const int &fontSize)
    {
        DrawTextEx(this->font, text.c_str(), {x, y}, fontSize, 0, WHITE);
    }
}