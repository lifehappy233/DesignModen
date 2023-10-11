#include <memory>

#include "editor.h"
#include "command.h"

int main() {
  auto editor = std::make_shared<memento::Editor>();
  auto command = std::make_shared<memento::Command>(editor);

  editor->AddContent("lifehappy ");
  editor->AddContent("luck");

  editor->Show();
  command->Save();

  editor->AddContent(" okk");
  editor->Show();
  command->Undo();
  editor->Show();
  return 0;
}
