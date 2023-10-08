#include <memory>
#include <iostream>

#include "voter.h"

int main() {
  auto groupVoter = std::make_unique<responsibility::GroupVoter>(100);
  auto manageVoter = std::make_unique<responsibility::ManageVoter>(1000);

  groupVoter->SetSuperVoter(std::move(manageVoter));

  groupVoter->Handle(98);
  std::cout << "----------------------\n";
  groupVoter->Handle(100);
  std::cout << "----------------------\n";
  groupVoter->Handle(1000);
  std::cout << "----------------------\n";
  groupVoter->Handle(10000);
  std::cout << "----------------------\n";
  return 0;
}