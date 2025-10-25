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
    Texture2D CG3 = LoadTexture("chapter/CG3.png");

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);
        const char* experimental = "Experimental raylib version by Martin Eesmaa";

        if(IsKeyReleased(KEY_ENTER) || IsGamepadButtonReleased(0, GAMEPAD_BUTTON_RIGHT_FACE_DOWN)) {
            framesample++;
        }

        if(framesample == 0) {
            DrawTexture(textbox, 0, GetScreenHeight() - textbox.height, WHITE);
            TypeTextEx(atp, "So, let's just start off by saying Cheese Festivals never, ever worked out in my\nfavor...", (Vector2){ 20, GetScreenHeight() - textbox.height + 20 }, atp.baseSize, 0, WHITE);
        }
        
        if(framesample >= 1 && framesample <= 3) {
            DrawTexture(CG1, 0, 0, WHITE);
        } else if (framesample >= 4 && framesample <= 6) {
            DrawTexture(CG2, 0, 0, WHITE);
        } else if (framesample >= 7 && framesample <= 14) {
            DrawTexture(CG3, 0, 0, WHITE);
        }

        if (framesample >= 1 && framesample <= 14) {
            DrawTexture(textbox, 0, GetScreenHeight() - textbox.height, WHITE);
            DrawText(experimental, GetScreenWidth() - MeasureText(experimental, 20), 0, 20, WHITE);
        }
        else {
            DrawText(experimental, GetScreenWidth() - MeasureText(experimental, 20), 0, 20, WHITE);
        }
        
        if(framesample == 1) {
            TypeTextEx(atp, "I can remember...", (Vector2){ 20, GetScreenHeight() - textbox.height + 20 }, atp.baseSize, 0, WHITE);
        } else if (framesample == 2) {
            TypeTextEx(atp, "There were two of them when I was nine-years-old and both of them ended up\nwith me...", (Vector2){ 20, GetScreenHeight() - textbox.height + 20 }, atp.baseSize, 0, WHITE);
        } else if(framesample == 3) {
            TypeTextEx(atp, "Well, how do they put it...", (Vector2){ 20, GetScreenHeight() - textbox.height + 20 }, atp.baseSize, 0, WHITE);
        } else if(framesample == 4) {
            TypeTextEx(atp, "Forever alone.", (Vector2){ 20, GetScreenHeight() - textbox.height + 20 }, atp.baseSize, 0, WHITE);
        } else if(framesample == 5) {
            TypeTextEx(atp, "And now...", (Vector2){ 20, GetScreenHeight() - textbox.height + 20 }, atp.baseSize, 0, WHITE);
        } else if(framesample == 6) {
            TypeTextEx(atp, "It was that time of year again.", (Vector2){ 20, GetScreenHeight() - textbox.height + 20 }, atp.baseSize, 0, WHITE);
        } else if(framesample == 7) {
            TypeTextEx(atp, "Hillwood was going to have another one.", (Vector2){ 20, GetScreenHeight() - textbox.height + 20 }, atp.baseSize, 0, WHITE);
        } else if(framesample == 8) {
            TypeTextEx(atp, "And I wasn't looking forward to it.", (Vector2){ 20, GetScreenHeight() - textbox.height + 20 }, atp.baseSize, 0, WHITE);
        } else if(framesample == 9) {
            TypeTextEx(atp, "Because I knew it would be filled with people who were happier than me.", (Vector2){ 20, GetScreenHeight() - textbox.height + 20 }, atp.baseSize, 0, WHITE);
        } else if(framesample == 10) {
            TypeTextEx(atp, "They would be having a good time, laughing...enjoying their lives.", (Vector2){ 20, GetScreenHeight() - textbox.height + 20 }, atp.baseSize, 0, WHITE);
        } else if(framesample == 11) {
            TypeTextEx(atp, "Their loves...", (Vector2){ 20, GetScreenHeight() - textbox.height + 20 }, atp.baseSize, 0, WHITE);
        } else if(framesample == 12) {
            TypeTextEx(atp, "And the one thing that made me truly happy...", (Vector2){ 20, GetScreenHeight() - textbox.height + 20 }, atp.baseSize, 0, WHITE);
        } else if(framesample == 13) {
            TypeTextEx(atp, "Well it made me so miserable every time the Festival came to town.", (Vector2){ 20, GetScreenHeight() - textbox.height + 20 }, atp.baseSize, 0, WHITE);
        } else if(framesample == 14) {
            TypeTextEx(atp, "I hate that.", (Vector2){ 20, GetScreenHeight() - textbox.height + 20 }, atp.baseSize, 0, WHITE);
        }

        EndDrawing();
    }
    UnloadTexture(textbox);
    UnloadFont(atp);
    UnloadTexture(CG1);
    UnloadTexture(CG2);
    CloseWindow();
    return 0;
}