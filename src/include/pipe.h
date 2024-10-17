#pragma once
#include <cstring>
#include <string>

#include "consts.h"
#include "logger.h"
#include "raylib.h"

enum PipeType { TO_UP, TO_DOWN };
class Pipe {
 private:
  float y;
  float x;
  float width;
  float height;
  PipeType type;
  Texture2D texture;
  bool passed;

 public:
  Pipe(float x, PipeType type, float height);

  // Геттеры
  float getX() const;
  float getY() const;
  float getWidth() const;
  float getHeight() const;
  bool isPassed() const;
  void setPassed(bool newPassed);
  PipeType getType() const;

  Rectangle getHitBox() const;

  void setHeight(float newHeight);

  void setX(float newX);
  void Draw() const;
};