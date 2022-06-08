/*
** EPITECH PROJECT, 2022
** indie
** File description:
** raylib
*/

#include "scenes/AScene.hpp"
#include "Raylib.hpp"

indie::Raylib::Raylib() :
    _camera({{0.0f, 10.0f, 10.0f}, {0.0f, 0.0f, 0.0f}, {0.0f, 1.0f, 0.0f}, 45.0f, 0})
{
}

indie::Raylib::~Raylib()
{
    if (IsWindowReady())
        CloseWindow();
}

void indie::Raylib::setCamera(Vector3 pos, Vector3 target, Vector3 up, float fovy, int projection)
{
    _camera.position = pos;
    _camera.target = target;
    _camera.up = up;
    _camera.fovy = fovy;
    _camera.projection = projection;
};

Camera indie::Raylib::getCamera() const
{
    return _camera;
};

void indie::Raylib::createWindow(int screenWidth, int screenHeight, std::string const &title, std::size_t const fps)
{
    _screenSize.first = screenWidth;
    _screenSize.second = screenHeight;
    InitWindow(screenWidth, screenHeight, title.c_str());
    SetTargetFPS(fps);
}

bool indie::Raylib::gameLoop()
{
    return !WindowShouldClose();
}

bool indie::Raylib::isKeyDown(int button) const noexcept
{
    return (IsKeyDown(button));
}

bool indie::Raylib::isKeyPressed(int button) const noexcept
{
    return (IsKeyPressed(button));
}

bool indie::Raylib::isKeyReleased(int button) const noexcept
{
    return (IsKeyReleased(button));
}

void indie::Raylib::printCircle(typeEntityLine const typeEntityLine, std::pair<int, int> const position, float const radius, std::pair<Color, Color> const color) const
{
    if (typeEntityLine == BASIC)
        DrawCircle(position.first, position.second, radius, color.first);
    else if (typeEntityLine == GRADIENT)
        DrawCircleGradient(position.first, position.second, radius, color.first, color.second);
    else if (typeEntityLine == LINES)
        DrawCircleLines(position.first, position.second, radius, color.first);
    else
        std::cout << "Unknow Circle Type\n";
}

void indie::Raylib::printRectangle(typeEntityLine const typeEntityLine, std::pair<int, int> const position, std::pair<int, int> const size, std::pair<Color, Color> const color) const
{
    if (typeEntityLine == BASIC)
        DrawRectangle(position.first, position.second, size.first, size.second, color.first);
    else if (typeEntityLine == GRADIENT)
        DrawRectangleGradientH(position.first, position.second, size.first, size.second, color.first, color.second);
    else if (typeEntityLine == LINES)
        DrawRectangleLines(position.first, position.second, size.first, size.second, color.first);
    else
        std::cout << "Unknow Rectangle Type\n";
}

void indie::Raylib::printCube(typeEntityLine const typeEntityLine, Vector3 const position, Vector3 const size, Color const color) const
{
    if (typeEntityLine == BASIC)
        DrawCube(position, size.x, size.y, size.z, color);
    else if (typeEntityLine == WIRES)
        DrawCubeWires(position, size.x, size.y, size.z, color);
    else
        std::cout << "Unknow Cube Type\n";
}

void indie::Raylib::printSphere(typeEntityLine const typeEntityLine, Vector3 const position, float const size, std::pair<int, int> const Vertex, Color const color) const
{
    if (typeEntityLine == BASIC)
        DrawSphere(position, size, color);
    else if (typeEntityLine == WIRES)
        DrawSphereWires(position, size, Vertex.first, Vertex.second, color);
    else
        std::cout << "Unknow Shpere Type\n";
}

void indie::Raylib::printGrid(int const slices, float const space) const
{
    DrawGrid(slices, space);
}

void indie::Raylib::printFps(std::pair<int, int> const pos) const
{
    DrawFPS(pos.first, pos.second);
}

void indie::Raylib::printText(std::shared_ptr<indie::IComponent> text_comp, std::shared_ptr<indie::IComponent> vector2) const
{
    SpriteText *text = dynamic_cast<SpriteText *>(text_comp.get());
    Vector2D *vector = dynamic_cast<Vector2D *>(vector2.get());
    Font font = LoadFontEx("../../font/Minecrafter.Reg.ttf", text->_fontSize, 0, 0);
    DrawTextEx(font, text->_text.c_str(), {vector->_x, vector->_y}, text->_fontSize, 0, BLACK);
}

void indie::Raylib::printSprite(std::shared_ptr<indie::IComponent> texture, std::shared_ptr<indie::IComponent> vector2d) const
{
    Sprite2D *sprite = dynamic_cast<Sprite2D *>(texture.get());
    Vector2D *vector = dynamic_cast<Vector2D *>(vector2d.get());
    Texture2D texture2d = LoadTexture(sprite->_texture.c_str());
    BeginDrawing();
        DrawTexture(texture2d, vector->_x, vector->_y, WHITE);
    EndDrawing();
    UnloadTexture(texture2d);
    return;
}

void indie::Raylib::displayAll(std::map<typeEntity ,std::vector<std::shared_ptr<indie::Entity>>> &entities)
{
    auto drawable_entity = entities.find(typeEntity::DRAWABLE);
    for (int i = 0; i != drawable_entity->second.size(); i++) {
        auto component = drawable_entity->second.at(i)->getComponents();
        auto texture2d_compo = component.find(tag::TEXTURE2D);
        auto vector2d_compo = component.find(tag::VECTOR2D);
        if (texture2d_compo != component.end() && vector2d_compo != component.end())
            printSprite(texture2d_compo->second, vector2d_compo->second);
        auto text_compo = component.find(tag::TEXT);
        if (text_compo != component.end() && vector2d_compo != component.end())
            printText(text_compo->second, vector2d_compo->second);
    }
    return;
    }
