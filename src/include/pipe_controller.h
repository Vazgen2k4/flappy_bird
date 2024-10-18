#pragma once

#include <vector>
#include <functional>

#include "bird.h"
#include "pipe.h"

class PipeController {
 public:
  PipeController();

  void Draw(bool with_debug) const;
  void Reset();

  void Update(Rectangle bird, int& score, bool& gameOver);

 private:
  std::vector<Pipe> pipes;
  float spawnTimer;
  void SpawnPipe();
};
