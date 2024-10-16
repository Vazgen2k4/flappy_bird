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
  // Обновляем таймер и добавляем новую трубу при необходимости
  spawnTimer += GetFrameTime();
  if (spawnTimer >= spawnInterval) {
    SpawnPipe();
    spawnTimer = 0;
  }

  // Обновляем позиции труб
  for (auto& pipe : pipes) {
    pipe.setX(pipe.getX() - pipeSpeed * GetFrameTime());
  }

  // Удаляем трубы, вышедшие за экран
  if (!pipes.empty() && pipes.front().getX() + pipes.front().getWidth() < 0) {
    pipes.erase(pipes.begin());
  }
}

void PipeController::Draw() const {
  for (const auto& pipe : pipes) {
    pipe.Draw();
  }
}

void PipeController::SpawnPipe() {
  float x = GetScreenWidth();  // Начальная позиция трубы справа за экраном
  pipes.push_back(Pipe(x, PipeType::UP));
  pipes.push_back(Pipe(x, PipeType::DOWN));
  Logger::log_info("Spawned new pipes");
}
