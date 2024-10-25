#pragma once
#include <string>

#include "app_sound.h"
#include "bird.h"
#include "consts.h"
#include "pipe_controller.h"
#include "raylib.h"
#include "sky_controller.h"

class Game {
 public:
  // Конструктор и деструктор
  Game(std::string app_icon, std::string title, int FPS);
  ~Game();

  // Запуск игры
  void Run();

  // Инициализация объектов игры
  void Init(Bird* bird, PipeController* controller);

 private:
  // Члены класса
  std::string app_icon_path;
  std::string title;
  Image icon;
  Texture2D land;

  Bird* bird;
  PipeController* controller;
  SkyController sky_controller;

  int score = 0;
  int best_score = 0;
  bool is_started = false;
  bool game_over = false;
  bool is_collider_mode = false;

  // Приватные методы
  // Обработка ввода
  void HandleInput();
  // Сброс игры
  void RestartGame();
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


  int ReadBestScore();
  void WriteBestScore(int score);
};
