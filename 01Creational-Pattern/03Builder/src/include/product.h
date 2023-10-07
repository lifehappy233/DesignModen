#ifndef PRODUCT_H_
#define PRODUCT_H_

#include <string>
#include <iostream>

namespace builder {

class Car {
 public:
  auto SetTire(std::string tire) -> void {
    tire_ = tire;
    std::cout << "SetTire: " << tire_ << "\n";
  }

  auto SetEngine(std::string engine) -> void {
    engine_ = engine;
    std::cout << "SetEngine: " << engine_ << "\n";
  }

  auto SetSteeringWheel(std::string steering_wheel) -> void {
    steering_wheel_ = steering_wheel;
    std::cout << "SetSteeringWheel: " << steering_wheel_ << "\n";
  }
 private:

  std::string tire_;
  std::string engine_;
  std::string steering_wheel_;
};

}

#endif
