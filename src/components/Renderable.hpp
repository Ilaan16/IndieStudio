/*
** EPITECH PROJECT, 2022
** IndieStudio
** File description:
** Renderable
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

    class Renderable : public IComponent {
        public:
            Renderable(std::string model = "", std::string texture = "", std::string text = "",
                float fontSize = 0, Vector3D position = {0}, float angle = 0, Vector3D size = {0}, Vector3D rect = {0})
                :_model(model), _texture(texture), _text(text), _fontSize(fontSize), _position(position), _angle(angle), _size(size), _rect(rect) {}
            ~Renderable() = default;

            std::string _model;
            std::string _texture;
            std::string _text;
            float _fontSize;
            Vector3D _position;
            Vector3D _rect;
            float _angle;
            Vector3D _size;
        protected:
        private:
    };
}
#endif /* !RANDERABLE_HPP_ */