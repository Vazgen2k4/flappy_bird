#pragma once

#include <string>

#include "consts.h"
#include "raylib.h"

class SkyController {
 public:
  SkyController();
  ~SkyController();
  
  
  void Update();
  void Init(std::string icon, float speed, float y);
  void Draw();

 private:
  Texture2D sky;
  float speed;
  float position;
  float y;
  int repetitions;
};