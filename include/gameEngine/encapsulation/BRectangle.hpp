/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** BRectangle
*/

#ifndef BRECTANGLE_HPP_
#define BRECTANGLE_HPP_

#include <iostream>
#include <string>
#include <stdexcept>
#include "raylib.h"
#include "BColor.hpp"

namespace gameEngine
{
    namespace encapsulation
    {
        class BRectangle
        {
        public:
            BRectangle(float width, float height,
                        float x = 0,
                        float y = 0,
                        const BColor &color = BLACK,
                        float rotation = 0
                        );
            BRectangle(const BRectangle &ref);
            BRectangle &operator=(const BRectangle &ref);
            ~BRectangle();

            //getter
                [[nodiscard]] Rectangle getObj() const noexcept;
                [[nodiscard]] float getWidth() const noexcept;
                [[nodiscard]] float getHeight() const noexcept;
                [[nodiscard]] float getX() const noexcept;
                [[nodiscard]] float getY() const noexcept;
                [[nodiscard]] float getRotation() const noexcept;
                [[nodiscard]] BColor getColor() const noexcept;

            //setter
                void setX(const float &x) noexcept;
                void setY(const float &y) noexcept;
                void setWidth(const float &width) noexcept;
                void setHeight(const float &height) noexcept;
                void setRotation(const float &rotation) noexcept;
                void setColor(const BColor &color) noexcept;

            //draw
                void draw() const noexcept;

            //collision
                bool checkCollision(const BRectangle &other) const noexcept;

        protected:
        private:
            float _x;
            float _y;
            float _width;
            float _height;
            float _rotation;
            BColor _color;
        };
    } // namespace encapsulation

} // namespace gameEngine

std::ostream& operator<<(std::ostream& out, const gameEngine::encapsulation::BRectangle &ref);


#endif /* !BRECTANGLE_HPP_ */