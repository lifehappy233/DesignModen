#ifndef PEN_H_
#define PEN_H_

#include <memory>
#include <utility>

#include "color.h"

namespace bridge {
class Pen {
 public:
  Pen() = delete;

  virtual ~ Pen() = default;

  explicit Pen(std::shared_ptr<Color> color) : color_(std::move(color)) {}

  auto GetColor() -> std::string {
    return color_->GetColor();
  }

  virtual auto GetTypeName() -> std::string = 0;

 private:
  std::shared_ptr<Color> color_;
};

class Pencil : public Pen {
 public:
  Pencil() = delete;

  ~ Pencil() override {
    std::cout << "~ Pencil()\n";
  }

  explicit Pencil(std::shared_ptr<Color> color) : Pen(std::move(color)) {}

  auto GetTypeName() -> std::string override {
    return "Pencil";
  }
};

class BallPen : public Pen {
 public:
  BallPen() = delete;

  ~ BallPen() override {
    std::cout << "~ BallPen()\n";
  }

  explicit BallPen(std::shared_ptr<Color> color) : Pen(std::move(color)) {}

  auto GetTypeName() -> std::string override {
    return "BallPen";
  }
};

}

#endif
