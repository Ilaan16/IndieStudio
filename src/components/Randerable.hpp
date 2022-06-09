/*
** EPITECH PROJECT, 2022
** IndieStudio
** File description:
** Randerable
*/

#ifndef RANDERABLE_HPP_
#define RANDERABLE_HPP_

#include <string>
#include "IComponent.hpp"

namespace indie {

    struct Vector3D {
        float x;
        float y;
        float z;
    };

    class Randerable : public IComponent {
        public:
            Randerable(std::string model = "", std::string texture = "", std::string text = "",
                float fontSize = 0, Vector3D position = {0}, float angle = 0, Vector3D size = {0})
                :_model(model), _texture(texture), _text(text), _fontSize(fontSize), _position(position), _angle(angle), _size(size) {}
            ~Randerable() = default;

            std::string _model;
            std::string _texture;
            std::string _text;
            float _fontSize;
            Vector3D _position;
            float _angle;
            Vector3D _size;
        protected:
        private:
    };
}
#endif /* !RANDERABLE_HPP_ */
