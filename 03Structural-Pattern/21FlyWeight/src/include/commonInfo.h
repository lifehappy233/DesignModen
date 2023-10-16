#ifndef COMMONINFO_H_
#define COMMONINFO_H_

#include <string>
#include <iostream>
#include <utility>

namespace flyWeight {

class CommonInfo {
 public:
  CommonInfo() = delete;

  ~ CommonInfo() {
    std::cout << "~ CommonInfo\n";
  }

  CommonInfo(std::string name, std::string color)
      : name_(std::move(name)), color_(std::move(color)) {}

  auto GetName() -> std::string {
    return name_;
  }

  auto GetColor() -> std::string {
    return color_;
  }

 private:
  std::string name_;
  std::string color_;
};

}

#endif
