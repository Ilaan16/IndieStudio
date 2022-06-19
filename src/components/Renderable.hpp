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
#include "raylib/RModel.hpp"
#include "raylib/Rtext.hpp"
#include "raylib/RTexture2D.hpp"
#include "raylib/RShape.hpp"
#include "raylib/RMusicManager.hpp"
#include "raylib/Player.hpp"
#include "raylib/RMap.hpp"
#include "raylib/RAnim.hpp"

namespace indie {

    struct Vector3D {
        float x;
        float y;
        float z;
    };

    class Renderable : public IComponent {
        public:
            Renderable(std::string model = "", std::string texture = "", std::string text = "", std::string image = "", float fontSize = 0, Vector3D position = {0},
                float angle = 0, Vector3D size = {0}, Vector3D rect = {0}, Vector3D textPosition = {0}, bool is3D = false, std::string animation = "")
                :_model(model, texture), _anim(animation), _music(texture), _shape(texture), _map(image, texture), _texture(texture), _text(fontSize), _strString(text),
                _fontSize(fontSize), _position(position), _angle(angle), _size(size), _rect(rect), _textPos(textPosition), _is3D(is3D), _inventory() {}
            ~Renderable() = default;

            indie::RModel _model;
            indie::RAnim _anim;
            indie::RShape _shape;
            indie::raylib::RMusicManager _music;
            indie::RTexture2D _texture;
            indie::Rtext _text;
            indie::RMap _map;
            indie::Player _inventory;
            std::string _strString;
            float _fontSize;
            Vector3D _position;
            Vector3D _rect;
            float _angle;
            Vector3D _size;
            Vector3D _textPos;
            bool _is3D;
        protected:
        private:
    };
}
#endif /* !RANDERABLE_HPP_ */
