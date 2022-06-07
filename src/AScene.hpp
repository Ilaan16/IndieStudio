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

#include "Raylib.hpp"
#include "IScene.hpp"
#include "Entity.hpp"

namespace indie
{
    enum type {
        DRAWABLE,
        MOVABLE,
        PLAYABLE
    };

    class AScene : public IScene {
        public:
            AScene() = default;
            virtual ~AScene() = default;
            virtual Scenes run(Raylib &lib, Scenes const &prevScene) = 0;
            virtual std::map<type ,std::vector<std::shared_ptr<indie::Entity>>> &getEntities() = 0;
        protected:
            std::map<type ,std::vector<std::shared_ptr<indie::Entity>>> _entities;
        private:
    };
}
#endif /* !ascenedef */
