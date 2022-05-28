/*
** EPITECH PROJECT, 2022
** inide
** File description:
** scenemanage
*/

#ifndef ascenedef
#define ascenedef

#include <vector>
#include <memory>
#include <string>

#include "Raylib.hpp"

class AScene {
    public:
        AScene() = default;
        virtual ~AScene() = default;
        virtual int run(Raylib &lib) = 0;

    protected:
    private:
};

#endif /* !ascenedef */
