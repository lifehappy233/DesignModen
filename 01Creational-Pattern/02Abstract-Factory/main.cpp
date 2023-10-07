#include <iostream>

#include "product.h"
#include "factory.h"
#include "concrete_factory.h"

int main() {
  std::shared_ptr<factory::Creator> creator;
  std::shared_ptr<factory::Movie> movie;
  std::shared_ptr<factory::Book> book;

  creator = std::make_shared<factory::ChineseCreator>();
  movie = creator->create_movie();
  book = creator->create_book();
  std::cout << movie->get_movie_name() << ", " << book->get_book_name() << "\n";

  creator = std::make_shared<factory::JapaneseCreator>();
  movie = creator->create_movie();
  book = creator->create_book();
  std::cout << movie->get_movie_name() << ", " << book->get_book_name() << "\n";
  return 0;
}
