#include "logger.h"

bool Logger::with_file = false;
std::string Logger::file_path = "";
std::ofstream Logger::log_file;

void Logger::initialize(const std::string& file) {
  file_path = file;
  with_file = true;
  log_file.open(file_path, std::ios::out | std::ios::app);

  if (!log_file.is_open()) {
    std::cerr << "Ошибка открытия файла для логирования: " << file_path
              << std::endl;
  }
}

void Logger::close() {
  if (with_file && log_file.is_open()) {
    log_file.close();
  }
}

void Logger::write_log(const std::string& prefix, const std::string& message) {
  auto now = std::chrono::system_clock::now();
  std::time_t now_time_t = std::chrono::system_clock::to_time_t(now);
  std::tm now_tm = *std::localtime(&now_time_t);

  if (with_file && log_file.is_open()) {
    log_file << prefix << "[" << std::put_time(&now_tm, "%H:%M:%S") << "] "
             << message << std::endl;
  }

  std::cout << prefix << "[" << std::put_time(&now_tm, "%H:%M:%S") << "] "
            << message << std::endl;
  ;
}

void Logger::log(const std::string& message) { write_log("[LOG]: ", message); }

void Logger::log_error(const std::string& message) {
  write_log("[ERROR]:", message);
}

void Logger::log_warning(const std::string& message) {
  write_log("[WARNING]:", message);
}

void Logger::log_info(const std::string& message) {
  write_log("[INFO]:", message);
}
