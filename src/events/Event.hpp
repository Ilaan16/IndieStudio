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
    #include "raylib/Window.hpp"
    #include "raylib/RMusicManager.hpp"

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
            GoScene(const Scenes &scene, bool keepTime = false): scene(scene), keepTime(keepTime) {}
            ~GoScene() = default;

            void useDown(std::unique_ptr<AScene> &ownScene, std::shared_ptr<Entity> &ownEntity) noexcept final;
            void usePressed(std::unique_ptr<AScene> &ownScene, std::shared_ptr<Entity> &ownEntity) noexcept final;
            void useReleased(std::unique_ptr<AScene> &ownScene, std::shared_ptr<Entity> &ownEntity) noexcept final;
            void useNone(std::unique_ptr<AScene> &ownScene, std::shared_ptr<Entity> &ownEntity) noexcept final;

        private:
            Scenes scene;
            bool keepTime;
    };
    class Slider : public MouseEvent {
        public:
            Slider(raylib::Window &window): mouse({0,0}), mouse_last({0,0}), window(window) {}
            ~Slider() = default;

            void useDown(std::unique_ptr<AScene> &ownScene, std::shared_ptr<Entity> &ownEntity) noexcept final;
            void usePressed(std::unique_ptr<AScene> &ownScene, std::shared_ptr<Entity> &ownEntity) noexcept final;
            void useReleased(std::unique_ptr<AScene> &ownScene, std::shared_ptr<Entity> &ownEntity) noexcept final;
            void useNone(std::unique_ptr<AScene> &ownScene, std::shared_ptr<Entity> &ownEntity) noexcept final;

        private:
            raylib::Window window;
            Vector2 mouse;
            Vector2 mouse_last;
    };
    class FullScreen : public MouseEvent {
        public:
            FullScreen(raylib::Window &window): window(window) {}
            ~FullScreen() = default;

            void useDown(std::unique_ptr<AScene> &ownScene, std::shared_ptr<Entity> &ownEntity) noexcept final;
            void usePressed(std::unique_ptr<AScene> &ownScene, std::shared_ptr<Entity> &ownEntity) noexcept final;
            void useReleased(std::unique_ptr<AScene> &ownScene, std::shared_ptr<Entity> &ownEntity) noexcept final;
            void useNone(std::unique_ptr<AScene> &ownScene, std::shared_ptr<Entity> &ownEntity) noexcept final;

        private:
            raylib::Window window;
    };
}

#endif /* !EVENT_HPP_ */
