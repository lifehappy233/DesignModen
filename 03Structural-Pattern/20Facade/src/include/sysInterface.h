#ifndef SYSINTERFACE
#define SYSINTERFACE

#include <memory>
#include <utility>

#include "cpu.h"
#include "disk.h"

namespace facade {

class SysInterface {
 public:
  SysInterface() : cpu_(std::make_shared<Cpu>()),
                   disk_(std::make_shared<Disk>()) {}

  auto Write(std::string str) -> void {
    cpu_->Interrupt();
    disk_->Write(std::move(str));
  }

  auto Read() -> void {
    auto info = disk_->Read();
    std::cout << "Read(" << info << ") from disk\n";
  }

 private:
  std::shared_ptr<Cpu> cpu_;
  std::shared_ptr<Disk> disk_;
};

}

#endif
