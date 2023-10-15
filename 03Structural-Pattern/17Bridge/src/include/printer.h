#ifndef PRINTER_H_
#define PRINTER_H_

#include <memory>
#include <iostream>

#include "pen.h"

namespace bridge {

class Printer {
 public:
  Printer() = default;

  auto Draw(const std::shared_ptr<Pen>& pen) -> void {
    std::cout << "using " << pen->GetColor() << " " <<
        pen->GetTypeName() << " draw\n";
  }
};

}

#endif
