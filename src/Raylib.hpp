/*
** EPITECH PROJECT, 2022
** Indie
** File description:
** Raylib
*/

#ifndef encap
#define encap

#include <cstddef>
#include <string>
#include <utility>
#include <memory>
#include <iostream>
#include <unordered_map>
#include <functional>
#include "AScene.hpp"
#include "raylib.h"

namespace indie {

    enum typeLine {
        BASIC,
        GRADIENT,
        LINES,
        WIRES
    };

    class Raylib {
        public:

            Raylib();
            ~Raylib();

            void createWindow(int screenWidth, int screenHeight, std::string const &title, std::size_t const Fps);

            bool gameLoop();
            void displayAll(std::map<type ,std::vector<std::shared_ptr<Entity>>> &entities);

            void printSprite(std::unique_ptr<indie::IComponent> texture, std::unique_ptr<indie::IComponent> vector2) const;
            void printText(std::unique_ptr<indie::IComponent> text, std::unique_ptr<indie::IComponent> vector2) const;
            void printCircle(typeLine const typeLine, std::pair<int, int> const position, float const radius, std::pair<Color, Color> const color) const;
            void printRectangle(typeLine const typeLine, std::pair<int, int> const position, std::pair<int, int> const size, std::pair<Color, Color> const color) const;
            void printGrid(int const slices, float const space) const;
            void printCube(typeLine const typeLine, Vector3 const position, Vector3 const size, Color const color) const;
            void printSphere(typeLine const typeLine, Vector3 const position, float const size, std::pair<int, int> const Vertex ,Color const color) const;
            void printFps(std::pair<int, int> const pos) const;

            void setCamera(Vector3 pos, Vector3 target, Vector3 up, float fovy, int projection);
            Camera getCamera() const;

            bool isKeyDown(int button) const noexcept;
            bool isKeyPressed(int button) const noexcept;
            bool isKeyReleased(int button) const noexcept;

        protected:
        private:
            std::pair<int, int> _screenSize;
            Camera _camera;
            std::unordered_map<KeyboardKey,std::function<void()>> _keys = {
                {KEY_ENTER, [](){}},
                {KEY_SPACE, [](){}},
                {KEY_ESCAPE, [](){}},
                {KEY_TAB, [](){}},
                {KEY_UP, [](){}},
                {KEY_DOWN, [](){}},
                {KEY_RIGHT, [](){}},
                {KEY_LEFT, [](){}},
                {KEY_A, [](){}},
                {KEY_B, [](){}},
                {KEY_C, [](){}},
                {KEY_D, [](){}},
                {KEY_E, [](){}},
                {KEY_E, [](){}},
                {KEY_F, [](){}},
                {KEY_G, [](){}},
                {KEY_H, [](){}},
                {KEY_I, [](){}},
                {KEY_J, [](){}},
                {KEY_K, [](){}},
                {KEY_L, [](){}},
                {KEY_M, [](){}},
                {KEY_N, [](){}},
                {KEY_O, [](){}},
                {KEY_P, [](){}},
                {KEY_Q, [](){}},
                {KEY_R, [](){}},
                {KEY_S, [](){}},
                {KEY_T, [](){}},
                {KEY_U, [](){}},
                {KEY_V, [](){}},
                {KEY_W, [](){}},
                {KEY_X, [](){}},
                {KEY_Y, [](){}},
                {KEY_Z, [](){}},
            };
    };
}

#endif /* !encap */
