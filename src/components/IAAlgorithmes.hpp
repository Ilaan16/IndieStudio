/*
** EPITECH PROJECT, 2022
** dev
** File description:
** The IAAlgorithmes
*/

#ifndef IAALGORITHMES_HPP_
    #define IAALGORITHMES_HPP_

    #include <string>

    #include "IComponent.hpp"
    #include "Vector3D.hpp"

    namespace indie {
        class IAAlgorithmes : public IComponent {
            IAAlgorithmes(Vector3D posIA = NULL, Vector3D posP1 = NULL, Vector3D posP2 = NULL, Vector3D posP3 = NULL)
            : _posIA(posIA), _posP1(posP1), _posP2(posP2), _posP3(posP3) {}

            Vector3D _posIA;
            Vector3D _posP1;
            Vector3D _posP2;
            Vector3D _posP3;
        }
    }

#endif /* !IAALGORITHMES_HPP_ */