#ifndef PROTOTYPE_H_
#define PROTOTYPE_H_

#include <memory>

namespace prototype {

class Object {
 public:
  virtual ~ Object() = default;
  virtual auto Clone() -> std::shared_ptr<Object> = 0;
};

}

#endif
