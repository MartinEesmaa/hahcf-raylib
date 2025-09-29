#pragma once
#include "raylib.h"

// Implements a typewriter text effect for DrawTextEx.
int TypeTextEx(Font font, const char *text, Vector2 pos, float fontSize, float spacing, Color color);