#pragma once
#include <string>
#include <cstring>

#include "logger.h"
#include "raylib.h"
#include "consts.h"

enum PipeType { UP, DOWN };
class Pipe {
 private:
  float y;
  float x;
  float width;
  float height;
  PipeType type;
  Texture2D texture;

 public:
  Pipe(float x, PipeType type = PipeType::UP);
  
  // Геттеры
  float getX() const;
  float getY() const;
  float getWidth() const;
  float getHeight() const;
  PipeType getType() const;
  
  // Сеттеры
  void setX(float newX);
  void setY(float newY);

  
  void Update();
  void Draw() const;
};