#ifndef PRICE_H_
#define PRICE_H_

#include <memory>
#include <utility>
#include <iostream>

#include "strategy.h"

namespace strategy {

class Price {
 public:
  Price() = delete;

  ~ Price() {
    std::cout << "~ Price()\n";
  }

  explicit Price(std::shared_ptr<Strategy> strategy)
      : strategy_(std::move(strategy)) {}

  auto GetPrice(double originalPrice) -> double {
    return strategy_->CalcPrice(originalPrice);
  }

 private:
  std::shared_ptr<Strategy> strategy_;
};

}

#endif
