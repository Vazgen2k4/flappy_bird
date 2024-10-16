#pragma once

#include <vector>
#include "pipe.h"

class PipeController {
 public:
  PipeController();
  void Update();
  void Draw() const;
  void Reset();

 private:
  std::vector<Pipe> pipes;
  float spawnTimer;
  const float spawnInterval = 2.0f;  // Интервал появления новых труб в секундах
  const float pipeSpeed = 200.0f;    // Скорость движения труб
  void SpawnPipe();
};


