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

#include "Raylib.hpp"
#include "IScene.hpp"
#include "Entity.hpp"

namespace indie
{
    class AScene : public IScene {
        public:
            AScene() = default;
            virtual ~AScene() = default;
            virtual Scenes run(Raylib &lib, Scenes const &prevScene) = 0;

        protected:
            std::vector<std::unique_ptr<indie::Entity>> _entities;
        private:
    };
}
#endif /* !ascenedef */
