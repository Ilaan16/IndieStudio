/*
** EPITECH PROJECT, 2022
** indie
** File description:
** raylib
*/

#include "AScene.hpp"
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

void print_sprite(indie::Entity &entitie, std::pair<int, int> _screensize)
{
    Image Sprite = LoadImage(entitie._components[0]->_sprite.path);
    Texture2D texture = LoadTextureFromImage(Sprite);
    BeginDrawing();
        DrawTexture(texture, _screensize.first/2 - texture.width/2, _screensize.second/2 - texture.height/2, WHITE);
    EndDrawing();
    return;
}

// void print_text(Entity &entitie, sf::RenderWindow &window)
// {
//     sf::Text text;
//     sf::Font font;

//     if (!font.loadFromFile(entitie._components[0]->_text.pathFont))
//         throw("CANNOT LOAD FONT");
//     text.setFont(font);
//     text.setCharacterSize(20);
//     text.setFillColor(sf::Color::White);
//     text.setPosition(entitie._components[0]->_position.x, entitie._components[0]->_position.y);
//     text.setString(entitie._components[0]->_text.text);
//     window.draw(text);
//     return;
// }

void Raylib::displayAll(std::map<std::vector<type>, std::unique_ptr<indie::Entity>> &entities)
{
    auto sprite = entities.find(indie::tag::TEXTURE2D);
    print_sprite()
    for (int i = 0; i < entities.size(); i++) {
        if (entities[i]->_components[0]->_sprite.path != "")
            print_sprite(*entities[i], this->_screenSize);
        else if (entities[i]->_components[0]->_text.text != "")
            print_text(*entities[i], this->_screenSize);
    }
    BeginDrawing();
    return;
}