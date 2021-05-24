/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** BCamera
*/

#include "BCamera.hpp"

using namespace gameEngine;

encapsulation::BCamera::BCamera()
{
}

encapsulation::BCamera::BCamera(const BCamera &ref)
{
    this->_camera = ref.getObj();
}

encapsulation::BCamera &encapsulation::BCamera::operator=(const BCamera &ref)
{
    if (this == &ref)
        return *this;
    this->_camera = ref.getObj();
    return *this;
}

encapsulation::BCamera::~BCamera()
{
}

//-----------------

//GETTER

Camera encapsulation::BCamera::getObj() const noexcept
{
    return this->_camera;
}

//------------------

//SETTER

void encapsulation::BCamera::setPosition(float x, float y, float z) noexcept
{
   Vector3 vec = {x, y, z};

   this->_camera.position = vec;
}

void encapsulation::BCamera::setTarget(float x, float y, float z) noexcept
{
   Vector3 vec = {x, y, z};

   this->_camera.target = vec;
}

void encapsulation::BCamera::setUp(float x, float y, float z) noexcept
{
    Vector3 vec = {x, y, z};

    this->_camera.up = vec;
}

void encapsulation::BCamera::setFovy(float fov) noexcept
{
    this->_camera.fovy = fov;
}

void encapsulation::BCamera::setProjection(CameraProjection projection) noexcept
{
    this->_camera.projection = projection;
}
