#pragma once
#include <app_sound.h>

#include <iomanip>
#include <iostream>
#include <vector>

#include "consts.h"
#include "logger.h"
#include "raylib.h"

class Bird {
 public:
  Bird(const char* sourse);
  ~Bird();

  void Update();
  void Draw(bool with_debug) const;
  // void Draw() const;

  // Добавляем геттеры для координат и размеров
  float getX() const { return x; }
  float getY() const { return y; }
  float getWidth() const { return width; }
  float getHeight() const { return height; }

  Rectangle getHitBox() const {
    auto scaled_width = width * Consts::SCALE_BIRD;
    auto scaled_height = height * Consts::SCALE_BIRD;
    return {x, y, scaled_width, scaled_height};
  }

  void Reset();

 private:
  float x;
  float y;
  float angle;
  float width;
  float height;
  Texture2D texture;

  float max_y_pos;
};