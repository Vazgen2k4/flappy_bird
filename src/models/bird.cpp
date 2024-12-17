#include "bird.hpp"


Bird::Bird(const char* sourse) : angle(0) {
  Logger::log_info("Init Bird");
  Logger::log_info("Load bird sprite");

  texture = LoadTexture(sourse);

  width = texture.width;
  height = texture.height;

  Bird::Reset();

  max_y_pos = Consts::WIN_HEIGHT - height - Consts::LAND_HEIGT;

  Logger::log_info("Bird width is [" + std::to_string(width) + "]");
  Logger::log_info("Bird height is [" + std::to_string(height) + "]");
}

Bird::~Bird() { UnloadTexture(texture); }

void Bird::Update() {
  const float gravity = 0.5f;
  const float jumpStrength = -10.0f;
  static float velocity = 0.0f;

  if (IsKeyPressed(KEY_SPACE)) {    
    PlayWingSound();
    velocity = jumpStrength;
  }

  velocity += gravity;
  y += velocity;
  angle += velocity;

  if (angle > Consts::MAX_ANGLE_ROTATE_UP) {
    angle = Consts::MAX_ANGLE_ROTATE_UP;
  } else if (angle < -Consts::MAX_ANGLE_ROTATE_DOWN) {
    angle = -Consts::MAX_ANGLE_ROTATE_DOWN;
  }

  if (y > max_y_pos) {
    velocity = 0;
    y = max_y_pos;
  } else if (y < 0) {
    y = 0;
  }
}

void Bird::Draw(bool with_debug) const {
  DrawTextureEx(texture, {x, y}, angle, Consts::SCALE_BIRD, WHITE);

  if (with_debug) {
    DrawRectangleLinesEx(getHitBox(), Consts::WIDTH_COLIDER, RED);
  }
}

void Bird::Reset() {
  y = (Consts::WIN_HEIGHT / 2) - height / 2;
  x = (Consts::WIN_WIDTH / 2 - width / 2) * .33;
  angle = 0;
}