/*
** EPITECH PROJECT, 2022
** indie
** File description:
** main
*/

#ifndef mainscenedef
#define mainscenedef

#include "AScene.hpp"

class MainScene : public AScene {
    public:
        MainScene();
        ~MainScene();

        Scenes run(Raylib &lib, Scenes const &prevScene) final;
    protected:
    private:
};

#endif /* !mainscenedef */
