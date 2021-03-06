/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** Button
*/

#include "Button.hpp"

using namespace gameEngine::encapsulation;
using namespace gameEngine;

Button::Button(const Vector<float> &size, const Vector<float> &pos,
                const std::string &content, const int &textSize, const BColor &color, const BColor &selectColor, const std::string &textureFile,
                float rotation, int nbFrames) : AButton(size, pos, content, textSize, color, selectColor, rotation)
{
    _frameRec = std::make_shared<BRectangle>(size, Vector<float>(0, 0), color, rotation);
    _texture = std::make_shared<BTexture2D>();
    if (textureFile != "") {
        _texture->loadFromFile(textureFile);
    }
    _nbFrames = nbFrames;
    _buttonPressed = false;
}

Button::Button(const Vector<float> &size, const Vector<float> &pos,
                const BText &content, const BColor &color, const BColor &selectColor, const std::string &textureFile,
                float rotation, int nbFrames) : AButton(size, pos, content, color, selectColor, rotation)
{
    _frameRec = std::make_shared<BRectangle>(size, Vector<float>(0, 0), color, rotation);
    _texture = std::make_shared<BTexture2D>();
    if (textureFile != "") {
        _texture->loadFromFile(textureFile);
    }
    _nbFrames = nbFrames;
    _buttonPressed = false;
}

Button::Button(const std::shared_ptr<BTexture2D> &text, const std::shared_ptr<BRectangle> &rect, const std::shared_ptr<BText> &content)
: AButton(rect, content)
{
    _texture = text;
    _rectangle = rect;
    _content = content;
    _frameRec = std::make_shared<BRectangle>(*rect);
    _state = IButton::State::NORMAL;
    _nbFrames = 1;
    _buttonPressed = false;
}

Button::~Button()
{}

Button &Button::operator=(const Button &ref)
{
    if (this == &ref)
        return *this;
    *_content = ref.getContent();
    *_texture = ref.getTexture();
    _nbFrames = ref.getNbFrames();
    _state = ref.getState();
    _buttonPressed = ref.getButtonPressed();
    *_rectangle = *ref._rectangle;
    *_frameRec = ref.getFrameRect();
    return *this;
}

//GETTER
bool Button::getButtonPressed() const
{
    return _buttonPressed;
}

BTexture2D Button::getTexture() const
{
    return *_texture;
}

BRectangle Button::getFrameRect() const
{
    return *_frameRec;
}

int Button::getNbFrames() const
{
    return _nbFrames;
}

//SETTERS
void Button::setNbFrames(const int &nb)
{
    _nbFrames = nb;
}

void Button::setFrameRect(const BRectangle &rect)
{
    *_frameRec = rect;
}

void Button::setFrameRectSize(const Vector<float> &size)
{
    _frameRec->setTransform()._scale._x = size._x;
    _frameRec->setTransform()._scale._y = size._y;
}

//CHECKERS
void Button::update()
{
    updateState();
}

//DRAW
void Button::draw()
{
    if (!_enabled)
        return;
    Vector<float> pos(
        _rectangle->getTransform().getPosition()._x,
        _rectangle->getTransform().getPosition()._y);
    Vector<float> scaling(1, 1);

    if (_texture->isLoad()) {
        if (_enabled == false)
            _texture->setColor(LIGHTGRAY);
        else
            _texture->setColor(WHITE);
        _texture->setPos(Vector<int>((int)pos._x, (int)pos._y));
        if (_texture->getSize()._x >= _rectangle->getWidth())
            scaling._x = _rectangle->getWidth() / _texture->getSize()._x;
        if (_texture->getSize()._y >= _rectangle->getHeight())
            scaling._y = _rectangle->getHeight() / _texture->getSize()._y;
        if (scaling._x == 1 && scaling._y == 1) {
            _texture->drawRect(*_frameRec, pos);
        } else {
            _texture->drawEx(scaling);
        }
        _content->draw();
    } else {
        drawButtonRect();
        drawButtonText();
    }
    drawOutline();
}
