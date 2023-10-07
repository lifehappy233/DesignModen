#ifndef CONCRETE_BUILDER_H_
#define CONCRETE_BUILDER_H_

#include "product.h"
#include "builder.h"

namespace builder {

class BenzBuilder : public CarBuilder {
 public:

  ~ BenzBuilder() = default;

  auto BuildTire() -> void override {
    car_.SetTire("BenzTire");
  }

  auto BuildEngine() -> void override {
    car_.SetEngine("BenzEngine");
  }

  auto BuildSteeringWheel() -> void override {
    car_.SetSteeringWheel("BenzSteeringWheel");
  }
};

class AudiBuilder : public CarBuilder {
 public:
  ~ AudiBuilder() = default;

  auto BuildTire() -> void override {
    car_.SetTire("AudiTire");
  }

  auto BuildEngine() -> void override {
    car_.SetEngine("AudiEngine");
  }

  auto BuildSteeringWheel() -> void override {
    car_.SetSteeringWheel("AudiSteeringWheel");
  }
};

}

#endif
