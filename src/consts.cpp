#include "consts.hpp"


const int Consts::WIN_WIDTH = 900;
const int Consts::WIN_HEIGHT = 600;

const string Consts::FILE_FOLDER = "flappy_data_vazgen/";
const string Consts::LOGGER_FILE = FILE_FOLDER + "info.log";
const string Consts::BEST_SCORE_FILE = FILE_FOLDER + "best.txt";
const int Consts::MAX_ANGLE_ROTATE_UP = 70;
const int Consts::MAX_ANGLE_ROTATE_DOWN = 30;

const float Consts::SCALE_BIRD = 1.0;
const float Consts::BIRD_HORIZONTAL_PERCENTILE = .33;

const float Consts::BIRD_GRAVITY = 0.5f;
const float Consts::BIRD_JUMP_STRENGTH = -10.0f;

const float Consts::spawnInterval = 1.5f;
const float Consts::pipeSpeed = 200.0f;
const float Consts::pipeGap = 120;
const float Consts::LAND_HEIGT = 112;

const int Consts::MEDAL_OFFSET_X = 31;
const int Consts::MEDAL_OFFSET_Y = 112;

const int Consts::WIDTH_COLIDER = 3;
const int Consts::FONT_SIZE = 20;

const int Consts::DashBoard_SCORES_DX = 175;
const int Consts::DashBoard_SCORES_DY = 105;
const int Consts::DashBoard_BEST_SCORES_DY = 145;


const Color Colors::BG = {78, 192, 202, 255};


const string Images::IMAGES_FOLDER = "assets/images/";
const string Images::BIRD = Images::IMAGES_FOLDER + "bird-01.png";
const string Images::LAND = Images::IMAGES_FOLDER + "land.png";

const string Images::PIPE_TO_DOWN = Images::IMAGES_FOLDER + "pipe-down.png";
const string Images::PIPE_TO_UP = Images::IMAGES_FOLDER + "pipe-up.png";
const string Images::PIPE = Images::IMAGES_FOLDER + "pipe.png";

const string Images::SCOREBOARD = Images::IMAGES_FOLDER + "scoreboard.png";
const string Images::SKY = Images::IMAGES_FOLDER + "sky.png";

const std::vector<std::string> Images::MEDAL_PATHS = {
    Images::IMAGES_FOLDER + "medal_bronze.png",
    Images::IMAGES_FOLDER + "medal_silver.png",
    Images::IMAGES_FOLDER + "medal_gold.png",
    Images::IMAGES_FOLDER + "medal_platinum.png",
};

void Consts::CreateDirectoryIfNotExists(const std::string& dir) {
  struct stat info;

  if (stat(dir.c_str(), &info) != 0) {
    if (mkdir(dir.c_str()) != 0) {
      std::cerr << "Error creating directory:" << dir << std::endl;
    }
  } else if (info.st_mode & S_IFDIR) {
    std::cout << "Directory already exists:" << dir << std::endl;
  } else {
    std::cerr << "Error: A file with this name already exists." << std::endl;
  }
}
