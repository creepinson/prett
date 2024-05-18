#include <prett/color.hpp>

namespace prett {
std::string to_string(Color code) {
  std::string str("\e[0;");
  str.append(std::to_string(static_cast<int>(code)));
  str.append("m");
  return str;
}

std::ostream &operator<<(std::ostream &os, Color code) {
  return os << to_string(code);
}

std::string to_string(BackgroundColor code) {
  std::string str("\e[");
  str.append(std::to_string(static_cast<int>(code)));
  str.append("m");
  return str;
}

std::ostream &operator<<(std::ostream &os, BackgroundColor code) {
  return os << to_string(code);
}

} // namespace prett
