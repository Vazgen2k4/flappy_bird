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

 public:
  Pipe(float x, PipeType type, float height);

  // Геттеры
  float getX() const;
  float getY() const;
  float getWidth() const;
  float getHeight() const;
  PipeType getType() const;

  void setHeight(float newHeight);

  void setX(float newX);
  void Draw() const;
};