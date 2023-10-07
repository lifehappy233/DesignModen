#include <memory>

#include "product.h"
#include "builder.h"
#include "decorator.h"
#include "concrete_builder.h"

int main() {
  auto decorator = std::make_unique<builder::Decorator>();
  std::unique_ptr<builder::CarBuilder> car_builder;

  car_builder = std::make_unique<builder::BenzBuilder>();
  decorator->SetBuilder(std::move(car_builder));
  builder::Car benz_car = decorator->ConstructCar();

  std::cout << "-------------------------------------\n";

  car_builder = std::make_unique<builder::AudiBuilder>();
  decorator->SetBuilder(std::move(car_builder));
  builder::Car audi_car = decorator->ConstructCar();
  return 0;
}
