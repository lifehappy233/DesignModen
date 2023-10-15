#ifndef COLOR_H_
#define COLOR_H_

#include <string>
#include <iostream>

namespace bridge {

class Color {
 public:
  virtual ~ Color() = default;

  virtual auto GetColor() -> std::string = 0;
};

class Pink : public Color {
 public:
  ~ Pink() override {
    std::cout << "~ Pink()\n";
  }

  auto GetColor() -> std::string override {
    return "Pink";
  }
};

class Blue : public Color {
 public:
  ~ Blue() override {
    std::cout << "~ Blue()\n";
  }

  auto GetColor() -> std::string override {
    return "Blue";
  }
};

}

#endif
