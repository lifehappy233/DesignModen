#ifndef PUBLISHER_H_
#define PUBLISHER_H_

#include <iostream>
#include <memory>
#include <set>

#include "subscriber.h"

namespace observer {

class Supermarket {
 public:
  auto Subscribe(const std::shared_ptr<Subscriber>& subscriber) -> void {
    subscribers_.insert(subscriber);
  }

  auto CancelSubscribe(const std::shared_ptr<Subscriber>& subscriber) -> void {
    subscribers_.erase(subscribers_.find(subscriber));
  }

  auto SomethingArrived() -> void {
    std::cout << "SomethingArrived --------------------\n";
    for (auto &it : subscribers_) {
      it->DoSomething();
    }
  }
 public:
  std::set<std::shared_ptr<Subscriber>> subscribers_;
};
}

#endif
