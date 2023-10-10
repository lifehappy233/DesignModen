#include "button.h"

int main() {
  auto ctrlX = command::CtrlXButton();
  auto ctrlC = command::CtrlCButton();

  ctrlX.Push();

  ctrlC.Push();
  return 0;
}