
#include <raylib.h>
#include <unistd.h>

#include <cstring>
#include <iostream>

#include "consts.h"
#include "logger.h"
#include "bird.h"

int main() {
  Logger::initialize(Consts::LOGGER_FILE);

  InitWindow(Consts::WIN_WIDTH, Consts::WIN_HEIGHT, "Vazgen project");
  SetTargetFPS(60);

  Logger::log_info("Init window");

  Bird bird = {Images::BIRD.c_str()};
  
  bool start = false;
  
  while (!WindowShouldClose()) {
    
    if(!start && IsKeyPressed(KEY_SPACE)) {
      start = true;
    }
      
    bird.Update(start);
  
    BeginDrawing();

    ClearBackground(Colors::BG);
    bird.Draw();

    EndDrawing();
  }

  CloseWindow();
}