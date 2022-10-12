#include <fmt/format.h>
#include <v8.h>

#include <libdone/done.hpp>

int main(int argc, char *argv[]) {
  char *filename = argv[1];
  fmt::print("Hello\n");
  auto *done = new Done();
  std::unique_ptr<v8::Platform> platform = done->initializeV8(argc, argv);

  done->initializeVM();
  done->InitializeProgram(filename);
  done->Shutdown();

  return 0;
}
