/*
** EPITECH PROJECT, 2022
** Indie
** File description:
** RTexture3D
*/

#include <iostream>
#include "RAnim.hpp"

namespace indie {
    RAnim::RAnim(const std::string &filename)
    {
        this->animsCount = 0;
        this->animFrameCounter = 0;
        this->anims = LoadModelAnimations(filename.c_str(), &animsCount);
    }

    RAnim::~RAnim()
    {
        UnloadModelAnimations(this->anims, this->animsCount);
    }

    void RAnim::draw(RModel &model)
    {
        this->animFrameCounter++;
        UpdateModelAnimation(model._model, this->anims[0], this->animFrameCounter);
        if (animFrameCounter >= anims[0].frameCount)
            animFrameCounter = 0;
    }
}