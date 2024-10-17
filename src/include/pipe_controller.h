#pragma once

#include <vector>

#include "pipe.h"
#include "bird.h"

class PipeController {
 public:
  PipeController();

  void Draw() const;
  void Reset();

  void Update(Bird& bird, int& score, bool& gameOver);

 private:


  std::vector<Pipe> pipes;
  float spawnTimer;
  void SpawnPipe();
};
