#pragma once
#include <raylib.h>

#include <cstring>
#include <string>

#include "bird.h"
#include "consts.h"
#include "pipe_controller.h"

class Game {
 private:
  std::string app_icon_path;
  Image icon;
  std::string title;
  bool is_started = false;
  int score = 0;
  bool game_over = false;
  Bird* bird;
  PipeController* controller;

  bool is_collider_mode = false;

  Texture2D land;
  Texture2D sky;

  void Draw();
  void Update();
  void CheckGameOver();
  void CheckEvents();

 public:
  Game(std::string app_icon, std::string title, int FPS);
  ~Game();

  void DrawTextureCenter(Texture2D texture, Color color = BLANK);
  void Init(Bird* bird, PipeController* controller);
  void Run();
};
