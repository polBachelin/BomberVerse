/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** PowerUpTile
*/

#include "PowerUpTile.hpp"

using namespace game::objects;

PowerUpTile::PowerUpTile(const std::shared_ptr<gameEngine::encapsulation::BModel> &model,
            const std::shared_ptr<gameEngine::encapsulation::BTexture2D> &texture,
            const game::Tag &type,
            const Vector3T<float> &position,
            const Vector3T<float> &rotation,
            const Vector3T<float> &scale,
            float idleSpeed,
            float minHeight,
            float maxHeight
        )
    : Tile(model, texture, type, position, rotation, scale)
{
    _idleSpeed = idleSpeed;
    _minHeight = minHeight;
    _maxHeight =  maxHeight;
    _speed._y = _idleSpeed;
    _collider.getBoundingBox().setBoundingBox(
        {position._x - scale._x * TILESIZE * TILESCALE,
        position._y,
        position._z - scale._z * TILESIZE * TILESCALE},
        {position._x + scale._x * TILESIZE * TILESCALE,
        position._y,
        position._z + scale._z * TILESIZE * TILESCALE});
}

PowerUpTile::PowerUpTile(const PowerUpTile &ref)
    : Tile(ref)
{
    _idleSpeed = ref._idleSpeed;
    _minHeight = ref._minHeight;
    _maxHeight =  ref._maxHeight;
    _speed._y = _idleSpeed;
    _collider.getBoundingBox().setBoundingBox(
        {this->getTransform().getPosition()._x - this->getTransform().getScale()._x * TILESIZE * TILESCALE,
        this->getTransform().getPosition()._y,
        this->getTransform().getPosition()._z - this->getTransform().getScale()._z * TILESIZE * TILESCALE},
        {this->getTransform().getPosition()._x + this->getTransform().getScale()._x * TILESIZE * TILESCALE,
        this->getTransform().getPosition()._y,
        this->getTransform().getPosition()._z + this->getTransform().getScale()._z * TILESIZE * TILESCALE});
}

PowerUpTile::~PowerUpTile()
{

}

//-------------------

void PowerUpTile::update()
{
    _transform._position = _transform._position + _speed;
    _transform._rotation = _transform._rotation + _rotationSpeed;
    checkHeight();
}

void PowerUpTile::checkHeight() noexcept
{
    if (_transform._position._y >= _maxHeight && _speed._y > 0)
        _speed._y = -_idleSpeed;
    else if (_transform._position._y <= _minHeight && _speed._y < 0)
        _speed._y = _idleSpeed;
}
