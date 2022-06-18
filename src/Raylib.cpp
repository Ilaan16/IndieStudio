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
    Camera camera = { { 0, 18, 8 }, { 0, -2, 0 }, { 0, 1, 0 }, 50, 0 };
    SetCameraMode(camera, CAMERA_ORBITAL);

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
            } else {
                entity->_model.draw(entity->_position.x, entity->_position.y, entity->_position.z, camera);
                entity->_map.draw(camera);
            }
        }
}
