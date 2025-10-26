#include "raylib.h"
#include "typetext.h"

int premorning(void)
{
    Image textbox1 = LoadImage("img/textbox.png");
    ImageResize(&textbox1, GetScreenWidth(), textbox1.height);
    Texture2D textbox = LoadTextureFromImage(textbox1);
    UnloadImage(textbox1);
    Font atp = LoadFontEx("font/All Things Pink.ttf", 29, 0, 0);
    Font ch_name = LoadFontEx("font/ARNORG__.TTF", 29, 0, 0);

    int framesample = 17;

    Image bghhd1 = LoadImage("background/BG helga houseday.png");
    ImageResize(&bghhd1, GetScreenWidth(), GetScreenHeight());
    Texture2D bghhd = LoadTextureFromImage(bghhd1);
    UnloadImage(bghhd1);

    Texture2D phoebe3 = LoadTexture("character/phoebe/Phoebe 3.png");

    while (!WindowShouldClose()) 
    {
        BeginDrawing();
        ClearBackground(BLACK);
        const char* experimental = "Experimental raylib version by Martin Eesmaa";

        if(IsKeyReleased(KEY_ENTER) || IsGamepadButtonReleased(0, GAMEPAD_BUTTON_RIGHT_FACE_DOWN)) {
            framesample++;
        }

        if(framesample == 18) {
            DrawTexture(textbox, 0, GetScreenHeight() - textbox.height, WHITE);
            TypeTextEx(atp, "This all began on a morning pretty much exactly like any other.", (Vector2){ 20, GetScreenHeight() - textbox.height + 20 }, atp.baseSize, 0, WHITE);
        }

        if(framesample >= 20 && framesample <= 70) {
            DrawTexture(bghhd, 0, 0, WHITE);
        }

        if(framesample >= 22 && framesample <= 28) {
            DrawTexture(phoebe3, GetScreenWidth() - phoebe3.width * 2, GetScreenHeight() - phoebe3.height, WHITE);
        }

        if (framesample >= 19 && framesample <= 300) {
            DrawTexture(textbox, 0, GetScreenHeight() - textbox.height, WHITE);
            DrawText(experimental, GetScreenWidth() - MeasureText(experimental, 20), 0, 20, WHITE);
        }
        else {
            DrawText(experimental, GetScreenWidth() - MeasureText(experimental, 20), 0, 20, WHITE);
        }

        if (framesample == 19) {
            TypeTextEx(atp, "It started with me wondering if I should bother to tell my mother I was leaving\nfor school.", (Vector2){ 20, GetScreenHeight() - textbox.height + 20 }, atp.baseSize, 0, WHITE);
        } else if (framesample == 20) {
            TypeTextEx(atp, "Not that you can hear me passed out on the kitchen table... Criminy!", (Vector2){ 20, GetScreenHeight() - textbox.height + 50 }, atp.baseSize, 0, WHITE);
        } else if (framesample == 21) {
            TypeTextEx(atp, "Oh, morning Pheebs...", (Vector2){ 20, GetScreenHeight() - textbox.height + 50 }, atp.baseSize, 0, WHITE);
        }

        if (framesample >= 20 && framesample <= 21) {
            DrawTextEx(ch_name, "Helga", (Vector2){ 20, GetScreenHeight() - textbox.height + 20 }, ch_name.baseSize, 0, PINK);
        }

        EndDrawing();
    }
}