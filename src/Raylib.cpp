/*
** EPITECH PROJECT, 2022
** indie
** File description:
** raylib
*/

#include "Raylib.hpp"

Raylib::Raylib() :
    _camera({{0.0f, 10.0f, 10.0f}, {0.0f, 0.0f, 0.0f}, {0.0f, 1.0f, 0.0f}, 45.0f, 0})
{
}

Raylib::~Raylib()
{
    if (IsWindowReady())
        CloseWindow();
}

void Raylib::setCamera(Vector3 pos, Vector3 target, Vector3 up, float fovy, int projection)
{
    _camera.position = pos;
    _camera.target = target;
    _camera.up = up;
    _camera.fovy = fovy;
    _camera.projection = projection;
};

Camera Raylib::getCamera() const
{
    return _camera;
};

void Raylib::createWindow(int screenWidth, int screenHeight, std::string const &title, std::size_t const fps)
{
    _screenSize.first = screenWidth;
    _screenSize.second = screenHeight;
    InitWindow(screenWidth, screenHeight, title.c_str());
    SetTargetFPS(fps);
}

bool Raylib::gameLoop()
{
    return !WindowShouldClose();
}

bool Raylib::isKeyDown(int button) const noexcept
{
    return (IsKeyDown(button));
}

bool Raylib::isKeyPressed(int button) const noexcept
{
    return (IsKeyPressed(button));
}

bool Raylib::isKeyReleased(int button) const noexcept
{
    return (IsKeyReleased(button));
}

void Raylib::printText(std::string const &text, std::pair<int, int> const position, int const fontSize, Color const color) const
{
    DrawText(text.c_str(), position.first, position.second, fontSize, color);
}

void Raylib::printCircle(type const type, std::pair<int, int> const position, float const radius, std::pair<Color, Color> const color) const
{
    if (type == BASIC)
        DrawCircle(position.first, position.second, radius, color.first);
    else if (type == GRADIENT)
        DrawCircleGradient(position.first, position.second, radius, color.first, color.second);
    else if (type == LINES)
        DrawCircleLines(position.first, position.second, radius, color.first);
    else
        std::cout << "Unknow Circle Type\n";
}

void Raylib::printRectangle(type const type, std::pair<int, int> const position, std::pair<int, int> const size, std::pair<Color, Color> const color) const
{
    if (type == BASIC)
        DrawRectangle(position.first, position.second, size.first, size.second, color.first);
    else if (type == GRADIENT)
        DrawRectangleGradientH(position.first, position.second, size.first, size.second, color.first, color.second);
    else if (type == LINES)
        DrawRectangleLines(position.first, position.second, size.first, size.second, color.first);
    else
        std::cout << "Unknow Rectangle Type\n";
}

void Raylib::printCube(type const type, Vector3 const position, Vector3 const size, Color const color) const
{
    if (type == BASIC)
        DrawCube(position, size.x, size.y, size.z, color);
    else if (type == WIRES)
        DrawCubeWires(position, size.x, size.y, size.z, color);
    else
        std::cout << "Unknow Cube Type\n";
}

void Raylib::printSphere(type const type, Vector3 const position, float const size, std::pair<int, int> const Vertex, Color const color) const
{
    if (type == BASIC)
        DrawSphere(position, size, color);
    else if (type == WIRES)
        DrawSphereWires(position, size, Vertex.first, Vertex.second, color);
    else
        std::cout << "Unknow Shpere Type\n";
}

void Raylib::printGrid(int const slices, float const space) const
{
    DrawGrid(slices, space);
}

void Raylib::printFps(std::pair<int, int> const pos) const
{
    DrawFPS(pos.first, pos.second);
}