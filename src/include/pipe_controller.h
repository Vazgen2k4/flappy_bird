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
  const float spawnInterval = 1.5f;
  const float pipeSpeed = 200.0f;
  const float pipeGap = 10;

  std::vector<Pipe> pipes;
  float spawnTimer;
  void SpawnPipe();
};
