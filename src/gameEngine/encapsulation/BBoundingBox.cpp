/*
** EPITECH PROJECT, 2021
** Indie_Studio
** File description:
** BBoundingBox
*/

#include "BBoundingBox.hpp"

using namespace gameEngine::encapsulation;

BBoundingBox::BBoundingBox(const Vector3T<float> &min, const Vector3T<float> &max)
    : _min(min), _max(max)
{
    Vector3 vec_min {min._x, min._y, min._z};
    Vector3 vec_max {max._x, max._y, max._z};

    _box.min = vec_min;
    _box.max = vec_max;
}

BBoundingBox::~BBoundingBox()
{
}

void BBoundingBox::setBoundingBox(const Vector3T<float> &min, const Vector3T<float> &max)
{
    Vector3 vec_min {min._x, min._y, min._z};
    Vector3 vec_max {max._x, max._y, max._z};

    _box.min = vec_min;
    _box.max = vec_max;
    _min = min;
    _max = max;
}

bool BBoundingBox::checkCollision(const BBoundingBox &ref)
{
    return CheckCollisionBoxes(_box, ref._box);
}

Vector3T<float> BBoundingBox::getMin() const
{
    return _min;
}

Vector3T<float> BBoundingBox::getMax() const
{
    return _max;
}
