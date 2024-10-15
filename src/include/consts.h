#pragma once

#include <string>
#include "raylib.h"

using namespace std;

class Consts {
 public:
  static const int WIN_WIDTH;
  static const int WIN_HEIGHT;
  static const string LOGGER_FILE;
  static const int MAX_ANGLE_ROTATE_UP;
  static const int MAX_ANGLE_ROTATE_DOWN;
};

class Colors {
 public:
  static const Color BG;
};

class Images {
 public:
  static const string IMAGES_FOLDER;
  static const string BIRD;
  static const string LAND;
  static const string PIPE_DOWN;
  static const string PIPE_UP;
  static const string SCOREBOARD;
  static const string SKY;
};
