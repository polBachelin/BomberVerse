/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** BoxCollider
*/

#include "BoxCollider.hpp"

using namespace gameEngine::component;

BoxCollider::BoxCollider(const Vector3T<float> &min, const Vector3T<float> &max, bool enabled) :
_box(min, max), Collider(enabled)
{}

BoxCollider::~BoxCollider()
{}

gameEngine::encapsulation::BBoundingBox BoxCollider::getBoundingBox() const
{
    return _box;
}

bool BoxCollider::isColliding(const gameEngine::encapsulation::BBoundingBox &ref)
{
    return _box.checkCollision(ref);
}