#pragma once

#include <string>
#include <vector>

#include "consts.hpp"

enum MedalType {
  Bronze,
  Silver,
  Gold,
  Platinum,
  NONE = -1,
};

struct MedalThreshold {
  int score;        // Порог очков
  MedalType medal;  // Соответствующая медаль
};

class DashBoard {
 private:
  MedalType medalType;
  Texture2D scoreboard;
  Texture2D medal;
  // Массив с порогами и медалями
  static const std::vector<MedalThreshold> thresholds;
  static const int width = 236;
  static const int height = 280;

  void DrawMedal(Rectangle rect, bool is_collider_mode = false);

 public:
  DashBoard(int bestSxores = 0);
  ~DashBoard();

  bool setMedalTexture();
  bool setMedalByBestScores(int bestScores);

  void Draw(bool is_colider_mode, int scores, int best_scores);
  void Init();
};
