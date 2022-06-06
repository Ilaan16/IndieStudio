/*
** EPITECH PROJECT, 2022
** Indie
** File description:
** SceneOption
*/

#include "SceneOption.hpp"

namespace indie {
    SceneOption::SceneOption()
    {
        _entities.emplace(std::vector{type::DRAWABLE, type::CLICKABLE}, createButton);
        _entities.emplace(std::vector{type::DRAWABLE, type::CLICKABLE}, createButton);
        _entities.emplace(std::vector{type::DRAWABLE, type::CLICKABLE}, createButton);
        _entities.emplace(std::vector{type::DRAWABLE, type::CLICKABLE}, createSlider);
        _entities.emplace(std::vector{type::DRAWABLE, type::CLICKABLE}, createSlider);
    }

    SceneOption::~SceneOption()
    {
    }

    std::shared_ptr<Entity> SceneOption::createButton()
    {
        std::shared_ptr<Entity> Button = std::make_shared<indie::Entity>();
        Button->addEventListener(Button);
        Button->addSprite2D(Button, "uwu.png");
        return Button;
    }

    std::shared_ptr<Entity> SceneOption::createSlider()
    {
        std::shared_ptr<Entity> Slider = std::make_shared<indie::Entity>();
        Slider->addEventListener(Slider);
        Slider->addSprite2D(Slider, "uwu.png");
        return Slider;
    }

    std::map<std::vector<indie::type>, std::shared_ptr<indie::Entity>> &SceneOption::getEntities()
    {
        return (this->_entities);
    }
}