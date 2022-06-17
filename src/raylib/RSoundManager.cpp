/*
** EPITECH PROJECT, 2022
** SoungerManager
** File description:
** SoundManager
*/

#include "RSoundManager.hpp"

namespace indie {
    RSoundManager::RSoundManager(const std::string &filename) : _isPause(true)
    {
        this->_music = LoadMusicStream(filename.c_str());
        this->_music.looping = false;
    }

    RSoundManager::~RSoundManager()
    {
        UnloadMusicStream(this->_music);
    }

    void RSoundManager::playSong()
    {
        if (RSoundManager::isMuteSong() == true) {
            PlayMusicStream(this->_music);
            this->_isPause = false;
        }
    }

    void RSoundManager::PauseResumeTheme()
    {
        if (RSoundManager::isMuteSong() == false)
            PauseMusicStream(this->_music);
        else
            ResumeMusicStream(this->_music);
    } 
}