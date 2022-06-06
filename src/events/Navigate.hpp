/*
** EPITECH PROJECT, 2022
** Indie
** File description:
** Navigate
*/

#ifndef NAVIGATE_HPP_
    #define NAVIGATE_HPP_

    #include "KeyBoardEvent.hpp"

namespace indie {
    class NavigateUp : public KeyBoardEvent {
        public:
            NavigateUp() = default;
            ~NavigateUp() = default;

            void useKey() noexcept final;

        private:

    };

    class NavigateDown : public KeyBoardEvent {
        public:
            NavigateDown() = default;
            ~NavigateDown() = default;

            void useKey() noexcept final;

        private:

    };
}

#endif /* !NAVIGATE_HPP_ */
