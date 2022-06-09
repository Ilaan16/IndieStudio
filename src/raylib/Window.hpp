/*
** EPITECH PROJECT, 2022
** Indie
** File description:
** Window
*/

#ifndef WINDOW_HPP_
    #define WINDOW_HPP_

    #include <string>
    #include "raylib.h"

namespace indie {
    namespace raylib {
        class Window {
            public:
                Window(const std::string &title, int width = 1920, int height = 1080, int fps = 60);
                ~Window();

                void toggleFull(void);
                const int getFps() const;
                const int getWidth() const;
                const int getHeight() const;
                const bool isFullScreen() const;

                void setCamera(Vector3 pos, Vector3 target, Vector3 up, float fovy, int projection);
                const Camera &getCamera() const;

            private:
                int _fps;
                int _width;
                int _height;
                bool _fullScreen;
                Camera _camera;
        };
    }
}

#endif /* !WINDOW_HPP_ */
