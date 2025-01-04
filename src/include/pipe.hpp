#pragma once
#include <cstring>
#include <functional>
#include <string>

#include "consts.hpp"
#include "entity.hpp"
#include "logger.hpp"
#include "raylib.h"

enum PipeType { UP, DOWN };
class Pipe : public Entity {
 private:
  PipeType type;

  std::reference_wrapper<Texture2D> head;
  std::reference_wrapper<Texture2D> tail;

  bool passed;

 public:
  Pipe(float x, PipeType type, float height, Texture2D& tail, Texture2D& head);

  bool isPassed() const;
  void setPassed(bool newPassed);


  PipeType getType() const;
  
  void Draw(bool with_debug) const;
};