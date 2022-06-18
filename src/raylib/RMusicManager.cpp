/*
** EPITECH PROJECT, 2022
** SoungerManager
** File description:
** SoundManager
*/

#include "RMusicManager.hpp"

namespace indie {
    namespace raylib {
        float RMusicManager::musicTime = 0;

        RMusicManager::RMusicManager(const std::string &filename) : _isPause(true)
        {
            this->_music = LoadMusicStream(filename.c_str());
            this->_music.looping = true;
            PlayMusicStream(this->_music);
        }

        RMusicManager::~RMusicManager()
        {
            UnloadMusicStream(this->_music);
        }

        void RMusicManager::playSong()
        {
            UpdateMusicStream(this->_music);
        }

        void RMusicManager::PauseResumeTheme()
        {
            if (!_isPause) {
                PauseMusicStream(this->_music);
                this->_isPause = true;
            } else {
                ResumeMusicStream(this->_music);
                this->_isPause = false;
            }
        }

        void RMusicManager::setTime()
        {
            if (musicTime != 0) {
                SeekMusicStream(this->_music, musicTime);
                musicTime = 0;
            }
        }

        void RMusicManager::markTime()
        {
            musicTime = GetMusicTimePlayed(this->_music);
        }
    }
}