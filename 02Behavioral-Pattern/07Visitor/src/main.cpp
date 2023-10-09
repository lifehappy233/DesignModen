#include <memory>

#include "visitor.h"
#include "shopping_cart.h"

int main() {
  auto shoppingCart = visitor::ShoppingCart();

  auto customer = std::make_shared<visitor::Customer>(10000);
  auto salesman = std::make_shared<visitor::Salesman>();

  auto fruit = std::make_unique<visitor::Fruit>();
  auto meat = std::make_unique<visitor::Meat>();

  shoppingCart.AddItem(std::move(fruit));
  shoppingCart.AddItem(std::move(meat));

  shoppingCart.Accept(salesman);
  shoppingCart.Accept(customer);

  fruit = std::make_unique<visitor::Fruit>();
  shoppingCart.AddItem(std::move(fruit));
  shoppingCart.Accept(customer);
  return 0;
}