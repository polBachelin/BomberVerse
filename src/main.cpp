/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** main
*/

#include "raylib.h"
#include <iostream>
#include "gameEngine/encapsulation/Keyboard.hpp"
#include "Player.hpp"

int main(void)
{
    game::objects::Player player{"p1", "test_name"};
  //  player.setSpeed({1, 1, 1});
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;
    gameEngine::encapsulation::Keyboard keyboard;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - keyboard input");

    Vector2 ballPosition = { (float)screenWidth/2, (float)screenHeight/2 };

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        if (keyboard.isKeyDown(KEY_RIGHT)) ballPosition.x += 2.0f;
        if (keyboard.isKeyDown(KEY_LEFT)) ballPosition.x -= 2.0f;
        if (keyboard.isKeyDown(KEY_UP)) ballPosition.y -= 2.0f;
        if (keyboard.isKeyDown(KEY_DOWN)) ballPosition.y += 2.0f;
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawText("move the ball with arrow keys", 10, 10, 20, DARKGRAY);

            DrawCircleV(ballPosition, 50, MAROON);

        EndDrawing();
        player.handleKeyEvent();
        std::cout << "postion" << player.getPosition() << std::endl;
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}