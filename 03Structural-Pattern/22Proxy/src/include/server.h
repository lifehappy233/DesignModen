#ifndef SERVER_H_
#define SERVER_H_

#include <string>

namespace proxy {

class Server {
 public:
  virtual ~ Server() = default;

  virtual auto GetInfo(int32_t id) -> std::pair<std::string, std::string> = 0;
};

class RedisServer : public Server {
 public:

  ~ RedisServer() override {
    std::cout << "~ RedisServer()\n";
  }

  auto GetInfo(int32_t id) -> std::pair<std::string, std::string> override {
    return std::make_pair(std::to_string(id) + "_RedisInfo", "RedisServer");
  }
};

}

#endif
