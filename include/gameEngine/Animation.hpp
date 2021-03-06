/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** Animation
*/

#ifndef ANIMATION_HPP_
#define ANIMATION_HPP_

#include "raylib.h"
#include <stdio.h>
#include <string>
#include "BModel.hpp"
#include "BTexture2D.hpp"
#include "BModelAnimation.hpp"
#include <vector>
#include "Tile.hpp"

namespace gameEngine {
    class Animation {
        public:
            Animation(
                const std::shared_ptr<encapsulation::BModel> &model,
                const std::shared_ptr<encapsulation::BModelAnimation> &anim);
            Animation(const Animation &ref);
            Animation(const std::shared_ptr<Animation> &ref);
            ~Animation();

            void updateModelAnimation();
            void refresh();

            void setPos(const Vector3T<float> &pos);
            Vector3T<float> getPos() const;

        private:
            std::shared_ptr<encapsulation::BModel> _model;
            std::shared_ptr<encapsulation::BModelAnimation> _anim;
            int _frameCounter;
            Vector3T<float> _pos;
    };
}

#endif /* !ANIMATION_HPP_ */
