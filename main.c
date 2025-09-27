#include "raylib.h"

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Helga's Cheese Festival (Martin Eesmaa)");
    SetTargetFPS(60);
    Texture2D background = LoadTexture("img/GBACK.png");
        
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
        DrawTextEx(heyarnold, "Helga's Cheese Festival", (Vector2){ 100, 50 }, heyarnold.baseSize, 0, YELLOW);
        DrawText("raylib version by Martin Eesmaa (2025)", GetScreenWidth() / 6, GetScreenHeight() - 32, 32, WHITE);
        DrawRectangle(300, 200, 200, 100, PINK);
        DrawRectangle(300, 325, 200, 100, PINK);
        DrawTextEx(heyarnold, "Start", (Vector2){350, 230}, 50, 0, WHITE);
        DrawTextEx(heyarnold, "Quit", (Vector2){350, 350}, 50, 0, WHITE);

        Rectangle startbutton = { 300, 200, 200, 100 };
        Rectangle quitbutton = { 300, 325, 200, 100 };

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
