/*
** EPITECH PROJECT, 2022
** inide
** File description:
** scenemanage
*/

#ifndef ascenedef
#define ascenedef

#include <vector>
#include <memory>
#include <string>
#include <map>

#include "IScene.hpp"
#include "Entity.hpp"

namespace indie
{
    enum typeEntity {
        DRAWABLE,
        MOVABLE,
        PLAYABLE,
        CLICKABLE
    };

    class AScene : public IScene {
        public:
            AScene() = default;
            virtual ~AScene() = default;
            virtual std::map<typeEntity ,std::vector<std::shared_ptr<indie::Entity>>> &getEntities() = 0;
        protected:
            std::map<typeEntity ,std::vector<std::shared_ptr<indie::Entity>>> _entities;
        private:
    };
}
#endif /* !ascenedef */
