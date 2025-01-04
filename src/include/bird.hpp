#pragma once

#include <iomanip>
#include <iostream>
#include <vector>

#include "app_sound.hpp"
#include "consts.hpp"
#include "entity.hpp"
#include "logger.hpp"
#include "raylib.h"

class Bird : public Entity {
 public:
  Bird(const char* sourse);
  ~Bird();

  void Update();
  void Draw(bool with_debug) const;


  inline Rectangle getHitBox() const override {
    auto scaled_width = getWidth() * Consts::SCALE_BIRD;
    auto scaled_height = getHeight() * Consts::SCALE_BIRD;
    return {getX(), getY(), scaled_width, scaled_height};
  }

  void Reset();

 private:
  float angle;
  Texture2D texture;

  float max_y_pos;
};