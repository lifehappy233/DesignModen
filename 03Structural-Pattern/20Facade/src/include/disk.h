#ifndef DISK_H_
#define DISK_H_

#include <string>
#include <iostream>

namespace facade {

class Disk {
 public:
  auto Write(std::string str) -> void {
    std::cout << "Disk Write: " << str << "\n";
  }

  auto Read() -> std::string {
    return "Disk Read()";
  }
};

}

#endif
