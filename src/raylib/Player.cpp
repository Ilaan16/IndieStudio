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
        _timer = { 0 };
        _life = 2.0f;
        _putBomb = false;
        _explosion = false;
        _endup = false;
        
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
