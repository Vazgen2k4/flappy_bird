#include "consts.h"

// Определение статических переменных Consts
const int Consts::WIN_WIDTH = 900;
const int Consts::WIN_HEIGHT = 600;
const string Consts::LOGGER_FILE = "log.txt";
const int Consts::MAX_ANGLE_ROTATE_UP = 70;
const int Consts::MAX_ANGLE_ROTATE_DOWN = 30;

const float Consts::SCALE_PIPE = 3.0;
const float Consts::SCALE_BIRD = 1.7;


// Определение статических переменных Colors
const Color Colors::BG = {20, 160, 133, 255};

// Определение статических переменных Images
const string Images::IMAGES_FOLDER = "assets/images/";
const string Images::BIRD = Images::IMAGES_FOLDER + "bird-01.png";
const string Images::LAND = Images::IMAGES_FOLDER + "land.png";
const string Images::PIPE_DOWN = Images::IMAGES_FOLDER + "PipeDown.png";
const string Images::PIPE_UP = Images::IMAGES_FOLDER + "PipeUp.png";
const string Images::SCOREBOARD = Images::IMAGES_FOLDER + "scoreboard.png";
const string Images::SKY = Images::IMAGES_FOLDER + "sky.png";
