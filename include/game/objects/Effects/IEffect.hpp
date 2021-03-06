/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** IEffect
*/

#ifndef IEFFECT_HPP_
#define IEFFECT_HPP_

#include "Vector3T.hpp"

namespace game
{
    namespace interfaces
    {
        class IEffect {
        public:
            virtual ~IEffect() = default;

            virtual std::string getType() const noexcept = 0;

            virtual int getLife() const noexcept = 0;
            virtual int getMaxLife() const noexcept = 0;
            virtual int getBlastPower() const noexcept = 0;
            virtual int getNbBomb() const noexcept = 0;
            virtual int getBombPass() const noexcept = 0;
            virtual Vector3T<float> getSpeed() const noexcept = 0;
        };
    } // namespace interfaces
} // namespace game

#endif /* !IEFFECT_HPP_ */
