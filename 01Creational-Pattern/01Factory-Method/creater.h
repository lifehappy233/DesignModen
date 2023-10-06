#ifndef CREATER_H_
#define CREATER_H_

#include <memory>

#include "product.h"

namespace factory {

class Creater {
 public:
  virtual auto get_product() -> std::shared_ptr<Product> = 0;
};

} // namespace factory

#endif
