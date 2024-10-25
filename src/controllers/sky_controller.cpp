#include "sky_controller.h"

SkyController::SkyController() : speed(0), position(0), repetitions(0) {}

SkyController::~SkyController() { UnloadTexture(sky); }

void SkyController::Init(std::string icon, float speed, float land_height) {
  this->speed = speed;
  sky = LoadTexture(icon.c_str());

  this->y = Consts::WIN_HEIGHT - land_height - sky.height;

  repetitions = (Consts::WIN_WIDTH / sky.width) + 2;
}

void SkyController::Draw() {
  Rectangle sky_src = {0, 0, (float)sky.width, (float)sky.height};

   for (int i = 0; i < repetitions; ++i) {
    float dest_x = position + (i * sky.width);
    Rectangle sky_dest = {dest_x, y, (float)sky.width, (float)sky.height};
    DrawTexturePro(sky, sky_src, sky_dest, {0, 0}, 0.0f, WHITE);
  }
}

void SkyController::Update() {
  position -= speed * GetFrameTime();

  if (position <= -sky.width) {
    position += sky.width;
  }
}
