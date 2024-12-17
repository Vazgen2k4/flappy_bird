#include "dash_board.hpp"

void DashBoard::DrawMedal(Rectangle rect, bool is_collider_mode) {
  if (this->medalType == MedalType::NONE) {
    return;
  }

  int m_x = rect.x + Consts::MEDAL_OFFSET_X;
  int m_y = rect.y + Consts::MEDAL_OFFSET_Y;

  DrawTexture(this->medal, m_x, m_y, WHITE);

  if (is_collider_mode) {
    Rectangle r = {(float)m_x, (float)m_y, (float)this->medal.width,
                   (float)this->medal.height};
    DrawRectangleLinesEx(r, Consts::WIDTH_COLIDER, RED);
  }
}

DashBoard::DashBoard(int bestSxores) : medalType(MedalType::NONE) {}

const std::vector<MedalThreshold> DashBoard::thresholds = {
    {50, MedalType::Platinum},
    {25, MedalType::Gold},
    {15, MedalType::Silver},
    {10, MedalType::Bronze}};

DashBoard::~DashBoard() {
  if (this->medalType != NONE) {
    UnloadTexture(this->medal);
  }

  UnloadTexture(this->scoreboard);
}

bool DashBoard::setMedalTexture() {
  if (this->medalType == MedalType::NONE) {
    return false;
  }

  if (IsTextureReady(this->medal)) {
    UnloadTexture(this->medal);
  }

  this->medal = LoadTexture(Images::MEDAL_PATHS[this->medalType].c_str());
  return IsTextureReady(this->medal);
}

bool DashBoard::setMedalByBestScores(int bestScores) {
  // Проход по массиву и поиск подходящего значения
  for (const auto& threshold : thresholds) {
    if (bestScores >= threshold.score && this->medalType != threshold.medal) {
      this->medalType = threshold.medal;
      return setMedalTexture();
    }
  }

  // Если очки не подходят ни под один порог
  this->medalType = MedalType::NONE;
  return false;
}

void DashBoard::Draw(bool is_colider_mode, int scores, int best_scores) {
  int x = Consts::WIN_WIDTH / 2 - DashBoard::width / 2;
  int y = Consts::WIN_HEIGHT / 2 - DashBoard::height / 2;

  DrawRectangle(0, 0, Consts::WIN_WIDTH, Consts::WIN_HEIGHT, {0, 0, 0, 200});

  DrawTexture(scoreboard, x, y, WHITE);
  Rectangle r = {(float)x, (float)y, DashBoard::width, DashBoard::height};
  if (is_colider_mode) {
    DrawRectangleLinesEx(r, Consts::WIDTH_COLIDER, RED);
  }

  DrawMedal(r, is_colider_mode);

  DrawText(TextFormat("%i", scores), x + Consts::DashBoard_SCORES_DX,
           y + Consts::DashBoard_SCORES_DY, Consts::FONT_SIZE, WHITE);

  DrawText(TextFormat("%i", best_scores), x + Consts::DashBoard_SCORES_DX,
           y + Consts::Consts::DashBoard_BEST_SCORES_DY, Consts::FONT_SIZE,
           WHITE);
}

void DashBoard::Init() {
  this->scoreboard = LoadTexture(Images::SCOREBOARD.c_str());
}
