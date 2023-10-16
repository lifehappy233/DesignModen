#ifndef SINGLEFACTORY_H_
#define SINGLEFACTORY_H_

#include <memory>
#include <mutex>
#include <map>
#include <algorithm>

#include "commonInfo.h"
#include "singleInfo.h"

namespace flyWeight {

class SingleFactory {
 public:
  static auto GetInstance() -> std::shared_ptr<SingleFactory> {
    if (instance_) {
      return instance_;
    }
    auto lock = std::unique_lock<std::mutex>(mutex_);
    if (instance_) {
      return instance_;
    }
    auto instance = new SingleFactory();
    instance_ = std::shared_ptr<SingleFactory>(instance);
    return instance_;
  }

  auto GenSingleInfo(std::pair<int32_t, int32_t> position,
                     const std::string &name, const std::string &color) -> SingleInfo {
    return {position, getCommonInfo(name, color)};
  }

 private:
  SingleFactory() = default;

  static std::shared_ptr<SingleFactory> instance_;
  static std::mutex mutex_;
  std::map<std::string, std::shared_ptr<CommonInfo>> commonInfos_;

  auto getCommonInfo(const std::string& name, const std::string& color)
      -> std::shared_ptr<CommonInfo> {
    auto key = name + color;
    if (commonInfos_.count(key)) {
      return commonInfos_[key];
    }

    auto lock = std::unique_lock<std::mutex>(mutex_);
    if (!commonInfos_.count(key)) {
      commonInfos_[key] = std::make_shared<CommonInfo>(name, color);
    }
    return commonInfos_[key];
  }
};

}

#endif
