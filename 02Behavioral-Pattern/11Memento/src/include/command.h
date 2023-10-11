#ifndef COMMAND_H_
#define COMMAND_H_

#include <utility>
#include <iostream>

#include "snapshot.h"
#include "editor.h"

namespace memento {

class Command {
 public:
  ~ Command() {
    std::cout << "~ Command()\n";
  }

  explicit Command(std::shared_ptr<Editor> editor)
      : editor_(std::move(editor)) {}

  auto Save() -> void {
    snapshot_ = editor_->CreateSnapshot();
  }

  auto Undo() -> void {
    if (snapshot_) {
      editor_->LoadSnapshot(snapshot_);
    }
  }

 private:
  std::shared_ptr<Editor> editor_;
  std::shared_ptr<Snapshot> snapshot_;
};

}

#endif
