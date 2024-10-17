#include <raylib.h>
#include <unistd.h>

#include <cstring>
#include <iostream>
#include <vector>

#include "bird.h"
#include "consts.h"
#include "logger.h"
#include "pipe.h"
#include "pipe_controller.h"

int main() {
  Logger::initialize(Consts::LOGGER_FILE);

  InitWindow(Consts::WIN_WIDTH, Consts::WIN_HEIGHT, "Vazgen project");
  SetTargetFPS(60);

  SetWindowIcon(LoadImage(Images::BIRD.c_str()));

  Logger::log_info("Init window");

  // Загрузка текстуры для экрана "Game Over"
  Texture2D gameOverTexture = LoadTexture(Images::SCOREBOARD.c_str());

  Bird bird = {Images::BIRD.c_str()};
  PipeController pipeController;

  bool start = false;
  bool gameOver = false;
  int score = 0;

  while (!WindowShouldClose()) {
    if (!gameOver && !start && IsKeyPressed(KEY_SPACE)) {
      start = true;
    }

    // Обновляем трубы, если игра началась и не наступил гейм овер
    if (start && !gameOver) {
      // Обновляем состояние птички
      bird.Update(start);
      pipeController.Update(bird, score, gameOver);
    }

    BeginDrawing();
    ClearBackground(Colors::BG);

    // Отрисовываем трубы и птичку
    pipeController.Draw();
    bird.Draw();

    // Отображаем счет на экране
    DrawText(TextFormat("Score: %i", score), 10, 10, 20, WHITE);

    if (gameOver) {
      DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), {0, 0, 0, 100});
      DrawTexture(gameOverTexture,
                  (Consts::WIN_WIDTH - gameOverTexture.width) / 2,
                  (Consts::WIN_HEIGHT - gameOverTexture.height) / 2, WHITE);

      // Перезапуск игры при нажатии клавиши R
      if (IsKeyPressed(KEY_R)) {
        pipeController.Reset();
        bird = Bird(Images::BIRD.c_str());  // Пересоздаем птицу
        score = 0;
        start = false;
        gameOver = false;
      }
    }

    EndDrawing();
  }

  // Освобождаем ресурсы после завершения
  UnloadTexture(gameOverTexture);
  CloseWindow();
}
