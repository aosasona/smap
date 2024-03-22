#include <iostream>

#define VERSION "0.0.1"

#ifndef COMMIT_HASH
#define COMMIT_HASH "unknown"
#endif

#ifndef COMPILE_DATE
#define COMPILE_DATE __DATE__ " " __TIME__
#endif

#define HELP_MESSAGE \
  "Usage: smap [options] \
\n\nOptions: \
\n  repl \t\t\t\tStart the smap REPL \
\n  run [filename] \t\tThe file to execute \
\n  --version, -v \t\t\tPrint the version of smap \
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

  if (arg == "-v" || arg == "--version") {
    std::printf("SMaP version: %s (%s)\n", VERSION, COMMIT_HASH);
    std::printf("Built on: %s\n", COMPILE_DATE);
    return 0;
  }

  std::cout << "Hello, world!" << std::endl;
  return 0;
}
