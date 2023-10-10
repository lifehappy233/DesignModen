#include <memory>

#include "mediator.h"

int main() {
  auto houseAgent = std::make_shared<mediator::HouseAgent>();

  auto landlord1 = std::make_shared<mediator::Landlord>("lord1", houseAgent);
  auto landlord2 = std::make_shared<mediator::Landlord>("lord2", houseAgent);

  auto tenant1 = std::make_shared<mediator::Tenant>("tenant1", houseAgent);
  auto tenant2 = std::make_shared<mediator::Tenant>("tenant2", houseAgent);

  houseAgent->AddColleague(landlord1);
  houseAgent->AddColleague(landlord2);
  houseAgent->AddColleague(tenant1);
  houseAgent->AddColleague(tenant2);

  landlord1->SendMessage();

  tenant1->SendMessage();
  return 0;
}