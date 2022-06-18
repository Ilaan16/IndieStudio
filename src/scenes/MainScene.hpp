/*
** EPITECH PROJECT, 2022
** indie
** File description:
** main
*/

#ifndef mainscenedef
#define mainscenedef

#include "scenes/AScene.hpp"
#include "events/Event.hpp"
#include "raylib/REvent.hpp"

namespace indie
{
    class MainScene : public AScene {
        public:
            MainScene();
            ~MainScene();

            std::map<typeEntity ,std::vector<std::shared_ptr<indie::Entity>>> &getEntities();
            void update(int *sceneId, std::map<indie::typeEntity, std::vector<std::shared_ptr<indie::Entity>>> &entity);
            void putBomb(int *sceneId, float *x, float *y, float *z, Player *player, Camera3D camera, Texture2D cubicmap, Color *mapPixels, std::vector<Vector3> collision_entity);
            bool checkHit(Vector3 position, float *position1, float *position2, float movement, int *explose, Texture2D cubicmap, Color *mapPix);
            void hitPlayer(int *sceneId, Vector3 position, std::vector<Vector3> collision_entity);
            void createPlayer();
            void createCamera();
        protected:
        private:
            void addEventToLastEntity(const KeyboardKey &key, std::shared_ptr<Event> &evt);
    };
}

#endif /* !mainscenedef */
