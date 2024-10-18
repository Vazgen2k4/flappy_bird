#include "pipe_controller.h"

#include "consts.h"
#include "logger.h"
#include "raylib.h"

PipeController::PipeController() : spawnTimer(0) { Reset(); }

void PipeController::Reset() {
  pipes.clear();
  spawnTimer = 0;
}

void PipeController::Update(Rectangle bird, int& score, bool& gameOver) {
  spawnTimer += GetFrameTime();
  if (spawnTimer >= Consts::spawnInterval) {
    SpawnPipe();
    spawnTimer = 0;
  }

  for (auto& pipe : pipes) {
    pipe.setX(pipe.getX() - Consts::pipeSpeed * GetFrameTime());

    if (CheckCollisionRecs(bird, pipe.getHitBox())) {
      gameOver = true;
    }

    if (!gameOver && pipe.getX() + pipe.getWidth() < bird.x &&
        !pipe.isPassed() && pipe.getType() == TO_UP) {
      score++;
      pipe.setPassed(true);
    }
  }

  if (!pipes.empty() && pipes.front().getX() + pipes.front().getWidth() < 0) {
    pipes.erase(pipes.begin(), pipes.begin() + 2);
  }
}

void PipeController::Draw(bool with_debug) const {
  for (const auto& pipe : pipes) {
    pipe.Draw(with_debug);
  }
}

void PipeController::SpawnPipe() {
  float x = Consts::WIN_WIDTH;
  float screenHeight = Consts::WIN_HEIGHT;
  float randomPosition =
      GetRandomValue(100, screenHeight - Consts::pipeGap - 100);

  float halfGap = (Consts::pipeGap / 2);

  auto to_up_height = randomPosition;

  auto to_down_height = screenHeight - randomPosition - Consts::pipeGap;

  pipes.push_back({x, PipeType::TO_DOWN, to_down_height});
  pipes.push_back({x, PipeType::TO_UP, to_up_height});
}