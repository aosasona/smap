#include <iostream>

#define VERSION "0.0.1"

#define HELP_MESSAGE \
  "Usage: smap [options] \
\n\nOptions: \
\n  repl \t\t\t\tStart the smap REPL \
\n  run [filename] \t\tThe file to execute \
\n  -h, --help\t\t\tPrint this help message \
\n  -v, --version\t\t\tPrint the version of smap \
"

int main(int argc, char** argv) {
  std::string arg;
  if (argc > 1) {
    arg = argv[1];
  }

  if (arg == "-h" || arg == "--help" || argc == 1) {
    std::cout << HELP_MESSAGE << std::endl;
    return 0;
  }

  std::cout << "Hello, world!" << std::endl;
  return 0;
}
