#include "typetext.h"
#include <string.h>

int TypeTextEx(Font font, const char *text, Vector2 pos, float fontSize, float spacing, Color color)
{
    static const char *newText = NULL;
    static int charsToShow = 0;
    static float timer = 0.0f;
    float cps = 24.0f;
    float charInterval = 1.0f / cps;

    // Reset the typewriter text
    if (newText != text) {
        newText = text;
        charsToShow = 0;
        timer = 0.0f;
    }

    int textLen = strlen(text);

    if (charsToShow < textLen) {
        timer += GetFrameTime();
        if (timer >= charInterval) {
            timer -= charInterval;
            charsToShow++;
        }
    }

    char temp[512] = {0};
    strncpy(temp, text, charsToShow);
    temp[charsToShow] = '\0';
    DrawTextEx(font, temp, pos, fontSize, spacing, color);

    return (charsToShow >= textLen);
}