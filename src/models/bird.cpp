#include "bird.hpp"

Bird::Bird(const char* sourse) : angle(0) {
  Logger::log_info("Init Bird");
  Logger::log_info("Load bird sprite");

  texture = LoadTexture(sourse);

  setWidth(texture.width);
  setHeight(texture.height);

  Bird::Reset();

  max_y_pos = Consts::WIN_HEIGHT - getHeight() - Consts::LAND_HEIGT;

  Logger::log_info("Bird width is [" + std::to_string(getWidth()) + "]");
  Logger::log_info("Bird height is [" + std::to_string(getHeight()) + "]");
}

Bird::~Bird() { UnloadTexture(texture); }

void Bird::Update() {
  static float velocity = 0.0f;

  if (IsKeyPressed(KEY_SPACE)) {
    PlayWingSound();
    velocity = Consts::BIRD_JUMP_STRENGTH;
  }

  velocity += Consts::BIRD_GRAVITY;
  angle += velocity;
  setY(getY() + velocity);

  if (angle > Consts::MAX_ANGLE_ROTATE_UP) {
    angle = Consts::MAX_ANGLE_ROTATE_UP;
  } else if (angle < -Consts::MAX_ANGLE_ROTATE_DOWN) {
    angle = -Consts::MAX_ANGLE_ROTATE_DOWN;
  }

  if (getY() > max_y_pos) {
    velocity = 0;
    setY(max_y_pos);
  } else if (getY() < 0) {
    setY(0);
  }
}

void Bird::Draw(bool with_debug) const {
  DrawTextureEx(texture, getCoords(), angle, Consts::SCALE_BIRD, WHITE);

  if (with_debug) {
    DrawRectangleLinesEx(getHitBox(), Consts::WIDTH_COLIDER, RED);
  }
}

void Bird::Reset() {
  setX((Consts::WIN_WIDTH / 2 - getWidth() / 2) * Consts::BIRD_HORIZONTAL_PERCENTILE);
  setY((Consts::WIN_HEIGHT / 2) - getHeight() / 2);
  angle = 0;
}