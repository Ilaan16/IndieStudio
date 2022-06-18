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
        namespace raylib {
            class RMusicManager {
                public:
                    enum Theme {
                        MENU,
                        GAME
                    };
                    RMusicManager(const std::string &filename);
                    ~RMusicManager();
                    bool isMuteSong() {return _isPause;};
                    void playSong();
                    void PauseResumeTheme();
                    void setTime();
                    void markTime();

                private:
                    static float musicTime;
                    bool _isPause;
                    Music _music;
            };
        }
    }

#endif /* !RSOUNDMANAGER_HPP_ */