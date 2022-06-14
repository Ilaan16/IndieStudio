/*
** EPITECH PROJECT, 2022
** indie
** File description:
** iscene
*/

#ifndef iscenedef
#define iscenedef

enum Scenes {
    QUIT = -1,
    MENU = 0,
    NEW_GAME,
    GAME,
    LOAD,
    OPTION
};

class IScene {
    public:
        virtual ~IScene() {};

    protected:
    private:
};

#endif /* !iscenedef */
