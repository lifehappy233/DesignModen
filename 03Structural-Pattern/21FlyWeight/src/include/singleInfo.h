#ifndef SINGLEINFO_H_
#define SINGLEINFO_H_

#include <utility>

#include "commonInfo.h"

namespace flyWeight {

class SingleInfo {
 public:
  SingleInfo() = delete;

  SingleInfo(std::pair<int32_t, int32_t> position,
             std::shared_ptr<CommonInfo> commonInfo)
      : position_(std::move(position)), commonInfo_(std::move(commonInfo)) {}

  auto GetName() -> std::string {
    return commonInfo_->GetName();
  }

  auto GetColor() -> std::string {
    return commonInfo_->GetColor();
  }

  auto GetPosition() -> std::pair<int32_t, int32_t> {
    return position_;
  }

 private:
  std::pair<int32_t, int32_t> position_;
  std::shared_ptr<CommonInfo> commonInfo_;
};

}

#endif
