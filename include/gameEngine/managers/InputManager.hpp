/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** KeyboardManager
*/

#ifndef KEYBOARDMANAGER_HPP_
#define KEYBOARDMANAGER_HPP_

#include "gameEngine/interfaces/IInputManager.hpp"
#include "gameEngine/interfaces/IInput.hpp"
#include <unordered_map>
#include "raylib.h"
#include <string>

namespace game
{
    namespace managers
    {
        template <typename E>
        class InputManager : public gameEngine::Interfaces::IInputManager
        {
            public:
                InputManager(gameEngine::interfaces::IInput *input, E interpret_values, std::string id={0}) : input(input) {}
                ~InputManager();
                bool isKeyPressed(int) final;
                bool isKeyReleased(int) final;
                int getKeyPressed() final;
                bool mapDefaultKeys(int, int);
                template <typename E>
                bool game::managers::InputManager::mapKey(int key, E interpret_value) final;
                {}

            private:
                std::unordered_map<int,E> _Eventsmap;
                std::string _id;
                gameEngine::interfaces::IInput *input;
        };

    }
}

#endif /* !KEYBOARDMANAGER_HPP_ */