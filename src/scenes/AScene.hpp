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
    #include "events/Listener.hpp"

namespace indie {
    class AScene : public IScene {
        public:
            virtual ~AScene() = default;
            virtual std::map<typeEntity ,std::vector<std::shared_ptr<indie::Entity>>> &getEntities() = 0;
            raylib::REvent events;
            Listener listener;
        protected:
            std::map<typeEntity ,std::vector<std::shared_ptr<indie::Entity>>> _entities;
        private:
    };
}
#endif /* !ascenedef */
