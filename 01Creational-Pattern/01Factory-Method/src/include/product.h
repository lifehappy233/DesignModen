#ifndef PRODUCT_H_
#define PRODUCT_H_

#include <string>

namespace factory {

class Product {
 public:
  virtual auto get_name() -> std::string = 0;
};
  
} // namespace factory 

#endif
