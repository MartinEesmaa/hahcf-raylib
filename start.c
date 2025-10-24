#include "raylib.h"
#include "typetext.h"

int start_game(void) 
{
    Image textbox1 = LoadImage("img/textbox.png");
    ImageResize(&textbox1, GetScreenWidth(), textbox1.height);
    Texture2D textbox = LoadTextureFromImage(textbox1);
    UnloadImage(textbox1);
    Font atp = LoadFontEx("font/All Things Pink.ttf", 29, 0, 0);

    int framesample = 0;

    Texture2D CG1 = LoadTexture("chapter/CG1.png");
    Texture2D CG2 = LoadTexture("chapter/CG2.png");

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);
        DrawTexture(textbox, 0, GetScreenHeight() - textbox.height, WHITE);
        const char* experimental = "Experimental raylib version by Martin Eesmaa";

        if(IsKeyReleased(KEY_ENTER) || IsGamepadButtonReleased(0, GAMEPAD_BUTTON_RIGHT_FACE_DOWN)) {
            framesample += 1;
        }

        if(framesample == 0) {
            TypeTextEx(atp, "So, let's just start off by saying Cheese Festivals never, ever worked out in my\n\nfavor...", (Vector2){ 20, GetScreenHeight() - textbox.height + 20 }, atp.baseSize, 0, WHITE);
        }
        
        if(framesample >= 1 && framesample <= 3) {
            DrawTexture(CG1, 0, 0, WHITE);
            DrawTexture(textbox, 0, GetScreenHeight() - textbox.height, WHITE);
        } else if (framesample >= 4 && framesample <= 6) {
            DrawTexture(CG2, 0, 0, WHITE);
            DrawTexture(textbox, 0, GetScreenHeight() - textbox.height, WHITE);
        }

        if (framesample <= 6) {
            DrawText(experimental, GetScreenWidth() - MeasureText(experimental, 20), 0, 20, WHITE);
        }
        
        if(framesample == 1) {
            TypeTextEx(atp, "I can remember...", (Vector2){ 20, GetScreenHeight() - textbox.height + 20 }, atp.baseSize, 0, WHITE);
        } else if (framesample == 2) {
            TypeTextEx(atp, "There were two of them when I was nine-years-old and both of them ended up\n\nwith me...", (Vector2){ 20, GetScreenHeight() - textbox.height + 20 }, atp.baseSize, 0, WHITE);
        } else if(framesample == 3) {
            TypeTextEx(atp, "Well, how do they put it...", (Vector2){ 20, GetScreenHeight() - textbox.height + 20 }, atp.baseSize, 0, WHITE);
        } else if(framesample == 4) {
            TypeTextEx(atp, "Forever alone.", (Vector2){ 20, GetScreenHeight() - textbox.height + 20 }, atp.baseSize, 0, WHITE);
        } else if(framesample == 5) {
            TypeTextEx(atp, "And now...", (Vector2){ 20, GetScreenHeight() - textbox.height + 20 }, atp.baseSize, 0, WHITE);
        } else if(framesample == 6) {
            TypeTextEx(atp, "It was that time of year again.", (Vector2){ 20, GetScreenHeight() - textbox.height + 20 }, atp.baseSize, 0, WHITE);
        }

        EndDrawing();
    }
    UnloadTexture(textbox);
    UnloadFont(atp);
    CloseWindow();
    return 0;
}