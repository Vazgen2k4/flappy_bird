#include "pipe.h"

Pipe::Pipe(float x, PipeType type, float hh)
    : x(x), type(type), height(hh), passed(false) {
  auto source = type == PipeType::TO_UP ? Images::PIPE_UP : Images::PIPE_DOWN;

  texture = LoadTexture(source.c_str());

  width = texture.width;

  if (type == PipeType::TO_UP) {
    y = GetScreenHeight() - height;
  } else {
    y = 0;
  }
}

float Pipe::getX() const { return x; }
float Pipe::getY() const { return y; }
float Pipe::getWidth() const { return width; }
float Pipe::getHeight() const { return height; }
bool Pipe::isPassed() const { return passed; }
void Pipe::setPassed(bool newPassed) { passed = newPassed; }
PipeType Pipe::getType() const { return type; }

Rectangle Pipe::getHitBox() const {
  auto scaled_width = width * Consts::SCALE_PIPE;
  auto scaled_height = height;
  return {x, y, scaled_width, scaled_height};
}

void Pipe::setHeight(float newHeight) { height = newHeight; }

void Pipe::setX(float newX) { x = newX; }

void Pipe::Draw() const {
  if (type == TO_UP) {
    DrawTextureEx(texture, {x, y}, 0, Consts::SCALE_PIPE, WHITE);
  } else {
    auto s = texture.height * Consts::SCALE_PIPE;
    auto new_y = -abs(s - height);

    DrawTextureEx(texture, {x, new_y}, 0, Consts::SCALE_PIPE, WHITE);
  }

  DrawRectangleLinesEx(getHitBox(), 10, RED);
}
