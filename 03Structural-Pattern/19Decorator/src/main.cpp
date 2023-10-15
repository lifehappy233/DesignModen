#include <memory>

#include "decorator.h"
#include "component.h"

int main() {
  auto fileWriter = std::make_shared<decorator::FileWriter>();

  auto compressDecorator =
      std::make_shared<decorator::CompressDecorator>(fileWriter);

  auto entropyDecorator =
      std::make_shared<decorator::EntropyDecorator>(compressDecorator);

  std::cout << fileWriter.use_count() << " "
            << compressDecorator.use_count() << " "
            << entropyDecorator.use_count() << "\n";

  entropyDecorator->Execute("data");
  return 0;
}