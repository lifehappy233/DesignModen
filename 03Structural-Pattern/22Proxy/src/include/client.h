#ifndef CLIENT_H_
#define CLIENT_H_

#include <memory>
#include <utility>

#include "server.h"
#include "proxy.h"

namespace proxy {

class Client {
 public:
  Client() = delete;

  explicit Client(std::shared_ptr<Server> server) : server_(std::move(server)) {}

  auto GetInfo(int32_t id) -> std::string {
    auto result = server_->GetInfo(id);
    return result.first + " " + result.second;
  }

 private:
  std::shared_ptr<Server> server_;
};

}

#endif
