/*
** EPITECH PROJECT, 2022
** indie
** File description:
** Player
*/

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

    #include <raylib.h>
    #include <vector>
    #include <random>
    #include <raymath.h>
    #include "Bomb.hpp"

    namespace indie {
        typedef struct {
            float Lifetime;
        } Timer;

        class Player {
            public:
                Vector3 _playerPosition;
                Vector3 _playerSize;
                Model _modelPlayer;
                Texture2D _texturePlayer;

                void StartTimer(Timer* timer, float lifetime);
                void UpdateTimer(Timer* timer);
                bool TimerDone(Timer* timer);

                bool _endup;
                bool _explosion;
                bool _putBomb;
                Vector3 _tnt;

                Bomb _up;
                Bomb _down;
                Bomb _left;
                Bomb _right;

                Timer _timer;
                float _life;
                Player();
                ~Player();
            protected:
            private:
        };
    }

#endif /* !PLAYER_HPP_ */
