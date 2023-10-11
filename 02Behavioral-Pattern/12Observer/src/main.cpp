#include <memory>

#include "publisher.h"
#include "subscriber.h"

int main() {
  auto teacher = std::make_shared<observer::Teacher>();
  auto children = std::make_shared<observer::Children>();

  auto supermarket = observer::Supermarket();

  supermarket.Subscribe(teacher);
  supermarket.Subscribe(children);
  supermarket.SomethingArrived();

  supermarket.CancelSubscribe(children);
  supermarket.SomethingArrived();
  return 0;
}
