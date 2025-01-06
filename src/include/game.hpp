#pragma once
#include <string>

#include "app_sound.hpp"
#include "bird.hpp"
#include "consts.hpp"
#include "dash_board.hpp"
#include "pipe_controller.hpp"
#include "raylib.h"
#include "sky_controller.hpp"

class Game {
 public:
  // Конструктор и деструктор
  Game(std::string app_icon, std::string title, int FPS);
  ~Game();

  bool isStarted() const { return is_started; }
  bool isGameOver() const { return game_over; }
  int getScore() const { return score; }

  int ReadBestScore();
  void WriteBestScore(int score);

  void Run();

  void Init(Bird* bird, PipeController* controller);
  void RestartGame();

 private:
  // Члены класса
  std::string app_icon_path;
  std::string title;
  Image icon;
  Texture2D land;

  Bird* bird;
  PipeController* controller;
  SkyController sky_controller;

  DashBoard dashboard;

  int score = 0;
  int best_score = 0;
  bool is_started = false;
  bool game_over = false;
  bool is_collider_mode = false;

  // Приватные методы
  // Обработка ввода
  void HandleInput();
  // Сброс игры

  // Обновление состояния игры
  void Update();
  // Отрисовка всех элементов
  void Draw();
  // dsds
  void DrawTextInCorner(vector<const char*> texts);
  // Отрисовка земли
  void DrawLand();
  // Центрированная отрисовка текстуры
  void DrawTextureCenter(Texture2D texture, Color color);
};
