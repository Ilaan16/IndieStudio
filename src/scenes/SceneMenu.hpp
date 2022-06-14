/*
** EPITECH PROJECT, 2022
** indie
** File description:
** scenemenu
*/

#ifndef scenemenudef
#define scenemenudef

#include <array>
#include <unordered_map>
#include "scenes/AScene.hpp"
#include "raylib/REvent.hpp"
#include "events/Event.hpp"

namespace indie
{
    // enum class menu_e {
    //     START,
    //     LOAD,
    //     OPTION,
    //     QUIT
    // };

    // static const std::unordered_map<menu_e, Scenes> _returnScene {
    //     {menu_e::START, Scenes::NEW_GAME},
    //     {menu_e::LOAD, Scenes::GAME},
    //     {menu_e::OPTION, Scenes::OPTION},
    //     {menu_e::QUIT, Scenes::QUIT}
    // };

    class SceneMenu : public AScene {
        public:
            SceneMenu();
            ~SceneMenu() = default;

            void createBackground();

            std::map<typeEntity ,std::vector<std::shared_ptr<Entity>>> &getEntities();
            bool clockGame();

        protected:
        private:
            void addEventToLastEntity(const MouseButton &mouse, std::unique_ptr<MouseEvent> &evt);
            std::size_t _select;
            static const std::vector<std::array<std::pair<float, float>, 2>> _menuPos;
            static const std::vector<std::string> _assetsPath;
            static const std::vector<std::string> _menuText;
    };
}
#endif /* !scenemenudef */
