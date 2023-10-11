#ifndef SNAPSHOT_H_
#define SNAPSHOT_H_

#include <memory>
#include <string>
#include <utility>
#include <iostream>

namespace memento {

class Snapshot {
 public:
  ~ Snapshot() {
    std::cout << "~ Snapshot()\n";
  }

  explicit Snapshot(std::string content) : content_(std::move(content)) {}

  auto GetContent() -> std::string { return content_; }

 private:
  std::string content_;
};

}

#endif
