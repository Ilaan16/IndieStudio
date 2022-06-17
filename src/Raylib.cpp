/*
** EPITECH PROJECT, 2022
** indie
** File description:
** raylib
*/

#include "scenes/AScene.hpp"
#include "Raylib.hpp"

void indie::Raylib::displayAll(std::map<typeEntity ,std::vector<std::shared_ptr<indie::Entity>>> &entities)
{
    Camera camera;
    camera.position = (Vector3){ 10.0f, 10.0f, 10.0f }; // Camera position
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };      // Camera looking at point
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    camera.fovy = 45.0f;                                // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE;

    BeginDrawing();
    auto drawable_entity = entities.find(typeEntity::DRAWABLE);
    for (int i = 0; i < drawable_entity->second.size(); i++) {
        auto component = drawable_entity->second.at(i)->getComponents();
        auto renderer = component.find(tag::RENDERABLE);
        indie::Renderable *entity = dynamic_cast<indie::Renderable *>(renderer->second.get());
        if (entity->_is3D == false) {
            entity->_music.setTime();
            entity->_music.playSong();
            entity->_texture.draw(entity->_position.x, entity->_position.y, {entity->_rect.x, entity->_rect.y, entity->_size.x, entity->_size.y});
            entity->_text.draw(entity->_textPos.x, entity->_textPos.y, entity->_strString, entity->_fontSize);
        } else
            if (sceneId == 2) {
                entity->_model.draw(entity->_position.x, entity->_position.y, entity->_position.z, camera);
                entity->_map.putBomb(&entity->_position.x, &entity->_position.y, &entity->_position.z, &entity->_inventory, camera);
                entity->_map.draw(camera);
            }
    }
    EndDrawing();
}
