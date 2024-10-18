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

  land = LoadTexture(Images::LAND.c_str());
  sky = LoadTexture(Images::SKY.c_str());
}

Game::~Game() {
  UnloadImage(icon);
  UnloadTexture(land);
  UnloadTexture(sky);
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
  Rectangle land_src = {0, 0, (float)land.width, (float)land.height};
  Rectangle land_dest = {0, Consts::WIN_HEIGHT - land.height,
                         (float)Consts::WIN_WIDTH, (float)land.height};

  auto k_sky = Consts::WIN_WIDTH / sky.width;

  Rectangle sky_src = {0, 0, (float)sky.width, (float)sky.height};
  Rectangle sky_dest = {0, land_dest.y - land_dest.height, Consts::WIN_WIDTH,
                        (float)sky.height * k_sky};

  // DrawTextureEx(sky, {50, land_dest.y - sky.height}, 0.0f, k_sky, WHITE);

  DrawTexturePro(sky, sky_src, sky_dest, {0, (float)sky.height}, 0.0f, {WHITE});

  bird->Draw(is_collider_mode);
  controller->Draw(is_collider_mode);

  DrawTexturePro(land, land_src, land_dest, {0, 0}, 0.0f, {WHITE});

  DrawText(TextFormat("Score: %i", score), 10, 10, 20, WHITE);

  if (is_collider_mode) {
    DrawText("Collider mode", 10, 30, 20, WHITE);
  }
}

void Game::Update() {
  bool can_update = is_started && !game_over;

  if (!can_update) {
    return;
  }

  bird->Update();
  controller->Update(bird->getHitBox(), score, game_over);
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
