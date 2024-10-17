#include "pipe_controller.h"

#include "consts.h"
#include "logger.h"
#include "raylib.h"

PipeController::PipeController() : spawnTimer(0) { Reset(); }

void PipeController::Reset() {
  pipes.clear();
  spawnTimer = 0;
}

void PipeController::Update() {
  spawnTimer += GetFrameTime();
  if (spawnTimer >= spawnInterval) {
    SpawnPipe();
    spawnTimer = 0;
  }

  for (auto& pipe : pipes) {
    pipe.setX(pipe.getX() - pipeSpeed * GetFrameTime());
  }

  if (!pipes.empty() && pipes.front().getX() + pipes.front().getWidth() < 0) {
    pipes.erase(pipes.begin(), pipes.begin() + 2);
  }
}

void PipeController::Draw() const {
  for (const auto& pipe : pipes) {
    pipe.Draw();
  }
}

void PipeController::SpawnPipe() {
  float x = GetScreenWidth();
  float screenHeight = GetScreenHeight();
  float randomPositon = GetRandomValue(100, screenHeight - 100);

  float halfGap = (pipeGap / 2);

  auto to_down_height = screenHeight - randomPositon + halfGap;
  auto to_up_height = screenHeight - (to_down_height + pipeGap);

  pipes.push_back({x, PipeType::TO_DOWN, to_down_height});
  pipes.push_back({x, PipeType::TO_UP, to_up_height});
}