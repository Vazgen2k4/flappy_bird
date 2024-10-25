#pragma once

#include <vector>
#include <functional>

#include "bird.h"
#include "pipe.h"

class PipeController {
 public:
  PipeController();
  ~PipeController();

  void Draw(bool with_debug) const;
  void Reset();
  void Update(Rectangle bird, int& score, bool& gameOver);
  
 private:
  std::vector<Pipe> pipes;
  float spawnTimer;
  void SpawnPipe();
  
  Texture2D pipe;
  Texture2D pipe_to_down;
  Texture2D pipe_to_up;
  
};
