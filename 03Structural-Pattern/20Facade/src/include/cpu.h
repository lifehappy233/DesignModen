#ifndef CPU_H_
#define CPU_H_

#include <iostream>

namespace facade {
class Cpu {
 public:
  auto Interrupt() -> void {
    std::cout << "Cpu interrupt\n";
  }
};
}

#endif
