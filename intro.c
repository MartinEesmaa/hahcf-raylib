#include "raylib.h"

void start_game(void);

int begin(void)
{
    Font heyarnold = LoadFontEx("font/ARNORG__.TTF", 60, 0, 0);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);
        static float timer = 0;
        timer += GetFrameTime();

        if (timer < 2.0f) {
            DrawText("Martin Eesmaa presents...",
            GetScreenWidth() / 2 - MeasureText("Martin Eesmaa presents...", 40) / 2,
            GetScreenHeight() / 2 - 40, 40, WHITE);
        }

        if (timer > 4.0f) {
            DrawTextEx(heyarnold, "Helga's Cheese Festival", 
            (Vector2){ GetScreenWidth() / 2 - 250, 
            GetScreenHeight() / 2 - heyarnold.baseSize}, heyarnold.baseSize, 0, PINK);
        }

        if (timer > 6.0f) {
            DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), BLACK);
        }

        if (timer > 8.0f) {
            start_game();
        }

        EndDrawing();
    }
    CloseWindow();
    return 0;
}