#include "bird.h"

#include <sys/stat.h>

#include <iomanip>
#include <iostream>
#include <vector>

bool fileExists(const std::string& path) {
  struct stat buffer;
  return (stat(path.c_str(), &buffer) == 0);
}

Bird::Bird(const char* sourse) : x(100), y(100) {
  std::cout << "Init Bird" << std::endl;
  std::cout << "Load bird sprite" << std::endl;

  if (fileExists(sourse)) {
    std::cerr << "Error: File does not exist at path: " << sourse
              << std::endl;
  }
  texture = LoadTexture(sourse);

  width = texture.width;
  height = texture.height;
  std::cout << "Bird width is [" << std::setw(4) << width << "]" << std::endl;
  std::cout << "Bird height is [" << std::setw(4) << height << "]" << std::endl;
}

void Bird::Update() {}

void Bird::Draw() const { DrawTexture(texture, x, y, WHITE); }


