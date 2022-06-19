/*
** EPITECH PROJECT, 2022
** indie
** File description:
** main
*/

#include "scenes/MainScene.hpp"
#include "EntitiesFactory.hpp"
#include "components/Listener.hpp"
#include "Core.hpp"
#include <vector>

indie::MainScene::MainScene()
{
    std::vector<std::shared_ptr<Entity>> drawable_ent;
    std::vector<std::shared_ptr<Entity>> movable_ent;
    std::vector<std::shared_ptr<Entity>> playable_ent;
    std::vector<std::shared_ptr<Entity>> map_ent;

    std::shared_ptr<Event> move_right = std::make_shared<Movement>(1);
    std::shared_ptr<Event> move_left = std::make_shared<Movement>(2);
    std::shared_ptr<Event> move_down = std::make_shared<Movement>(3);
    std::shared_ptr<Event> move_up = std::make_shared<Movement>(4);

    std::shared_ptr<Event> put_bomb = std::make_shared<Action>();

    _entities.emplace(typeEntity::DRAWABLE, drawable_ent);
    _entities.emplace(typeEntity::MOVABLE, movable_ent);
    _entities.emplace(typeEntity::PLAYABLE, playable_ent);
    _entities.emplace(typeEntity::MAP, map_ent);

    EntitiesFactory Entities;

    Entities.createSound(_entities, "assets/sound/C418 - Aria Math, but its an EPIC Soundtrack.mp3");

    Entities.createPlayer(_entities,"./assets/characters/character.iqm", "./assets/characters/steve.png", {-6.0f, 2.0f, 6.0f}, 0.0F, {1920, 1080, 0}, "assets/characters/characterAnim.iqm");
    this->addEventToLastEntity(KeyboardKey::KEY_RIGHT, move_right);
    this->addEventToLastEntity(KeyboardKey::KEY_LEFT, move_left);
    this->addEventToLastEntity(KeyboardKey::KEY_DOWN, move_down);
    this->addEventToLastEntity(KeyboardKey::KEY_UP, move_up);

    this->addEventToLastEntity(KeyboardKey::KEY_ENTER, put_bomb);

    Entities.createPlayer(_entities,"./assets/characters/character.iqm", "./assets/characters/steve.png", {6.0f, 2.0f, 6.0f}, 0.0F, {1920, 1080, 0}, "assets/characters/characterAnim.iqm");
    this->addEventToLastEntity(KeyboardKey::KEY_D, move_right);
    this->addEventToLastEntity(KeyboardKey::KEY_A, move_left);
    this->addEventToLastEntity(KeyboardKey::KEY_S, move_down);
    this->addEventToLastEntity(KeyboardKey::KEY_W, move_up);

    this->addEventToLastEntity(KeyboardKey::KEY_SPACE, put_bomb);

    Entities.createMap(_entities,"", "assets/map/cubicmap_atlas.png", {0, 0, 0}, 0.0F, {1920, 1080, 0}, "assets/map/map.png");

    std::vector<std::pair<KeyboardKey, ButtonState>> input;
    input.push_back(std::make_pair(KeyboardKey::KEY_RIGHT, ButtonState::None));
    input.push_back(std::make_pair(KeyboardKey::KEY_LEFT, ButtonState::None));
    input.push_back(std::make_pair(KeyboardKey::KEY_DOWN, ButtonState::None));
    input.push_back(std::make_pair(KeyboardKey::KEY_UP, ButtonState::None));

    input.push_back(std::make_pair(KeyboardKey::KEY_D, ButtonState::None));
    input.push_back(std::make_pair(KeyboardKey::KEY_A, ButtonState::None));
    input.push_back(std::make_pair(KeyboardKey::KEY_S, ButtonState::None));
    input.push_back(std::make_pair(KeyboardKey::KEY_W, ButtonState::None));

    input.push_back(std::make_pair(KeyboardKey::KEY_ENTER, ButtonState::None));
    input.push_back(std::make_pair(KeyboardKey::KEY_SPACE, ButtonState::None));

    events = raylib::REvent({input}, {});
}

void indie::MainScene::addEventToLastEntity(const KeyboardKey &key, std::shared_ptr<Event> &evt)
{
    std::shared_ptr<indie::IComponent> comp = _entities.find(MOVABLE)->second.back()->getComponents().find(LISTENER)->second;
    std::shared_ptr<indie::Listener> listener = std::static_pointer_cast<Listener, IComponent>(comp);

    listener->addEvent(key, evt);
}

indie::MainScene::~MainScene()
{
    //clear objects
}

std::map<indie::typeEntity, std::vector<std::shared_ptr<indie::Entity>>> &indie::MainScene::getEntities()
{
    return (this->_entities);
}

bool indie::MainScene::checkHit(int *sceneId, Vector3 position, float *position1, float *position2, float movement, int *explose, Texture2D cubicmap, Color *mapPix, std::vector<Vector3> collision_entity)
{
    Vector3 _mapPos = { -7, 2, -5 };
    *(position2) += movement;
    float playerRadius = 0.1f;
    Vector2 playerPos = { position.x, position.z };
    int playerCellX = (int)(position1 - position2 + 0.5f);
    int playerCellY = (int)(position2 - position1 + 0.5f);
    if (playerCellX < 0) {
        playerCellX = 0;
    } else if (playerCellX >= cubicmap.width) {
        playerCellX = cubicmap.width - 1;
    }
    if (playerCellY < 0) {
        playerCellY = 0;
    } else if (playerCellY >= cubicmap.height) {
        playerCellY = cubicmap.height - 1;
    }

    for (int y = 0; y < cubicmap.height; y++) {
        for (int x = 0; x < cubicmap.width; x++) {
            if (mapPix[y*cubicmap.width + x].r == 255 && CheckCollisionCircleRec(playerPos, playerRadius, (Rectangle){ _mapPos.x - 0.5f + x*1.0f, _mapPos.z - 0.5f + y*1.0f, 1.0f, 1.0f })) {
                return (false);
            }
        }
    }

    for (Vector3 position_player : collision_entity) {
        if (_raylib.collision_entities(position_player, position, 1.0f) == true)
            *sceneId = 5;
    }
    return (true);
}

void indie::MainScene::putBomb(int *sceneId, float *x, float *y, float *z, Player *player, Camera3D camera, Texture2D cubicmap, Color *mapPixels, std::vector<Vector3> collision_entity)
{
    BeginMode3D(camera);
    (*player).UpdateTimer(&(*player)._timer);
    if ((*player)._putBomb == true && !(*player).TimerDone(&(*player)._timer)) {
        _raylib.displayCube(Raylib::BASIC, (*player)._tnt, { 1.0f, 1.0f, 1.0f }, RED);
    }

    if ((*player).TimerDone(&(*player)._timer) && ((*player)._explosion > 0 || (*player)._putBomb == true)) {
        (*player)._putBomb = false;
        if ((*player)._up_stillalive == true) {
            (*player)._up_stillalive = checkHit(sceneId, (*player)._up._bomb, &(*player)._up._bomb.x, &(*player)._up._bomb.z, -0.2f, &(*player)._explosion, cubicmap, mapPixels, collision_entity);
            _raylib.displayCube(Raylib::BASIC, (*player)._up._bomb, { 1.0f, 2.0f, 1.0f }, RED);
        }
        if ((*player)._down_stillalive == true) {
            (*player)._down_stillalive = checkHit(sceneId, (*player)._down._bomb, &(*player)._down._bomb.x, &(*player)._down._bomb.z, 0.2f, &(*player)._explosion, cubicmap, mapPixels, collision_entity);
            _raylib.displayCube(Raylib::BASIC, (*player)._down._bomb, { 1.0f, 2.0f, 1.0f }, RED);
        }
        if ((*player)._left_stillalive == true) {
            (*player)._left_stillalive = checkHit(sceneId, (*player)._left._bomb, &(*player)._left._bomb.z, &(*player)._left._bomb.x, -0.2f, &(*player)._explosion, cubicmap, mapPixels, collision_entity);
            _raylib.displayCube(Raylib::BASIC, (*player)._left._bomb, { 1.0f, 2.0f, 1.0f }, RED);
        }
        if ((*player)._right_stillalive == true) {
            (*player)._right_stillalive = checkHit(sceneId, (*player)._right._bomb, &(*player)._right._bomb.z, &(*player)._right._bomb.x, 0.2f, &(*player)._explosion, cubicmap, mapPixels, collision_entity);
            _raylib.displayCube(Raylib::BASIC, (*player)._right._bomb, { 1.0f, 2.0f, 1.0f }, RED);
        }
    }
    EndMode3D();
}

void indie::MainScene::update(int *sceneId, std::map<indie::typeEntity, std::vector<std::shared_ptr<indie::Entity>>> &entities)
{
    Camera camera = { { 0, 18, 8 }, { 0, -2, 0 }, { 0, 1, 0 }, 50, 0 };
    SetCameraMode(camera, CAMERA_ORBITAL);

    auto drawable_entity = entities.find(typeEntity::DRAWABLE);
    Texture2D cubicmap;
    Color *mapPixels;
    std::vector<Vector3> collision_entity;

    auto mapEntity = entities.find(typeEntity::MAP)->second.at(0)->getComponents();
    auto rendererMap = dynamic_cast<indie::Renderable *>(mapEntity.find(tag::RENDERABLE)->second.get());
    cubicmap = rendererMap->_map.getMap();
    mapPixels = rendererMap->_map._mapPixels;

    auto playerEntity = entities.find(typeEntity::MOVABLE);
    for (int i = 0; i < playerEntity->second.size(); i++) {
        auto component = playerEntity->second.at(i)->getComponents();
        indie::Renderable *rendererPlayer = dynamic_cast<indie::Renderable *>(component.find(tag::RENDERABLE)->second.get());
        Vector3 position = {rendererPlayer->_position.x, rendererPlayer->_position.y, rendererPlayer->_position.z};
        collision_entity.push_back(position);
    }

    for (int i = 0; i < drawable_entity->second.size(); i++) {
        auto component = drawable_entity->second.at(i)->getComponents();
        auto renderer = component.find(tag::RENDERABLE);
        indie::Renderable *entity = dynamic_cast<indie::Renderable *>(renderer->second.get());
        putBomb(sceneId, &entity->_position.x, &entity->_position.y, &entity->_position.z, &entity->_inventory, camera, cubicmap, mapPixels, collision_entity);
    }
}