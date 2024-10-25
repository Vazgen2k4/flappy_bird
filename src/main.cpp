#include <raylib.h>

#include "bird.h"
#include "consts.h"
#include "game.h"
#include "logger.h"
#include "pipe.h"
#include "pipe_controller.h"

int main() {
  // Logger::initialize(Consts::LOGGER_FILE);
  Logger::log_info("Init window");

  const std::string title = "Flappy Bird by Vazgen";

  Game game(Images::BIRD, title, 60);

  Bird bird = {Images::BIRD.c_str()};
  PipeController pipeController;

  game.Init(&bird, &pipeController);
  game.Run();

  Logger::close();
  return 0;
}
