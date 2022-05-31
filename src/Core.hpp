/*
** EPITECH PROJECT, 2022
** indie
** File description:
** core
*/

#ifndef coredef
#define coredef

#include <utility>
#include <string>
#include <memory>
#include "AScene.hpp"

class Core {
    public:
        Core(int screenWidth = 1920, int screenHeight = 1080, std::string const &title = "default", std::size_t const fps = 60);
        ~Core();
        void start();

    protected:
    private:
        std::vector<std::unique_ptr<indie::AScene>> _vecScenes;
        int _screenWidth;
        int _screenHeight;
        Scenes _scenePos;
        std::string _title;
        std::size_t _fps;
};

#endif /* !coredef */
