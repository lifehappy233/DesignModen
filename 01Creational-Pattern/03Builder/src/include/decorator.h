#ifndef DECORATOR_H_
#define DECORATOR_H_

#include <memory>

#include "builder.h"
#include "product.h"

namespace builder {

class Decorator {
 public:
  Decorator() = default;

  Decorator(std::unique_ptr<CarBuilder> &&car_builder)
      : car_builder_(std::move(car_builder)) {}

  auto SetBuilder(std::unique_ptr<CarBuilder> &&car_builder) -> void {
    car_builder_ = std::move(car_builder);
  }

  auto ConstructCar() -> Car {
    car_builder_->BuildTire();
    car_builder_->BuildSteeringWheel();
    car_builder_->BuildEngine();
    return car_builder_->GetCar();
  }

 private:
  std::unique_ptr<CarBuilder> car_builder_{nullptr};
};

}

#endif
