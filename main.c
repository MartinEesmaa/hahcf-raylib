#include "raylib.h"

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Helga's Cheese Festival (Martin Eesmaa)");
    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);
        const char *comingsoon = "Coming soon... (Martin Eesmaa)";
        DrawText(comingsoon, screenWidth / 2 - MeasureText(comingsoon, 20) / 2, screenHeight / 2 - 10, 20, WHITE);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
