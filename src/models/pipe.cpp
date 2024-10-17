#include "pipe.h"

Pipe::Pipe(float x, PipeType type, float hh) : x(x), type(type), height(hh) {
  auto source = type == PipeType::TO_UP ? Images::PIPE_UP : Images::PIPE_DOWN;

  texture = LoadTexture(source.c_str());

  width = texture.width;

  if (type == PipeType::TO_UP) {
    y = GetScreenHeight() - height;
  } else {
    y = height - GetScreenHeight();
  }
}

float Pipe::getX() const { return x; }
float Pipe::getY() const { return y; }
float Pipe::getWidth() const { return width; }
float Pipe::getHeight() const { return height; }
PipeType Pipe::getType() const { return type; }

void Pipe::setHeight(float newHeight) { height = newHeight; }

void Pipe::setX(float newX) { x = newX; }

void Pipe::Draw() const {
  DrawTextureEx(texture, {x, y}, 0, Consts::SCALE_PIPE, WHITE);
}
