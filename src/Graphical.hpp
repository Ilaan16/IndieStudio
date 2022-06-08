/*
** EPITECH PROJECT, 2022
** B-YEP-400-TLS-4-1-indiestudio-ilan.chekroun
** File description:
** Graphical
*/

#ifndef GRAPHICAL_HPP_
#define GRAPHICAL_HPP_

#include "AScene.hpp"
#include "IEvent.hpp"
#include "Raylib.hpp"

namespace indie {

    class Graphical {
        public:
            Graphical();
            ~Graphical();

            int updateSystem(std::unique_ptr<AScene> &scene);
            void destroyGame();
            IEvent *translateEvent();
        protected:
        private:
            indie::Raylib _raylib;
    };
}
#endif /* !GRAPHICAL_HPP_ */
