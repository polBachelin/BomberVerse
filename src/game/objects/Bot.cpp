/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** Bot
*/

#include "Bot.hpp"

using namespace game::objects;

Bot::Bot(const std::string &id, const std::string &name, const std::string &text,
         const std::string &model, const std::string &animWalk, const std::string &animIdle,
         std::vector<std::shared_ptr<game::objects::Tile>> &map, int level, Vector<int> sizeMap)
        : Character(id, name, text, model, animWalk, animIdle), Brain(map, level, sizeMap)
{
    _goal = GET_MAP_POS_Z(sizeMap, this->getTransform().getPosition());
    //_key_event.insert({NULL_EVENT, &Character::stand});
}

Bot::~Bot()
{
}

void Bot::update()
{
    this->updateMaps();
    if (!_isMoving) {
        _timer = 0;
    }
    this->setCurrentEvent(takeDecision(this->getTransform().getPosition()));
    //std::cout << "Je me deplace en" << printEvent(this->_currentEvent) << std::endl;
    this->setIsMoving(false);
    //this->printEvent(_currentEvent);
    handleEvent();
    checkLives();
    updateModelAnimation();
}

game::Tag_e Bot::getTag() const noexcept
{
    return game::Tag_e::BOT;
}
