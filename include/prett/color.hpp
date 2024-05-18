#include <ostream>

namespace prett {
enum class Color {
  RED = 31,
  GREEN = 32,
  YELLOW = 33,
  BLUE = 34,
  PURPLE = 35,
  CYAN = 36,
  WHITE = 37,
  DEFAULT = 39
};

enum class BackgroundColor {
  RED = 41,
  GREEN = 42,
  YELLOW = 43,
  BLUE = 44,
  PURPLE = 45,
  CYAN = 46,
  WHITE = 47,
  DEFAULT = 49
};

std::string to_string(Color code);

std::ostream &operator<<(std::ostream &os, Color code);

std::string to_string(BackgroundColor code);

std::ostream &operator<<(std::ostream &os, BackgroundColor code);
} // namespace prett
