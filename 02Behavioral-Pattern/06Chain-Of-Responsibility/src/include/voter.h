#ifndef VOTER_H_
#define VOTER_H_

#include <memory>
#include <string>
#include <iostream>

namespace responsibility {

class BaseVoter {
 public:

  virtual ~BaseVoter() = default;

  BaseVoter(std::string name, int64_t max_number_can_vote)
      : name_(std::move(name)), max_number_can_vote_(max_number_can_vote) {}

  auto SetSuperVoter(std::unique_ptr<BaseVoter> &&voter) -> void {
    super_voter_ = std::move(voter);
  }

  auto Handle(int64_t number) -> void {
    if (number <= max_number_can_vote_) {
      std::cout << name_ << " handle " << number << "\n";
      return ;
    }

    if (super_voter_) {
      std::cout << name_ << " upload to super voter\n";
      super_voter_->Handle(number);
      return ;
    }
    std::cout << "no one handle " << number << "\n";
  }

 private:
  std::unique_ptr<BaseVoter> super_voter_{nullptr};

  int64_t max_number_can_vote_;

  std::string name_;
};

class GroupVoter : public BaseVoter {
 public:
  explicit GroupVoter(int64_t max_number_can_vote)
      : BaseVoter("GroupVoter", max_number_can_vote) {}

  ~ GroupVoter() {
    std::cout << "~ GroupVoter()\n";
  }
};

class ManageVoter : public BaseVoter {
 public:
  explicit ManageVoter(int64_t max_number_can_vote)
      : BaseVoter("ManageVoter", max_number_can_vote) {}

  ~ManageVoter() {
    std::cout << "~ ManageVoter()\n";
  }
};

}

#endif