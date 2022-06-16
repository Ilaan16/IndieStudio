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
    #include "Entity.hpp"
    #include "scenes/AScene.hpp"

namespace indie {
    class Event {
        public:
            virtual ~Event() = default;

            virtual void useDown(std::unique_ptr<AScene> &ownScene, std::shared_ptr<Entity> &ownEntity) noexcept = 0;
            virtual void usePressed(std::unique_ptr<AScene> &ownScene, std::shared_ptr<Entity> &ownEntity) noexcept = 0;
            virtual void useReleased(std::unique_ptr<AScene> &ownScene, std::shared_ptr<Entity> &ownEntity) noexcept = 0;
    };

    class MouseEvent : public Event {
        public:
            virtual ~MouseEvent() = default;

            virtual void useNone(std::unique_ptr<AScene> &ownScene, std::shared_ptr<Entity> &ownEntity) noexcept = 0;
    };

    class TestKey : public Event {
        public:
            TestKey() = default;
            ~TestKey() = default;

            void useDown(std::unique_ptr<AScene> &ownScene, std::shared_ptr<Entity> &ownEntity) noexcept final;
            void usePressed(std::unique_ptr<AScene> &ownScene, std::shared_ptr<Entity> &ownEntity) noexcept final;
            void useReleased(std::unique_ptr<AScene> &ownScene, std::shared_ptr<Entity> &ownEntity) noexcept final;
    };

    class TestClick : public MouseEvent {
        public:
            TestClick() = default;
            ~TestClick() = default;

            void useDown(std::unique_ptr<AScene> &ownScene, std::shared_ptr<Entity> &ownEntity) noexcept final;
            void usePressed(std::unique_ptr<AScene> &ownScene, std::shared_ptr<Entity> &ownEntity) noexcept final;
            void useReleased(std::unique_ptr<AScene> &ownScene, std::shared_ptr<Entity> &ownEntity) noexcept final;
            void useNone(std::unique_ptr<AScene> &ownScene, std::shared_ptr<Entity> &ownEntity) noexcept final;
    };

    class GoScene : public MouseEvent {
        public:
            GoScene(const Scenes &scene): scene(scene) {}
            ~GoScene() = default;

            void useDown(std::unique_ptr<AScene> &ownScene, std::shared_ptr<Entity> &ownEntity) noexcept final;
            void usePressed(std::unique_ptr<AScene> &ownScene, std::shared_ptr<Entity> &ownEntity) noexcept final;
            void useReleased(std::unique_ptr<AScene> &ownScene, std::shared_ptr<Entity> &ownEntity) noexcept final;
            void useNone(std::unique_ptr<AScene> &ownScene, std::shared_ptr<Entity> &ownEntity) noexcept final;

        private:
            Scenes scene;
    };
    class Slider : public MouseEvent {
        public:
            Slider() = default;
            ~Slider() = default;

            void useDown(std::unique_ptr<AScene> &ownScene, std::shared_ptr<Entity> &ownEntity) noexcept final;
            void usePressed(std::unique_ptr<AScene> &ownScene, std::shared_ptr<Entity> &ownEntity) noexcept final;
            void useReleased(std::unique_ptr<AScene> &ownScene, std::shared_ptr<Entity> &ownEntity) noexcept final;
            void useNone(std::unique_ptr<AScene> &ownScene, std::shared_ptr<Entity> &ownEntity) noexcept final;

        private:
            Vector2 mouse;
    };
}

#endif /* !EVENT_HPP_ */
