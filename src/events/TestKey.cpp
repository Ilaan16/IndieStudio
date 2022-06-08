/*
** EPITECH PROJECT, 2022
** Indie
** File description:
** TestKey
*/

#include <iostream>
#include "KeyboardEvent.hpp"

namespace indie {
    void TestKey::useKey(std::shared_ptr<Entity> &ownEntity) noexcept
    {
        std::cout << "Test key" << std::endl;
    }
}
