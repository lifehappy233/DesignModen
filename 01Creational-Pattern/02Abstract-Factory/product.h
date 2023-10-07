#ifndef PRODUCT_H_
#define PRODUCT_H_

#include <string>

namespace factory {

class Movie {
 public:
  virtual auto get_movie_name() -> std::string = 0;
};

class Book {
 public:
  virtual auto get_book_name() -> std::string = 0;
};

}

#endif
