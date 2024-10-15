#pragma once
#include <iomanip>
#include <iostream>
#include <vector>

#include "raylib.h"
#include "logger.h"
#include "consts.h"

class Bird {
 public:
  Bird(const char* sourse);
  void Update(bool start);

  void Draw() const;

 private:
  float x;
  float y;
  float angle;
  float width;
  float height;
  Texture2D texture;
};