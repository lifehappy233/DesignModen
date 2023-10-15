#ifndef COMPONENT_H_
#define COMPONENT_H_

#include <string>
#include <iostream>

namespace decorator {

class Component {
 public:
  virtual ~ Component() = default;

  virtual auto Execute(std::string str) -> void = 0;
};

class FileWriter : public Component {
 public:
  ~ FileWriter() override {
    std::cout << "~ FileWriter()\n";
  }

  auto Execute(std::string str) -> void override {
    std::cout << "write file: " << str << "\n";
  }
};
}

#endif
