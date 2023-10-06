#ifndef CONCRETE_CREATER_H_
#define CONCRETE_CREATER_H_

#include <string>

#include "creater.h"
#include "product.h"
#include "concrete_product.h"

namespace factory {

class ChineseCreater : public Creater {
 public:
  auto get_product() -> std::shared_ptr<Product> override {
    return std::make_shared<ChineseProduct>();
  }
};

class JapaneseCreater : public Creater {
 public:
  auto get_product() -> std::shared_ptr<Product> override {
    return std::make_shared<JapaneseProduct>();
  }
};

} // namespace factory

#endif
