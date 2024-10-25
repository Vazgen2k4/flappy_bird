#include "game.h"

Game::Game(std::string app_icon, std::string title, int FPS)
    : app_icon_path(app_icon),
      title(title),
      bird(nullptr),
      controller(nullptr) {
  icon = LoadImage(app_icon.c_str());

  InitWindow(Consts::WIN_WIDTH, Consts::WIN_HEIGHT, title.c_str());
  SetTargetFPS(FPS);
  SetWindowIcon(icon);

  InitAudioDevice();
  InitSounds();

  land = LoadTexture(Images::LAND.c_str());
  sky_controller.Init(Images::SKY, 100, (float)land.height);
  best_score = ReadBestScore();
}

Game::~Game() {
  UnloadImage(icon);
  UnloadTexture(land);
  UnloadSounds();
}

void Game::Run() {
  while (!WindowShouldClose()) {
    HandleInput();
    Update();

    BeginDrawing();
    ClearBackground(Colors::BG);
    Draw();
    EndDrawing();
  }

  CloseAudioDevice();
  CloseWindow();
}

void Game::HandleInput() {
  if (!game_over && !is_started && IsKeyPressed(KEY_SPACE)) {
    is_started = true;
  }

  if (IsKeyPressed(KEY_R) && game_over) {
    RestartGame();
  }

  if (IsKeyPressed(KEY_C)) {
    is_collider_mode = !is_collider_mode;
  }
}

void Game::RestartGame() {
  score = 0;
  is_started = false;
  game_over = false;

  bird->Reset();
  controller->Reset();
}

void Game::DrawTextureCenter(Texture2D texture, Color color) {
  auto x_center = (Consts::WIN_WIDTH - texture.width) / 2;
  auto y_center = (Consts::WIN_HEIGHT - texture.height) / 2;

  DrawTexture(texture, x_center, y_center, color);
}


int Game::ReadBestScore() {
  std::ifstream best_scores(Consts::BEST_SCORE_FILE);

  int _score = 0;

  if (best_scores.is_open()) {
    best_scores >> _score;
    best_scores.close();
  }

  return _score;
}

void Game::WriteBestScore(int _score) {
  std::ofstream best_scores(Consts::BEST_SCORE_FILE,
                            std::ios::out | std::ios::trunc);

  if (!best_scores.is_open()) {
    Logger::log_error("failed to open file " + Consts::BEST_SCORE_FILE);
    return;
  }

  best_scores << _score;
  Logger::log_info("The best score was update to [" + to_string(_score) + "]");
  best_scores.close();
}

void Game::Init(Bird* bird, PipeController* controller) {
  this->bird = bird;
  this->controller = controller;
}

void Game::Draw() {
  sky_controller.Draw();

  bird->Draw(is_collider_mode);
  controller->Draw(is_collider_mode);

  DrawTextInCorner({TextFormat("Score: %i", score),
                    TextFormat("Best Score: %i", best_score),
                    is_collider_mode ? "Collider mode" : ""});

  DrawLand();
}

void Game::DrawTextInCorner(vector<const char*> texts) {
  auto i = 0;

  for (auto text : texts) {
    if (text == "") continue;

    DrawText(text, 10, 10 + (20 * i++), 20, WHITE);
  }
}

void Game::DrawLand() {
  float dist_y = Consts::WIN_HEIGHT - land.height;

  Rectangle land_src = {0, 0, (float)land.width, (float)land.height};
  Rectangle land_dest = {0, dist_y, (float)Consts::WIN_WIDTH,
                         Consts::LAND_HEIGT};

  DrawTexturePro(land, land_src, land_dest, {0, 0}, 0.0f, WHITE);
}

void Game::Update() {
  if ((score > best_score) && game_over) {
    best_score = score;
    WriteBestScore(best_score);
  }

  if (!is_started || game_over) {
    return;
  }

  bird->Update();
  controller->Update(bird->getHitBox(), score, game_over);
  sky_controller.Update();
}
