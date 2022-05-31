/*
** EPITECH PROJECT, 2022
** B-YEP-400-TLS-4-1-indiestudio-ilan.chekroun
** File description:
** Entity
*/

#ifndef ENTITY_HPP_
#define ENTITY_HPP_

#include <vector>
#include <memory>
#include "IComponent.hpp"

class Entity {
    public:
        Entity();
        ~Entity();

    protected:
    private:
        std::vector<std::unique_ptr<indie::IComponent>> _components;
};

#endif /* !ENTITY_HPP_ */
