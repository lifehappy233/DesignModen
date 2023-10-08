#ifndef SINGLETON_H_
#define SINGLETON_H_

#include <atomic>
#include <iostream>

namespace singleton {

class Singleton;

class IDGenerator {
 public:
  IDGenerator(const IDGenerator &idGenerator) = delete;

  IDGenerator(const IDGenerator &&idGenerator) = delete;

  IDGenerator& operator = (const IDGenerator &idGenerator) = delete;

  IDGenerator& operator = (const IDGenerator &&idGenerator) = delete;

  ~IDGenerator() {
    std::cout << "~IDGenerator()\n";
  }

  auto GetNextID() -> int64_t {
    return ++next_id_;
  }

  friend class Singleton;

 private:
  std::atomic<int64_t> next_id_{0};

  IDGenerator() {
    std::cout << "IDGenerator()\n";
  }
};

class Singleton {
 public:
  auto GetIDGenerator() -> std::shared_ptr<IDGenerator> {
    if (idGenerator_) {
      return idGenerator_;
    }

    auto lock = std::unique_lock<std::mutex>(mutex_);

    if (idGenerator_) {
      return idGenerator_;
    }
    idGenerator_ = std::shared_ptr<IDGenerator>(new IDGenerator());
    return idGenerator_;
  }

 private:
  std::shared_ptr<IDGenerator> idGenerator_{nullptr};

  std::mutex mutex_;
};

}

#endif
