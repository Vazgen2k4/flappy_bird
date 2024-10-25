#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <chrono>
#include <iomanip>

#include "consts.h"

class Logger {
 private:
  static bool with_file;
  static std::string file_path;
  static std::ofstream log_file;

  static void write_log(const std::string& prefix, const std::string& message);

 public:
  static void initialize(const std::string& file);
  static void log(const std::string& message);
  static void log_error(const std::string& message);
  static void log_warning(const std::string& message);
  static void log_info(const std::string& message);
  static void close();
  
  
};
