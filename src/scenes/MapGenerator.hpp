/*
** EPITECH PROJECT, 2022
** IndieStudio
** File description:
** MapGenerator
*/

#ifndef MAPGENERATOR_HPP_
    #define MAPGENERATOR_HPP_

    #include <vector>
    #include <random>
    #include <raylib.h>
    #include <iostream>
    #include "components/Renderable.hpp"

    namespace indie {

        class MapGenerator {
            public:
                MapGenerator();
                ~MapGenerator();

                Vector3D calcul(int number, Vector3D mapPosition2);
                int verif(std::vector <int> tab, int temp);
                std::vector <int> aleatoire();
                void createMap();
            protected:
            private:
        };
    }

#endif /* !MAPGENERATOR_HPP_ */
