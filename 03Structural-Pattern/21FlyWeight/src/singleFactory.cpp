#include "singleFactory.h"

namespace flyWeight {

std::shared_ptr<SingleFactory> SingleFactory::instance_;

std::mutex SingleFactory::mutex_;

}
