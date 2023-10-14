#ifndef DRINK_H
#define DRINK_H

#include <iostream>

namespace temp {

class Drink {
 public:
  auto PreWork() -> void {
    std::cout << "Put tea\n";
  }

  virtual auto GetWater() -> void = 0;
  virtual auto Handle() -> void = 0;
};

class HotDrink : public Drink {
 public:
  auto GetWater() -> void override {
    std::cout << "Get hot water\n";
  }
  auto Handle() -> void override {
    std::cout << "Hot tea\n";
  }
};

class NormalDrink : public Drink {
 public:
  auto GetWater() -> void override {
    std::cout << "Get normal water\n";
  }
  auto Handle() -> void override {
    std::cout << "Normal tea\n";
  }
};

}

#endif
