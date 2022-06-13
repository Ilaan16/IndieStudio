/*
** EPITECH PROJECT, 2022
** Indie
** File description:
** Event
*/

#ifndef EVENT_HPP_
    #define EVENT_HPP_

    #include <memory>
    #include "raylib/REvent.hpp"

namespace indie {
    class AScene;

    class Event {
        public:
            virtual ~Event() = default;

            virtual void useDown(std::unique_ptr<AScene> &ownScene) noexcept = 0;
            virtual void usePressed(std::unique_ptr<AScene> &ownScene) noexcept = 0;
            virtual void useReleased(std::unique_ptr<AScene> &ownScene) noexcept = 0;
    };
    class TestKey : public Event {
        public:
            TestKey() = default;
            ~TestKey() = default;

            void useDown(std::unique_ptr<AScene> &ownScene) noexcept final;
            void usePressed(std::unique_ptr<AScene> &ownScene) noexcept final;
            void useReleased(std::unique_ptr<AScene> &ownScene) noexcept final;
    };
}

#endif /* !EVENT_HPP_ */
