#ifndef CONCRETE_PROTOTYPE_H_
#define CONCRETE_PROTOTYPE_H_

#include <memory>
#include <string>
#include <utility>

#include "prototype.h"

namespace prototype {

class Email : public Object {
 public:
  ~ Email() = default;

  Email() = default;

  Email(std::string &&title, std::string &&attach)
      : title_(std::move(title)), attach_(std::move(attach)) {}

  auto Clone() -> std::shared_ptr<Object> override {
    return std::make_shared<Email>(std::move(title_), std::move(attach_));
  }

  auto SetTitle(std::string title) -> void {
    title_ = std::move(title);
  }

  auto SetAttach(std::string attach) -> void {
    attach_ = std::move(attach);
  }

  auto Display() -> void {
    std::cout << "========== Display ==========\n";
    std::cout << "Title: " << title_ << "\n";
    std::cout << "Attach: " << attach_ << "\n";
    std::cout << "=============================\n";
  }

 private:
  std::string title_;
  std::string attach_;
};

}

#endif
