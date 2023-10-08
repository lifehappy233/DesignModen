#include <iostream>
#include <memory>
#include <thread>
#include <vector>
#include <string>

#include "singleton.h"

int main() {
  auto single = std::make_shared<singleton::Singleton>();

  std::vector<std::thread> threads;
  for (int i = 0; i < 10; i++) {
    threads.emplace_back([single = single, id = i]() {
      auto idGenerator = single->GetIDGenerator();
      for (int i = 0; i < 1000; i++) {
        std::string str = std::to_string(id) + ": " +
                          std::to_string(idGenerator->GetNextID()) + "\n";
        std::cout << str;
      }
    });
  }
  for (int i = 0; i < 10; i++) {
    threads[i].join();
  }
  return 0;
}
