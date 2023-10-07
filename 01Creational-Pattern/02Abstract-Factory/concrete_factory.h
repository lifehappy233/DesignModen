#ifndef CONCRETE_FACTORY_H_
#define CONCRETE_FACTORY_H_

#include <memory>

#include "factory.h"
#include "product.h"
#include "concrete_product.h"

namespace factory {

class ChineseCreator : public Creator {
 public:
  auto create_movie() -> std::shared_ptr<Movie> override {
    return std::make_shared<ChineseMovie>();
  }

  auto create_book() -> std::shared_ptr<Book> override {
    return std::make_shared<ChineseBook>();
  }
};

class JapaneseCreator : public Creator {
 public:
  auto create_movie() -> std::shared_ptr<Movie> override {
    return std::make_shared<JapaneseMovie>();
  }

  auto create_book() -> std::shared_ptr<Book> override {
    return std::make_shared<JapaneseBook>();
  }
};

}

#endif
