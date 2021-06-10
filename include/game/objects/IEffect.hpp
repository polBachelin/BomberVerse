/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** IEffect
*/

#ifndef IEFFECT_HPP_
#define IEFFECT_HPP_

namespace game
{
    typedef enum EffectType {
        HEALTH,
    } EffectType_e;
} // namespace game

namespace game
{
    namespace interfaces
    {
        class IEffect {
        public:
            virtual ~IEffect() = default;

            virtual game::EffectType_e getType() const noexcept = 0;

            virtual int getHealth() const noexcept = 0;
        };
    } // namespace interfaces
} // namespace game

#endif /* !IEFFECT_HPP_ */
