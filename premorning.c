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

    Image bgcd1 = LoadImage("background/BG City Day.png");
    ImageResize(&bgcd1, GetScreenWidth(), GetScreenHeight());
    Texture2D bgcd = LoadTextureFromImage(bgcd1);
    UnloadImage(bgcd1);

    Texture2D phoebe1 = LoadTexture("character/phoebe/Phoebe 1.png");
    Texture2D phoebe2 = LoadTexture("character/phoebe/Phoebe 2.png");
    Texture2D phoebe3 = LoadTexture("character/phoebe/Phoebe 3.png");
    Texture2D phoebe4 = LoadTexture("character/phoebe/Phoebe 4.png");
    Texture2D phoebe8 = LoadTexture("character/phoebe/Phoebe 8.png");
    Texture2D phoebe12 = LoadTexture("character/phoebe/Phoebe 12.png");

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

        if(framesample >= 20 && framesample <= 72) {
            DrawTexture(bghhd, 0, 0, WHITE);
        } else if(framesample >= 73 && framesample <= 87) {
            DrawTexture(bgcd, 0, 0, WHITE);
        }

        if(framesample >= 22 && framesample <= 28) {
            DrawTexture(phoebe3, GetScreenWidth() - phoebe3.width * 2, GetScreenHeight() - phoebe3.height, WHITE);
        } else if (framesample >= 29 && framesample <= 30) {
            DrawTexture(phoebe1, GetScreenWidth() - phoebe1.width * 2, GetScreenHeight() - phoebe1.height, WHITE);
        } else if (framesample >= 31 && framesample <= 40) {
            DrawTexture(phoebe8, GetScreenWidth() - phoebe8.width * 2, GetScreenHeight() - phoebe8.height, WHITE);
        } else if (framesample >= 41 && framesample <= 50) {
            DrawTexture(phoebe2, GetScreenWidth() - phoebe2.width * 2, GetScreenHeight() - phoebe2.height, WHITE);
        } else if (framesample >= 51 && framesample <= 58) {
            DrawTexture(phoebe4, GetScreenWidth() - phoebe4.width * 2, GetScreenHeight() - phoebe4.height, WHITE);
        } else if (framesample >= 59 && framesample <= 61) {
            DrawTexture(phoebe2, GetScreenWidth() - phoebe2.width * 2, GetScreenHeight() - phoebe12.height, WHITE);
        } else if (framesample >= 62 && framesample <= 65) {
            DrawTexture(phoebe4, GetScreenWidth() - phoebe2.width * 2, GetScreenHeight() - phoebe12.height, WHITE);
        } else if (framesample == 66) {
            DrawTexture(phoebe12, GetScreenWidth() - phoebe2.width * 2, GetScreenHeight() - phoebe12.height, WHITE);
        } else if (framesample >= 67 && framesample <= 72) {
            DrawTexture(phoebe3, GetScreenWidth() - phoebe2.width * 2, GetScreenHeight() - phoebe12.height, WHITE);
        } else if (framesample >= 83 && framesample <= 87) {
            DrawTexture(phoebe4, GetScreenWidth() - phoebe2.width * 2, GetScreenHeight() - phoebe12.height, WHITE);
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
        } else if (framesample == 22) {
            TypeTextEx(atp, "Phoebe's my best friend.", (Vector2){ 20, GetScreenHeight() - textbox.height + 20 }, atp.baseSize, 0, WHITE);
        } else if (framesample == 23) {
            TypeTextEx(atp, "And a damn good assistant", (Vector2){ 20, GetScreenHeight() - textbox.height + 20 }, atp.baseSize, 0, WHITE);
        } else if (framesample == 24) {
            TypeTextEx(atp, "But of course she's mostly my friend.", (Vector2){ 20, GetScreenHeight() - textbox.height + 20 }, atp.baseSize, 0, WHITE);
        } else if (framesample == 25) {
            TypeTextEx(atp, "Good morning Helga, how are you today?", (Vector2){ 20, GetScreenHeight() - textbox.height + 50 }, atp.baseSize, 0, WHITE);
        } else if (framesample == 26) {
            TypeTextEx(atp, "Oh you know, same ol', same ol'...", (Vector2){ 20, GetScreenHeight() - textbox.height + 50 }, atp.baseSize, 0, WHITE);
        } else if (framesample == 27) {
            TypeTextEx(atp, "I was lying...", (Vector2){ 20, GetScreenHeight() - textbox.height + 20 }, atp.baseSize, 0, WHITE);
        } else if (framesample == 28) {
            TypeTextEx(atp, "I was much worse.", (Vector2){ 20, GetScreenHeight() - textbox.height + 20 }, atp.baseSize, 0, WHITE);
        } else if (framesample == 29) {
            TypeTextEx(atp, "That's good to hear!", (Vector2){ 20, GetScreenHeight() - textbox.height + 50 }, atp.baseSize, 0, WHITE);
        } else if (framesample == 30) {
            TypeTextEx(atp, "Jeez, feeling perky, Phoebe?", (Vector2){ 20, GetScreenHeight() - textbox.height + 50 }, atp.baseSize, 0, WHITE);
        } else if (framesample == 31) {
            TypeTextEx(atp, "Of course! Since the Cheese Festival is only a few days away now and...", (Vector2){ 20, GetScreenHeight() - textbox.height + 50 }, atp.baseSize, 0, WHITE);
        } else if (framesample == 32) {
            TypeTextEx(atp, "Phoebe's grinning like an idiot, talking about that damn Festival.", (Vector2){ 20, GetScreenHeight() - textbox.height + 20 }, atp.baseSize, 0, WHITE);
        } else if (framesample == 33) {
            TypeTextEx(atp, "I can't even imagine myself having a good time.", (Vector2){ 20, GetScreenHeight() - textbox.height + 20 }, atp.baseSize, 0, WHITE);
        } else if (framesample == 34) {
            TypeTextEx(atp, "So I snap at her...", (Vector2){ 20, GetScreenHeight() - textbox.height + 20 }, atp.baseSize, 0, WHITE);
        } else if (framesample == 35) {
            TypeTextEx(atp, "I just can't help myself.", (Vector2){ 20, GetScreenHeight() - textbox.height + 20 }, atp.baseSize, 0, WHITE);
        } else if (framesample == 36) {
            TypeTextEx(atp, "Blah, blah, blah...", (Vector2){ 20, GetScreenHeight() - textbox.height + 50 }, atp.baseSize, 0, WHITE);
        } else if (framesample == 37) {
            TypeTextEx(atp, "That stupid festival never changes.", (Vector2){ 20, GetScreenHeight() - textbox.height + 50 }, atp.baseSize, 0, WHITE);
        } else if (framesample == 38) {
            TypeTextEx(atp, "It's the same damn carnival every year.", (Vector2){ 20, GetScreenHeight() - textbox.height + 50 }, atp.baseSize, 0, WHITE);
        } else if (framesample == 39) {
            TypeTextEx(atp, "Big freaking deal...", (Vector2){ 20, GetScreenHeight() - textbox.height + 50 }, atp.baseSize, 0, WHITE);
        } else if (framesample == 40) {
            TypeTextEx(atp, "I continue to mumble quiet profanities under my breath.", (Vector2){ 20, GetScreenHeight() - textbox.height + 20 }, atp.baseSize, 0, WHITE);
        } else if (framesample == 41) {
            TypeTextEx(atp, "Ever since a few years back, whenever they started dating, Phoebe and her\nboyfriend Gerald were like the \"it\" couple.", (Vector2){ 20, GetScreenHeight() - textbox.height + 20 }, atp.baseSize, 0, WHITE);
        } else if (framesample == 42) {
            TypeTextEx(atp, "He was cool, and she was smart and they just worked out perfectly...I guess...", (Vector2){ 20, GetScreenHeight() - textbox.height + 20 }, atp.baseSize, 0, WHITE);
        } else if (framesample == 43) {
            TypeTextEx(atp, "...", (Vector2){ 20, GetScreenHeight() - textbox.height + 20 }, atp.baseSize, 0, WHITE);
        } else if (framesample == 44) {
            TypeTextEx(atp, "I'll never, ever tell her I'm slightly jealous.", (Vector2){ 20, GetScreenHeight() - textbox.height + 20 }, atp.baseSize, 0, WHITE);
        } else if (framesample == 45) {
            TypeTextEx(atp, "Why so down Helga? Don't you find the fair fun anymore?", (Vector2){ 20, GetScreenHeight() - textbox.height + 50 }, atp.baseSize, 0, WHITE);
        } else if (framesample == 46) {
            TypeTextEx(atp, "Phoebe, how can you not remember...", (Vector2){ 20, GetScreenHeight() - textbox.height + 50 }, atp.baseSize, 0, WHITE);
        } else if (framesample == 47) {
            TypeTextEx(atp, "Then again, why would she? She always ended up not feeling like a miserable failure by the end of it.", (Vector2){ 20, GetScreenHeight() - textbox.height + 20 }, atp.baseSize, 0, WHITE);
        } else if (framesample == 48) {
            TypeTextEx(atp, "Unlike me...", (Vector2){ 20, GetScreenHeight() - textbox.height + 20 }, atp.baseSize, 0, WHITE);
        } else if (framesample == 49) {
            TypeTextEx(atp, "Never mind, I'm just being negative...or whatever.", (Vector2){ 20, GetScreenHeight() - textbox.height + 50 }, atp.baseSize, 0, WHITE);
        } else if (framesample == 50) {
            TypeTextEx(atp, "Negative? Hah. That's a word for it.", (Vector2){ 20, GetScreenHeight() - textbox.height + 20 }, atp.baseSize, 0, WHITE);
        } else if (framesample == 51) {
            TypeTextEx(atp, "If you say so.", (Vector2){ 20, GetScreenHeight() - textbox.height + 50 }, atp.baseSize, 0, WHITE);
        } else if (framesample == 52) {
            TypeTextEx(atp, "I do say so!", (Vector2){ 20, GetScreenHeight() - textbox.height + 50 }, atp.baseSize, 0, WHITE);
        } else if (framesample == 53) {
            TypeTextEx(atp, "And while we're on the topic of the Festival...", (Vector2){ 20, GetScreenHeight() - textbox.height + 50 }, atp.baseSize, 0, WHITE);
        } else if (framesample == 54) {
            TypeTextEx(atp, "Yes?", (Vector2){ 20, GetScreenHeight() - textbox.height + 50 }, atp.baseSize, 0, WHITE);
        } else if (framesample == 55) {
            TypeTextEx(atp, "There's no way I'm going this year.", (Vector2){ 20, GetScreenHeight() - textbox.height + 50 }, atp.baseSize, 0, WHITE);
        } else if (framesample == 56) {
            TypeTextEx(atp, "Phoebe frowns deeper...", (Vector2){ 20, GetScreenHeight() - textbox.height + 20 }, atp.baseSize, 0, WHITE);
        } else if (framesample == 57) {
            TypeTextEx(atp, "But why not Helga?", (Vector2){ 20, GetScreenHeight() - textbox.height + 50 }, atp.baseSize, 0, WHITE);
        } else if (framesample == 58) {
            TypeTextEx(atp, "Even if you've had a bad time before...", (Vector2){ 20, GetScreenHeight() - textbox.height + 50 }, atp.baseSize, 0, WHITE);
        } else if (framesample == 59) {
            TypeTextEx(atp, "I cut her off before she can go on.", (Vector2){ 20, GetScreenHeight() - textbox.height + 20 }, atp.baseSize, 0, WHITE);
        } else if (framesample == 60) {
            TypeTextEx(atp, "Give it a break Phoebe, criminy...", (Vector2){ 20, GetScreenHeight() - textbox.height + 50 }, atp.baseSize, 0, WHITE);
        } else if (framesample == 61) {
            TypeTextEx(atp, "Why do you even care?", (Vector2){ 20, GetScreenHeight() - textbox.height + 50 }, atp.baseSize, 0, WHITE);
        } else if (framesample == 62) {
            TypeTextEx(atp, "It's just...", (Vector2){ 20, GetScreenHeight() - textbox.height + 50 }, atp.baseSize, 0, WHITE);
        } else if (framesample == 63) {
            TypeTextEx(atp, "She shakes her head, like she's clearing her thoughts. She seems ready to give me some type of lecture.", (Vector2){ 20, GetScreenHeight() - textbox.height + 20 }, atp.baseSize, 0, WHITE);
        } else if (framesample == 64) {
            TypeTextEx(atp, "It seems to me...", (Vector2){ 20, GetScreenHeight() - textbox.height + 50 }, atp.baseSize, 0, WHITE);
        } else if (framesample == 65) {
            TypeTextEx(atp, "Maybe if you tried to focus on something other than...uh...", (Vector2){ 20, GetScreenHeight() - textbox.height + 50 }, atp.baseSize, 0, WHITE);
        } else if (framesample == 66) {
            TypeTextEx(atp, "...You-know-who...", (Vector2){ 20, GetScreenHeight() - textbox.height + 50 }, atp.baseSize, 0, WHITE);
        } else if (framesample == 67) {
            TypeTextEx(atp, "You might be able to enjoy yourself more...", (Vector2){ 20, GetScreenHeight() - textbox.height + 50 }, atp.baseSize, 0, WHITE);
        } else if (framesample == 68) {
            TypeTextEx(atp, "I nod my head slowly, taking it all in.", (Vector2){ 20, GetScreenHeight() - textbox.height + 20 }, atp.baseSize, 0, WHITE);
        } else if (framesample == 69) {
            TypeTextEx(atp, "Even if you've had a bad time before...", (Vector2){ 20, GetScreenHeight() - textbox.height + 20 }, atp.baseSize, 0, WHITE);
        } else if (framesample == 70) {
            TypeTextEx(atp, "Just kidding.", (Vector2){ 20, GetScreenHeight() - textbox.height + 20 }, atp.baseSize, 0, WHITE);
        } else if (framesample == 71) {
            TypeTextEx(atp, "I had heard this all before, multiple times in fact.", (Vector2){ 20, GetScreenHeight() - textbox.height + 20 }, atp.baseSize, 0, WHITE);
        } else if (framesample == 72) {
            TypeTextEx(atp, "...", (Vector2){ 20, GetScreenHeight() - textbox.height + 50 }, atp.baseSize, 0, WHITE);
        } else if (framesample == 73) {
            TypeTextEx(atp, "Even if I sat her down to explain the insanity of my emotions...", (Vector2){ 20, GetScreenHeight() - textbox.height + 20 }, atp.baseSize, 0, WHITE);
        } else if (framesample == 74) {
            TypeTextEx(atp, "She just couldn't understand how hard that was for me, to put him aside.", (Vector2){ 20, GetScreenHeight() - textbox.height + 20 }, atp.baseSize, 0, WHITE);
        } else if (framesample == 75) {
            TypeTextEx(atp, "She would never understand how most of the time he felt like the only good part in my whole life...", (Vector2){ 20, GetScreenHeight() - textbox.height + 20 }, atp.baseSize, 0, WHITE);
        } else if (framesample == 76) {
            TypeTextEx(atp, "The light in my otherwise bleak existence.", (Vector2){ 20, GetScreenHeight() - textbox.height + 20 }, atp.baseSize, 0, WHITE);
        } else if (framesample == 77) {
            TypeTextEx(atp, "But at the very same time, that damn Football Head could ruin me with a smile...", (Vector2){ 20, GetScreenHeight() - textbox.height + 20 }, atp.baseSize, 0, WHITE);
        } else if (framesample == 78) {
            TypeTextEx(atp, "Especially if that smile was aimed at someone other than me.", (Vector2){ 20, GetScreenHeight() - textbox.height + 20 }, atp.baseSize, 0, WHITE);
        } else if (framesample == 79) {
            TypeTextEx(atp, "And almost always, it was.", (Vector2){ 20, GetScreenHeight() - textbox.height + 20 }, atp.baseSize, 0, WHITE);
        } else if (framesample == 80) {
            TypeTextEx(atp, "You don't get it.", (Vector2){ 20, GetScreenHeight() - textbox.height + 50 }, atp.baseSize, 0, WHITE);
        } else if (framesample == 81) {
            TypeTextEx(atp, "What?", (Vector2){ 20, GetScreenHeight() - textbox.height + 50 }, atp.baseSize, 0, WHITE);
        } else if (framesample == 82) {
            TypeTextEx(atp, "It's not that easy...", (Vector2){ 20, GetScreenHeight() - textbox.height + 50 }, atp.baseSize, 0, WHITE);
        } else if (framesample == 83) {
            TypeTextEx(atp, "Helga...", (Vector2){ 20, GetScreenHeight() - textbox.height + 50 }, atp.baseSize, 0, WHITE);
        } else if (framesample == 84) {
            TypeTextEx(atp, "Ugh, don't pity me Phoebe.", (Vector2){ 20, GetScreenHeight() - textbox.height + 50 }, atp.baseSize, 0, WHITE);
        } else if (framesample == 85) {
            TypeTextEx(atp, "My warning didn't matter, she gives me a pitiful look anyway.", (Vector2){ 20, GetScreenHeight() - textbox.height + 20 }, atp.baseSize, 0, WHITE);
        } else if (framesample == 86) {
            TypeTextEx(atp, "I'm used to it now.", (Vector2){ 20, GetScreenHeight() - textbox.height + 50 }, atp.baseSize, 0, WHITE);
        } else if (framesample == 87) {
            TypeTextEx(atp, "I know...", (Vector2){ 20, GetScreenHeight() - textbox.height + 50 }, atp.baseSize, 0, WHITE);
        }

        if (framesample >= 20 && framesample <= 21) {
            DrawTextEx(ch_name, "Helga", (Vector2){ 20, GetScreenHeight() - textbox.height + 20 }, ch_name.baseSize, 0, PINK);
        } else if (framesample == 25) {
            DrawTextEx(ch_name, "Phoebe", (Vector2){ 20, GetScreenHeight() - textbox.height + 20 }, ch_name.baseSize, 0, PINK);
        } else if (framesample == 26) {
            DrawTextEx(ch_name, "Helga", (Vector2){ 20, GetScreenHeight() - textbox.height + 20 }, ch_name.baseSize, 0, PINK);
        } else if (framesample == 29) {
            DrawTextEx(ch_name, "Phoebe", (Vector2){ 20, GetScreenHeight() - textbox.height + 20 }, ch_name.baseSize, 0, PINK);
        } else if (framesample == 30) {
            DrawTextEx(ch_name, "Helga", (Vector2){ 20, GetScreenHeight() - textbox.height + 20 }, ch_name.baseSize, 0, PINK);
        } else if (framesample == 31) {
            DrawTextEx(ch_name, "Phoebe", (Vector2){ 20, GetScreenHeight() - textbox.height + 20 }, ch_name.baseSize, 0, PINK);
        } else if (framesample >= 36 && framesample <= 39) {
            DrawTextEx(ch_name, "Helga", (Vector2){ 20, GetScreenHeight() - textbox.height + 20 }, ch_name.baseSize, 0, PINK);
        } else if (framesample == 45) {
            DrawTextEx(ch_name, "Phoebe", (Vector2){ 20, GetScreenHeight() - textbox.height + 20 }, ch_name.baseSize, 0, PINK);
        } else if (framesample == 46) {
            DrawTextEx(ch_name, "Helga", (Vector2){ 20, GetScreenHeight() - textbox.height + 20 }, ch_name.baseSize, 0, PINK);
        } else if (framesample == 49) {
            DrawTextEx(ch_name, "Helga", (Vector2){ 20, GetScreenHeight() - textbox.height + 20 }, ch_name.baseSize, 0, PINK);
        } else if (framesample == 51) {
            DrawTextEx(ch_name, "Phoebe", (Vector2){ 20, GetScreenHeight() - textbox.height + 20 }, ch_name.baseSize, 0, PINK);
        } else if (framesample >= 52 && framesample <= 53) {
            DrawTextEx(ch_name, "Helga", (Vector2){ 20, GetScreenHeight() - textbox.height + 20 }, ch_name.baseSize, 0, PINK);
        } else if (framesample == 54) {
            DrawTextEx(ch_name, "Phoebe", (Vector2){ 20, GetScreenHeight() - textbox.height + 20 }, ch_name.baseSize, 0, PINK);
        } else if (framesample == 55) {
            DrawTextEx(ch_name, "Helga", (Vector2){ 20, GetScreenHeight() - textbox.height + 20 }, ch_name.baseSize, 0, PINK);
        } else if (framesample >= 57 && framesample <= 58) {
            DrawTextEx(ch_name, "Helga", (Vector2){ 20, GetScreenHeight() - textbox.height + 20 }, ch_name.baseSize, 0, PINK);
        } else if (framesample >= 60 && framesample <= 61) {
            DrawTextEx(ch_name, "Helga", (Vector2){ 20, GetScreenHeight() - textbox.height + 20 }, ch_name.baseSize, 0, PINK);
        } else if (framesample == 62) {
            DrawTextEx(ch_name, "Phoebe", (Vector2){ 20, GetScreenHeight() - textbox.height + 20 }, ch_name.baseSize, 0, PINK);
        } else if (framesample >= 64 && framesample <= 67) {
            DrawTextEx(ch_name, "Phoebe", (Vector2){ 20, GetScreenHeight() - textbox.height + 20 }, ch_name.baseSize, 0, PINK);
        } else if (framesample == 72) {
            DrawTextEx(ch_name, "Helga", (Vector2){ 20, GetScreenHeight() - textbox.height + 20 }, ch_name.baseSize, 0, PINK);
        } else if (framesample == 80) {
            DrawTextEx(ch_name, "Helga", (Vector2){ 20, GetScreenHeight() - textbox.height + 20 }, ch_name.baseSize, 0, PINK);
        } else if (framesample == 81) {
            DrawTextEx(ch_name, "Phoebe", (Vector2){ 20, GetScreenHeight() - textbox.height + 20 }, ch_name.baseSize, 0, PINK);
        } else if (framesample == 82) {
            DrawTextEx(ch_name, "Helga", (Vector2){ 20, GetScreenHeight() - textbox.height + 20 }, ch_name.baseSize, 0, PINK);
        } else if (framesample == 83) {
            DrawTextEx(ch_name, "Phoebe", (Vector2){ 20, GetScreenHeight() - textbox.height + 20 }, ch_name.baseSize, 0, PINK);
        } else if (framesample == 84) {
            DrawTextEx(ch_name, "Helga", (Vector2){ 20, GetScreenHeight() - textbox.height + 20 }, ch_name.baseSize, 0, PINK);
        } else if (framesample >= 86 && framesample <= 87) {
            DrawTextEx(ch_name, "Helga", (Vector2){ 20, GetScreenHeight() - textbox.height + 20 }, ch_name.baseSize, 0, PINK);
        }

        EndDrawing();
    }
    UnloadTexture(textbox);
    UnloadTexture(bghhd);
    UnloadTexture(bgcd);
    UnloadTexture(phoebe1);
    UnloadTexture(phoebe2);
    UnloadTexture(phoebe3);
    UnloadTexture(phoebe4);
    UnloadTexture(phoebe8);
    UnloadTexture(phoebe12);
    UnloadFont(atp);
    UnloadFont(ch_name);
}