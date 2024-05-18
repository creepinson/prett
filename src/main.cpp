#include <cstdlib>
#include <cstring>
#include <filesystem>
#include <iostream>
#include <prett/color.hpp>
#include <span>
#include <string>

namespace prett::icon {
static std::string get(const std::filesystem::path &file_path) {
  const std::string file_name = file_path.string();

  if (file_name.ends_with(".cpp"))
    return prett::to_string(prett::Color::BLUE) + "";
  else if (file_name.ends_with(".ts"))
    return prett::to_string(prett::Color::BLUE) + "";
  else if (file_name.ends_with(".js"))
    return prett::to_string(prett::Color::YELLOW) + "";
  else if (file_name.ends_with(".json") || file_name.ends_with(".json5") ||
           file_name.ends_with(".jsonc"))
    return prett::to_string(prett::Color::YELLOW) + "";
  else if (file_name.ends_with("config"))
    return prett::to_string(prett::Color::CYAN) + "";
  else if (file_name.ends_with("data"))
    return prett::to_string(prett::Color::CYAN) + "";
  else if (file_name.ends_with("node_modules"))
    return prett::to_string(prett::Color::RED) + "";
  else if (file_name.ends_with("package-lock.json"))
    return prett::to_string(prett::Color::RED) + "";
  else if (file_name.ends_with("Dockerfile") ||
           file_name.ends_with("dockerfile") ||
           file_name.ends_with("Containerfile") ||
           file_name.ends_with("containerfile") ||
           file_name.ends_with("docker-compose.yml"))
    return prett::to_string(prett::Color::CYAN) + "";
  else if (file_name.ends_with(".git"))
    return prett::to_string(prett::Color::PURPLE) + "";
  else if (file_name.ends_with(".css"))
    return prett::to_string(prett::Color::BLUE) + "";
  else if (file_name.ends_with(".scss") || file_name.ends_with(".sass"))
    return prett::to_string(prett::Color::RED) + "";
  else if (file_name.ends_with(".github"))
    return prett::to_string(prett::Color::WHITE) + "";
  else if (file_name.ends_with(".md") || file_name.ends_with(".rst") ||
           file_name.ends_with(".org"))
    return prett::to_string(prett::Color::CYAN) + "";
  else if (file_name.ends_with(".flac") || file_name.ends_with(".mp3") ||
           file_name.ends_with(".wav") || file_name.ends_with(".ogg") ||
           file_name.ends_with(".opus"))
    return prett::to_string(prett::Color::PURPLE) + "";
  else if (std::filesystem::is_directory(file_path))
    return prett::to_string(prett::Color::PURPLE) + "";

  return prett::to_string(prett::Color::BLUE) + "";
}
} // namespace prett::icon

void list_files(const std::filesystem::path &path) {
  if (std::filesystem::is_directory(path)) {
    for (auto const &entry : std::filesystem::directory_iterator(path)) {
      std::cout << prett::icon::get(entry.path())
                << prett::to_string(prett::Color::DEFAULT) << " "
                << entry.path().filename().string() << std::endl;
    }
  } else {
    std::cout << prett::icon::get(path)
              << prett::to_string(prett::Color::DEFAULT) << " "
              << path.filename().string() << std::endl;
  }
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cout << "Usage: " << prett::to_string(prett::Color::PURPLE) << "prett"
              << prett::to_string(prett::Color::DEFAULT)
              << " <subcommand> [options]" << std::endl;
    std::cout << "   " << prett::to_string(prett::Color::CYAN) << "ls"
              << prett::to_string(prett::Color::DEFAULT)
              << ": List files in a directory." << std::endl;
    return 0;
  }

  auto const args = std::span(argv, static_cast<size_t>(argc));

  if (args.size() >= 1 && std::strcmp(args[0], "ls")) {
    if (args.size() < 3) {
      list_files(".");
    }

    for (std::size_t i = 2; i < args.size(); i++) {
      list_files(args[i]);
    }
  }

  return 0;
}
