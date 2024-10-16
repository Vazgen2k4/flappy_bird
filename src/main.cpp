#include <raylib.h>
#include <unistd.h>

#include <cstring>
#include <iostream>
#include <vector>

#include "bird.h"
#include "consts.h"
#include "logger.h"
#include "pipe.h"
#include "pipe_controller.h"

int main() {
  Logger::initialize(Consts::LOGGER_FILE);

  InitWindow(Consts::WIN_WIDTH, Consts::WIN_HEIGHT, "Vazgen project");
  SetTargetFPS(60);

  Logger::log_info("Init window");

  Bird bird = {Images::BIRD.c_str()};
  PipeController pipeController;

  bool start = false;

  while (!WindowShouldClose()) {
    if (!start && IsKeyPressed(KEY_SPACE)) {
      start = true;
    }

    bird.Update(start);

    if (start) {
      pipeController.Update();
    }

    BeginDrawing();

    ClearBackground(Colors::BG);
    pipeController.Draw();
    bird.Draw();

    EndDrawing();
  }

  CloseWindow();
}