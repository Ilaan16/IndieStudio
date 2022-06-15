/*
** EPITECH PROJECT, 2022
** IndieStudio
** File description:
** SceneEnd
*/

#ifndef SCENEEND_HPP_
#define SCENEEND_HPP_

#include "scenes/AScene.hpp"
#include <array>
#include <unordered_map>

namespace indie {

    class SceneEnd : public AScene {
        public:
            SceneEnd();
            ~SceneEnd();

            std::map<typeEntity ,std::vector<std::shared_ptr<indie::Entity>>> &getEntities();

        protected:
        private:
    };
}
#endif /* !SCENEEND_HPP_ */
