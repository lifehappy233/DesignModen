#ifndef MEDIATOR_H_
#define MEDIATOR_H_

#include <string>
#include <memory>
#include <iostream>
#include <utility>

namespace mediator {

class Colleague;

class Mediator {
 public:
  virtual auto SendMessage(Colleague *colleague) -> void = 0;

  auto AddColleague(const std::shared_ptr<Colleague>& colleague) -> void {
    colleagues_.emplace_back(colleague);
  }

 protected:
  std::vector<std::weak_ptr<Colleague>> colleagues_;
};

enum class HouseAgentType {
  Tenant = 0,
  Landlord = 1,
};

class Colleague {
 public:
  Colleague(HouseAgentType type, std::shared_ptr<Mediator> mediator)
      : type_(type), mediator_(std::move(mediator)) {}

  virtual auto SendMessage() -> void = 0;

  virtual auto GetMessage() -> void =0;

  auto GetType() -> HouseAgentType {
    return type_;
  }

 protected:
  HouseAgentType type_;
  std::weak_ptr<Mediator> mediator_;
};

class HouseAgent : public Mediator {
 public:
  ~ HouseAgent() {
    std::cout << "~ HouseAgent()\n";
  }

  auto SendMessage(Colleague *colleague) -> void override {
    for (auto &it : colleagues_) {
      if (it.lock()->GetType() != colleague->GetType()) {
        it.lock()->GetMessage();
      }
    }
  }
};

class Tenant : public Colleague {
 public:
  ~ Tenant() {
    std::cout << "~ Tenant()\n";
  }

  Tenant(std::string name, std::shared_ptr<Mediator> mediator)
      : Colleague(HouseAgentType::Tenant, std::move(mediator)),
        name_(std::move(name)) {}
  auto SendMessage() -> void override {
    mediator_.lock()->SendMessage(this);
  }

  auto GetMessage() -> void override {
    std::cout << name_ << ": Tenant get house\n";
  }
 private:
  std::string name_;
};

class Landlord : public Colleague {
 public:
  ~ Landlord() {
    std::cout << "~ Landlord()\n";
  }

  Landlord(std::string name, std::shared_ptr<Mediator> mediator)
      : Colleague(HouseAgentType::Landlord, std::move(mediator)),
        name_(std::move(name)) {}
  auto SendMessage() -> void override {
    mediator_.lock()->SendMessage(this);
  }

  auto GetMessage() -> void override {
    std::cout << name_ << ": Landlord have house\n";
  }
 private:
  std::string name_;
};

}

#endif
