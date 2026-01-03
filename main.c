/*
 * Copyright (C) 2025 Martin Eesmaa
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 * Video game title: Helga's Cheese Festival (raylib port version)
 * Source code: https://github.com/MartinEesmaa/hahcf-raylib
 */

#include "raylib.h"

#ifdef __SWITCH__
#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720
#define PATCH_FIX 200
#else
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define PATCH_FIX 0
#endif

int begin(void);

int main(void)
{
    const int screenWidth = SCREEN_WIDTH;
    const int screenHeight = SCREEN_HEIGHT;

    InitWindow(screenWidth, screenHeight, "Helga's Cheese Festival (Martin Eesmaa)");
    SetTargetFPS(60);
    
    Image background1 = LoadImage("img/GBACK.png");
    ImageResize(&background1, SCREEN_WIDTH, SCREEN_HEIGHT);
    Texture2D background = LoadTextureFromImage(background1);
    UnloadImage(background1);
        
    Image girl1 = LoadImage("img/girl1.png");
    ImageResize(&girl1, 188, 350);
    Texture2D girl = LoadTextureFromImage(girl1);
    UnloadImage(girl1);

    Image boy1 = LoadImage("img/boy1.png");
    ImageResize(&boy1, 250, 400);
    Texture2D boy = LoadTextureFromImage(boy1);
    UnloadImage(boy1);

    Font heyarnold = LoadFontEx("font/ARNORG__.TTF", 72, 0, 0);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);
        DrawTexture(background, 0, 0, WHITE);
        DrawTexture(girl, 0, GetScreenHeight() - girl.height, WHITE);
        DrawTexture(boy, GetScreenWidth() - boy.width, GetScreenHeight() - boy.height, WHITE);
        DrawTextEx(heyarnold, "Helga's Cheese Festival", (Vector2){ 100 + PATCH_FIX, 50 }, heyarnold.baseSize, 0, YELLOW);
        DrawText("raylib version by Martin Eesmaa (2025)", 32 + 38 + PATCH_FIX, GetScreenHeight() - 32, 32, WHITE);
        DrawRectangle(300 + PATCH_FIX, 200, 200, 100, PINK);
        DrawRectangle(300 + PATCH_FIX, 325, 200, 100, PINK);
        DrawTextEx(heyarnold, "Start", (Vector2){350 + PATCH_FIX, 230}, 50, 0, WHITE);
        DrawTextEx(heyarnold, "Quit", (Vector2){350 + PATCH_FIX, 350}, 50, 0, WHITE);

        if(IsGamepadAvailable(0)) {
            if (TextFindIndex(TextToLower(GetGamepadName(0)), "xbox") > -1 || TextFindIndex(TextToLower(GetGamepadName(0)), "x-box") > -1)
            {
                DrawTextEx(heyarnold, "Press A to Play", (Vector2){ 20, GetScreenHeight() - 50 - 40}, 50, 0, WHITE);
                DrawTextEx(heyarnold, "Press B to Quit", (Vector2){ GetScreenWidth() / 2 + 50, GetScreenHeight() - 50 - 40}, 50, 0, WHITE);
            }
            else if (TextFindIndex(GetGamepadName(0), "playstation") > - 1) {
                DrawTextEx(heyarnold, "Press X to Play", (Vector2){ 20, GetScreenHeight() - 50 - 40}, 50, 0, WHITE);
                DrawTextEx(heyarnold, "Press O to Quit", (Vector2){ GetScreenWidth() / 2 + 50, GetScreenHeight() - 50 - 40}, 50, 0, WHITE);
            }
            else {
                DrawTextEx(heyarnold, "Press A/X to Play", (Vector2){ 20, GetScreenHeight() - 50 - 40}, 50, 0, WHITE);
                DrawTextEx(heyarnold, "Press B/O to Quit", (Vector2){ GetScreenWidth() / 2 + 50, GetScreenHeight() - 50 - 40}, 50, 0, WHITE);
            }
        }

        Rectangle startbutton = { 300 + PATCH_FIX, 200, 200, 100 };
        Rectangle quitbutton = { 300 + PATCH_FIX, 325, 200, 100 };

        if(CheckCollisionPointRec(GetMousePosition(), startbutton) ||
           CheckCollisionPointRec(GetMousePosition(), quitbutton))
        {
            SetMouseCursor(4);
        }
        else {
            SetMouseCursor(1);
        }

        if(IsMouseButtonReleased(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), quitbutton))
        {
            SetMouseCursor(1);
            break;
        }

        if(IsMouseButtonReleased(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), startbutton))
        {
            SetMouseCursor(1);
            ClearBackground(BLACK);
            UnloadTexture(background);
            UnloadTexture(girl);
            UnloadTexture(boy);
            UnloadFont(heyarnold);
            begin();
        }

        if(IsGamepadButtonReleased(0, GAMEPAD_BUTTON_RIGHT_FACE_DOWN)) begin();
        if(IsGamepadButtonReleased(0, GAMEPAD_BUTTON_RIGHT_FACE_RIGHT)) break;

        EndDrawing();
    }
    UnloadTexture(background);
    UnloadTexture(girl);
    UnloadTexture(boy);
    UnloadFont(heyarnold);
    CloseWindow();
    return 0;
}
