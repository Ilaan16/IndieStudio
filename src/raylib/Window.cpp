/*
** EPITECH PROJECT, 2022
** Indie
** File description:
** Window
*/

#include "Window.hpp"

namespace indie {
    namespace raylib {
        Window::Window(const std::string &title, int width, int height, int fps):
            _fps(fps), _width(width), _height(height), _fullScreen(false)
        {
            InitWindow(width, height, title.c_str());
            if (!IsWindowReady())
                throw ;
            SetTargetFPS(fps);
            _fullScreen = IsWindowFullscreen();
        }

        Window::~Window()
        {
            if (IsWindowReady())
                CloseWindow();
        }

        void Window::toggleFull(void)
        {
            ToggleFullscreen();
            _fullScreen = !_fullScreen;
        }

        const int Window::getFps(void) const
        {
            return _fps;
        }

        const int Window::getWidth(void) const
        {
            return _width;
        }

        const int Window::getHeight(void) const
        {
            return _height;
        }

        const bool Window::isFullScreen(void) const
        {
            return _fullScreen;
        }
    }
}
