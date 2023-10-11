#ifndef SUBSCRIBER_H_
#define SUBSCRIBER_H_

#include <iostream>

namespace observer {

class Subscriber {
 public:
  virtual ~ Subscriber() = default;

  virtual auto DoSomething() -> void = 0;
};

class Children : public Subscriber {
 public:
  ~ Children() override {
    std::cout << "~ Children()\n";
  }

  auto DoSomething() -> void override {
    std::cout << "Children buy snake\n";
  }
};

class Teacher : public Subscriber {
 public:
  ~ Teacher() override {
    std::cout << "~ Teacher()\n";
  }

  auto DoSomething() -> void override {
    std::cout << "Teacher buy books\n";
  }
};

}

#endif
