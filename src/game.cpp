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
  ceiling = LoadTexture(Images::CEILING.c_str());
  sky_controller.Init(Images::SKY, 100, (float)land.height);
}

Game::~Game() {
  UnloadImage(icon);
  UnloadTexture(land);

  UnloadTexture(ceiling);
  UnloadSounds();
}

void Game::Run() {
  while (!WindowShouldClose()) {
    if (!game_over && !is_started && IsKeyPressed(KEY_SPACE)) {
      is_started = true;
    }

    Update();

    BeginDrawing();
    ClearBackground(Colors::BG);

    Draw();
    CheckGameOver();
    CheckEvents();
    EndDrawing();
  }

  CloseAudioDevice();
  CloseWindow();
}

void Game::DrawTextureCenter(Texture2D texture, Color color) {
  auto x_center = (Consts::WIN_WIDTH - texture.width) / 2;
  auto y_center = (Consts::WIN_HEIGHT - texture.height) / 2;

  DrawTexture(texture, x_center, y_center, WHITE);
}

void Game::Init(Bird* bird, PipeController* controller) {
  this->bird = bird;
  this->controller = controller;
};

void Game::Draw() {
  sky_controller.Draw();

  bird->Draw(is_collider_mode);
  controller->Draw(is_collider_mode);

  DrawText(TextFormat("Score: %i", score), 10, 10, 20, WHITE);

  DrawLand();

  if (is_collider_mode) {
    DrawText("Collider mode", 10, 30, 20, WHITE);
  }
}

void Game::DrawLand() {
  float dist_y = Consts::WIN_HEIGHT - land.height;

  Rectangle land_src = {0, 0, (float)land.width, (float)land.height};
  Rectangle land_dest = {0, dist_y, (float)Consts::WIN_WIDTH,
                         Consts::LAND_HEIGT};

  DrawTexturePro(land, land_src, land_dest, {0, 0}, 0.0f, {WHITE});
}

void Game::Update() {
  bool can_update = is_started && !game_over;

  if (!can_update) {
    return;
  }

  bird->Update();
  controller->Update(bird->getHitBox(), score, game_over);
  sky_controller.Update();
}

void Game::CheckGameOver() {
  if (!game_over) {
    return;
  }

  if (IsKeyPressed(KEY_R)) {
    score = 0;
    is_started = false;
    game_over = false;

    bird->Reset();
    controller->Reset();
  }
}

void Game::CheckEvents() {
  if (IsKeyPressed(KEY_C)) {
    is_collider_mode = !is_collider_mode;
  }
}
