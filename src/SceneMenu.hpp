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

namespace menu {

    enum menu_e {
        START,
        LOAD,
        OPTION,
        QUIT
    };
    class SceneMenu : public AScene {
        public:
            SceneMenu();
            ~SceneMenu();
            int run(Raylib &lib) final;
            void InitAssets();
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
