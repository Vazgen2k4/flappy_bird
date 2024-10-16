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
    pipe.Draw(scaleFactor);
  }
}

void PipeController::SpawnPipe() {
  float x = GetScreenWidth();
  float randomPositon = GetRandomValue(pipeGap, GetScreenHeight() - pipeGap);

  float halfGap = (pipeGap / 2);
  auto curentPipeHeight = randomPositon;

  Logger::log_warning("Random position: " + to_string(randomPositon));

  auto downHeight = (randomPositon - halfGap) / scaleFactor;
  auto upHeight =
      (GetScreenHeight() - curentPipeHeight - halfGap) / scaleFactor;

  pipes.push_back({x, PipeType::TO_DOWN, downHeight});
  pipes.push_back({x, PipeType::TO_UP, upHeight});
}