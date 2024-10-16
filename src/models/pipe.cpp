#include "pipe.h"

Pipe::Pipe(float x, PipeType type) : x(x), type(type) {
  Logger::log_info("Init pipe");
  Logger::log_info("Load pipe sprite");

  auto sourse = type == PipeType::UP ? Images::PIPE_UP : Images::PIPE_DOWN;

  texture = LoadTexture(sourse.c_str());

  width = texture.width;
  height = texture.height;

  if (type == PipeType::UP) {
    y = GetScreenHeight() - height;
  } else {
    y = 0;
  }

  Logger::log_info("Bird width is [" + std::to_string(width) + "]");
  Logger::log_info("Bird height is [" + std::to_string(height) + "]");
}

float Pipe::getX() const { return x; }
float Pipe::getY() const { return y; }
float Pipe::getWidth() const { return width; }
float Pipe::getHeight() const { return height; }
PipeType Pipe::getType() const { return type; }

void Pipe::setX(float newX) { x = newX; }
void Pipe::setY(float newY) { y = newY; }

void Pipe::Update() {}

void Pipe::Draw() const { DrawTextureEx(texture, {x, y}, 0, 1.0f, WHITE); }
