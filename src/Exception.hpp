/*
** EPITECH PROJECT, 2022
** indie
** File description:
** Exception
*/

#ifndef EXCEPTION_HPP_
#define EXCEPTION_HPP_

#include <string>

namespace indie
{
    class Exception : public std::exception {
        public:
            Exception(std::string const &message) noexcept {
                _message = message;
            }
            const char *what() const noexcept override { return _message.c_str(); }

        protected:
        private:
            std::string _message;
    };

    class AudioError : public Exception {
        public:
            AudioError(const std::string &message) noexcept : Exception(message) {}
    };

    class WindowError : public Exception {
        public:
            WindowError(const std::string &message) noexcept : Exception(message) {}
    };

    class TypeError : public Exception {
        public:
            TypeError(const std::string &message) noexcept : Exception(message) {}
    };
}

#endif /* !EXCEPTION_HPP_ */
