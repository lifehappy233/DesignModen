#ifndef COMMAND_H_
#define COMMAND_H_

#include <iostream>

namespace command {

class Command {
 public:
  virtual auto Execute() -> void = 0;
};

class SaveCommand : public Command {
 public:
  auto Execute() -> void override {
    std::cout << "Save\n";
  }
};

class CopyCommand : public Command {
 public:
  auto Execute() -> void override {
    std::cout << "Copy\n";
  }
};

class CutCommand : public Command {
 public:
  auto Execute() -> void override {
    std::cout << "Cut\n";
  }
};

}

#endif
