/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** SoundManager
*/

#ifndef RSOUNDMANAGER_HPP_
    #define RSOUNDMANAGER_HPP_

    #include <raylib.h>
    #include <iostream>
    #include <map>

    namespace indie {
        class RSoundManager {
            public:
                enum Theme {
                    MENU,
                    GAME
                };
                RSoundManager(const std::string &filename);
                ~RSoundManager();
                bool isMuteSong() {return _isPause;};
                void playSong();
                void PauseResumeTheme();
            private:
                bool _isPause;
                Music _music;
        };
    }

#endif /* !RSOUNDMANAGER_HPP_ */