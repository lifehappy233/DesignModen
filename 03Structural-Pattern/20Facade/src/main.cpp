#include "sysInterface.h"

int main() {
  auto interface = facade::SysInterface();
  interface.Read();
  interface.Write("lifehappy");
  return 0;
}
