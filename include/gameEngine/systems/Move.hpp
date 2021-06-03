/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** Move
*/

#ifndef MOVE_HPP_
#define MOVE_HPP_

#include "Vector3T.hpp"
#include <cstddef>
#include <unordered_map>
#include <stdexcept>

namespace gameEngine
{
    namespace systems
    {
        class Move;

        typedef void (*moveFct)(Vector3T<float> &pos, const float velocity, std::size_t tick);

        class Move
        {
        public:
            typedef enum e_direction {
                RIGHT,      //x+
                LEFT,       //x-
                FORWARD,    //y+
                BACKWARD,   //y-
                UP,         //z+
                DOWN        //z-
            } direction_e;

            static void move(Vector3T<float> &pos, const Vector3T<float> velocity, std::size_t tick) noexcept;

            static void moveDirection(Vector3T<float> &pos, const float velocity,
                                     std::size_t tick, const direction_e direction);

            static void moveRight(Vector3T<float> &pos, const float velocity, std::size_t tick) noexcept;
            static void moveLeft(Vector3T<float> &pos, const float velocity, std::size_t tick) noexcept;
            static void moveForward(Vector3T<float> &pos, const float velocity, std::size_t tick) noexcept;
            static void moveBackward(Vector3T<float> &pos, const float velocity, std::size_t tick) noexcept;
            static void moveUp(Vector3T<float> &pos, const float velocity, std::size_t tick) noexcept;
            static void moveDown(Vector3T<float> &pos, const float velocity, std::size_t tick) noexcept;
        private:
            static const std::unordered_map<direction_e, moveFct> _movement;

        };

    } // namespace systems
} // namespace gameEngine



#endif /* !MOVE_HPP_ */
