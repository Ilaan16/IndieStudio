/*
** EPITECH PROJECT, 2022
** indie
** File description:
** scenemenu
*/

#ifndef scenemenudef
#define scenemenudef

#include <array>
#include "AScene.hpp"

namespace indie
{
    enum menu_e {
        START,
        LOAD,
        OPTION,
        QUIT
    };

    static const std::unordered_map<menu_e, Scenes> _returnScene {
        {menu_e::START, Scenes::NEW_GAME},
        {menu_e::LOAD, Scenes::GAME},
        {menu_e::OPTION, Scenes::OPTION},
        {menu_e::QUIT, Scenes::QUIT}
    };

    class SceneMenu : public AScene {
        public:
            SceneMenu();
            ~SceneMenu();
            Scenes run(Raylib &lib, Scenes const &prevScene) final;
            std::vector<std::unique_ptr<indie::Entity>> &getEntities();
            bool clockGame();

        protected:
        private:
            std::size_t _select;
            static const std::vector<std::array<std::pair<float, float>, 2>> _menuPos;
            static const std::vector<std::string> _assetsPath;
            static const std::vector<std::string> _menuText;
    };
}
#endif /* !scenemenudef */
