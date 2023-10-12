#include <memory>

#include "price.h"
#include "strategy.h"

int main() {
  {
    auto strategy = std::make_shared<strategy::NormalStrategy>();
    strategy::Price price(strategy);
    std::cout << price.GetPrice(10) << "\n";
  }

  std::cout << "\n------------------------------\n\n";

  {
    auto strategy = std::make_shared<strategy::VipStrategy>();
    strategy::Price price(strategy);
    std::cout << price.GetPrice(10) << "\n";
  }
  return 0;
}
