#include <memory>

#include "pen.h"
#include "color.h"
#include "printer.h"

int main() {
  auto pink = std::make_shared<bridge::Pink>();
  auto blue = std::make_shared<bridge::Blue>();

  auto pinkPencil = std::make_shared<bridge::Pencil>(pink);
  auto pinkBallPen = std::make_shared<bridge::BallPen>(pink);
  auto bluePencil = std::make_shared<bridge::Pencil>(blue);
  auto blueBallPen = std::make_shared<bridge::BallPen>(blue);

  bridge::Printer printer;
  printer.Draw(pinkPencil);
  printer.Draw(pinkBallPen);
  printer.Draw(bluePencil);
  printer.Draw(blueBallPen);
  return 0;
}