/*
** EPITECH PROJECT, 2022
** IndieStudio
** File description:
** ChoosePersoScene
*/

#include "scenes/ChoosePersoScene.hpp"
#include "Core.hpp"

namespace indie {

    ChoosePersoScene::ChoosePersoScene()
    {
        std::vector<std::shared_ptr<Entity>> drawable_ent;
        std::vector<std::shared_ptr<Entity>> clickable_ent;
        _entities.emplace(typeEntity::DRAWABLE, drawable_ent);
        _entities.emplace(typeEntity::CLICKABLE, clickable_ent);
        createBackground();
        createButton("./assets/menu/button.png", "P1", {80, 458, 0});
        createButton("./assets/menu/button.png", "P2", {1540, 458, 0});
        createButton("./assets/menu/button.png", "P3", {80, 993, 0});
        createButton("./assets/menu/button.png", "P4", {1540, 993, 0});
        createButton("./assets/menu/button.png", "START", {800, 905, 0});
        createButton("./assets/menu/player1.png", "", {545, 132, 0});
        createButton("./assets/menu/player2.png", "", {846, 132, 0});
    }

    ChoosePersoScene::~ChoosePersoScene()
    {
    }

    void ChoosePersoScene::createBackground()
    {
        std::shared_ptr<Entity> background = std::make_shared<Entity>();
        background->addRenderer("", "./assets/background.png", "", 0.0F, {0, 0, 0}, 0.0F, {0, 0, 0});
        _entities.find(indie::DRAWABLE)->second.push_back(background);
    }

    void ChoosePersoScene::createButton(const char *path ,const char *text, Vector3D pos)
    {
        std::shared_ptr<Entity> button = std::make_shared<Entity>();
        button->addRenderer("", path, text, 0.0F, pos, 0.0F, {100, 100, 0});
        _entities.find(indie::DRAWABLE)->second.push_back(button);
        _entities.find(indie::CLICKABLE)->second.push_back(button);
    }

    Scenes ChoosePersoScene::run(Scenes const &prevScene)
    {

    }

    std::map<typeEntity ,std::vector<std::shared_ptr<Entity>>> &ChoosePersoScene::getEntities()
    {
        return (this->_entities);
    }

}