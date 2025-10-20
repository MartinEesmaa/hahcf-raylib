#include "raylib.h"
#include "typetext.h"

int start(void) 
{
    Texture2D textbox = LoadTexture("img/textbox.png");
    Font atp = LoadFontEx("font/All Things Pink.ttf", 29, 0, 0);

    int framesample = 0;

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);
        DrawTexture(textbox, 0, GetScreenHeight() - textbox.height, WHITE);
        const char* experimental = "Experimental version by Martin Eesmaa";
        DrawText(experimental, GetScreenWidth() - MeasureText(experimental, 20), 0, 20, WHITE);

        if(IsKeyReleased(KEY_ENTER) || IsGamepadButtonReleased(0, GAMEPAD_BUTTON_RIGHT_FACE_DOWN)) {
            framesample += 1;
        }

        if(framesample == 0) {
            TypeTextEx(atp, "Sorry, it's not implemented yet. Coming soon... - Martin Eesmaa", (Vector2){ 20, GetScreenHeight() - textbox.height + 20 }, atp.baseSize, 0, WHITE);
        } else if(framesample == 1) {
            TypeTextEx(atp, "Nice it's working!", (Vector2){ 20, GetScreenHeight() - textbox.height + 20 }, atp.baseSize, 0, WHITE);
        }

        EndDrawing();
    }
    UnloadTexture(textbox);
    UnloadFont(atp);
    CloseWindow();
    return 0;
}