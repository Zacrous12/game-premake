/**********************************************************************************************
*
*   raylib - Advance Game template
*
*   Gameplay Screen Functions Definitions (Init, Update, Draw, Unload)
*
*   Copyright (c) 2014-2022 Ramon Santamaria (@raysan5)
*
*   This software is provided "as-is", without any express or implied warranty. In no event
*   will the authors be held liable for any damages arising from the use of this software.
*
*   Permission is granted to anyone to use this software for any purpose, including commercial
*   applications, and to alter it and redistribute it freely, subject to the following restrictions:
*
*     1. The origin of this software must not be misrepresented; you must not claim that you
*     wrote the original software. If you use this software in a product, an acknowledgment
*     in the product documentation would be appreciated but is not required.
*
*     2. Altered source versions must be plainly marked as such, and must not be misrepresented
*     as being the original software.
*
*     3. This notice may not be removed or altered from any source distribution.
*
**********************************************************************************************/

#include "raylib.h"
#include "screens.h"

//----------------------------------------------------------------------------------
// Module Variables Definition (local)
//----------------------------------------------------------------------------------
static int framesCounter = 0;
static int finishScreen = 0;
static const int screenWidth = 800;
static const int screenHeight = 450;

// Player Variables
float playerX = 800 / 2.0;
float playerY = 450/ 2.0;
int speed = 3;


//----------------------------------------------------------------------------------
// Gameplay Screen Functions Definition
//----------------------------------------------------------------------------------

// Gameplay Screen Initialization logic
void InitGameplayScreen(void)
{
    // TODO: Initialize GAMEPLAY screen variables here!
    framesCounter = 1;
    finishScreen = 0;
}

// Gameplay Screen Update logic
void UpdateGameplayScreen(void)
{
    // TODO: Update GAMEPLAY screen variables here!

    // Press enter or tap to change to ENDING screen
    if (IsKeyPressed(KEY_ESCAPE) || IsGestureDetected(GESTURE_TAP))
    {
        finishScreen = 1;
        PlaySound(fxCoin);
    }

    if (IsKeyDown(KEY_RIGHT) && IsKeyDown(KEY_LEFT)) {}
    else {
        if (IsKeyDown(KEY_RIGHT)) {
            playerX += 3;
        }  
        else if (IsKeyDown(KEY_LEFT)) {
            playerX -= 3;
        }
    }

    if (IsKeyDown(KEY_UP) && IsKeyDown(KEY_DOWN)) {}
    else {
        if (IsKeyDown(KEY_UP)) {
            playerY -= 3;
        }
        else if (IsKeyDown(KEY_DOWN)) {
            playerY += 3;
        }
    }

}

// Gameplay Screen Draw logic
void DrawGameplayScreen(void)
{
    // TODO: Draw GAMEPLAY screen here!
    DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), WHITE);
    Vector2 pos = { 20, 10 };

    Vector3 player = {
        playerX,
        playerY,
        1.0
    };
    DrawCircleGradient(200, 300, 40.0, GREEN, BLUE);
    DrawCapsule(player, player, 40, 4, 1000, BLUE);

}

// Gameplay Screen Unload logic
void UnloadGameplayScreen(void)
{
    // TODO: Unload GAMEPLAY screen variables here!
}

// Gameplay Screen should finish?
int FinishGameplayScreen(void)
{
    return finishScreen;
}