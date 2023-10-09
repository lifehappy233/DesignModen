#ifndef SHOPPING_CART_H_
#define SHOPPING_CART_H_

#include <memory>
#include <vector>

#include "visitor.h"

namespace visitor {

class ShoppingCart {
 public:
  auto Accept(const std::shared_ptr<Visitor>& visitor) -> void {
    for (auto &it : items_) {
      it->Accept(visitor);
    }
  }

  auto AddItem(std::unique_ptr<Item> &&item) -> void {
    items_.emplace_back(std::move(item));
  }

 private:
  std::vector<std::unique_ptr<Item>> items_;
};

}

#endif
