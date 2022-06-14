/*
** EPITECH PROJECT, 2022
** inide
** File description:
** scenemanage
*/

#ifndef ascenedef
    #define ascenedef

    #include <string>
    #include <vector>
    #include <memory>
    #include <map>

    #include "IScene.hpp"
    #include "Entity.hpp"
    #include "raylib/REvent.hpp"

namespace indie {
    enum typeEntity {
        DRAWABLE,
        MOVABLE,
        PLAYABLE,
        CLICKABLE
    };

    class AScene : public IScene {
        public:
            virtual ~AScene() = default;
            virtual std::map<typeEntity ,std::vector<std::shared_ptr<indie::Entity>>> &getEntities() = 0;
            raylib::REvent events;
        protected:
            std::map<typeEntity ,std::vector<std::shared_ptr<indie::Entity>>> _entities;
        private:
    };
}
#endif /* !ascenedef */
