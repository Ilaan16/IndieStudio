/*
** EPITECH PROJECT, 2022
** dev
** File description:
** The interface IComponent is used to create and manipulate all Game entities components.
** the interface allows the use of any components as an IComponent and then has no methods.
*/

#ifndef ICOMPONENT_HPP_
#define ICOMPONENT_HPP_

namespace indie
{
    class IComponent
    {
    public:
        virtual ~IComponent() = default;

    protected:
    private:
    };
    /* There are several components inheriting from IComponent and used by game and graphical libraries. To create and use libraries you must handle all components. */
}

#endif /* !ICOMPONENT_HPP_ */
