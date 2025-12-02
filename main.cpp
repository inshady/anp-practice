#include <iostream>

namespace topit {
  struct p_t {
    int x, y;
  };
  bool operator==(p_t a, p_t b);
  bool operator!=(p_t a, p_t b);
}


int main() {
  using namespace topit;
  p_t a{1,1}, b{0,1};
  std::cout << (a==b) << "\n";
}

bool topit::operator==(p_t a, p_t b) {
  return a.x == b.x && a.y == b.y;
}

bool topit::operator!=(p_t a, p_t b) {
  return !(a==b);
}