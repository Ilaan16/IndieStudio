/*
** EPITECH PROJECT, 2022
** indie
** File description:
** iscene
*/

#ifndef iscenedef
#define iscenedef

#include "Raylib.hpp"

enum Scenes {
    QUIT = -1,
    MENU,
    NEW_GAME,
    GAME,
    LOAD,
    OPTION
};

class IScene {
    public:
        virtual ~IScene() {};
        virtual Scenes run(Raylib &lib, Scenes const &prevScene) = 0;

    protected:
    private:
};

#endif /* !iscenedef */
