#ifndef BUTTON_H_
#define BUTTON_H_

#include <vector>

#include "command.h"

namespace command {

class Button {
 public:
  virtual auto Push() -> void = 0;

 protected:
  std::vector<std::shared_ptr<Command>> commands_;

  auto AddCommand(std::shared_ptr<Command> command) -> void {
    commands_.emplace_back(command);
  }
};

class CtrlXButton : public Button {
 public:
  auto Push() -> void override {
    std::cout << "Push CtrlX\n";
    if (commands_.empty()) {
      AddCommand(std::make_shared<CopyCommand>());
      AddCommand(std::make_shared<CutCommand>());
    }

    for (auto &it : commands_) {
      it->Execute();
    }
  }
};

class CtrlCButton : public Button {
 public:
  auto Push() -> void override {
    std::cout << "Push CtrlC\n";
    if (commands_.empty()) {
      AddCommand(std::make_shared<CopyCommand>());
    }

    for (auto &it : commands_) {
      it->Execute();
    }
  }
};

}

#endif
