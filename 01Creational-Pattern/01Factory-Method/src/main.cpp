#include <iostream>
#include <string>

#include "creater.h"
#include "product.h"
#include "concrete_creater.h"

int main() {
  std::shared_ptr<factory::Creater> creater;
  std::shared_ptr<factory::Product> product;

  creater = std::make_shared<factory::ChineseCreater>();
  product = creater->get_product();
  std::cout << product->get_name() << "\n";

  creater = std::make_shared<factory::JapaneseCreater>();
  product = creater->get_product();
  std::cout << product->get_name() << "\n";
  return 0;
}
