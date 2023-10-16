#include "singleInfo.h"
#include "singleFactory.h"

int main() {
  {
    auto factory = flyWeight::SingleFactory::GetInstance();
    std::cout << int64_t(factory.get()) << "\n";
    std::vector<flyWeight::SingleInfo> infos;

    for (int i = 0; i < 100; i++) {
      if (i & 1) {
        infos.emplace_back(factory->GenSingleInfo({i, i}, "lifehappy", "pink"));
      } else {
        infos.emplace_back(factory->GenSingleInfo({i, i}, "lifehappy", "blue"));
      }
    }
  }

  {
    auto factory = flyWeight::SingleFactory::GetInstance();
    std::cout << int64_t(factory.get()) << "\n";
    std::vector<flyWeight::SingleInfo> infos;

    for (int i = 0; i < 100; i++) {
      if (i & 1) {
        infos.emplace_back(factory->GenSingleInfo({i, i}, "lifehappy", "waite"));
      } else {
        infos.emplace_back(factory->GenSingleInfo({i, i}, "lifehappy", "black"));
      }
    }
  }
  return 0;
}