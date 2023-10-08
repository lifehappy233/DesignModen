#include <iostream>

#include "concrete_prototype.h"

int main() {
  auto email = std::make_shared<prototype::Email>();
  email->SetTitle("original email");
  email->SetAttach("original email's attach");

  auto original_email = std::dynamic_pointer_cast<prototype::Email>(email->Clone());

  email->SetTitle("new email");
  email->SetAttach("new email's attach");

  original_email->Display();
  email->Display();
  return 0;
}
