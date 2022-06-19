/*
** EPITECH PROJECT, 2022
** indie
** File description:
** iscene
*/

#ifndef iscenedef
    #define iscenedef

namespace indie {
    enum class Scenes {
        QUIT = -1,
        SPLASH = 0,
        MENU,
        PERSO,
        GAME,
        OPTION,
        END
    };

    class IScene {
        public:
            virtual ~IScene() {};
        protected:
        private:
    };
}
#endif /* !iscenedef */
