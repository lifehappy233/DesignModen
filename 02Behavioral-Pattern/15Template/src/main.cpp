#include <iostream>

#include "drink.h"
#include "worker.h"

int main() {
  temp::HotDrink hotDrink;
  temp::NormalDrink normalDrink;

  temp::Worker worker;

  worker.Done(&hotDrink);
  std::cout << "------------\n";
  worker.Done(&normalDrink);
  return 0;
}
