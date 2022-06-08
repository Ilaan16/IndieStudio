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
    OPTION = 0,
    MENU,
    NEW_GAME,
    GAME,
    LOAD
};

class IScene {
    public:
        virtual ~IScene() {};
        virtual Scenes run(Scenes const &prevScene) = 0;

    protected:
    private:
};

#endif /* !iscenedef */
