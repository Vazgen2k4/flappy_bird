#include <raylib.h>
#include <unistd.h>


#include <cstring>
#include <iostream>

#include "ball.h"
#include "models/bird/bird.h"



int main() {
  char cwd[1024];
  if (getcwd(cwd, sizeof(cwd)) != nullptr) {
    std::cout << "Текущая директория: " << cwd << std::endl;
  }

  const Color darkGreen = {20, 160, 133, 255};

  constexpr int screenWidth = 800;
  constexpr int screenHeight = 600;
  

  InitWindow(screenWidth, screenHeight, "Vazgen project");
  SetTargetFPS(60);

  Bird bird = {"./images/bird-01.png"};


  while (!WindowShouldClose()) {
    bird.Update();

    BeginDrawing();
    ClearBackground(darkGreen);
    bird.Draw();
    EndDrawing();
  }

  CloseWindow();
}