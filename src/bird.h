#pragma once
#include "raylib.h"

class Bird {
 public:
  Bird(const char* sourse);
  void Update();
  void Draw() const;

 private:
  int x;
  int y;
  int width;
  int height;
  Texture2D texture;
};