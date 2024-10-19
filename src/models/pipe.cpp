#include "pipe.h"

Pipe::Pipe(float x, PipeType type, float height) : type(type), passed(false) {
  std::string source_head;
  std::string source_tail;
  float y = 0;

  if (type == PipeType::UP) {
    source_head = Images::PIPE_TO_DOWN;

  } else {
    source_head = Images::PIPE_TO_UP;
    y = Consts::WIN_HEIGHT - height ;
  }

  head = LoadTexture(source_head.c_str());
  tail = LoadTexture(Images::PIPE.c_str());

  hit_box = {x, y, (float)tail.width, height};
}

float Pipe::getX() const { return hit_box.x; }
float Pipe::getY() const { return hit_box.y; }

float Pipe::getWidth() const { return hit_box.width; }
float Pipe::getHeight() const { return hit_box.height; }

bool Pipe::isPassed() const { return passed; }
void Pipe::setPassed(bool newPassed) { passed = newPassed; }
PipeType Pipe::getType() const { return type; }

Rectangle Pipe::getHitBox() const { return hit_box; }

void Pipe::setX(float newX) { hit_box.x = newX; }

void Pipe::Draw(bool with_debug) const {
  Rectangle tail_sourse = {0, 0, (float)tail.width, (float)tail.height};
  DrawTexturePro(tail, tail_sourse, hit_box, {0, 0}, 0, WHITE);

  Rectangle head_sourse = {0, 0, (float)head.width, (float)head.height};

  float head_y = hit_box.y;

  if (type == UP) {
    head_y += hit_box.height - head.height;
  }

  Rectangle head_target = {hit_box.x, head_y, (float)head.width,
                           (float)head.height};

  DrawTexturePro(head, head_sourse, head_target, {0, 0}, 0, WHITE);

  if (with_debug) {
    DrawRectangleLinesEx(getHitBox(), 10, RED);
  }
}
