#pragma once
#include <cstring>
#include <functional>
#include <string>

#include "consts.hpp"
#include "logger.hpp"
#include "raylib.h"

enum PipeType { UP, DOWN };
class Pipe {
 private:
  Rectangle hit_box;
  PipeType type;

  std::reference_wrapper<Texture2D> head;
  std::reference_wrapper<Texture2D> tail;

  bool passed;

 public:
  Pipe(float x, PipeType type, float height, Texture2D& tail, Texture2D& head);

  // Геттеры
  float getX() const;
  float getY() const;
  float getWidth() const;
  float getHeight() const;
  bool isPassed() const;
  void setPassed(bool newPassed);
  void setHeight(float newHeight);

  PipeType getType() const;
  Rectangle getHitBox() const;

  // void setHeight(float newHeight);

  void setX(float newX);
  void Draw(bool with_debug) const;
};