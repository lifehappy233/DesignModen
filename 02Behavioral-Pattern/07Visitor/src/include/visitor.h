#ifndef ITEM_H_
#define ITEM_H_

#include <memory>
#include <iostream>

namespace visitor {

class Fruit;
class Meat;

class Visitor {
 public:
  virtual auto Visit(Fruit *fruit) -> void = 0;

  virtual auto Visit(Meat *meat) -> void = 0;
};

class Item {
 public:

  virtual ~ Item() = default;

  virtual auto Accept(std::shared_ptr<Visitor> visitor) -> void = 0;

  virtual auto GetPrice() -> int64_t = 0;
};

class Fruit : public Item {
 public:
  ~ Fruit() override {
    std::cout << "~ Fruit()\n";
  }

  Fruit() {
    std::cout << "Fruit()\n";
  }

  auto Accept(std::shared_ptr<Visitor> visitor) -> void override {
    visitor->Visit(this);
  }

  auto GetPrice() -> int64_t override {
    return price_;
  }

  friend class Salesman;

 private:
  int64_t price_{-1};
};

class Meat : public Item {
 public:

  ~ Meat() override {
    std::cout << "~ Meat()\n";
  }

  Meat() {
    std::cout << "Meat()\n";
  }

  auto Accept(std::shared_ptr<Visitor> visitor) -> void override {
    visitor->Visit(this);
  }

  auto GetPrice() -> int64_t override {
    return price_ == -1 ? -1 : price_ - discount_;
  }

  friend class Salesman;

 private:
  int64_t price_{-1};
  int64_t discount_{0};
};

class Customer : public Visitor {
 public:
  Customer() = delete;

  explicit Customer(int64_t total_money) : total_money_(total_money) {}

  auto Visit(Fruit *fruit) -> void override {
    if (auto price = fruit->GetPrice(); price != -1) {
      std::cout << "Successful get fruit, before get(" << total_money_ <<
          ")" << ", after get(" << total_money_ - price << ")\n";
      total_money_ -= price;
    } else {
      std::cout << "Fruit has no price\n";
    }
  }

  auto Visit(Meat *meat) -> void override {
    if (auto price = meat->GetPrice(); price != -1) {
      std::cout << "Successful get meat, before get(" << total_money_ <<
          ")" << ", after get(" << total_money_ - price << ")\n";
      total_money_ -= price;
    } else {
      std::cout << "Meat has no price\n";
    }
  }
 public:
  int64_t total_money_;
};

class Salesman : public Visitor {
 public:
  auto Visit(Fruit *fruit) -> void override {
    fruit->price_ = 10;
  }

  auto Visit(Meat *meat) -> void override {
    meat->price_ = 100;
    meat->discount_ = 9;
  }
};

}

#endif
