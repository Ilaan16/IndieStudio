/*
** EPITECH PROJECT, 2022
** Indie
** File description:
** Window
*/

#include <iostream>
#include "Exception.hpp"
#include "Window.hpp"

namespace indie {
    namespace raylib {
        Window::Window(const std::string &title, int width, int height, int fps):
            _fps(fps), _width(width), _height(height)
        {
            InitWindow(width, height, title.c_str());
            if (!IsWindowReady())
                throw WindowError("Window not ready");
            InitAudioDevice();
            if (!IsAudioDeviceReady())
                throw AudioError("Audio device not ready");
            SetMasterVolume(1.0);
            SetTargetFPS(fps);
            SetWindowState(FLAG_WINDOW_RESIZABLE);
        }

        Window::~Window()
        {
            if (IsAudioDeviceReady())
                CloseAudioDevice();
            if (IsWindowReady())
                CloseWindow();
        }

        void Window::toggleFull(void)
        {
            ToggleFullscreen();
        }

        const int &Window::getFps(void) const
        {
            return _fps;
        }

        const int &Window::getWidth(void) const
        {
            return _width;
        }

        const int &Window::getHeight(void) const
        {
            return _height;
        }

        bool Window::isFullScreen(void) const
        {
            return IsWindowFullscreen();
        }

        const bool Window::closing(void) const
        {
            return WindowShouldClose();
        }

        void Window::changeVolume(float size, float max) const
        {
            float volume = size / max;
            SetMasterVolume(volume);
        }

        void Window::clear(void)
        {
            ClearBackground(RAYWHITE);
        }
    }
}
