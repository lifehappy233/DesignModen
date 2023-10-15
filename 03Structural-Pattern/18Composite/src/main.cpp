#include <memory>

#include "file.h"

int main() {
  auto root = std::make_shared<composite::Director>("root");
  auto dir1 = std::make_shared<composite::Director>("dir1");
  auto dir2 = std::make_shared<composite::Director>("dir2");
  auto file11 = std::make_shared<composite::NormalFile>("file11");
  auto file12 = std::make_shared<composite::NormalFile>("file12");
  auto file21 = std::make_shared<composite::NormalFile>("file21");
  auto file22 = std::make_shared<composite::NormalFile>("file22");
  auto file23 = std::make_shared<composite::NormalFile>("file23");

  root->AddFile(dir1);
  root->AddFile(dir2);

  dir1->AddFile(file11);
  dir1->AddFile(file12);

  dir2->AddFile(file21);
  dir2->AddFile(file22);
  dir2->AddFile(file23);

  root->Process("");
  return 0;
}