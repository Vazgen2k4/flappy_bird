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
  const float spawnInterval = 1.0f;  
  const float pipeSpeed = 200.0f;   
  const float pipeGap = 100;   
  const float scaleFactor = 2.5f;   
  
  std::vector<Pipe> pipes;
  float spawnTimer;
  void SpawnPipe();
};


