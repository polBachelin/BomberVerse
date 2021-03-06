/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** ButtonManager
*/

#include "ButtonManager.hpp"

using namespace gameEngine::managers;
using namespace gameEngine::encapsulation;

ButtonManager::ButtonManager()
{}

ButtonManager::~ButtonManager()
{}

void ButtonManager::setEnabledButton(const std::string &content, bool enabled)
{
    for (auto it : _currentButtons) {
        if (it->getContent().getStr() == content) {
            it->setEnabled(enabled);
            break;
        }
    }
}

void ButtonManager::setCallBackForButton(const std::string &content, std::shared_ptr<game::managers::GameManager> info,
                                        std::function<void(std::shared_ptr<game::managers::GameManager> info)> func)
{
    for (auto it : _currentButtons) {
        if (it->getContent().getStr() == content) {
            it->setCallback(func, info);
        }
    }
}

bool ButtonManager::isButtonClicked(const Vector<float> &pos)
{
    for (auto it : _currentButtons) {
        if (it->getPos() == pos)
            return it->checkAction();
    }
    return false;
}

bool ButtonManager::isButtonClicked(const std::string &content)
{
    bool ret;

    for (auto it : _currentButtons) {
        if (it->getContent().getStr() == content) {
            ret = it->checkAction();
            return ret;
        }
    }
    return false;
}

void ButtonManager::createButton(const std::shared_ptr<BTexture2D> &texture, const std::shared_ptr<BRectangle> &rect, const std::shared_ptr<BText> &content)
{
    std::shared_ptr<AButton> button = std::make_shared<Button>(texture, rect, content);

    _currentButtons.push_back(button);
    return;
}

void ButtonManager::pushButton(std::shared_ptr<gameEngine::encapsulation::AButton> button)
{
    _currentButtons.push_back(button);
}

std::vector<std::shared_ptr<gameEngine::encapsulation::AButton>> ButtonManager::getCurrentButtons() const
{
    return _currentButtons;
}

void ButtonManager::drawButtons()
{
    for (auto it : _currentButtons) {
        it->draw();
    }
}

void ButtonManager::updateButtons()
{
    for (auto it : _currentButtons) {
        it->update();
    }
}
