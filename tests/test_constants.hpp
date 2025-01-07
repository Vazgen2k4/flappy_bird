#pragma once
#include "raylib.h"

extern const char* birdTexturePath;

inline void InitRaylibForTests() {
  InitWindow(10, 10, "Flappy Bird Test");
  SetTargetFPS(1);
}

inline void CloseRaylibAfterTests() { CloseWindow(); }