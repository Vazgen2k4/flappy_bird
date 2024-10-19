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
      PlayHitSound();
      PlayDeathSound();
    }

    if (pipe.getType() == UP) {
      continue;
    }

    float pipe_border = pipe.getX() + pipe.getWidth() / 2;
    float bird_border = bird.x + bird.width;
    bool border_passed = pipe_border < bird_border;

    if (!gameOver && border_passed && !pipe.isPassed()) {
      score++;
      pipe.setPassed(true);
      PlayPointSound();
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
  float randomPosition = GetRandomValue(
      Consts::pipeGap, screenHeight - Consts::pipeGap - Consts::LAND_HEIGT);

  float halfGap = (Consts::pipeGap / 2);

  auto to_up_height = randomPosition - halfGap;
  auto to_down_height = screenHeight - randomPosition - halfGap;

  pipes.push_back({x, PipeType::DOWN, to_down_height});
  pipes.push_back({x, PipeType::UP, to_up_height});
}