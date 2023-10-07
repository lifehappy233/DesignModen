#ifndef BUILDER_H_
#define BUILDER_H_

#include "product.h"

namespace builder {

class CarBuilder {
 public:
  virtual ~CarBuilder() = default;

  Car GetCar() {
    return car_;
  }

  virtual auto BuildTire() -> void = 0;
  virtual auto BuildEngine() -> void = 0;
  virtual auto BuildSteeringWheel() -> void = 0;

 protected:
  Car car_;
};

}

#endif
