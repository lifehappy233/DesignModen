#include <iostream>
#include <string>

#include "creater.h"
#include "product.h"
#include "concrete_creater.h"
#include "concrete_creater.h"

int main() {
  std::shared_ptr<factory::Creater> creater;
  std::shared_ptr<factory::Product> product;

  std::string conf;
  std::cin >> conf;

  if (conf == "china") {
    creater = std::make_shared<factory::ChineseCreater>();
  } else if (conf == "japan") {
    creater = std::make_shared<factory::JapaneseCreater>();
  } else {
    std::cout << "error conf\n";
    exit(1);
  }

  product = creater->get_product();
  std::cout << product->get_name() << "\n";
  return 0;
}
