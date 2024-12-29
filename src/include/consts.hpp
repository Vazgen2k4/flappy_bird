#pragma once

#include <sys/stat.h>  // Для Unix-подобных систем

#include <iostream>
#include <string>
#include <vector>

#include "raylib.h"
#ifdef _WIN32
#include <direct.h>  // Для Windows
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
  static const float spawnInterval;
  static const float pipeSpeed;
  static const float pipeGap;
  static const float LAND_HEIGT;

  static const int MEDAL_OFFSET_X = 31;
  static const int MEDAL_OFFSET_Y = 112;
  
  static const int WIDTH_COLIDER = 3;
  static const int FONT_SIZE = 20;
  
  static const int  DashBoard_SCORES_DX = 175;
  static const int  DashBoard_SCORES_DY = 105;
  static const int  DashBoard_BEST_SCORES_DY = 145;

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
  InitWindow(800, 600, "Flappy Bird Test");
  SetTargetFPS(60);
}

inline void CloseRaylibAfterTests() { CloseWindow(); }