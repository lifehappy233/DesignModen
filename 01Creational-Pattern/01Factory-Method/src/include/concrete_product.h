#ifndef CONCRETE_PRODUCT_H_
#define CONCRETE_PRODUCT_H_

#include "product.h"

namespace factory {

class ChineseProduct : public Product {
 public:
  auto get_name() -> std::string override {
    return "ChineseProduct";
  }
};

class JapaneseProduct : public Product {
 public:
  auto get_name() -> std::string override {
    return "JapaneseProduct";
  }
};

} // namespace factory

#endif
