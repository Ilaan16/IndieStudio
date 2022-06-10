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
            void createButton(std::map<typeEntity ,std::vector<std::shared_ptr<Entity>>> &_entities, const char *text, Vector3D pos, Vector3D rect, Vector3D posRect);
            void createBackground(std::map<typeEntity ,std::vector<std::shared_ptr<Entity>>> &_entities, const char *path);

        protected:
        private:
    };
}

#endif /* !ENTITIESFACTORY_HPP_ */
