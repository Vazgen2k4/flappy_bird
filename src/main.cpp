#include <raylib.h>

#include "bird.hpp"
#include "consts.hpp"
#include "game.hpp"
#include "logger.hpp"
#include "pipe.hpp"
#include "pipe_controller.hpp"

int main() {
  Logger::initialize(Consts::LOGGER_FILE);
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
