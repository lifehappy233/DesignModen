#ifndef STRATEGY_H_
#define STRATEGY_H_

#include <iostream>

namespace strategy {

class Strategy {
 public:
  virtual auto CalcPrice(double originalPrice) -> double = 0;
};

class NormalStrategy : public Strategy {
 public:
  ~ NormalStrategy() {
    std::cout << "~ NormalStrategy()\n";
  }

  auto CalcPrice(double originalPrice) -> double override {
    std::cout << "Normal Strategy, price * 1\n";
    return originalPrice;
  }
};

class VipStrategy : public Strategy {
 public:
  ~ VipStrategy() {
    std::cout << "~ VipStrategy()\n";
  }

  auto CalcPrice(double originalPrice) -> double override {
    std::cout << "Vip Strategy, price * 0.9\n";
    return originalPrice * 0.9;
  }
};


}

#endif
