/*
** EPITECH PROJECT, 2022
** indie
** File description:
** Player
*/

#include "Player.hpp"
#include <iostream>

namespace indie {
    
    void Player::StartTimer(Timer* timer, float lifetime)
    {
        if (timer != NULL)
            timer->Lifetime = lifetime;
    }

    void Player::UpdateTimer(Timer* timer)
    {
        if (timer != NULL && timer->Lifetime > 0)
            timer->Lifetime -= GetFrameTime();
    }

    bool Player::TimerDone(Timer* timer)
    {
        if (timer != NULL)
            return timer->Lifetime <= 0;

        return false;
    }

    Player::Player()
    {
        Image imMap = LoadImage("assets/map/cubicmap_atlas.png");
        this->_cubicmap = LoadTextureFromImage(imMap);
        this->_mapPixels = LoadImageColors(imMap);
        _timer = { 0 };
        _life = 2.0f;
        _putBomb = false;
        _explosion = 0;
        _endup = false;
        
        _up_stillalive = false;
        _down_stillalive = false;
        _left_stillalive = false;
        _right_stillalive = false;


        _playerPosition = { -6.0f, 2.0f, 6.0f };
        _playerSize = { 2.0f, 2.0f, 2.0f };
        _modelPlayer = LoadModel("assets/characters/character.iqm");
        _texturePlayer = LoadTexture("assets/characters/steve.png");
        SetMaterialTexture(&_modelPlayer.materials[0], MATERIAL_MAP_DIFFUSE, _texturePlayer);
    }

    Player::~Player()
    {
    }
}