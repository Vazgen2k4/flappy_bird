#include "pipe.h"

Pipe::Pipe(float x, PipeType type, float hh) : x(x), type(type), height(hh) {
  Logger::log_info("Init pipe");
  Logger::log_info("Load pipe sprite");

  auto source = type == PipeType::TO_UP ? Images::PIPE_UP : Images::PIPE_DOWN;

  texture = LoadTexture(source.c_str());

  width = texture.width;

  y = (type == PipeType::TO_UP) ? GetScreenHeight() - height : -height;

  Logger::log_info("Pipe width is [" + std::to_string(width) + "]");
  Logger::log_info("Pipe height is [" + std::to_string(height) + "]");
}

float Pipe::getX() const { return x; }
float Pipe::getY() const { return y; }
float Pipe::getWidth() const { return width; }
float Pipe::getHeight() const { return height; }
PipeType Pipe::getType() const { return type; }

void Pipe::setHeight(float newHeight) {
  height = newHeight;
  y = (type == PipeType::TO_UP) ? GetScreenHeight() - height : 0;
}

void Pipe::setX(float newX) { x = newX; }

void Pipe::Draw(float skale) const {
  auto new_h = skale * height;

  float new_y;
  if (type == PipeType::TO_DOWN) {
    new_y = y;
  } else {
    new_y = y + (new_h - height);
  }

  Vector2 position = {x, new_y};

  Logger::log_warning("Позиция: "+to_string(x) + "  " + to_string(new_y));
  Logger::log_warning("Позиция: "+to_string(x) + "  " + to_string(new_y));

      DrawTextureEx(texture, position, 0, skale, WHITE);
}
