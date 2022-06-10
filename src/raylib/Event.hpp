/*
** EPITECH PROJECT, 2022
** Indie
** File description:
** Event
*/

#ifndef EVENT_HPP_
    #define EVENT_HPP_

    #include "raylib.h"

namespace indie {

    enum ButtonState
    {
        None = -1,
        Pressed,
        Released
    };

    namespace raylib {
        class Event {
            public:
                Event();
                ~Event();

            protected:
            private:
        };
    }
}

#endif /* !EVENT_HPP_ */
