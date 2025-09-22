#include "raylib.h"

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Helga's Cheese Festival (Martin Eesmaa)");
    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        Texture2D background = LoadTexture("img/gback.png");
        
        Image girl1 = LoadImage("img/girl1.png");
        ImageResize(&girl1, 188, 350);
        Texture2D girl = LoadTextureFromImage(girl1);
        UnloadImage(girl1);

        Image boy1 = LoadImage("img/boy1.png");
        ImageResize(&boy1, 188, 400);
        Texture2D boy = LoadTextureFromImage(boy1);
        UnloadImage(boy1);

        BeginDrawing();
        ClearBackground(BLACK);
        DrawTexture(background, 0, 0, WHITE);
        DrawTexture(girl, 0, GetScreenHeight() - 350, WHITE);
        DrawTexture(boy, GetScreenWidth() - 188, GetScreenHeight() - 400, WHITE);
        DrawText("Helga's Cheese Festival", 100, 50, 50, WHITE);
        DrawText("raylib version by Martin Eesmaa", GetScreenWidth() / 6, GetScreenHeight() - 32, 32, WHITE);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
