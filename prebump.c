#include "raylib.h"
#include "typetext.h"

int prebump(void)
{
    Image textbox1 = LoadImage("img/textbox.png");
    ImageResize(&textbox1, GetScreenWidth(), textbox1.height);
    Texture2D textbox = LoadTextureFromImage(textbox1);
    UnloadImage(textbox1);
    Font atp = LoadFontEx("font/All Things Pink.ttf", 29, 0, 0);
    Font ch_name = LoadFontEx("font/ARNORG__.TTF", 29, 0, 0);

    int framesample = 87;

    Image CG4temp = LoadImage("chapter/CG4.png");
    Image CG5temp = LoadImage("chapter/CG5.png");
    Image CG6temp = LoadImage("chapter/CG6.png");
    Image CG7temp = LoadImage("chapter/CG7.png");

    ImageResize(&CG4temp, GetScreenWidth(), GetScreenHeight());
    ImageResize(&CG5temp, GetScreenWidth(), GetScreenHeight());
    ImageResize(&CG6temp, GetScreenWidth(), GetScreenHeight());
    ImageResize(&CG7temp, GetScreenWidth(), GetScreenHeight());

    Texture2D CG4 = LoadTextureFromImage(CG4temp);
    Texture2D CG5 = LoadTextureFromImage(CG5temp);
    Texture2D CG6 = LoadTextureFromImage(CG6temp);
    Texture2D CG7 = LoadTextureFromImage(CG6temp);

    UnloadImage(CG4temp);
    UnloadImage(CG5temp);
    UnloadImage(CG6temp);
    UnloadImage(CG7temp);

    while (!WindowShouldClose()) 
    {
        BeginDrawing();
        ClearBackground(BLACK);
        const char* experimental = "Experimental raylib version by Martin Eesmaa";
        static float timerasset = 0;
        timerasset += GetFrameTime();

        if(IsKeyReleased(KEY_ENTER) || IsGamepadButtonReleased(0, GAMEPAD_BUTTON_RIGHT_FACE_DOWN)) {
            framesample++;
        }

        if(framesample == 88) {
            if (timerasset <= 0.1 || timerasset >= 0.4 && timerasset <= 0.6) {
                DrawTexture(CG4, -10, 0, WHITE);
            } else if (timerasset >= 0.7 && timerasset <= 1.0) {
                DrawTexture(CG4, 10, 0, WHITE);
            } else {
                DrawTexture(CG4, 0, 0, WHITE);
            }
        } else if(framesample >= 89 && framesample <= 90) {
            DrawTexture(CG5, 0, 0, WHITE);
        } else if(framesample == 91) {
            DrawTexture(CG6, 0, 0, WHITE);
        } else if(framesample == 92) {
            DrawTexture(CG7, 0, 0, WHITE);
        }

        if (framesample >= 88 && framesample <= 300) {
            DrawTexture(textbox, 0, GetScreenHeight() - textbox.height, WHITE);
            DrawText(experimental, GetScreenWidth() - MeasureText(experimental, 20), 0, 20, WHITE);
        }
        else {
            DrawText(experimental, GetScreenWidth() - MeasureText(experimental, 20), 0, 20, WHITE);
        }

        if (framesample == 88) {
            TypeTextEx(atp, "CRASH!!", (Vector2){ 20, GetScreenHeight() - textbox.height + 20 }, atp.baseSize, 0, WHITE);
        } else if (framesample == 89) {
            TypeTextEx(atp, "Arnold!", (Vector2){ 20, GetScreenHeight() - textbox.height + 50 }, atp.baseSize, 0, WHITE);
        } else if (framesample == 90) {
            TypeTextEx(atp, "Helga!", (Vector2){ 20, GetScreenHeight() - textbox.height + 50 }, atp.baseSize, 0, WHITE);
        } else if (framesample == 91) {
            TypeTextEx(atp, "We've got to stop bumping into each other like this! Haha!", (Vector2){ 20, GetScreenHeight() - textbox.height + 50 }, atp.baseSize, 0, WHITE);
        } else if (framesample == 92) {
            TypeTextEx(atp, "Uh...well...", (Vector2){ 20, GetScreenHeight() - textbox.height + 50 }, atp.baseSize, 0, WHITE);
        }

        if (framesample == 89 || framesample == 92)
        {
            DrawTextEx(ch_name, "Helga", (Vector2){ 20, GetScreenHeight() - textbox.height + 20 }, ch_name.baseSize, 0, PINK);
        } else if (framesample >= 90 && framesample <= 91) {
            DrawTextEx(ch_name, "Arnold", (Vector2){ 20, GetScreenHeight() - textbox.height + 20 }, ch_name.baseSize, 0, PINK);
        }

        EndDrawing();
    }
    UnloadTexture(textbox);
    UnloadTexture(CG4);
    UnloadTexture(CG5);
    UnloadTexture(CG6);
    UnloadTexture(CG7);
    UnloadFont(atp);
    UnloadFont(ch_name);
    CloseWindow();
}