#include "pipe.hpp"

Pipe::Pipe(float x, PipeType type, float height, Texture2D& tail,
           Texture2D& head)
    : type(type), passed(false), tail(tail), head(head) {
  float y = 0;

  if (type != PipeType::UP) {
    y = Consts::WIN_HEIGHT - height;
  }

  hit_box = {x, y, (float)tail.width, height};
}



bool Pipe::isPassed() const { return passed; }
void Pipe::setPassed(bool newPassed) { passed = newPassed; }



PipeType Pipe::getType() const { return type; }



void Pipe::Draw(bool with_debug) const {
  Rectangle tail_sourse = {0, 0, (float)(tail.get().width),
                           (float)(tail.get().height)};
  DrawTexturePro(tail, tail_sourse, hit_box, {0, 0}, 0, WHITE);

  Rectangle head_sourse = {0, 0, (float)(head.get().width),
                           (float)(head.get().height)};

  float head_y = hit_box.y;

  if (type == UP) {
    head_y += hit_box.height - head.get().height;
  }

  Rectangle head_target = {hit_box.x, head_y, (float)head.get().width,
                           (float)head.get().height};

  DrawTexturePro(head, head_sourse, head_target, {0, 0}, 0, WHITE);

  if (with_debug) {
    DrawRectangleLinesEx(getHitBox(), Consts::WIDTH_COLIDER, RED);
  }
}
