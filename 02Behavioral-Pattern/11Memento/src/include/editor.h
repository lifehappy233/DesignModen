#ifndef EDITOR_H_
#define EDITOR_H_

#include <string>
#include <iostream>

#include "snapshot.h"

namespace memento {

class Editor {
 public:
  ~ Editor() {
    std::cout << "~ Editor()\n";
  }

  auto AddContent(const std::string& content) -> void {
    content_ += content;
  }

  auto CreateSnapshot() -> std::shared_ptr<Snapshot> {
    return std::make_shared<Snapshot>(content_);
  }

  auto LoadSnapshot(const std::shared_ptr<Snapshot>& snapshot) -> void {
    content_ = snapshot->GetContent();
  }

  auto Show() -> void {
    std::cout << content_ << "\n";
  }

 private:

  std::string content_;
};

}


#endif
