/*
** EPITECH PROJECT, 2022
** Indie
** File description:
** RTexture3D
*/

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
    }

    void RAnim::draw(const float &x, const float &y, Model model)
    {
        UpdateModelAnimation(model, this->anims[0], this->animFrameCounter);
    }
}