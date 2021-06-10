/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** AEffect
*/

#include "AEffect.hpp"

using namespace game::objects;

AEffect::AEffect(game::EffectType_e type)
{
    _type = type;
}

AEffect::~AEffect()
{
}

//-----------------

//GETTER

game::EffectType_e AEffect::getType() const noexcept
{
    return this->_type;
}

int AEffect::getHealth() const noexcept
{
    return this->_health;
}
