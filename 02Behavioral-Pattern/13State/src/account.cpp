#include "account.h"

namespace state {
auto NewbieState::CurrentState(Account *account) -> void {
  if (account->GetSource() >= 20) {
    std::cout << "from Newbie to Enter\n";
    account->SetState(std::make_shared<EnterState>());
  }
}
}