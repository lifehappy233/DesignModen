#ifndef ACCOUNT_H_
#define ACCOUNT_H_

#include <string>
#include <iostream>
#include <memory>
#include <utility>

namespace state {

class Account;

class State {
 public:
  virtual auto CurrentState(Account *account) -> void = 0;
  virtual auto Handle(Account *account) -> void = 0;
};

class EnterState : public State {
 public:
  auto CurrentState(Account *account) -> void override {
    std::cout << "Do nothing\n";
  }

  auto Handle(Account *account) -> void override {
    std::cout << "Enter Handle\n";
  }
};

class NewbieState : public State {
 public:
  auto CurrentState(Account *account) -> void override;

  auto Handle(Account *account) -> void override {
    std::cout << "Newbie Handle\n";
  }
};

class Account {
 public:
  Account() = delete;

  explicit Account(std::string name) : name_(std::move(name)) {
    state_ = std::make_shared<NewbieState>();
  }

  [[nodiscard]] auto GetSource() const -> int64_t {
    return source_;
  }

  auto SetState(std::shared_ptr<State> state) -> void {
    state_ = std::move(state);
  }

  auto PublicPaper() -> void {
    std::cout << name_ << " public paper\n";
    source_ += 10;
    state_->CurrentState(this);
    state_->Handle(this);
  }

 private:
  std::string name_;
  int64_t source_{0};
  std::shared_ptr<State> state_;
};

}

#endif
