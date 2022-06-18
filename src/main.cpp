/*
** EPITECH PROJECT, 2022
** indie
** File description:
** main
*/

#include <iostream>
#include "Core.hpp"
#include "Raylib.hpp"

int main(void)
{
    try {
        indie::Core core(60);

        core.start();
    } catch(std::runtime_error &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    return (0);
}
