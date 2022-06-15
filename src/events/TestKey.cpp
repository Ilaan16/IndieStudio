/*
** EPITECH PROJECT, 2022
** Indie
** File description:
** TestKey
*/

#include <iostream>
#include "Event.hpp"

namespace indie {
    void TestKey::useDown(std::unique_ptr<AScene> &ownScene, std::shared_ptr<Entity> &ownEntity) noexcept
    {
        std::cout << "Test Down" << std::endl;
    }

    void TestKey::usePressed(std::unique_ptr<AScene> &ownScene, std::shared_ptr<Entity> &ownEntity) noexcept
    {
        std::cout << "Test Pressed" << std::endl;
    }

    void TestKey::useReleased(std::unique_ptr<AScene> &ownScene, std::shared_ptr<Entity> &ownEntity) noexcept
    {
        std::cout << "Test Released" << std::endl;
    }
}
