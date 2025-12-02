#include <iostream>
#include <stdexcept>

namespace topit {
  struct p_t {
    int x, y;
  };

  struct f_t {
    p_t aa;
    p_t bb;
  };

  bool operator==(p_t a, p_t b);
  bool operator!=(p_t a, p_t b);

  struct IDraw {
    virtual p_t begin() const = 0;
    virtual p_t next(p_t prev) const = 0;
    virtual ~IDraw() = default;
  };

  struct Dot: IDraw {
    explicit Dot(p_t dd);
    p_t begin() const override;
    p_t next(p_t prev) const override;
    p_t d;
  };

  void append(const IDraw* sh, p_t** ppts, size_t &s);
}


int main() {
  using namespace topit;
  int err = 0;
  IDraw* shp[3] = {};
  p_t* pts = nullptr;
  size_t s = 0;
  try {
    shp[0] = new Dot({0, 0});
    shp[1] = new Dot({2, 3});
    for (size_t i = 0; i < 3; i++) {
      append(shp[i], &pts, s);
    }
  } catch (...) {
    std::cerr << "Error\n";
    err = 1;
  }
  delete shp[0];
  delete shp[1];
  return err;
}

topit::Dot::Dot(p_t dd):
 IDraw(),
 d{dd}
{}

topit::p_t topit::Dot::begin() const {
  return d;
}

topit::p_t topit::Dot::next(p_t prev) const {
  if (prev != d) {
    throw std::logic_error("bad prev");
  }
  return d;
}

bool topit::operator==(p_t a, p_t b) {
  return a.x == b.x && a.y == b.y;
}

bool topit::operator!=(p_t a, p_t b) {
  return !(a==b);
}