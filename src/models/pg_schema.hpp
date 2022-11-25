#pragma once
#include <fmt/core.h>
#include <string>
#include <string_view>

namespace Models {
struct pg_schema {
  std::string name;
  int count;
};
std::string ToString(const pg_schema& rhs) {
  return fmt::format("{} {}", rhs.name, rhs.count);
}
}  // namespace Models