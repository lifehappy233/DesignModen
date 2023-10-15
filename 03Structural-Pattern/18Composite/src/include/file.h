#ifndef FILE_H_
#define FILE_H_

#include <string>
#include <iostream>
#include <utility>

namespace composite {

class File {
 public:
  File() = delete;

  virtual ~ File() = default;

  explicit File(std::string name) : name_(std::move(name)){}

  virtual auto Process(std::string) -> void = 0;

 protected:
  std::string name_;
};

class Director : public File {
 public:
  Director() = delete;

  ~ Director() override {
    std::cout << "~ Director()\n";
  }

  explicit Director(std::string name) : File(std::move(name)) {}

  auto AddFile(const std::shared_ptr<File>& file) -> void {
    files_.emplace_back(file);
  }

  auto Process(std::string path) -> void override {
    for (const auto &file : files_) {
      file->Process(path + "/" + name_);
    }
  }
 public:
  std::vector<std::shared_ptr<File>> files_;
};

class NormalFile : public File {
 public:
  NormalFile() = delete;

  ~ NormalFile() override {
    std::cout << "~ NormalFile()\n";
  }

  NormalFile(std::string name) : File(std::move(name)) {}

  auto Process(std::string path) -> void override {
    std::cout << path + "/" + name_ << "\n";
  }
};

}

#endif
