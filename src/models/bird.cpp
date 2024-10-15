#include "bird.h"

Bird::Bird(const char* sourse) : angle(0) {
  Logger::log_info("Init Bird");
  Logger::log_info("Load bird sprite");

  texture = LoadTexture(sourse);

  width = texture.width;
  height = texture.height;

  y = GetScreenHeight() / 2 - height / 2;
  x = (GetScreenWidth() / 2 - width / 2) * .33;

  Logger::log_info("Bird width is [" + std::to_string(width) + "]");
  Logger::log_info("Bird height is [" + std::to_string(height) + "]");
}

void Bird::Update(bool start) {
  if (!start) {
    return;
  }

  const float gravity = 0.5f;
  const float jumpStrength = -10.0f;
  static float velocity = 0.0f;

  if (IsKeyPressed(KEY_SPACE)) {
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

  if (y > GetScreenHeight() - height) {
    y = GetScreenHeight() - height;
    velocity = 0;
  } else if (y < 0) {
    y = 0;
  }
}

void Bird::Draw() const {
  Vector2 origin = {static_cast<float>(width) / 2,
                    static_cast<float>(height) / 2};

  DrawTextureEx(texture, {x, y}, angle, 1.0f, WHITE);
}
