#include "raylib.h"

int start(void) 
{
    Texture2D textbox = LoadTexture("img/textbox.png");
    Font atp = LoadFontEx("font/All Things Pink.ttf", 29, 0, 0);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);
        DrawTexture(textbox, 0, GetScreenHeight() - textbox.height, WHITE);
        DrawTextEx(atp, "Sorry, it's not implemented yet. Coming soon... - Martin Eesmaa", (Vector2){ 20, GetScreenHeight() - textbox.height + 20 }, atp.baseSize, 0, WHITE);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}