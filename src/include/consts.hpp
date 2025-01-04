#pragma once

// for Unix-подобных систем
#include <sys/stat.h>

#include <iostream>
#include <string>
#include <vector>

#include "raylib.h"

// For Windows
#ifdef _WIN32
#include <direct.h>
#define mkdir _mkdir

#endif

using namespace std;

class Consts {
 public:
  static const int WIN_WIDTH;
  static const int WIN_HEIGHT;
  static const string FILE_FOLDER;
  static const string LOGGER_FILE;
  static const string BEST_SCORE_FILE;
  static const int MAX_ANGLE_ROTATE_UP;
  static const int MAX_ANGLE_ROTATE_DOWN;
  
  static const float SCALE_PIPE;
  static const float SCALE_BIRD;
  static const int BIRD_HORIZONTAL_PERCENTILE;
  static const float BIRD_GRAVITY;
  static const float BIRD_JUMP_STRENGTH;



  static const float spawnInterval;
  static const float pipeSpeed;
  static const float pipeGap;
  static const float LAND_HEIGT;

  static const int MEDAL_OFFSET_X;
  static const int MEDAL_OFFSET_Y;

  static const int WIDTH_COLIDER;
  static const int FONT_SIZE;

  static const int DashBoard_SCORES_DX;
  static const int DashBoard_SCORES_DY;
  static const int DashBoard_BEST_SCORES_DY;

  static void CreateDirectoryIfNotExists(const std::string& dir);
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

  static const string PIPE_TO_DOWN;
  static const string PIPE_TO_UP;
  static const string PIPE;

  static const string SCOREBOARD;
  static const string SKY;

  static const std::vector<std::string> MEDAL_PATHS;
};

inline void InitRaylibForTests() {
  InitWindow(10, 10, "Flappy Bird Test");
  SetTargetFPS(1);
}

inline void CloseRaylibAfterTests() { CloseWindow(); }