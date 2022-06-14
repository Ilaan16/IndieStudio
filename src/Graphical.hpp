/*
** EPITECH PROJECT, 2022
** B-YEP-400-TLS-4-1-indiestudio-ilan.chekroun
** File description:
** Graphical
*/

#ifndef GRAPHICAL_HPP_
#define GRAPHICAL_HPP_

#include "scenes/AScene.hpp"
#include "Raylib.hpp"


namespace indie {

    class Graphical {
        public:
            Graphical();
            ~Graphical();

            void updateSystem(std::unique_ptr<AScene> &scene);
        protected:
        private:
            indie::Raylib _raylib;
    };
}
#endif /* !GRAPHICAL_HPP_ */
