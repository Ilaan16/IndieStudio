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

                Texture2D _cubicmap;
                Color *_mapPixels;
                
                int _explosion;
                bool _endup;

                bool _putBomb;
                Vector3 _tnt;

                Bomb _up;
                bool _up_stillalive;
                Bomb _down;
                bool _down_stillalive;
                Bomb _left;
                bool _left_stillalive;
                Bomb _right;
                bool _right_stillalive;

                Timer _timer;
                float _life;
                Player();
                ~Player();
            protected:
            private:
        };
    }

#endif /* !PLAYER_HPP_ */
