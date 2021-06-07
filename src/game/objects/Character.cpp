/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** Character
*/

#include "Character.hpp"

using namespace game;

objects::Character::Character(
                        const std::string &id,
                        const std::string &name,
                        const Vector3T<float> &pos
                        ) : gameEngine::objects::Moveable(id)
{
    this->_name = name;
    this->setPostion(pos);
}

objects::Character::~Character()
{
}

//getter

std::string objects::Character::getName() const noexcept
{
    return this->_name;
}

ssize_t objects::Character::getScore() const noexcept
{
    return this->_score;
}

//setter
void objects::Character::addScore(const size_t value) noexcept
{
    this->_score += value;
}

void objects::Character::subScore(const size_t value) noexcept
{
    this->_score -= value;
}


