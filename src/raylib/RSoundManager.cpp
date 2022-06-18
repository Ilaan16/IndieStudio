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
        this->_music.looping = true;
        PlayMusicStream(this->_music);
    }

    RSoundManager::~RSoundManager()
    {
        UnloadMusicStream(this->_music);
    }

    void RSoundManager::playSong()
    {
        UpdateMusicStream(this->_music);
    }

    void RSoundManager::PauseResumeTheme()
    {
        if (!_isPause) {
            PauseMusicStream(this->_music);
            this->_isPause = true;
        } else {
            ResumeMusicStream(this->_music);
            this->_isPause = false;
        }
    }
}