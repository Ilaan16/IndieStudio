/*
** EPITECH PROJECT, 2022
** IndieStudio
** File description:
** EntitiesFactory
*/

#ifndef ENTITIESFACTORY_HPP_
#define ENTITIESFACTORY_HPP_

#include "components/Renderable.hpp"
#include "AScene.hpp"

namespace indie {
    class EntitiesFactory {
        public:
            EntitiesFactory();
            ~EntitiesFactory();
            void createButton(std::map<typeEntity ,std::vector<std::shared_ptr<Entity>>> &_entities, std::string text, Vector3D pos, Vector3D rect, Vector3D posRect, Vector3D posText);
            void createSlider(std::map<typeEntity ,std::vector<std::shared_ptr<Entity>>> &_entities, std::string text, Vector3D pos, Vector3D rect, Vector3D posRect, Vector3D posText);
            void createLogo(std::map<typeEntity ,std::vector<std::shared_ptr<Entity>>> &_entities, std::string path, std::string text, Vector3D pos, Vector3D rect, Vector3D posRect);
            void createBackground(std::map<typeEntity ,std::vector<std::shared_ptr<Entity>>> &_entities, std::string path);
            void createPlayer2D(std::map<typeEntity ,std::vector<std::shared_ptr<Entity>>> &_entities, std::string text, Vector3D pos, Vector3D rect, Vector3D posRect, Vector3D posText);
            void createPlayer(std::map<typeEntity ,std::vector<std::shared_ptr<Entity>>> &_entities, std::string model, std::string texture);
        protected:
        private:
    };
}

#endif /* !ENTITIESFACTORY_HPP_ */
