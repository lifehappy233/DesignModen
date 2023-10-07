#ifndef CONCRETE_PRODUCT_H_
#define CONCRETE_PRODUCT_H_

#include <string>

#include "product.h"

namespace factory {

class ChineseMovie : public Movie {
 public:
  auto get_movie_name() -> std::string override {
    return "ChineseMovie";
  }
};

class JapaneseMovie : public Movie {
 public:
  auto get_movie_name() -> std::string override {
    return "JapaneseMovie";
  }
};

class ChineseBook : public Book {
 public:
  auto get_book_name() -> std::string override {
    return "ChineseBook";
  }
};

class JapaneseBook : public Book {
 public:
  auto get_book_name() -> std::string override {
    return "JapaneseBook";
  }
};

}

#endif
