/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** BEvt
*/

#include "BEvt.hpp"

using namespace gameEngine::encapsulation;

bool BEvt::isKeyPressed(gameEngine::Key key)
{
    return IsKeyPressed(key);
}

bool BEvt::isKeyDown(gameEngine::Key key)
{
    return IsKeyDown(key);
}

bool BEvt::isKeyUp(gameEngine::Key key)
{
    return IsKeyUp(key);
}

bool BEvt::isKeyReleased(gameEngine::Key key)
{
    return IsKeyReleased(key);
}

gameEngine::Key BEvt::getKeyPressed(void)
{
    return (gameEngine::Key)GetKeyPressed();
}

bool BEvt::isMouseBtnPressed(gameEngine::Key key)
{
    return IsMouseButtonPressed(key);
}

bool BEvt::isMouseBtnReleased(gameEngine::Key key)
{
    return IsMouseButtonReleased(key);
}

bool BEvt::isMouseBtnDown(gameEngine::Key key)
{
    return IsMouseButtonDown(key);
}

bool BEvt::isMouseBtnUp(gameEngine::Key key)
{
    return IsMouseButtonUp(key);
}