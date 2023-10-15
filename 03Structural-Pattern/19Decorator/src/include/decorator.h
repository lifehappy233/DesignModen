#ifndef DECORATOR_H_
#define DECORATOR_H_

#include <memory>
#include <utility>
#include <utility>

#include "component.h"

namespace decorator {

class CompressDecorator : public Component {
 public:
  CompressDecorator() = delete;

  ~ CompressDecorator() override {
    std::cout << "~ CompressDecorator()\n";
  }

  explicit CompressDecorator(std::shared_ptr<Component> component)
      : component_(std::move(std::move(component))) {}

  auto Execute(std::string str) -> void override {
    component_->Execute("Compress(" + str + ")");
  }

 private:
  std::shared_ptr<Component> component_;
};

class EntropyDecorator : public Component {
 public:
  EntropyDecorator() = delete;

  ~ EntropyDecorator() override {
    std::cout << "~ EntropyDecorator()\n";
  }

  explicit EntropyDecorator(std::shared_ptr<Component> component)
      : component_(std::move(component)) {}

  auto Execute(std::string str) -> void override {
    component_->Execute("Entropy(" + str + ")");
  }

 private:
  std::shared_ptr<Component> component_;
};

}

#endif
