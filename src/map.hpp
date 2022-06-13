/*
** EPITECH PROJECT, 2022
** map_hpp
** File description:
** map_hpp
*/

#include "raylib.h"
#include <iostream>
#include <stdlib.h>
#include <random>

class Map {
        public:
            Map();
            ~Map();
            int start();
            Vector3 calcul(int number);
            int verif(std::vector <int> tab, int temp);
            std::vector <int> aleatoire();
        private:
            Vector3 mapPosition;
            Vector3 mapPosition2;
            Vector3 mapPosition3;
};