#ifndef FACTORY_H_
#define FACTORY_H_

#include <memory>

#include "product.h"

namespace factory {

class Creator {
 public:
  virtual auto create_movie() -> std::shared_ptr<Movie> = 0;
  virtual auto create_book() -> std::shared_ptr<Book> = 0;
};

}

#endif
