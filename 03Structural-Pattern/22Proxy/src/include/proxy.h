#ifndef PROXY_H_
#define PROXY_H_

#include <map>
#include <utility>
#include <utility>

#include "server.h"

namespace proxy {

class RedisProxy : public Server {
 public:
  RedisProxy() = delete;

  ~ RedisProxy() override {
    std::cout << "~ RedisProxy()\n";
  }

  explicit RedisProxy(std::shared_ptr<Server> redisServer)
      : redisServer_(std::move(redisServer)) {}

  auto GetInfo(int32_t id) -> std::pair<std::string, std::string> override {
    if (redisInfos_.count(id)) {
      return std::make_pair(redisInfos_[id], "RedisProxy");
    }

    auto result = std::make_pair(std::to_string(id) + "_RedisInfo", "RedisServer");
    redisInfos_[id] = result.first;
    return result;
  }

 private:
  std::map<int32_t, std::string> redisInfos_;
  std::shared_ptr<Server> redisServer_;
};

}

#endif
