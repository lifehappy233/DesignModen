#ifndef WORKER_H_
#define WORKER_H_

#include "drink.h"

namespace temp {

class Worker {
 public:
  auto Done(Drink *drink) {
    drink->PreWork();
    drink->GetWater();
    drink->Handle();
  }
};

}

#endif
