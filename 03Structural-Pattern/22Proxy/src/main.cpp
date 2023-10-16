#include <memory>
#include <iostream>

#include "proxy.h"
#include "client.h"
#include "server.h"

int main() {
  auto redisServer = std::make_shared<proxy::RedisServer>();
  auto redisProxy = std::make_shared<proxy::RedisProxy>(redisServer);

  auto client = proxy::Client(redisProxy);
  for (int i = 0; i < 3; i++) {
    std::cout << client.GetInfo(i) << "\n";
    std::cout << client.GetInfo(i) << "\n";
  }

  return 0;
}
