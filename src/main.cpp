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
    } catch (indie::Exception &error) {
		std::cerr << error.what() << std::endl;
		return (84);
	}
    return (0);
}
